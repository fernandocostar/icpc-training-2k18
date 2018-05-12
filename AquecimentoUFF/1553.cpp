#include <bits/stdc++.h>
#define MAX 1010

using namespace std;

int main(){
	int perguntas[MAX];
	int n, k, aux, count;
	cin >> n;
	cin >> k;
	while(n && k){
		memset(perguntas, 0, MAX*sizeof(int));
		count = 0;
		for(int i = 0; i < n; i++){
			cin >> aux;
			perguntas[aux]++;
		}

		for (int i = 0; i < MAX; ++i)
		{
			if(perguntas[i] >= k)count++;
		}
		cout << count<< endl;
		cin >> n;
		cin >> k;
	}
	return 0;
}