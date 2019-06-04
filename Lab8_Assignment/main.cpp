#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Function prototypes
int getSize();
double getSum(double[], int);
double getAvg(double[], int);

int main() {

	ifstream inputFile("dataFile.txt");
	double* data;
	int size = 0;		// size = number of values in file to be put into array

	// Read the file and then create a dynamic array that stores its elements.
	if (!inputFile)
		cout << "Error: file could not be opened.\n";
	else {
		// Get size: count number of values in file
		size = getSize();

		// Create dynamic array
		data = new double[size];
		if (data == nullptr)
			cout << "Error: memory could not be allocated.\n";
		else {
			cout << "Values in dynamic array:\n";
			cout << fixed << showpoint << setprecision(1);
			for (int i = 0; i < size; i++) {
				inputFile >> *(data + i);
				cout << *(data + i) << endl;
			}
			cout << endl;
		}

		// Find the sum and the average of all numbers
		double sum, average;

		sum = getSum(data, size);
		cout << "Sum of all elements = " << sum << endl;

		average = getAvg(data, size);
		cout << "Average of all elements = " << average << endl;
		
		cout << endl;
	
		// Deallocate memory
		delete[] data;
	}

	inputFile.close();

	system("pause");
	return 0;
}

// Function implementations
int getSize() {								// Find number of values in file
	ifstream inFile("dataFile.txt");
	int sz = 0;
	for (double i; inFile >> i; i++)
		sz++;
	return sz;
}

double getSum(double a[], int sz) {			// Find sum of all elements 
	double sm = 0;
	for (int i = 0; i < sz; i++) {
		sm += *(a + i);
	}
	return sm;
}

double getAvg(double a[], int sz) {			// Find average of all elements
	double avg, sm;
	sm = getSum(a, sz);
	avg = sm / sz;
	return avg;
}
