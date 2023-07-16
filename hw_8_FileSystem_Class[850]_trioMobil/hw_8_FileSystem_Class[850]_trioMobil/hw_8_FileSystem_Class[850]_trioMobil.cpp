#include <iostream>
#include <string>

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
            return (found != string::npos && found > lastSlash);
        }

        bool has_filename() const {
            return !path_.empty() && path_.find_last_of("/\\") != string::npos;
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
            }
            else {
                std::cout << "Error occurred while changing the file extension!" << std::endl;
            }
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
}
