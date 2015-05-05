#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	ofstream output;
	output.open("input3-2.txt");
	int n = 50000; // generate 50000 numbers as input
	output << n << endl;
	int maximum = pow( 2, 30 );
	for (int i = 0; i < n; i++)
	{
		int x = rand() % (maximum+1);
		output << x << " ";
	}
	output << endl;
	return 0;
}