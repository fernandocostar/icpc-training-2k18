#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> flavinho;
    set<int> sorteados;
    set<int> intersecao;

    int tmp;

    for (int i = 0; i < 6; i++) {
        cin >> tmp;
        flavinho.insert(tmp);
    }

    for (int i = 0; i < 6; i++) {
        cin >> tmp;
        sorteados.insert(tmp);
    }

    set_intersection(flavinho.begin(), flavinho.end(), sorteados.begin(), sorteados.end(), inserter(intersecao, intersecao.begin()));

    size_t s = intersecao.size();
    if (s == 3) {
        cout << "terno" << endl;
    } else if (s == 4) {
        cout << "quadra" << endl;
    } else if (s == 5) {
        cout << "quina" << endl;
    } else if (s == 6) {
        cout << "sena" << endl;
    } else {
        cout << "azar" << endl;
    }
    return 0;
}
