//thanks, ormlis!
constexpr int MOD = 998244353; //1e9 + 9;

int norm(int x) {
    if (x < 0) {
        x += MOD;
    }
    if (x >= MOD) {
        x -= MOD;
    }
    return x;
}

int add(const int a, const int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(const int a, const int b) {
    return a - b < 0 ? a - b + MOD : a - b;
}

int mul(const int a, const int b) {
    return (1ll * a * b) % MOD;
}

int power(int a, int b) {
    int r = 1;
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) r = mul(r, a);
    return r;
}

int rev(int a) {
    return power(a, MOD - 2);
}

const int maxF = 4e5 + 5;
int fact[maxF];
int rfact[maxF];

void initF() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}