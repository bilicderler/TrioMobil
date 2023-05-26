
#include <iostream>
using namespace std;

//Required variables:
int h_control, m_control, hour, minute;

// Create function that converts number to word:
string number_to_words(int number) {
    static const string units[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    static const string teens[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    static const string tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

    if (number >= 0 && number < 10) {
        return units[number];
    }
    else if (number >= 10 && number < 20) {
        return teens[number - 10];
    }
    else if (number >= 20 && number < 100) {
        int unit = number % 10;
        int ten = number / 10;

        string result = tens[ten];
        if (unit > 0) {
            result += " " + units[unit];
        }
        return result;
    }
    else {
        return "Invalid number!";
    }
}


string timeInWords(int h, int m) {
    // Conditions to take output of the time:
    if (h > 12)
    {
        h = h - 12;
    }

    if (m < 30 && m>0)
    {
        if (m == 15)
        {
            return "Quarter past " + number_to_words(h);
        }
        else if (m == 1)
        {
            return number_to_words(m) + " minute past " + number_to_words(h);
        }
        else
        {
            return number_to_words(m) + " minutes past " + number_to_words(h);
        }
    }
    else if (m == 30)
    {
        return "Half past " + number_to_words(h);
    }
    else if (m>30 && m<60)
    {
        if (m == 45)
        {
            return "Quarter to " + number_to_words(h + 1);
        }
        else
        {
            return number_to_words(60-m) + " minutes to " + number_to_words(h+1);
        }
    }
    else
    {
        return number_to_words(h) + " o'clock";
    }

}

int main()
{
    //Take the hour portion of time:
    cout << "Enter hour portion of the time: ";
    cin >> h_control;
    if (h_control > 0 && h_control <= 23)
    {
        hour = h_control;
    }
    else
    {
        cout<< "\n\nEnded the program because entered invalid hour value for the time";
        return 0;
    }

    //Take the minute portion of time:
    cout << "Enter minute portion of the time: ";
    cin >> m_control;
    if (m_control >= 0 && m_control <= 59)
    {
        minute = m_control;
    }
    else
    {
        cout << "\n\nEnded the program because entered invalid minute value for the time";
        return 0;
    }

    //Take output of time as words presentation
    cout << "\n--------------------------\n" + timeInWords(hour, minute) + "\n\n"; 


}
