#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace Trio {
    class TrioPath {
    public:
        TrioPath(const string& path) : path_(path) {}

        TrioPath branch_path() const {
            size_t found = path_.find_last_of("/\\");
            if (found != string::npos) {
                return TrioPath(path_.substr(0, found));
            }
            return TrioPath("");
        }

        bool is_empty() const {
            return path_.empty();
        }

        TrioPath extension() const {
            size_t found = path_.find_last_of(".");
            if (found != string::npos && found > path_.find_last_of("/\\")) {
                return TrioPath(path_.substr(found));
            }
            else if (found != string::npos)
            {
                return TrioPath(path_.substr(found));
            }
            return TrioPath("");
        }

        TrioPath filename() const {
            size_t found = path_.find_last_of("/\\");
            if (found != string::npos) {
                return TrioPath(path_.substr(found + 1));
            }
            return TrioPath(path_);
        }

        bool has_extension() const {
            size_t found = path_.find_last_of(".");
            size_t lastSlash = path_.find_last_of("/\\");
            if (found != string::npos && found > lastSlash)
            {
                return true;
            }
            else if (found && !lastSlash)
            {
                return true;
            }
            else if (!found && !lastSlash)
            {
                return false;
            }

        }

        bool has_filename() const {
            size_t lastSlash = path_.find_last_of("/\\");
            if (!path_.empty() && lastSlash != string::npos && lastSlash < path_.size() - 1)
            {
                return true;
            }
            else if (!path_.empty())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        TrioPath root_directory() const {
            size_t found = path_.find_first_of("/\\");
            if (found != string::npos) {
                return TrioPath(path_.substr(0, found + 1));
            }
            return TrioPath("");
        }

        TrioPath stem() const {
            size_t lastSlash = path_.find_last_of("/\\");
            size_t lastDot = path_.find_last_of(".");
            if (lastDot != string::npos && lastDot > lastSlash) {
                return TrioPath(path_.substr(lastSlash + 1, lastDot - lastSlash - 1));
            }
            else if (lastDot != string::npos)
            {
                return path_.substr(0,(path_.size()- (path_.size()-lastDot)));
            }
            return TrioPath(path_);
        }


        size_t size() const {
            return path_.size();
        }

        void replace_extension(const string& filePath, const string& newExtension) {
            string newFilePath = filePath.substr(0, filePath.find_last_of('.')) + newExtension;
            // Using rename() function to rename the file
            if (std::rename(filePath.c_str(), newFilePath.c_str()) == 0) {
                std::cout << "File extension changed successfully!" << std::endl;
                path_ = newFilePath; // Update the path_ member variable
            }
            else {
                std::cout << "Error occurred while changing the file extension!" << std::endl;
            }
        }

        bool file_exists() const {
            ifstream file(path_);
            return file.good() && file.is_open();
        }

        string get_status() const {
            return file_exists() ? "File exists!" : "File not found!";
        }

        string getString() const {
            return path_;
        }

    private:
        string path_;
    };
}

int main() {
    cout << "Enter a path: ";
    string userPath;
    getline(cin, userPath);

    Trio::TrioPath path(userPath);

    if (!path.file_exists()) {
        cout << "Error: The specified file does not exist!" << endl;
        return 1;
    }
    cout << "Is the path empty? : " << (path.is_empty() ? "Yes" : "No") << endl;

    Trio::TrioPath branchPath = path.branch_path();
    cout << "Does the branch path exist? : " << (branchPath.has_filename() ? "Yes" : "No") << endl;
    cout << "Root Path: " << path.root_directory().getString() << endl;
    cout << "Branch Path: " << branchPath.getString() << endl;

    cout << "Does the filename exist? : " << (path.has_filename() ? "Yes" : "No") << endl;
    cout << "Filename: " << path.filename().getString() << endl;

    cout << "Does the extension exist? : " << (path.has_extension() ? "Yes" : "No") << endl;
    cout << "Extension: " << path.extension().getString() << endl;

    cout << "File name without extension: " << path.stem().getString() << endl;
    cout << "Character length: " << path.size() << endl;

    cout << "What extension would you like to replace with (provide with a leading dot): ";
    string newExtension;
    getline(cin, newExtension);
    path.replace_extension(userPath, newExtension);

    cout << "New filename: " << path.filename().getString() << endl;

    return 0;
