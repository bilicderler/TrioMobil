#include <iostream>
#include <vector>
#include <string>
#include <locale>

using namespace std;

int findLetterIndex(const vector<wstring>& charVector, wstring targetLetter) {
    for (size_t i = 0; i < charVector.size(); i++) {
        if (charVector[i] == targetLetter) {
            return i;  // Found the letter, return its index
        }
    }

    return -1;  // Letter not found
}

wstring Solve_crypto(const wstring& cryipted_message, const vector<wstring>& small_alphabet, const vector<wstring>& big_alphabet, const vector<wstring>& num) {
    wstring target_letter{};
    wstring new_message{ L"" };

    for (auto l : cryipted_message)
    {
        target_letter = l;
        if (findLetterIndex(big_alphabet, target_letter) != -1)
        {
            int index = findLetterIndex(big_alphabet, target_letter);
            int new_index{ index + 3 };
            if (new_index > 28)
            {
                new_index -= 29;
            }
            new_message += big_alphabet[new_index];
        }
        else if (findLetterIndex(small_alphabet, target_letter) != -1)
        {
            int index = findLetterIndex(small_alphabet, target_letter);
            int new_index{ index + 3 };
            if (new_index > 28)
            {
                new_index -= 29;
            }
            new_message += small_alphabet[new_index];
        }
        else if (findLetterIndex(num, target_letter) != -1)
        {
            int index = findLetterIndex(num, target_letter);
            new_message += target_letter;
        }
        else
        {
            new_message += L" ";
        }

    }
    return new_message;
}

int main()
{
    locale::global(locale("")); // Set locale settings for Turkish character support

    vector<wstring> Small_alphabet{ L"a", L"b", L"c", L"ç", L"d", L"e", L"f", L"g", L"ğ", L"h", L"ı", L"i", L"j", L"k", L"l", L"m", L"n", L"o", L"ö", L"p", L"r", L"s", L"ş", L"t", L"u", L"ü", L"v", L"y", L"z" };
    vector<wstring> Big_alphabet{ L"A", L"B", L"C", L"Ç", L"D", L"E", L"F", L"G", L"Ğ", L"H", L"I", L"İ", L"J", L"K", L"L", L"M", L"N", L"O", L"Ö", L"P", L"R", L"S", L"Ş", L"T", L"U", L"Ü", L"V", L"Y", L"Z" };
    vector<wstring> Number{ L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9" };

    wstring secret_message;
    wcout << L"Enter your secret message please: ";
    getline(wcin, secret_message);

    wstring solved_message = Solve_crypto(secret_message, Small_alphabet, Big_alphabet, Number);

    wcout << L"Solved message that you entered secretly is: " << solved_message << endl;

    return 0;
}
