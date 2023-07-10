#include <iostream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class TrioPath {
private:
    fs::path path_;

public:
    TrioPath(const string& path) : path_(path) {}

    TrioPath branch_path() const {
        return TrioPath(path_.parent_path().string());
    }

    bool is_empty() const {
        return path_.empty();
    }

    TrioPath extension() const {
        return TrioPath(path_.extension().string());
    }

    TrioPath filename() const {
        return TrioPath(path_.filename().string());
    }

    bool has_extension() const {
        return !path_.extension().empty();
    }

    bool has_filename() const {
        return !path_.filename().empty();
    }

    TrioPath root_directory() const {
        return TrioPath(path_.root_path().string());
    }

    TrioPath stem() const {
        return TrioPath(path_.stem().string());
    }

    uintmax_t size() const {
        try {
            return fs::file_size(path_);
        } catch (const fs::filesystem_error& e) {
            cerr << "Hata: " << e.what() << endl;
            throw; // Hatanın yeniden fırlatılması
        }
    }

    void replace_extension(const string& newExtension) {
        fs::path newPath = path_;
        newPath.replace_extension(newExtension);
        path_ = newPath;
    }

    void apply_changes() {
        fs::rename(path_, path_);
    }

    string string() const {
        return path_.string();
    }
};

int main() {
    try {
        cout << "Bir path giriniz: ";
        string userPath;
        getline(cin, userPath);

        TrioPath path(userPath);

        cout << "Path boş mu? : " << (path.is_empty() ? "Evet" : "Hayır") << endl;

        TrioPath branchPath = path.branch_path();
        cout << "Branch path mevcut mu? : " << (branchPath.has_filename() ? "Evet" : "Hayır") << endl;
        cout << "Root Path: " << path.root_directory().string() << endl;
        cout << "Branch Path: " << branchPath.string() << endl;

        cout << "Filename mevcut mu? : " << (path.has_filename() ? "Evet" : "Hayır") << endl;
        cout << "Filename: " << path.filename().string() << endl;

        cout << "Extension mevcut mu? : " << (path.has_extension() ? "Evet" : "Hayır") << endl;
        cout << "Extension: " << path.extension().string() << endl;

        cout << "Uzantısız dosya adı: " << path.stem().string() << endl;
        cout << "Karakter uzunluğu: " << path.size() << endl;

        cout << "Uzantıyı ne ile değiştirmek isterseniz: ";
        string newExtension;
        getline(cin, newExtension);
        path.replace_extension(newExtension);
        path.apply_changes();

        cout << "Yeni filename: " << path.filename().string() << endl;
    } catch (const exception& e) {
        cerr << "Hata: " << e.what() << endl;
    }

    return 0;
}
