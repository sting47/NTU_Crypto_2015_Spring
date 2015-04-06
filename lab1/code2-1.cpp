#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> split(const char *str, char c = ' ') // function for spliting the data into three constant
{
    vector<string> result;

    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        result.push_back(string(begin, str));
    } while (0 != *str++);

    return result;
}

long long int bruteforce(long long int g, long long int p, long long int x) // find a, given g, p, x, to be g^a % p = x
{
	long long int a = 0;
	long long int tmp = 1; // store g^a of every iteration
	if (tmp == x) return a;
	while (tmp != x)
	{
		tmp = tmp * g;
		if (tmp >= p) tmp = tmp % p;
		a++;
	}
	return a-1;
}

int main (int argc, char const *argv[])
{
	ifstream input;
	input.open("prob2-1.csv");
	ofstream output;
	output.open("ans2-1.csv");

	long long int p, g, x;
	string str;
	getline(input, str); // first line of input
	output << str << endl;
	while ( !input.eof() )
	{
		getline(input, str);
		if (str.size() == 0) break;
		std::vector<string> result; // store the temp result of split
		result = split(str.c_str(), ',');
		p = stol(result[0]);
		g = stol(result[1]);
		x = stol(result[2]);
		output << p << "," << g << "," << x << "," << bruteforce(g, p, x) << endl;
	}

	input.close();
	output.close();

	return 0;
}