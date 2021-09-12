---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/MaxFlow.cpp
    title: Max Flow (Dinic)
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A
  bundledCode: "#line 1 \"test/MaxFlow.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A\"\
    \n\n#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i < n; i++)\n\
    #define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for (int i =\
    \ n - 1; i >= 0; i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n#define\
    \ all(v) v.begin(), v.end()\n#define PL pair<ll, ll>\n#define PI pair<int, int>\n\
    #define pi acos(-1)\n#define len(s) (int)s.size()\n#define compress(v) \\\n  \
    \  sort(all(v));   \\\n    v.erase(unique(all(v)), v.end());\n#define comid(v,\
    \ x) lower_bound(all(v), x) - v.begin()\n\ntemplate<class T>\nusing prique=priority_queue<T,vector<T>,greater<>>;\n\
    \ntemplate <class T, class U>\ninline bool chmin(T &a, U b) {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\ntemplate\
    \ <class T, class U>\ninline bool chmax(T &a, U b) {\n    if (a < b) {\n     \
    \   a = b;\n        return true;\n    }\n    return false;\n}\nconstexpr ll inf\
    \ = 3e18;\n#line 3 \"graph/MaxFlow.cpp\"\n\nstruct Dinic {\n    struct Edge {\n\
    \        ll to, cap, rev;\n    };\n    vector<vector<Edge>> G;\n    vector<ll>\
    \ level, iter;\n    void addEdge(ll from, ll to, ll cap) {\n        G[from].push_back({to,\
    \ cap, len(G[to])});\n        G[to].push_back({from, 0, len(G[from]) - 1});\n\
    \    }\n    void bfs(ll s) {\n        fill(all(level), -1);\n        level[s]\
    \ = 0;\n        queue<ll> que;\n        que.push(s);\n        while (len(que))\
    \ {\n            ll p = que.front();\n            que.pop();\n            for\
    \ (Edge e : G[p]) {\n                if (e.cap > 0 && level[e.to] == -1) {\n \
    \                   level[e.to] = level[p] + 1;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n    }\n    ll dfs(ll v, ll t, ll\
    \ f) {\n        if (v == t) return f;\n        for (ll &i = iter[v]; i < len(G[v]);\
    \ i++) {\n            Edge &e = G[v][i];\n            if (e.cap > 0 && level[e.to]\
    \ > level[v]) {\n                ll d = dfs(e.to, t, min(f, e.cap));\n       \
    \         if (d > 0) {\n                    e.cap -= d;\n                    G[e.to][e.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n    ll maxFlow(ll s, ll t) {\n        ll flow\
    \ = 0;\n        while (1) {\n            bfs(s);\n            if (level[t] < 0)\
    \ return flow;\n            fill(all(iter), 0);\n            ll f = 0;\n     \
    \       while ((f = dfs(s, t, inf)) > 0) {\n                flow += f;\n     \
    \       }\n        }\n    }\n    Dinic(ll N) : G(N), level(N), iter(N) {}\n};\n\
    /*\n@brief Max Flow (Dinic)\n@docs docs/MaxFlow.md\n*/\n#line 4 \"test/MaxFlow.test.cpp\"\
    \n\nint main(){\n    ll V,E;cin>>V>>E;\n    Dinic F(V);\n    rep(i,E){\n     \
    \   int u,v,c;cin>>u>>v>>c;\n        F.addEdge(u,v,c);\n    }\n    cout<<F.maxFlow(0,V-1)<<\"\
    \\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A\"\
    \n\n#include \"../graph/MaxFlow.cpp\"\n\nint main(){\n    ll V,E;cin>>V>>E;\n\
    \    Dinic F(V);\n    rep(i,E){\n        int u,v,c;cin>>u>>v>>c;\n        F.addEdge(u,v,c);\n\
    \    }\n    cout<<F.maxFlow(0,V-1)<<\"\\n\";\n}"
  dependsOn:
  - graph/MaxFlow.cpp
  - template/template.cpp
  isVerificationFile: true
  path: test/MaxFlow.test.cpp
  requiredBy: []
  timestamp: '2021-09-12 23:44:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/MaxFlow.test.cpp
layout: document
redirect_from:
- /verify/test/MaxFlow.test.cpp
- /verify/test/MaxFlow.test.cpp.html
title: test/MaxFlow.test.cpp
---
