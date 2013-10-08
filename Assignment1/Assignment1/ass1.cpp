#include <iostream>
#include <math.h>

using namespace std;

typedef double (*MaclaurinSeriesFunctions)(double t);



double firstTerm( double t)
{
	double firstTermValue = 1.0f;
	return firstTermValue;
}
double secondTerm(double t)
{
	double secondTermValue = -t;
	return secondTermValue;
}
double thirdTerm(double t)
{
	double thirdTermValue = (((double)pow(t,3.0f))/3.0f);
	return thirdTermValue;
}
double fourthTerm(double t)
{
	double fourthTermValue = -(((double)pow(t,4.0f))/6.0f);
	return fourthTermValue;
}
double fifthTerm(double t)
{
	double fifthTermValue = (((double)pow(t,5.0f))/30.0f);
	return fifthTermValue;
}



int main(void)
{
	MaclaurinSeriesFunctions seriesFunctions [] = 
		{ 
			firstTerm,
			secondTerm,
			thirdTerm,
			fourthTerm,
			fifthTerm
		};
	int input = 0;
	int terms;
	double range;

	while (input != 2)
	{
		terms = 0;
		range = 0;

		cout << "Evalutate the Taylor Series approximation to exp(-t)*cos(t)" << endl;
		cout << "1: Evaluate the series" << endl;
		cout << "2: quit\n";
		cin  >>  input;

		if(input == 1)
		{
			cout << "Evaluating the series" << endl;
			cout << "Please enter the number of terms in the series (max 5 terms): ";
			cin  >> terms;
			if (!cin.good() || terms > 5)
			{
				cin.clear();

				cin.ignore();

				cout <<endl<<"Incorrect input, please enter an integer number no greater than 5.";
				continue;
			}
			cout << "Please enter the range of t to evaluate in 10 increments( 0.0 < t < +2.0): ";
			cin	 >> range;
			if (!cin.good() || range < 0.0 || range > +2.0)
			{
				cin.clear();

				cin.ignore();

				cout <<endl<<"Incorrect input, please enter a double between 0.0 and + 2.0.";
				continue;
			}
			
			for (double j = 0;j < range; j += 0.2)
			{
				double result = 0.0f;
			for (int i=0; i<terms; i++)
			{	
				result += seriesFunctions[i](j);
			}		
			cout << result<<endl;
			}
			cin >> range;
			break;

		}
	}
	return 0;
}


