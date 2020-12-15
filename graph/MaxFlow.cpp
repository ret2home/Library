#pragma once
#include "../template/template.cpp"

struct Dinic {
    struct Edge {
        ll to, cap, rev;
    };
    vector<vector<Edge>> G;
    vector<ll> level, iter;
    void addEdge(ll from, ll to, ll cap) {
        G[from].push_back({to, cap, len(G[to])});
        G[to].push_back({from, 0, len(G[from]) - 1});
    }
    void bfs(ll s) {
        fill(all(level), -1);
        level[s] = 0;
        queue<ll> que;
        que.push(s);
        while (len(que)) {
            ll p = que.front();
            que.pop();
            for (Edge e : G[p]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[p] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    ll dfs(ll v, ll t, ll f) {
        if (v == t) return f;
        for (ll &i = iter[v]; i < len(G[v]); i++) {
            Edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] > level[v]) {
                ll d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    ll maxFlow(ll s, ll t) {
        ll flow = 0;
        while (1) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(all(iter), 0);
            ll f = 0;
            while ((f = dfs(s, t, inf)) > 0) {
                flow += f;
            }
        }
    }
    Dinic(ll N) : G(N), level(N), iter(N) {}
};
/*
@brief Max Flow (Dinic)
@docs docs/MaxFlow.md
*/