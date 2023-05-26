#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

// Function to take power of the number as number of digits:
int Power(int d, int num) {
    if (num==0)
    {
        return 0;
    }
    int power_of_d{ 1 };
    for (int i = 1; i <log10(num)+1 ; i++)
    {
        power_of_d *= d;
    }
    return power_of_d;
}

// Function to check if the number is Armstrong
bool isArmstrong(int n) {
    int sum_of_input_digits{ 0 };
    string int_to_text = to_string(n);

    for (int i = 0; i < int_to_text.length(); i++) {
        string s = int_to_text.substr(i, 1);
        int a = stoi(s);
        sum_of_input_digits += Power(a,n);
    }

    if (sum_of_input_digits == n) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    // Take a number from user:
    int input;
    cout << "Enter an integer to check if it's an Armstrong number: ";
    //assign the number to "input" variable:
    cin >> input;
    // Check if number entered if it's an Armstrong number, with the function: 
    bool is_armstrong = isArmstrong(input);
    // Print results:
    if (is_armstrong) {
        cout << "The number entered is an Armstrong number.\n";
    }
    else {
        cout << "The number entered is not an Armstrong number, please try again!..\n" ;
    }

    return 0;
}
