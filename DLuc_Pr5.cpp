/* 
Class: CMSC140 CRN 20433
Project 5
Instructor : Dr.Grinberg
Summary of Description : This program checks to see if a grid of 9 numbers meets the requirements to be a magic square.
Due Date : 12 / 06 / 21
Integrity Pledge : I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here : Derik Luc
*/


#include <iostream>
using namespace std;

// Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int ARRAY_SIZE = 3; // Size of each array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

string name = "Derik Luc";
const int ASSIGN_NUM = 5;
const string DUE_DATE = "12/6/21";

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size); 
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max); 
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size); 
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size); 
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size); 
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size); 
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size); 

int main()
{

	/* Define a Lo Shu Magic Square using 3 parallel arrays corresponding to each row of the grid */
	int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
	// Your code goes here
	fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, ARRAY_SIZE);
	showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, ARRAY_SIZE);

	if (isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, ARRAY_SIZE)) {
		cout << "This is a magic square!" << endl << endl;
	}else{
		cout << "This is NOT a magic square!" << endl << endl;
	}

	cout << "Thank you for testing my program!!\n";
	cout << "PROGRAMMER: " << name << "\n";
	cout << "CMSC140 Common Project " << ASSIGN_NUM << "\n";
	cout << "Due Date: " << DUE_DATE;

	return 0;
}
// Function definitions go here

void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	cout << "Please hit enter after typing each number." << endl;
	cout << "Enter first row of numbers: \n";
	cin >> arrayRow1[0] >> arrayRow1[1] >> arrayRow1[2];
	cout << "Enter second row of numbers: \n";
	cin >> arrayRow2[0] >> arrayRow2[1] >> arrayRow2[2];
	cout << "Enter third row of numbers: \n";
	cin >> arrayRow3[0] >> arrayRow3[1] >> arrayRow3[2];
	cout << endl;
}

// Displays the numbers in a 3 x 3 grid
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arrayRow1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << arrayRow2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << arrayRow3[i] << " ";
	}
	cout << endl << endl;
}

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {

	checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX);
	checkUnique(arrayRow1, arrayRow2, arrayRow3, size);
	checkRowSum(arrayRow1, arrayRow2, arrayRow3, size);
	checkColSum(arrayRow1, arrayRow2, arrayRow3, size);
	checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size);

	if (checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX) && checkUnique(arrayRow1, arrayRow2, arrayRow3, size) && checkRowSum(arrayRow1, arrayRow2, arrayRow3, size) && checkColSum(arrayRow1, arrayRow2, arrayRow3, size) && checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size)){
		return true;
	}else{
		return false;
	}
}

bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max) {
	for(int i = 0; i < size; i++){
		if (arrayRow1[i] < min || arrayRow1[i] > max || arrayRow2[i] < min || arrayRow2[i] > max || arrayRow3[i] < min || arrayRow3[i] > max){
			return false;
		}
	}
	return true;
}

bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	// Checking for number 1
	if (arrayRow1[0] == arrayRow1[1] || arrayRow1[0] == arrayRow1[2]) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (arrayRow1[0] == arrayRow2[i]) {
			return false;
		}
		if (arrayRow1[0] == arrayRow3[i]) {
			return false;
		}
	}
	// Checking for number 2
	if (arrayRow1[1] == arrayRow1[2]) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (arrayRow1[1] == arrayRow2[i]) {
			return false;
		}
		if (arrayRow1[1] == arrayRow3[i]) {
			return false;
		}
	}
	// Checking for number 3
	for (int i = 0; i < size; i++) {
		if (arrayRow1[2] == arrayRow2[i]) {
			return false;
		}
		if (arrayRow1[2] == arrayRow3[i]) {
			return false;
		}
	}
	// Checking for number 4
	if (arrayRow2[0] == arrayRow2[1] || arrayRow2[0] == arrayRow2[2]) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (arrayRow2[0] == arrayRow3[i]) {
			return false;
		}
	}
	// Checking for number 5
	if (arrayRow2[1] == arrayRow2[2]) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (arrayRow2[1] == arrayRow3[i]) {
			return false;
		}
	}
	// Checking for number 6
	for (int i = 0; i < size; i++) {
		if (arrayRow2[2] == arrayRow3[i]) {
			return false;
		}
	}
	// Checking for number 7
	if (arrayRow3[0] == arrayRow3[1] || arrayRow3[0] == arrayRow3[2]) {
		return false;
	}
	// Checking for number 8
	if (arrayRow3[1] == arrayRow3[2]) {
		return false;
	}

	return true;
}

// Finds the sum of each row and compares them.
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	int sum1 = 0, sum2 = 0, sum3 = 0;
	
	for (int i = 0; i < size; i++) {
		sum1 += arrayRow1[i];
	}
	for (int i = 0; i < size; i++) {
		sum2 += arrayRow2[i];
	}
	for (int i = 0; i < size; i++) {
		sum3 += arrayRow3[i];
	}

	if (sum1 != sum2 || sum2 != sum3 || sum1 != sum3) {
		return false;
	}
	else {
		return true;
	}
}

bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	int colSum[ROWS] = { 0, 0, 0 };

	for (int i = 0; i < size; i++) {
		colSum[i] = arrayRow1[i] + arrayRow2[i] + arrayRow3[i];
	}

	if (colSum[0] != colSum[1] || colSum[1] != colSum[2] || colSum[0] != colSum[2]) {
		return false;
	}else{
		return true;
	}
}

bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	int diagSum1, diagSum2;

	diagSum1 = arrayRow1[0] + arrayRow2[1] + arrayRow3[2];
	diagSum2 = arrayRow1[2] + arrayRow2[1] + arrayRow3[0];

	if (diagSum1 != diagSum2) {
		return false;
	}else{
		return true;
	}
}