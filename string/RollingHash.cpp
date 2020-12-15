#pragma once
#include "../template/template.cpp"

template <class T>
struct RollingHash {
    ll Base = 283;
    const ll MASK30 = (1ll << 30) - 1;
    const ll MASK31 = (1ll << 31) - 1;
    const ll MOD = (1ll << 61) - 1;
    vector<ll> hash, power;
    ll calcmod(ll v) {
        v = (v & MOD) + (v >> 61);
        if (v > MOD) v -= MOD;
        return v;
    }
    ll mul(ll x, ll y) {
        ll xu = x >> 31, xd = x & MASK31;
        ll yu = y >> 31, yd = y & MASK31;
        ll mid = xd * yu + xu * yd, midu = mid >> 30, midd = mid & MASK30;
        return calcmod(xu * yu * 2 + midu + (midd << 31) + xd * yd);
    }
    RollingHash(T s) {
        ll sz = s.size();
        hash.resize(sz + 1, 0);
        power.resize(sz + 1, 1);
        rep(i, sz) {
            hash[i + 1] = calcmod(mul(hash[i], Base) + s[i]);
            power[i + 1] = calcmod(mul(power[i], Base));
        }
    }
    ll get(ll l, ll r) {
        return calcmod(hash[r] - mul(hash[l], power[r - l]) + MOD);
    }
    ll lcp(ll x, ll y) {
        ll len = min(hash.size() - 1 - y, hash.size() - 1 - x);
        ll ok = 0, ng = len + 1;
        while (ng - ok > 1) {
            ll mid = (ok + ng) / 2;
            if (get(x, x + mid) == get(y, y + mid))
                ok = mid;
            else
                ng = mid;
        }
        return ok;
    }
};
/*
@brief Rolling Hash (mod 2^61-1)
@docs docs/RollingHash.md
*/