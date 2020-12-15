#pragma once
#include "../template/template.cpp"

template <class T>
class BIT {
    ll N;
    vector<T> bit;
    void add_(ll x, T y) {
        while (x <= N) {
            bit[x] += y;
            x += x & -x;
        }
    }
    T sum_(ll x) {
        T res = 0;
        while (x > 0) {
            res += bit[x];
            x -= x & -x;
        }
        return res;
    }

   public:
    ll lower_bound(T w) {
        if (w <= 0) return -1;
        ll x = 0;
        ll k = 1;
        while (k * 2 <= N) k *= 2;
        for (; k > 0; k /= 2) {
            if (x + k <= N && bit[x + k] < w) {
                w -= bit[x + k];
                x += k;
            }
        }
        return x;
    }
    void add(ll x, T y) { add_(x + 1, y); }
    T sum(ll l, ll r) { return sum_(r) - sum_(l); }
    BIT(ll x) : N(x), bit(x + 1) {}
};
/*
@brief Binary Indexed Tree
@docs docs/BIT.md
*/