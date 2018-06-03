#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long dp[51][100010];

long long sum(long long a, long long b){
	a += b;
	if(a < mod) return a;
	return a % mod;
}

long long solve(int dif, int min, int stage){
	if(!min) return stage >= 0 && stage <= dif;
	if(stage < 0 || stage > dif) return 0;
	if(dp[min][stage] != -1) return dp[min][stage];
	long long left = solve(dif, min-1, stage-1);
	dp[min][stage] = sum(left, solve(dif, min-1, stage+1));
	return dp[min][stage];
}

int main(){
	int dif, t, n, m;
	cin >> t >> n >> m;
	dif = m-n;
	long long result = 0;
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < dif+1; i++){
		result = sum(result, solve(dif, t-1, i));
	}

	cout << result << endl;
	return 0;
}