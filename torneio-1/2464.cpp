#include <bits/stdc++.h>

using namespace std;


int main() {
    map<char, char> m;
    string alfabeto, sentenca;
    cin >> alfabeto >> sentenca;

    char current = 'a';
    for (char c : alfabeto) {
        m[c] = current++;
    }

    for (char& c : sentenca) {
        c = m[c];
    }

    cout << sentenca << endl;
    return 0;
}
