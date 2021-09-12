---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i <\
    \ n; i++)\n#define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n\
    #define all(v) v.begin(), v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,\
    \ int>\n#define pi acos(-1)\n#define len(s) (int)s.size()\n#define compress(v)\
    \ \\\n    sort(all(v));   \\\n    v.erase(unique(all(v)), v.end());\n#define comid(v,\
    \ x) lower_bound(all(v), x) - v.begin()\n\ntemplate<class T>\nusing prique=priority_queue<T,vector<T>,greater<>>;\n\
    \ntemplate <class T, class U>\ninline bool chmin(T &a, U b) {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\ntemplate\
    \ <class T, class U>\ninline bool chmax(T &a, U b) {\n    if (a < b) {\n     \
    \   a = b;\n        return true;\n    }\n    return false;\n}\nconstexpr ll inf\
    \ = 3e18;\n#line 3 \"structure/PartialPersistentUnionFind.cpp\"\n\nstruct PartialPersistentUnionFind\
    \ {\n    ll version = 0;\n    vector<ll> tim, par;\n    vector<vector<PL>> siz;\n\
    \    ll find(ll x, ll t) {\n        if (tim[x] > t) return x;\n        return\
    \ find(par[x], t);\n    }\n    ll same(ll x, ll y, ll t) {\n        return find(x,\
    \ t) == find(y, t);\n    }\n    ll size(ll x, ll t) {\n        x = find(x, t);\n\
    \        return (--upper_bound(all(siz[x]), PL(t, inf)))->second;\n    }\n   \
    \ void merge(ll x, ll y) {\n        version++;\n        x = find(x, version);\n\
    \        y = find(y, version);\n        if (x == y) return;\n        ll sx = size(x,\
    \ version), sy = size(y, version);\n        if (sx > sy) swap(x, y);\n       \
    \ tim[x] = version;\n        par[x] = y;\n        siz[y].push_back({version, sx\
    \ + sy});\n    }\n    PartialPersistentUnionFind(ll x) : tim(x, inf) {\n     \
    \   siz.resize(x);\n        rep(i, x) {\n            par.push_back(i);\n     \
    \       siz[i].push_back(PL(0, 1));\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct PartialPersistentUnionFind\
    \ {\n    ll version = 0;\n    vector<ll> tim, par;\n    vector<vector<PL>> siz;\n\
    \    ll find(ll x, ll t) {\n        if (tim[x] > t) return x;\n        return\
    \ find(par[x], t);\n    }\n    ll same(ll x, ll y, ll t) {\n        return find(x,\
    \ t) == find(y, t);\n    }\n    ll size(ll x, ll t) {\n        x = find(x, t);\n\
    \        return (--upper_bound(all(siz[x]), PL(t, inf)))->second;\n    }\n   \
    \ void merge(ll x, ll y) {\n        version++;\n        x = find(x, version);\n\
    \        y = find(y, version);\n        if (x == y) return;\n        ll sx = size(x,\
    \ version), sy = size(y, version);\n        if (sx > sy) swap(x, y);\n       \
    \ tim[x] = version;\n        par[x] = y;\n        siz[y].push_back({version, sx\
    \ + sy});\n    }\n    PartialPersistentUnionFind(ll x) : tim(x, inf) {\n     \
    \   siz.resize(x);\n        rep(i, x) {\n            par.push_back(i);\n     \
    \       siz[i].push_back(PL(0, 1));\n        }\n    }\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/PartialPersistentUnionFind.cpp
  requiredBy: []
  timestamp: '2021-09-12 23:44:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/PartialPersistentUnionFind.cpp
layout: document
redirect_from:
- /library/structure/PartialPersistentUnionFind.cpp
- /library/structure/PartialPersistentUnionFind.cpp.html
title: structure/PartialPersistentUnionFind.cpp
---
