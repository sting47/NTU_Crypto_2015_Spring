#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

std::vector<int> pos; // store the positive exponential value of finite field
std::vector<int> binv; // store b*a^(-k), b*a^(-2k)..., b*a^(-rk) rk>p, but store 

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

void construct_pos(long long int p, long long int g, long long int k) // calculate g^1, g^2...g^k and store in pos
{
	pos.clear();
	long long int tmp = 1;
	pos.push_back(1);
	for(long long int i=pos.size()+1; i<=k+1; i++)
	{
		tmp = tmp * g;
		if (tmp >= p) tmp = tmp % p;
		pos.push_back(tmp);
	}
}

long long int inverse(long long int p, long long int g, long long int k) // calculate the inverse of g^(-k) in finite field
{
	long long int gi = pos[k];
	long long int tmp = 1;
	double result;
	while(1)
	{
		result = (double)tmp / (double)gi;
		if(result == (long long int)result) return (long long int)result;
		tmp = tmp + p;
	}
}

void construct_binv(long long int p, long long int g, long long int x, long long int k) // calculate construct_binv until rk>p
{
	binv.clear();
	long long int r = 1;
	long long int tmp = x;
	long long int ginvk = inverse(p, g, k);
	while(r*k <= p)
	{
		tmp = tmp * ginvk;
		if (tmp >= p) tmp = tmp % p;
		binv.push_back(tmp);
		r++;
	}
}

long long int BabyGiant(long long int p, long long int g, long long int x) // find a, given g, p, x, to be g^a % p = x using Baby step, Giant step
{
	int k = 1;
	// int counter = 1;
	while(1)
	{
		// int k = rand() % p; // randomly pick a number < p to be k
		// k++;
		// cout << "now k = " << k << endl;
		construct_pos(p, g, k);
		construct_binv(p, g, x, k);
		for(long long int i=0; i<binv.size(); i++)
		{
			for(long long int j=1; j<pos.size(); j++)
			{
				if( binv[i] == pos[j] )
				{
					// cout << "trying time : " << counter << endl;
					return ( (i+1)*k+j ) % (p-1);
				}
			}
		}
		k++;
		// counter++;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	ifstream input;
	input.open("prob2-2.csv");
	// ofstream output;
	// output.open("ans2-1.csv")

	long long int p, g, x;
	string str;
	getline(input, str); // first line of input
	while ( !input.eof() )
	{
		getline(input, str);
		if (str.size() == 0) break;
		std::vector<string> result; // store the temp result of split
		result = split(str.c_str(), ',');
		p = stol(result[0]);
		g = stol(result[1]);
		x = stol(result[2]);
		cout << p << " " << g << " " << x << " " << BabyGiant(p, g, x) << endl;
	}

	// construct_pos(59, 3, 5);
	// construct_binv(59, 3, 19, 5);
	// cout << binv[2] << endl;

	input.close();

	return 0;
}