#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, b;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> b;
		int d_total = 0, g_total = 0;
		int guarte[3];
		memset(guarte, 0, 3*sizeof(int));
		int dabriel[3];
		memset(dabriel, 0, 3*sizeof(int));

		for(int j = 0; j < 3; j++)cin >> dabriel[j];
		for(int j = 0; j < 3; j++)cin >> guarte[j];

		if(!(dabriel[2] % 2))d_total += b;
		if(!(guarte[2] % 2))g_total += b;

		d_total += (dabriel[0] + dabriel[1])/2;
		g_total += (guarte[0] + guarte[1])/2;

		if(d_total > g_total) cout << "Dabriel" << endl;
		else if( g_total > d_total) cout << "Guarte" << endl;
		else cout << "Empate" << endl;

	}
	return 0;
}