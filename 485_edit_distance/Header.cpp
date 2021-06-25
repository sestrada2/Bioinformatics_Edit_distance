#include "Header.h"

//Constructor with cin prompt from user
edit_distance::edit_distance()
{
	cout << "Enter a string: ";
	cin >> first;
	cout << "Enter another string: ";
	cin >> second;
	first = " " + first;
second = " " + second;
row = 0;
column = 0;
}
//Table printing function that calls print header
void edit_distance::printTable()
{
	for (string::iterator a = second.begin(); a != second.end(); a++) {
		if (a == second.begin()) {
			printHeader(first);
		}
		for (string::iterator b = first.begin(); b != first.end(); b++) {
			int tempValue;
			if (b == first.begin()) {
				cout << setw(3) << *a << " " << "|";
			}
			if (row == 0) {
				tempValue = chart[0][column];
			}
			else if (column == 0 && row != 0) {
				tempValue = chart[row][0];
			}
			else if (row != 0 && column != 0) {
				tempValue = fillInNumSpace(*b, *a, chart[row - 1][column - 1], chart[row - 1][column], chart[row][column - 1]);
			}
			cout << setw(3) << tempValue << " ";
			chart[row][column] = tempValue;
			column++;
		}
		cout << "\n";
		row++;
		column = 0;
	}
	cout << "\nThe edit distance is " << chart[second.length() - 1][first.length() - 1] << ".\n";
}
//Header funciton for the table
void edit_distance::printHeader(string tempString)
{
	cout << setw(4) << " ";
	for (string::iterator a = tempString.begin(); a != tempString.end(); a++) {
		cout << setw(3) << *a << " ";
	}
	cout << "\n";
	cout << setw(4) << " ";
	for (string::iterator a = tempString.begin(); a != tempString.end(); a++) {
		cout << "----";
	}
	cout << endl;
}
//Returns min value of the three integers
int edit_distance::min(int a, int b, int c)
{
	if (a < b && a < c) {
		return a;
	}
	if (b < a && b < c) {
		return b;
	}
	else
		return c;
}
//Compares if two chars are the same
int edit_distance::fillInNumSpace(char first, char second, int Tleft, int Tright, int Bleft)
{
	if (first == second) {
		return min(Tleft, Tright, Bleft);
	}
	else {
		return 1 + min(Tleft, Tright, Bleft);
	}
}

//Forming row and column
void edit_distance::addToChart()
{
	for (int i = 0; i < first.length(); i++) {
		chart[0][i] = i;
	}
	for (int i = 0; i < second.length(); i++) {
		chart[i][0] = i;
	}
}
//print distance, main function of project
void edit_distance::printDistance()
{
	int size;
	bool isBigger = false;
	int mark = 1;
	if (first.length() == second.length()) {
		cout << "\nAllignment:\n"<< first << "\n" << second << "\n";
	}
	else if (first.length() > second.length()) {
		size = first.length();
		isBigger = true;
	}
	else {
		size = second.length();
	}
	if (isBigger == true) {
		for (int i = 1; i < size - 1; i++) {
			if (chart[i][i] == 0) {
				mark = i;
			}
			else if (chart[i][i] != 0) {
				if (chart[i][i] == chart[i][i + 1]) {
					mark = i;
					break;
				}
			}
		}
		second.insert(mark, "_");
		cout << "\nAllignment\n" << first << "\n" << second << "\n";
	}
	else {
		for (int i = 1; i < size - 1; i++) {
			if (chart[i][i] == 0) {
				mark = i;
			}
			else if (chart[i][i] != 0) {
				if (chart[i][i] == chart[i + 1][i]) {
					mark = i;
					break;
				}
			}
		}
		first.insert(mark, "_");
		cout << "\nAllignment\n" << first << "\n" << second << "\n";
	}
}
