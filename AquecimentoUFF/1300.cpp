#include <bits/stdc++.h>
#define MAX 361

using namespace std;

int main(){
		int possible[MAX];
		memset(possible, 0 , MAX*sizeof(int));

		//calc possible
		int horas = 0, minutos = 0;
		while(horas != 360){
			minutos += 6;
			if(!(minutos % 72)) horas += 6;
			possible[abs(minutos - horas)] = 1;
			minutos %= 360;
		}

		int n;
		while(cin >> n){
			if(possible[n]) cout << "Y" << endl;
			else cout << "N" << endl;
		}

	return 0;
}