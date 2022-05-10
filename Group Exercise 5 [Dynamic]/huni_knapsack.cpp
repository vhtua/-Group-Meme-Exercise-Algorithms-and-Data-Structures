#include <iostream>
#include <iomanip>

using namespace std;

// Function to check your objective number;
int checkObjInput(int inputTest)
{

	int input;

	cin >> input;

	if (input <= inputTest)
	{

		return input;
	}

	else
	{
		int newInput = inputTest;
		cout << "Wrong input number" << endl;
		cout << "Input your number again" << endl;

		return checkObjInput(newInput);
	}
}

// Function to check your weight and vaule of the input
int checkInput(int inputTest)
{

	int newInput;

	if (inputTest <= 10)
	{

		return inputTest;
	}

	else
	{
		cout << "Wrong input number" << endl;
		cout << "Input your number again" << endl;
		cin >> newInput;
		return checkInput(newInput);
	}
}

int main()
{

	/*



	*/

	// set variable for input
	int a;		/* input number of object */
	int w1[100];	/* array for test weight */
	int w2[100];	/* array for input weitht */
	int v1[100];	/* array for test value */
	int v2[100];	/* array for input value */
	int maxWei = 0; /* the maxium weight */

	// set variable for calcuate
	int num;	      /* number to caculate */
	int wei;	      /* weight to caculate */
	int ktable[100][100]; /* table to caculate */
	int snack = 0;	      /* snack number */
	int ksnack[100];      /* array of snack */

	cout << "=============Run=============" << endl;
	cout << endl;

	// The note part
	cout << "Note: All value is natural numbers" << endl;
	cout << "      Maxium objects is 14" << endl; /* For testing purpose */
	cout << "      Maxium weight of each object is 10" << endl;
	cout << "      Maxium value of each object is 10" << endl;
	cout << endl;

	cout << "Close window if you want to stop or run the program again " << endl;

	cout << endl;
	cout << endl;

	/*** Start to input ***/

	cout << "=============Start============" << endl;
	cout << endl;

	// Input object
	cout << "How many input do you want to set ? " << endl;
	a = checkObjInput(14);

	cout << "Input sucess" << endl;
	cout << endl;

	// Input weight and value
	for (int i = 1; i <= a; i++)
	{

		cout << "Weigth of Object number  " << i << endl;
		cin >> w1[i];
		w2[i] = checkInput(w1[i]);
		maxWei = maxWei + w2[i];

		cout << "Value of Object number  " << i << endl;
		cin >> v1[i];
		v2[i] = checkInput(v1[i]);

		cout << endl;
		cout << "---";
		cout << endl;
		cout << endl;
	}

	// Draw the table
	cout << "The table" << endl;
	cout << "--------------------" << endl;
	cout << endl;

	cout << left << setw(10) << "Number";
	for (int i = 1; i <= a; i++)
	{

		cout << left << setw(5) << i;
	}
	cout << endl;

	cout << left << setw(10) << "Weight";
	for (int i = 1; i <= a; i++)
	{
		cout << left << setw(5) << w2[i];
	}
	cout << endl;

	cout << left << setw(10) << "Value";
	for (int i = 1; i <= a; i++)
	{
		cout << left << setw(5) << v2[i];
	}

	cout << endl;
	cout << endl;

	/*** Start to calulate ***/

	cout << "==========Caclulating=========" << endl;
	cout << endl;

	// Input number and weight K(n,w) to caculate
	cout << "The amnout of number you want to cacluate: ";
	num = checkObjInput(14);
	cout << "Input sucess" << endl;
	cout << endl;

	cout << "The maximum weight(<=" << maxWei << ") you want to calculate: ";
	wei = checkObjInput(maxWei);
	cout << "Input sucess" << endl;
	cout << endl;
	cout << endl;

	// Caluate optimal value
	for (int i = 1; i <= num; i++)
	{

		ktable[i][0] = 0;
	}

	for (int j = 0; j <= wei; j++)
	{

		if (w2[1] <= j)
		{
			ktable[1][j] = v2[1];
		}
		else
		{
			ktable[1][j] = 0;
		}
	}

	for (int i = 2; i <= num; i++)
	{

		for (int j = 1; j <= wei; j++)
		{

			if (j >= w2[i] && ktable[i - 1][j - w2[i]] + v2[i] > ktable[i - 1][j])
			{

				ktable[i][j] = ktable[i - 1][j - w2[i]] + v2[i];
			}

			else
			{
				ktable[i][j] = ktable[i - 1][j];
			}
		}
	}

	// Caculate the snack
	for (int i = 0; i < num; i++)
	{

		if (ktable[i + 1][10] > ktable[i][10])
		{
			ksnack[snack] = i + 1;
			snack = snack + 1;
		}
	}

	// Print the result
	cout << "------------------------------------------ " << endl;
	cout << " The optimal value for K(n,W) = " << ktable[num][wei] << endl;
	cout << "------------------------------------------ " << endl;
	cout << endl;

	cout << "------------------------------------------ " << endl;
	cout << " The snack for K(n,W) = { ";
	for (int i = 0; i < snack; i++)
	{
		cout << ksnack[i];
		if (i != (snack - 1))
		{
			cout << ", ";
		}
	}
	cout << " }" << endl;
	cout << "------------------------------------------ " << endl;

	return 0;
}