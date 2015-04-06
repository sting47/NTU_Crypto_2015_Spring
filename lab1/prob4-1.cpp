#include <iostream>
#include <string>
using namespace std;

#include "password.h" // string password = ...

bool check(const string &s) {
    if (s.size() != password.size()) return false;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != password[i]) return false;
    }
    return true;
}

int main() {
    cout << "Enter the top serect of CNS!" << endl;
    cout << "----------------------------" << endl;
    cout << "\nPassword: ";
    cout.flush();
    string s;
    cin >> s;
    if (check(s)) cout << "Good password" << endl;
    else cout << "Bad password" << endl;
    return 0;
}
