#include <bits/stdc++.h>

using namespace std;
int players[105];

int main(){

	int n, m, aux, count = 0;
	cin >> n;
	cin >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> aux;
			if(aux)players[i]++;
		}
	}

	for(int i = 0; i < n; i++){
		if(players[i] == m) count++;
	}

	cout << count << endl;
	return 0;
}