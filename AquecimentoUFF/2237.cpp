#include <bits/stdc++.h>
using namespace std;

struct State {
    uint64_t weigth = 0;
    array<int, 8> data;
    friend bool operator<(const State& lhs, const State& rhs);
    friend bool operator>(const State& lhs, const State& rhs);
    friend bool operator==(const State& lhs, const State& rhs);

    struct CompareData {
        bool operator()(const State& lhs, const State& rhs) const {
            return lhs.data < rhs.data;
        }
    };
};

bool operator<(const State& lhs, const State& rhs) {
    return lhs.weigth < rhs.weigth;
}

bool operator>(const State& lhs, const State& rhs) {
    return lhs.weigth > rhs.weigth;
}

bool operator==(const State& lhs, const State& rhs) {
    return lhs.data == rhs.data;
}

State startstate;
State finalstate;
vector<pair<int, int>> moves {{0, 1}, {2, 3}, {4, 5}, {6, 7}, {1, 2}, {5, 6}, {0, 4}, {1, 5}, {2, 6}, {3, 7}};

set<State, State::CompareData> p;
priority_queue<State, std::vector<State>, std::greater<State>> q;

int solve(const State& start) {
    q.push(start);
    while (!q.empty()) {
        State curstate = q.top();
        if (curstate == finalstate) {
            return curstate.weigth;
        }
        q.pop();
        if (p.insert(curstate).second) {
            for (const auto& m : moves) {
                State nextstate = curstate;
                nextstate.weigth += curstate.data[m.first] + curstate.data[m.second];
                nextstate.data[m.first] = curstate.data[m.second];
                nextstate.data[m.second] = curstate.data[m.first];
                q.push(nextstate);
            }
        }
    }
    return INT_MAX; // Should never get to here.
}

int main() {
    int tmp;

    for (int i = 0; i < 8; i++) {
        cin >> tmp;
        startstate.data[i] = tmp;
    }
    for (int i = 0; i < 8; i++) {
        cin >> tmp;
        finalstate.data[i] = tmp;
    }
    cout << solve(startstate) << endl;
    return 0;
}
