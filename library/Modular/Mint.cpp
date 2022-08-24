#include <cassert>

constexpr int MOD = 1e9 + 7;

using ll = long long;

// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += MOD;
    }
    if (x >= MOD) {
        x -= MOD;
    }
    return x;
}

struct Mint {

    int x;

    Mint(int x = 0) : x(norm(x)) {}

    int val() const {
        return x;
    }

    Mint operator-() const {
        return Mint(norm(MOD - x));
    }

    Mint inv() const {
        assert(x != 0);
        int p = MOD - 2, a = x, res = 1;
        for (; p > 0; p >>= 1, a = a * (long long) a % MOD)
            if (p & 1) res = res * (long long) a % MOD;
        return res;
    }

    Mint &operator*=(const Mint &rhs) {
        x = ll(x) * rhs.x % MOD;
        return *this;
    }

    Mint &operator+=(const Mint &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }

    Mint &operator-=(const Mint &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }

    Mint &operator/=(const Mint &rhs) {
        return *this *= rhs.inv();
    }

    friend Mint operator*(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }

    friend Mint operator+(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }

    friend Mint operator-(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }

    friend Mint operator/(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
};


Mint power(Mint a, long long b) {
    Mint res = 1;
    for (; b; b >>= 1, a *= a) {
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}

const int maxF = 2.5e5 + 228;

Mint fact[maxF], ifact[maxF], inum[maxF];

int K;

void initF() {
    int n = maxF - 1;
    fact[0] = inum[0] = ifact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    ifact[n] = power(fact[n], MOD - 2);
    inum[n] = ifact[n] * fact[n - 1];
    for (int i = n - 1; i > 0; --i) {
        ifact[i] = ifact[i + 1] * (i + 1);
        inum[i] = ifact[i] * fact[i - 1];
    }
}

Mint C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[n - k] * ifact[k];
}