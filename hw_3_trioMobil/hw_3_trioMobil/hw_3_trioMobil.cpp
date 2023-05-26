
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//Global variable to use in main:
int step;
int ballEnergy;

// Function to compute the start value:
int ballStartEnergy(vector<int> arr) {
	int startValue = arr[0];

	savePoint:
		ballEnergy = startValue;
		for (int i = 0; i < arr.size(); i++)
		{
			if (ballEnergy < arr[i])
			{
				ballEnergy -= arr[i] - ballEnergy;
			}
			else
			{
				ballEnergy += ballEnergy - arr[i];
			}
			step = i + 1;
		}
		if (ballEnergy < 0)
		{
			startValue += 1;
			goto savePoint;
		}
		return startValue;
}

int main()
{
	vector<int> heights;
	int vectorSize;

	cout << "Enter the size of legos: ";
	cin >> vectorSize;

	if (vectorSize > 0 && vectorSize < pow(10,5))
	{
		heights.resize(vectorSize);
		cout << "\nEnter the space-separated legos' heights, between 1 with 10 to the power of 5: ";
		
		for (int i = 0; i < heights.size(); i++)
		{
			cin >> heights.at(i);
			if (heights[i] < 0 || heights[i] > pow(10,5))
			{
				cout << "\n--------------------------------------------------\nEnter valid values as described above!..\n--------------------------------------------------\n";
				goto end;
			}
		}
	
		cout << "\n==========================================================================\nMinimum start energy of ball to complete challenge of legos is: " << ballStartEnergy(heights) <<  "\n------------------------------------------------------- \nFinally at step " << step << ", ball energy is " << ballEnergy <<"\n\n";
		// second for loop to control validation of value...
	}
	else
	{
		cout << "Enter a valid size of legos value, please!..";
		return 0;
	}
	end:
		return 0;
}
