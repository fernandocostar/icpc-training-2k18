#include <bits/stdc++.h>

using namespace std;

int planos[505][5];

int evaluate(int A, int B, int C, int D, int x, int y, int z){
	return A*x + B*y + C*z == D;
}

int main(){
	int m, n, aux, x, y, z, maximum = -1;
	
	cin >> m >> n;

	for(int i = 0; i < m; i++){
		scanf("%d %d %d %d", &planos[m][0], &planos[m][1], &planos[m][2], &planos[m][3]);
	}

	for(int j = 0; j < n; j++){
		cin >> x >> y >> z;
		for(int i = 0; i < m; i++){
			cout << i << " " << planos[i][4] << endl;
			planos[i][4] += evaluate(planos[i][0], planos[i][1], planos[i][2], planos[i][3], x, y, z);
			maximum = max(maximum, planos[i][4]);
		}
	}

	cout << maximum << endl;

	return 0;
}