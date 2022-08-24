//jiangly <3
template<class Info, class Merge = plus<Info>>
struct SegmentTree {
    int sz;
    const Merge merge;
    vector<Info> t;

    SegmentTree(int n) {
        sz = 1;
        while (sz < n) {
            sz <<= 1;
        }
        merge = Merge();
        t.resize(sz << 1);
    }
    SegmentTree(vector<Info> init) : SegmentTree(init.size()) {
        for (int i = 0; i < init.size(); ++i) {
            t[i + sz] = init[i];
        }
        for (int i = sz - 1; i > 0; --i) {
            pull(i);
        }
    }

    SegmentTree() = default;

    void pull(int p) {
        t[p] = merge(t[p << 1], t[p << 1 | 1]);
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            t[p] = v;
            return;
        }
        int m = (l + r) >> 1;
        if (x < m) {
            modify(p << 1, l, m, x, v);
        } else {
            modify(p << 1 | 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, sz, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return t[p];
        }
        int m = (l + r) >> 1;
        return merge(rangeQuery(p << 1, l, m, x, y), rangeQuery(p << 1 | 1, m, r, x, y));
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, sz, l, r);
    }
};

struct Info {
    int sum;
    int mxp, mxs;
    int mnp, mns;

    Info(int x = 0) : sum(x), mxp(std::max(0, x)), mxs(std::max(0, x)), mnp(std::min(0, x)), mns(std::min(0, x)) {}

};

Info operator+(const Info &a, const Info &b) {
    Info res;
    res;
    res.sum = a.sum + b.sum;
    res.mxp = std::max(a.mxp, a.sum + b.mxp);
    res.mxs = std::max(b.mxs, b.sum + a.mxs);
    res.mnp = std::min(a.mnp, a.sum + b.mnp);
    res.mns = std::min(b.mns, b.sum + a.mns);
    return res;
}