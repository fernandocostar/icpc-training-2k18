#include <bits/stdc++.h>

using namespace std;

uint8_t board[250100];
uint8_t visited[250100];

int N;

//                          >       <           V       A
pair<int, int> movement[] { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int dfs(int x, int y) {
    visited[y * N + x] = 1;
    int dx, dy;
    tie(dx, dy) = movement[board[y * N + x]];
    
    int nx = x + dx, ny = y + dy;
    if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
        visited[y * N + x] = 2;
        return -1;
    }

    if (!visited[ny * N + nx]) {
        int depth = dfs(nx, ny);
        if (depth != -1) {
            depth++;
        } else {
            visited[y * N + x] = 2;
        }
        return depth;
    } else if (visited[ny * N + nx] == 2) {
        visited[y * N + x] = 2;
        return -1;
    }

    return 1;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        int x = 0;
        
        for (char c : line) {
            int move;

            if (c == '>') {
                move = 0;
            } else if (c == '<') {
                move = 1;
            } else if (c == 'V') {
                move = 2;
            } else if (c == 'A') {
                move = 3;
            } else {
                cout << "WTF" << endl;
            }

            board[i*N + x++] = move;
        }
    }

    int total = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!visited[y * N + x]) {
                int depth = dfs(x, y);
                if (depth != -1) {
                    total += depth;
                }
            }
        }
    }

    cout << total << endl;
    return 0;
}
