#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fast_exp(ll x, ll y, ll m) {
    ll ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % m;
        y >>= 1;
        x = (x * x) % m;
    }
    return ret;
}

int mod_inverse(int a, int m) {
    if (m == 1) return 0;

    int m0 = m;
    int y = 0, x = 1;
    
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    
    if (x < 0) x += m0;
    
    return x;
}

int N, E, C;
vector<int> primes;
bool sieve[32000];

void compute_primes() {
    for (int p = 2; p * p <= N; p++) {
        if (!sieve[p]) {
            primes.push_back(p);
            for (int i = p * 2; i * i < N; i += p) {
                sieve[i] = true;
            }
        }
    }
}

int main() {
    cin >> N >> E >> C;
    compute_primes();
    
    int phi;
    for (int p : primes) {
        if (p > 2 && N % p == 0) {
            phi = (p - 1) * (N / p - 1);
            break;
        }
    }
    
    cout << fast_exp(C, mod_inverse(E, phi), N) << endl;
    return 0;
}
