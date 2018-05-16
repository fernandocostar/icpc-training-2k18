#include <bits/stdc++.h>

using namespace std;

int main() {
    char search = getchar();
    getchar();

    int words = 0;
    int count = 0;
    bool found = false;

    char c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            found = false;
            words++;
        } else if (!found && c == search) {
            found = true;
            count++;
        }
    }

    words++;

    printf("%.1f\n", (double) count / words * 100.0);
    
    return 0;
}
