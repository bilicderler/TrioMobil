

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
using namespace std;


int Convert_to_decimal(int binary_number) {
	string text_of_bin{};
	text_of_bin = to_string(binary_number);
	int sum_of_digits_power{ 0 };
	int power_loop{ 0 };
	for (int i=(text_of_bin.length()-1); i>=0; i--)
	{
		//Convert the character of text of bnary number, user entered, to int for calculate the sum of digit operations results.
		int digit = text_of_bin[i] - '0';
		sum_of_digits_power += (pow(2, power_loop)) * digit;
		power_loop += 1;
	}
	return sum_of_digits_power;
}


int Convert_to_binary(int decimal_number) {
	vector <string> text_of_bin{};
	string text_bin{""};
	int mode_of_number{ decimal_number };
	int str_to_int_binary{};
	
	// Calculate binary form of the decimal number
	do
	{
		text_of_bin.insert(text_of_bin.begin(), to_string(decimal_number % 2));
		decimal_number /= 2;
	} while (decimal_number!=0);
	
	// Assign vector to string rype to be convertable to int
	for (auto s :text_of_bin)
	{
		text_bin += s;
	}
	str_to_int_binary = stoi(text_bin);
	return str_to_int_binary;
}


int main()
{   
	int binary_num{};
	string bin_num_temp{};
	char selection{};
	int sum_of_decimals{ 0 }, sum_of_binaries{};
	do
	{
		cout << "Enter the number in base of binary: ";
		cin >> bin_num_temp;
		binary_num = stoi(bin_num_temp);
		sum_of_decimals += Convert_to_decimal(binary_num);
		cout << "Please press 'Q' to exit or press any key without 'Q' to do summation with other binary number...";
		cin >> selection;
	} while (toupper(selection) != 'Q');
	
	sum_of_binaries = Convert_to_binary(sum_of_decimals);
	string sum_of_binaries_text = to_string(sum_of_binaries);
	if (sum_of_binaries_text.length() != 8)
	{
		int zeroLength = 8 - sum_of_binaries_text.length();
		for (size_t i = 0; i < zeroLength; i++)
		{
			(sum_of_binaries_text).insert(sum_of_binaries_text.begin(), '0');
		}
	}
	(sum_of_binaries_text).insert(4, " ");
	cout << "\n======================================================================================\n";
	cout << "\nHere is the binary representation of the sum of the binary numbers you entered : " << sum_of_binaries_text << endl;
	return 0;
}
