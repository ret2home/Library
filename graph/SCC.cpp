#pragma once
#include "../template/template.cpp"

struct SCC {
    vector<vector<ll>> G, rG;
    vector<bool> used;
    vector<ll> vs;
    void addEdge(ll x, ll y) {
        G[x].push_back(y);
        rG[y].push_back(x);
    }
    void dfs(ll x) {
        used[x] = true;
        for (ll i : G[x])
            if (!used[i]) dfs(i);
        vs.push_back(x);
    }
    vector<ll> cmp;
    void rdfs(ll v, ll k) {
        used[v] = true;
        cmp[v] = k;
        for (ll i : rG[v])
            if (!used[i]) rdfs(i, k);
    }
    void scc() {
        fill(all(used), false);
        rep(i, len(G)) if (!used[i]) dfs(i);
        fill(all(used), false);
        ll k = 0;
        rev(i, len(vs)) if (!used[vs[i]]) rdfs(vs[i], k++);
    }
    SCC(ll N) : G(N), rG(N), used(N), cmp(N) {}
};
