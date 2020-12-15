---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (ll i = 0; i < n;\
    \ i++)\n#define REP(i, n) for (ll i = 1; i < n; i++)\n#define rev(i, n) for (ll\
    \ i = n - 1; i >= 0; i--)\n#define all(v) v.begin(), v.end()\n#define P pair<ll,\
    \ ll>\n#define len(s) (ll) s.size()\n\ntemplate <class T, class U>\ninline bool\
    \ chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T\
    \ &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/HLD.cpp\"\
    \n\nstruct HLD {\n    struct heavy_set {\n        vector<int> ele;\n        int\
    \ depth, par, cost1 = 0, cost2 = 0;\n        heavy_set(int v, int d, int par)\n\
    \            : ele(1, v), depth(d), par(par) {}\n    };\n    vector<vector<int>>\
    \ G;\n    vector<heavy_set> S;\n    vector<int> subsize, stidx, eleidx;\n    int\
    \ subtree(int v, int p) {\n        int &sz = subsize[v];\n        if (sz) return\
    \ sz;\n        sz = 1;\n        for (int i : G[v])\n            if (i != p) sz\
    \ += subtree(i, v);\n        return sz;\n    }\n    void make_path(int v, int\
    \ p, int id) {\n        stidx[v] = id;\n        eleidx[v] = S[id].ele.size() -\
    \ 1;\n        int mxidx, mx = 0;\n        for (int i : G[v])\n            if (i\
    \ != p) {\n                if (mx < subtree(i, v)) {\n                    mx =\
    \ subtree(i, v);\n                    mxidx = i;\n                }\n        \
    \    }\n        for (int i : G[v])\n            if (i != p) {\n              \
    \  if (mxidx == i) {\n                    S[id].ele.push_back(i);\n          \
    \          make_path(i, v, id);\n                } else {\n                  \
    \  S.emplace_back(i, S[id].depth + 1, v);\n                    make_path(i, v,\
    \ S.size() - 1);\n                }\n            }\n    }\n    int st(int v) {\
    \ return stidx[v]; }\n    int el(int v) { return eleidx[v]; }\n    HLD(vector<vector<int>>\
    \ &G) : G(G) {\n        int N = G.size();\n        subsize.resize(N);\n      \
    \  eleidx.resize(N);\n        stidx.resize(N);\n        S.emplace_back(0, 0, 0);\n\
    \        make_path(0, 0, 0);\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct HLD {\n   \
    \ struct heavy_set {\n        vector<int> ele;\n        int depth, par, cost1\
    \ = 0, cost2 = 0;\n        heavy_set(int v, int d, int par)\n            : ele(1,\
    \ v), depth(d), par(par) {}\n    };\n    vector<vector<int>> G;\n    vector<heavy_set>\
    \ S;\n    vector<int> subsize, stidx, eleidx;\n    int subtree(int v, int p) {\n\
    \        int &sz = subsize[v];\n        if (sz) return sz;\n        sz = 1;\n\
    \        for (int i : G[v])\n            if (i != p) sz += subtree(i, v);\n  \
    \      return sz;\n    }\n    void make_path(int v, int p, int id) {\n       \
    \ stidx[v] = id;\n        eleidx[v] = S[id].ele.size() - 1;\n        int mxidx,\
    \ mx = 0;\n        for (int i : G[v])\n            if (i != p) {\n           \
    \     if (mx < subtree(i, v)) {\n                    mx = subtree(i, v);\n   \
    \                 mxidx = i;\n                }\n            }\n        for (int\
    \ i : G[v])\n            if (i != p) {\n                if (mxidx == i) {\n  \
    \                  S[id].ele.push_back(i);\n                    make_path(i, v,\
    \ id);\n                } else {\n                    S.emplace_back(i, S[id].depth\
    \ + 1, v);\n                    make_path(i, v, S.size() - 1);\n             \
    \   }\n            }\n    }\n    int st(int v) { return stidx[v]; }\n    int el(int\
    \ v) { return eleidx[v]; }\n    HLD(vector<vector<int>> &G) : G(G) {\n       \
    \ int N = G.size();\n        subsize.resize(N);\n        eleidx.resize(N);\n \
    \       stidx.resize(N);\n        S.emplace_back(0, 0, 0);\n        make_path(0,\
    \ 0, 0);\n    }\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/HLD.cpp
  requiredBy: []
  timestamp: '2020-12-15 15:31:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/HLD.cpp
layout: document
redirect_from:
- /library/structure/HLD.cpp
- /library/structure/HLD.cpp.html
title: structure/HLD.cpp
---
