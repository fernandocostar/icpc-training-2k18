#include <cstdio>
using namespace std;

int main(){
	int n, ax, ay, bx, by, cx, cy, dx, dy, rx, ry;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d %d %d %d %d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy, &rx, &ry);

		if(rx >= ax && rx <= bx && rx >= dx && rx <= cx && ry >= ay && ry <= dy && ry >= by && ry <= cy){
			printf("1\n");		
		}else{
			printf("0\n");
		}
	}
	return 0;
}