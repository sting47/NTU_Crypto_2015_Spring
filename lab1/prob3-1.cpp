#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<int, int> ht;
    ifstream input;
    input.open("input3-1.txt");
    int n;
    input >> n;
    // cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        input >> x;
        // cin >> x;
        ht[x] = i;
    }

    // for(int i=0; i<7; i++)
    // {
    // 	cout << ht[i] << " ";
    // }
    // cout << endl;
    return 0;
}
