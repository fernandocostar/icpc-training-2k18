#include <bits/stdc++.h>

using namespace std;

map<string, int> id_map;
vector<int> graph[200100];
vector<int> transpose_graph[200100];
stack<int> order;

bool visited[200100];

void dfs(int node) {
    visited[node] = true;
    for (const auto& neighbour : graph[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour);
        }
    }
    order.push(node);
}

int dfs_transpose(int node) {
    visited[node] = true;
    for (const auto& neighbour : transpose_graph[node]) {
        if (!visited[neighbour]) {
            return 1 + dfs_transpose(neighbour);
        }
    }
    return 1;
}

int main() {
    int currentId = 0;
    string a, b;
    while (cin >> a >> b) {
        if (id_map.find(a) == id_map.end()) {
            id_map[a] = currentId++;
        }
        if (id_map.find(b) == id_map.end()) {
            id_map[b] = currentId++;
        }

        graph[id_map[a]].push_back(id_map[b]);
        transpose_graph[id_map[b]].push_back(id_map[a]);
    }

    for (int node = 0; node < currentId; node++) {
        if (!visited[node]) {
            dfs(node);
        }
    }

    memset(visited, false, currentId * sizeof(bool));

    int count = 0;
    while (!order.empty()) {
        int node = order.top();
        order.pop();

        if (!visited[node]) {
            int depth = dfs_transpose(node);
            if (depth > 1) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
