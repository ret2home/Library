#pragma once
#include "../template/template.cpp"

struct PartialPersistentUnionFind {
    ll version = 0;
    vector<ll> tim, par;
    vector<vector<P>> siz;
    ll find(ll x, ll t) {
        if (tim[x] > t) return x;
        return find(par[x], t);
    }
    ll same(ll x, ll y, ll t) {
        return find(x, t) == find(y, t);
    }
    ll size(ll x, ll t) {
        x = find(x, t);
        return (--upper_bound(all(siz[x]), P(t, inf)))->second;
    }
    void merge(ll x, ll y) {
        version++;
        x = find(x, version);
        y = find(y, version);
        if (x == y) return;
        ll sx = size(x, version), sy = size(y, version);
        if (sx > sy) swap(x, y);
        tim[x] = version;
        par[x] = y;
        siz[y].push_back({version, sx + sy});
    }
    PartialPersistentUnionFind(ll x) : tim(x, inf) {
        siz.resize(x);
        rep(i, x) {
            par.push_back(i);
            siz[i].push_back(P(0, 1));
        }
    }
};
