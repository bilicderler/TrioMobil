
#include <iostream>
#include "hw_1_trioMobil.h"
using namespace std;
// Define variables will used in code:
int a[3];
int b[3];
int result[2];
int a_points;
int b_points;
int constraint;

/* Create function will take 2 array as parameter to compare their value with each other for avery elements
 and return an array to take an output about result of comparison */
int* compareTriplets(int* a, int* b) {

    for (int i = 0; i < 3; i++)
    {
        if (a[i] > b[i])
        {
            a_points++;
            result[0] = a_points;
        }
        else if (a[i] < b[i])
        {
            b_points++;
            result[1] = b_points;
        }
    }
    cout << "\nCalculating the result of comparisons...";
    return result;
}


int main()
{
    //Take Alice's scores with constraints:
    cout << "Enter Alice's problem clarity score from 1 to 100: ";
    cin >> constraint;
    if (constraint>=0 && constraint<=100)
    {
        a[0] = constraint;
    }
    else
    {
        cout << "\nEnter valid point between 1-100, please!..";
        return 0;
    }

    cout << "Enter Alice's originality score from 1 to 100: ";
    cin >> constraint;
    if (constraint >= 0 && constraint <= 100)
    {
        a[1] = constraint;
    }
    else
    {
        cout << "\nEnter valid point between 1-100, please!..";
        return 0;
    }

    cout << "Enter Alice's difficulty score from 1 to 100: ";
    cin >> constraint;
    if (constraint >= 0 && constraint <= 100)
    {
        a[2] = constraint;
    }
    else
    {
        cout << "\nEnter valid point between 1-100, please!..";
        return 0;
    }

    //Take Bob's scores with constraints:
    cout << "Enter Bob's problem clarity score from 1 to 100: ";
    cin >> constraint;
    if (constraint >= 0 && constraint <= 100)
    {
        b[0] = constraint;
    }
    else
    {
        cout << "\nEnter valid point between 1-100, please!..";
        return 0;
    }

    cout << "Enter Bob's originality score from 1 to 100: ";
    cin >> constraint;
    if (constraint >= 0 && constraint <= 100)
    {
        b[1] = constraint;
    }
    else
    {
        cout << "\nEnter valid point between 1-100, please!..";
        return 0;
    }

    cout << "Enter Bob's difficulty score from 1 to 100: ";
    cin >> constraint;
    if (constraint >= 0 && constraint <= 100)
    {
        b[2] = constraint;
    }
    else
    {
        cout << "\nEnter valid point between 1-100, please !..";
        return 0;
    }
    //Compare the points using compareTriplets() function
    compareTriplets(a, b);
    cout << "\n----------------------------------------------------\n\nThe result is (Alice - Bob): " << result[0] << " " << result[1] <<"\n\n";
}   

