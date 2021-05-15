#pragma once
#include "../template/template.cpp"

template <typename Monoid,
          typename OperatorMonoid,
          Monoid (*f)(Monoid, Monoid, int),
          Monoid (*g)(Monoid, OperatorMonoid, int),
          OperatorMonoid (*h)(OperatorMonoid, OperatorMonoid, int)>
struct Segtree {
    int size = 1;

   private:
    vector<Monoid> dat;
    vector<OperatorMonoid> lazy;
    Monoid M;
    OperatorMonoid OM;

   public:
    void eval(int k, int l, int r) {
        if (lazy[k] != OM) {
            dat[k] = g(dat[k], lazy[k], r - l);
            if (r - l > 1) {
                lazy[(k << 1) + 1] = h(lazy[(k << 1) + 1], lazy[k], r - l);
                lazy[(k << 1) + 2] = h(lazy[(k << 1) + 2], lazy[k], r - l);
            }
            lazy[k] = OM;
        }
    }
    void update(int a, int b, OperatorMonoid M, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = size;
        eval(k, l, r);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = h(lazy[k], M, r - l);
            eval(k, l, r);
            return;
        }
        update(a, b, M, (k << 1) + 1, l, (l + r) >> 1);
        update(a, b, M, (k << 1) + 2, (l + r) >> 1, r);
        dat[k] = f(dat[(k << 1) + 1], dat[(k << 1) + 2], r - l);
    }
    Monoid query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = size;
        eval(k, l, r);
        if (r <= a || b <= l) return M;
        if (a <= l && r <= b) return dat[k];
        Monoid lv = query(a, b, (k << 1) + 1, l, (l + r) >> 1);
        Monoid rv = query(a, b, (k << 1) + 2, (l + r) >> 1, r);
        return f(lv, rv, r - l);
    }
    template <class C>
    int minLeft(int a, int b, C &check, Monoid x, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = size;
        eval(k, l, r);
        if (r <= a || b <= l || !check(dat[k], x)) return -1;
        if (r - l == 1) return l;
        int lv = minLeft(a, b, check, x, (k << 1) + 1, l, (l + r) >> 1);
        if (lv != -1) return lv;
        return minLeft(a, b, check, x, (k << 1) + 2, (l + r) >> 1, r);
    }
    template <class C>
    int maxRight(int a, int b, C &check, Monoid x, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = size;
        eval(k, l, r);
        if (r <= a || b <= l || !check(dat[k], x)) return -1;
        if (r - l == 1) return l;
        int rv = maxRight(a, b, check, x, (k << 1) + 2, (l + r) >> 1, r);
        if (rv != -1) return rv;
        return maxRight(a, b, check, x, (k << 1) + 1, l, (l + r) >> 1);
    }
    void set(int a, Monoid x) {
        dat[a + size - 1] = x;
    }
    void init(int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = size;
        if (r - l == 1) return;
        init((k << 1) + 1, l, (l + r) >> 1);
        init((k << 1) + 2, (l + r) >> 1, r);
        dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2], r - l);
    }
    Segtree(int x, Monoid M, OperatorMonoid OM)
        : M(M), OM(OM) {
        while (size < x) size <<= 1;
        dat.resize((size << 1) - 1, M);
        lazy.resize((size << 1) - 1, OM);
    }
};

/*
@brief Lazy Segment Tree
@docs docs/SegmentTree.md
*/