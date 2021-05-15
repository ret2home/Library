---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/MinCostFlow.test.cpp
    title: test/MinCostFlow.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/MinCostFlow.md
    document_title: Min Cost Flow (Primal Dual)
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i <\
    \ n; i++)\n#define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n\
    #define all(v) v.begin(), v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,int>\n\
    #define len(s) (int)s.size()\n\ntemplate <class T, class U>\ninline bool chmin(T\
    \ &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T &a, U\
    \ b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"graph/MinCostFlow.cpp\"\n\nstruct\
    \ PrimalDual {\n    struct edge {\n        ll to, cap, cost, rev;\n    };\n  \
    \  vector<vector<edge>> graph;\n    bool negative = false;\n    void add_edge(ll\
    \ from, ll to, ll cap, ll cost) {\n        graph[from].push_back({to, cap, cost,\
    \ len(graph[to])});\n        graph[to].push_back({from, 0ll, -cost, len(graph[from])\
    \ - 1});\n        if (cost < 0) negative = true;\n    }\n    ll minCostFlow(ll\
    \ s, ll t, ll f) {\n        ll V = len(graph);\n        vector<ll> potential(V),\
    \ minCost, prevv(V, -1), preve(V, -1);\n        ll res = 0;\n        if (negative)\
    \ {\n            minCost.assign(V, inf);\n            minCost[s] = 0;\n      \
    \      rep(_, V - 1) {\n                rep(i, V) {\n                    rep(j,\
    \ len(graph[i])) {\n                        edge &e = graph[i][j];\n         \
    \               if (e.cap > 0 && chmin(minCost[e.to], minCost[i] + e.cost + potential[i]\
    \ - potential[e.to])) {\n                            prevv[e.to] = i;\n      \
    \                      preve[e.to] = j;\n                        }\n         \
    \           }\n                }\n            }\n            if (minCost[t] ==\
    \ inf) return -1;\n            rep(i, V) potential[i] += minCost[i];\n       \
    \     for (ll i = t; i != s; i = prevv[i]) {\n                graph[prevv[i]][preve[i]].cap--;\n\
    \                graph[i][graph[prevv[i]][preve[i]].rev].cap++;\n            }\n\
    \            res += potential[t];\n            f--;\n        }\n\n        while\
    \ (f > 0) {\n            minCost.assign(V, inf);\n            minCost[s] = 0;\n\
    \            priority_queue<PL, vector<PL>, greater<>> que;\n            que.push({0,\
    \ s});\n            while (!que.empty()) {\n                PL p = que.top();\n\
    \                que.pop();\n                if (minCost[p.second] < p.first)\
    \ continue;\n                rep(i, len(graph[p.second])) {\n                \
    \    edge &e = graph[p.second][i];\n                    if (e.cap > 0 && chmin(minCost[e.to],\
    \ p.first + e.cost + potential[p.second] - potential[e.to])) {\n             \
    \           prevv[e.to] = p.second;\n                        preve[e.to] = i;\n\
    \                        que.push({minCost[e.to], e.to});\n                  \
    \  }\n                }\n            }\n\n            if (minCost[t] == inf) return\
    \ -1;\n            rep(i, V) potential[i] += minCost[i];\n            ll addflow\
    \ = f;\n            for (ll i = t; i != s; i = prevv[i]) chmin(addflow, graph[prevv[i]][preve[i]].cap);\n\
    \            f -= addflow;\n            res += addflow * potential[t];\n     \
    \       for (ll i = t; i != s; i = prevv[i]) {\n                edge &e = graph[prevv[i]][preve[i]];\n\
    \                e.cap -= addflow;\n                graph[i][e.rev].cap += addflow;\n\
    \            }\n        }\n        return res;\n    }\n    PrimalDual(ll V) :\
    \ graph(V){};\n};\n/*\n@brief Min Cost Flow (Primal Dual)\n@docs docs/MinCostFlow.md\n\
    */\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct PrimalDual\
    \ {\n    struct edge {\n        ll to, cap, cost, rev;\n    };\n    vector<vector<edge>>\
    \ graph;\n    bool negative = false;\n    void add_edge(ll from, ll to, ll cap,\
    \ ll cost) {\n        graph[from].push_back({to, cap, cost, len(graph[to])});\n\
    \        graph[to].push_back({from, 0ll, -cost, len(graph[from]) - 1});\n    \
    \    if (cost < 0) negative = true;\n    }\n    ll minCostFlow(ll s, ll t, ll\
    \ f) {\n        ll V = len(graph);\n        vector<ll> potential(V), minCost,\
    \ prevv(V, -1), preve(V, -1);\n        ll res = 0;\n        if (negative) {\n\
    \            minCost.assign(V, inf);\n            minCost[s] = 0;\n          \
    \  rep(_, V - 1) {\n                rep(i, V) {\n                    rep(j, len(graph[i]))\
    \ {\n                        edge &e = graph[i][j];\n                        if\
    \ (e.cap > 0 && chmin(minCost[e.to], minCost[i] + e.cost + potential[i] - potential[e.to]))\
    \ {\n                            prevv[e.to] = i;\n                          \
    \  preve[e.to] = j;\n                        }\n                    }\n      \
    \          }\n            }\n            if (minCost[t] == inf) return -1;\n \
    \           rep(i, V) potential[i] += minCost[i];\n            for (ll i = t;\
    \ i != s; i = prevv[i]) {\n                graph[prevv[i]][preve[i]].cap--;\n\
    \                graph[i][graph[prevv[i]][preve[i]].rev].cap++;\n            }\n\
    \            res += potential[t];\n            f--;\n        }\n\n        while\
    \ (f > 0) {\n            minCost.assign(V, inf);\n            minCost[s] = 0;\n\
    \            priority_queue<PL, vector<PL>, greater<>> que;\n            que.push({0,\
    \ s});\n            while (!que.empty()) {\n                PL p = que.top();\n\
    \                que.pop();\n                if (minCost[p.second] < p.first)\
    \ continue;\n                rep(i, len(graph[p.second])) {\n                \
    \    edge &e = graph[p.second][i];\n                    if (e.cap > 0 && chmin(minCost[e.to],\
    \ p.first + e.cost + potential[p.second] - potential[e.to])) {\n             \
    \           prevv[e.to] = p.second;\n                        preve[e.to] = i;\n\
    \                        que.push({minCost[e.to], e.to});\n                  \
    \  }\n                }\n            }\n\n            if (minCost[t] == inf) return\
    \ -1;\n            rep(i, V) potential[i] += minCost[i];\n            ll addflow\
    \ = f;\n            for (ll i = t; i != s; i = prevv[i]) chmin(addflow, graph[prevv[i]][preve[i]].cap);\n\
    \            f -= addflow;\n            res += addflow * potential[t];\n     \
    \       for (ll i = t; i != s; i = prevv[i]) {\n                edge &e = graph[prevv[i]][preve[i]];\n\
    \                e.cap -= addflow;\n                graph[i][e.rev].cap += addflow;\n\
    \            }\n        }\n        return res;\n    }\n    PrimalDual(ll V) :\
    \ graph(V){};\n};\n/*\n@brief Min Cost Flow (Primal Dual)\n@docs docs/MinCostFlow.md\n\
    */"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: graph/MinCostFlow.cpp
  requiredBy: []
  timestamp: '2021-05-15 13:43:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/MinCostFlow.test.cpp
documentation_of: graph/MinCostFlow.cpp
layout: document
redirect_from:
- /library/graph/MinCostFlow.cpp
- /library/graph/MinCostFlow.cpp.html
title: Min Cost Flow (Primal Dual)
---
## 概要

最小費用流のアルゴリズム Primal Dual の実装。負のコストの辺にも対応。

- ```addEdge(from,to,cap,cost)``` : ```from``` -> ```to``` に容量 ```cap``` , コスト ```cost``` の辺を張る
- ```minCostFlow(from,to,F)``` : ```from``` -> ```to``` に流量 ```f``` を流す時のコストの最小値（流せない場合は -1）

## 計算量

- ```addEdge``` : $O(1)$
- ```minCostFlow``` : $O(F\ E\ log V)$ (ただし、負の辺がある場合は 追加で $O(VE)$ がかかる)