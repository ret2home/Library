#pragma once
#include "../template/template.cpp"

struct PrimalDual {
    struct edge {
        ll to, cap, cost, rev;
    };
    vector<vector<edge>> graph;
    bool negative = false;
    void add_edge(ll from, ll to, ll cap, ll cost) {
        graph[from].push_back({to, cap, cost, len(graph[to])});
        graph[to].push_back({from, 0ll, -cost, len(graph[from]) - 1});
        if (cost < 0) negative = true;
    }
    ll minCostFlow(ll s, ll t, ll f) {
        ll V = len(graph);
        vector<ll> potential(V), minCost, prevv(V, -1), preve(V, -1);
        ll res = 0;
        if (negative) {
            minCost.assign(V, inf);
            minCost[s] = 0;
            rep(_, V - 1) {
                rep(i, V) {
                    rep(j, len(graph[i])) {
                        edge &e = graph[i][j];
                        if (e.cap > 0 && chmin(minCost[e.to], minCost[i] + e.cost + potential[i] - potential[e.to])) {
                            prevv[e.to] = i;
                            preve[e.to] = j;
                        }
                    }
                }
            }
            if (minCost[t] == inf) return -1;
            rep(i, V) potential[i] += minCost[i];
            for (ll i = t; i != s; i = prevv[i]) {
                graph[prevv[i]][preve[i]].cap--;
                graph[i][graph[prevv[i]][preve[i]].rev].cap++;
            }
            res += potential[t];
            f--;
        }

        while (f > 0) {
            minCost.assign(V, inf);
            minCost[s] = 0;
            priority_queue<PL, vector<PL>, greater<>> que;
            que.push({0, s});
            while (!que.empty()) {
                PL p = que.top();
                que.pop();
                if (minCost[p.second] < p.first) continue;
                rep(i, len(graph[p.second])) {
                    edge &e = graph[p.second][i];
                    if (e.cap > 0 && chmin(minCost[e.to], p.first + e.cost + potential[p.second] - potential[e.to])) {
                        prevv[e.to] = p.second;
                        preve[e.to] = i;
                        que.push({minCost[e.to], e.to});
                    }
                }
            }

            if (minCost[t] == inf) return -1;
            rep(i, V) potential[i] += minCost[i];
            ll addflow = f;
            for (ll i = t; i != s; i = prevv[i]) chmin(addflow, graph[prevv[i]][preve[i]].cap);
            f -= addflow;
            res += addflow * potential[t];
            for (ll i = t; i != s; i = prevv[i]) {
                edge &e = graph[prevv[i]][preve[i]];
                e.cap -= addflow;
                graph[i][e.rev].cap += addflow;
            }
        }
        return res;
    }
    PrimalDual(ll V) : graph(V){};
};
/*
@brief Min Cost Flow (Primal Dual)
@docs docs/MinCostFlow.md
*/