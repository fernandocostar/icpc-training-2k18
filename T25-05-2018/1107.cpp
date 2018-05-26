#include <bits/stdc++.h>

using namespace std;

int resolve(int* esculpida, int c, int a){
	int contagem = 0;
	for(int i = 0; i < c; i++){
		if(esculpida[i] > esculpida[i+1]){
			contagem += esculpida[i] - esculpida[i+1];
		}
	}
	return contagem;
}

int main(){
	int a, c, passadas;
	cin >> a >> c;
	while(a+c){
		int esculpida[c+1];
		passadas = 0;
		esculpida[0] = a;
		for(int i = 1; i <= c; i++){
			cin >> esculpida[i];
		}
		cout << resolve(esculpida, c, a) << endl;
		cin >> a >> c;
	}
	return 0;
}