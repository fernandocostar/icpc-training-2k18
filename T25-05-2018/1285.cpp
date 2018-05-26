#include <bits/stdc++.h>

using namespace std;

int digs[10];

int solveUtil(int n){
	int d;
	memset(digs, 0, 10 * sizeof(int));
	while(n){
		d = n%10;
		digs[d]++;
		if(digs[d] == 2) return 0;
		n = n/10;
	}
	return 1;
}

int solve(int n, int m){
	int count = 0;
	for(int i = n; i <= m; i++){
		count += solveUtil(i);
	}
	return count;
}

int main(){
	int n, m;
	while(cin >> n >> m){
		cout << solve(n, m) << endl;
	}
	return 0;
}