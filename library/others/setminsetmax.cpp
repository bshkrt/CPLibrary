template<typename T>
bool ckmin(T &a, T b) { return (b < a) ? a = b, 1 : 0; }

template<typename T>
bool ckmax(T &a, T b) { return (b > a) ? a = b, 1 : 0; }