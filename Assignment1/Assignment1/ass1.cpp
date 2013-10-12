/****************************************************************************************************
Author:					Thom Palmer
Student No:				040 713 234
Assignment #:			1
Course Name/Number:		Numerical Computing CST8233
Lab Sect: 				402
Professor:				Andrew Tyler 
Due Date:				October 13 2013                                         
Submission Date:		October 12 2013
Files:					ass1.cpp
****************************************************************************************************/

/****************************************************************************************************
Filename:				ass1.cpp
Version: 				1.0                                         
Author:					Thom Palmer                                            
Student No:  			040 713 234                                         
Course Name/Number:		Numerical Computing CST8233
Lab Sect: 				402                                                    
Assignment #:			1
Assignment name:		Tall Building Simulation	
Due Date:				October 13 2013                                         
Submission Date:		October 12 2013
Professor:				Andrew Tyler                                           
Purpose: 					Evaluates the advantage of using the Maclaurin series approximation vs 
							the exact value to determine the motion of a tall building in response
							to a gust of wind.
****************************************************************************************************/
#include <iostream>
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES 
#endif
#include <math.h>
using namespace std;

typedef double (*MaclaurinSeriesFunctions)(double);

// Forward Declarations
double GetFirstNonZeroValue(double);
double GetSecondNonZeroValue(double);
double GetThirdNonZeroValue(double);
double GetFourthNonZeroValue(double);
double GetFifthNonZeroValue(double);
double GetExactValue(double);			

/****************************************************************************************************
Function name:		main
Purpose:			main function
					Allows user to select options in order to evaluate the Maclaurin series at various
					terms and ranges						
In parameters:		none
Out parameters:		0 for successful execution
Version:			1.5
Author:				Thom Palmer
****************************************************************************************************/
int main(void)
{
	// Create an array of function pointers.
	MaclaurinSeriesFunctions seriesFunctions [] = 
		{ 
			GetFirstNonZeroValue, 
			GetSecondNonZeroValue,
			GetThirdNonZeroValue,
			GetFourthNonZeroValue,
			GetFifthNonZeroValue
		};

	int input;		// user selection
	int terms;		// number of terms to evaluate		
	double range;	// amount to increase each evaluation

	// Display options to user
	cout << "Evaluate the Taylor Series approximation to exp(-t)*cos(t)" << endl;
	cout << "1: Evaluate the series" << endl;
	cout << "2: quit" << endl;
	cin  >>  input;

	
	while (input != 2)
	{
		if(input == 1)
		{
			// Request number of terms until valid and store in terms when valid
			cout << "Evaluating the series" << endl;
			cout << "Please enter the number of terms in the series (max 5 terms): ";
			cin  >> terms;
			if (!cin.good() || terms > 5 || terms < 0)
			{
				cin.clear();

				cin.ignore();

				cout <<endl<<"Incorrect input, please enter an integer number no greater than 5 and not less than 0:";
				continue;
			}

			// Request range until valid and store in range when valid
			cout << "Please enter the range of t to evaluate in 10 increments( 0.0 < t < +2.0): ";
			cin	 >> range;
			if (!cin.good() || range < 0.0 || range > +2.0)
			{
				cin.clear();

				cin.ignore();

				cout <<endl<<"Incorrect input, please enter a double between 0.0 and + 2.0.";
				continue;
			}
			
			// Use nested for loop to evaulate each range and for the amount of terms requested
			for (double r = 0;r < range; r += (range/10))
			{
				double result; // Stores total result of Maclaurin Series
				
				// Evaluate the series to the amount of terms requested
				for (int t=0; t<terms; t++)
				{	
					// t Stores the index of the function to use and the value of r is passed into each function
					result += seriesFunctions[t](r);
				}

				cout << result<<endl;
				cout << GetExactValue(r)<<endl;
			}
			cout <<endl<< "Evaluate the Taylor Series approximation to exp(-t)*cos(t)" << endl;
			cout <<endl<< "1: Evaluate the series" << endl;
			cout << "2: quit" <<endl;
			cin  >>  input;
		}
	}
	return 0;
}

/****************************************************************************************************
Function name:		main
Purpose:			main function
					Allows user to select options in order to maintain the student database
In parameters:		none
Out parameters:		0 for successful execution
Version:			1.0
Author:				Andrew Tyler
****************************************************************************************************/
double GetFirstNonZeroValue(double t)
{
	double firstTermValue = 1.0f;
	return firstTermValue;
}
/****************************************************************************************************
Function name:		main
Purpose:			main function
					Allows user to select options in order to maintain the student database
In parameters:		none
Out parameters:		0 for successful execution
Version:			1.0
Author:				Andrew Tyler
****************************************************************************************************/
double GetSecondNonZeroValue(double t)
{
	double secondTermValue = -t;
	return secondTermValue;
}
/****************************************************************************************************
Function name:		main
Purpose:			main function
					Allows user to select options in order to maintain the student database
In parameters:		none
Out parameters:		0 for successful execution
Version:			1.0
Author:				Andrew Tyler
****************************************************************************************************/
double GetThirdNonZeroValue(double t)
{
	double thirdTermValue = (((double)pow(t,3.0f))/3.0f);
	return thirdTermValue;
}
/****************************************************************************************************
Function name:		main
Purpose:			main function
					Allows user to select options in order to maintain the student database
In parameters:		none
Out parameters:		0 for successful execution
Version:			1.0
Author:				Andrew Tyler
****************************************************************************************************/
double GetFourthNonZeroValue(double t)
{
	double fourthTermValue = -(((double)pow(t,4.0f))/6.0f);
	return fourthTermValue;
}
/****************************************************************************************************
Function name:		main
Purpose:			main function
					Allows user to select options in order to maintain the student database
In parameters:		none
Out parameters:		0 for successful execution
Version:			1.0
Author:				Andrew Tyler
****************************************************************************************************/
double GetFifthNonZeroValue(double t)
{
	double fifthTermValue = (((double)pow(t,5.0f))/30.0f);
	return fifthTermValue;
}
/****************************************************************************************************
Function name:		main
Purpose:			main function
					Allows user to select options in order to maintain the student database
In parameters:		none
Out parameters:		0 for successful execution
Version:			1.0
Author:				Andrew Tyler
****************************************************************************************************/
double GetExactValue(double t)
{
	double exactValue = exp(-t)*cos(t);
	return exactValue;
}
