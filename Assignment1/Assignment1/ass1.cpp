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
#include <iomanip>
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
	// Each functions represents a non zero term in the series
	MaclaurinSeriesFunctions seriesFunctions [] = 
		{ 
			GetFirstNonZeroValue, 
			GetSecondNonZeroValue,
			GetThirdNonZeroValue,
			GetFourthNonZeroValue,
			GetFifthNonZeroValue
		};

	int input = 0;		// user selection
	int terms = 0;		// number of terms to evaluate		
	double range = 0;	// amount to increase each evaluation

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
			
			// Set output alignment left and display table title and headers
			cout<<setiosflags(ios::left);
			cout<<endl<<"MACLAURIN SERIES"<<endl;
			// Use setw() to format columns
			cout<<setw(13)<<"  x"<<setw(15)<<"Series"<<setw(15)<<"Exact"<<setw(15)<<"Exact % Error"<<setw(15)<<" Trunc. % Error"<<endl;

			// Use nested for loop to evaulate each range for the amount of terms requested
			for (double x = 0;x < range;x += (range/10.0f))
			{
				double result = 0; // Stores total result of Maclaurin Series
				
				// Evaluate the series to the amount of terms requested
				for (int t=0; t<terms; t++)
				{	
					// t stores the index of the function to use and the value of x is passed into each function
					result += seriesFunctions[t](x);
				}
				// Format output to scientific format(exponential).
				// Adjust decimal place using setprecision()
				cout<<setiosflags(ios::scientific);
				cout<<setw(13)<<setprecision(3)<<x<<setw(15)<<setprecision(5)<<result;
				cout<<setw(15)<<setprecision(5)<<GetExactValue(x)<<endl;
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
Function name:		GetFirstNonZeroValue
Purpose:			Returns the value of the first non zero term in the series
In parameters:		Current value of t
Out parameters:		firstTermValue
Version:			1.0
Author:				Thom Palmer
****************************************************************************************************/
double GetFirstNonZeroValue(double t)
{
	double firstTermValue = 1.0f;
	return firstTermValue;
}
/****************************************************************************************************
Function name:		GetSecondNonZeroValue
Purpose:			Returns the value of the second non zero term in the series
In parameters:		Current value of t
Out parameters:		secondTermValue
Version:			1.0
Author:				Thom Palmer
****************************************************************************************************/
double GetSecondNonZeroValue(double t)
{
	double secondTermValue = -t;
	return secondTermValue;
}
/****************************************************************************************************
Function name:		GetThirdNonZeroValue
Purpose:			Returns the value of the third non zero term in the series
In parameters:		Current value of t
Out parameters:		thirdTermValue
Version:			1.0
Author:				Thom Palmer
****************************************************************************************************/
double GetThirdNonZeroValue(double t)
{
	double thirdTermValue = t*t*t/3.0f;
	return thirdTermValue;
}
/****************************************************************************************************
Function name:		GetFourthNonZeroValue
Purpose:			Returns the value of the fourth non zero term in the series
In parameters:		Current value of t
Out parameters:		fourthTermValue
Version:			1.0
Author:				Thom Palmer
****************************************************************************************************/
double GetFourthNonZeroValue(double t)
{
	double fourthTermValue = -t*t*t*t/6.0f;
	return fourthTermValue;
}
/****************************************************************************************************
Function name:		GetFifthNonZeroValue
Purpose:			Returns the value of the fifth non zero term in the series
In parameters:		Current value of t
Out parameters:		fifthTermValue
Version:			1.0
Author:				Thom Palmer
****************************************************************************************************/
double GetFifthNonZeroValue(double t)
{
	double fifthTermValue = t*t*t*t*t/30.0f;
	return fifthTermValue;
}
/****************************************************************************************************
Function name:		GetSixthNonZeroValue
Purpose:			Returns the value of the sixth non zero term in the series
In parameters:		Current value of t
Out parameters:		sixthTermValue
Version:			1.0
Author:				Thom Palmer
****************************************************************************************************/
double GetSixthNonZeroValue(double t)
{
	double sixthTermValue = t*t*t*t*t*t/630.0f;
	return sixthTermValue;
}
/****************************************************************************************************
Function name:		GetExactValue
Purpose:			Returns the exact value of the expression using the math libray
In parameters:		Current value of t
Out parameters:		exactValue
Version:			1.0
Author:				Thom Palmer
****************************************************************************************************/
double GetExactValue(double t)
{
	double exactValue = exp(-t)*cos(t);
	return exactValue;
}
/****************************************************************************************************
Function name:		GetExactPercentError
Purpose:			Calculates the exact percentage error
In parameters:		approxSeriesValue, exactSeriesValue
Out parameters:		exactValue
Version:			1.0
Author:				Thom Palmer
****************************************************************************************************/
double GetExactPercentError(double approxSeriesValue, double exactSeriesValue)
{
	double exactPercentError = exactSeriesValue - exactSeriesValue;
	return exactPercentError;
}
/****************************************************************************************************
Function name:		GetExactValue
Purpose:			Returns the exact value of the expression using the math libray
In parameters:		Current value of t
Out parameters:		exactValue
Version:			1.0
Author:				Thom Palmer
****************************************************************************************************/

