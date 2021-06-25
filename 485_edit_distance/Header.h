#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class edit_distance {
public:
	edit_distance();
	void printTable();
	void printHeader(string tempString);
	int min(int a, int b, int c);
	int fillInNumSpace(char first, char second, int Tleft, int Tright, int Bleft);
	void addToChart();
	void printDistance();

private:
	string first;
	string second;
	int chart[50][50];
	int row;
	int column;
};


