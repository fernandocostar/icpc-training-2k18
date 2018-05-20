#include <bits/stdc++.h>

using namespace std;
#define MAX 50

int dp[MAX][MAX];

struct pedido{
	int pizzas;
	int min;
};

int main(){
	int n, p;
	cin >> n;
	while(n){
		cin >> p;
		struct pedido pedidos[n+1];
		for(int i = 1; i < n+1; i++){
			scanf("%d %d", &pedidos[i].min, &pedidos[i].pizzas);
		}
		for(int i = 0; i < n+1; i++){
			for(int j = 0; j < p+1; j++){
				if(!i || !j)dp[i][j] = 0;
				else{
					if(pedidos[i].pizzas > j)dp[i][j] = dp[i-1][j];
					else{
						dp[i][j] = max((pedidos[i].min + dp[i-1][j-pedidos[i].pizzas]), dp[i-1][j]);
					}
				}
			}
		}
		cout << dp[n][p] << " min." << endl;
		cin >> n;
	}
	return 0;
}