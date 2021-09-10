---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/UnionFind.test.cpp
    title: test/UnionFind.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/UnionFind.md
    document_title: Union Find
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <algorithm>\n#include\
    \ <bitset>\n#include <complex>\n#include <deque>\n#include <exception>\n#include\
    \ <fstream>\n#include <functional>\n#include <iomanip>\n#include <ios>\n#include\
    \ <iosfwd>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <locale>\n#include <map>\n#include <memory>\n\
    #include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <typeinfo>\n#include <utility>\n#include\
    \ <valarray>\n#include <vector>\n#include <array>\n#include <atomic>\n#include\
    \ <chrono>\n#include <codecvt>\n#include <condition_variable>\n#include <forward_list>\n\
    #include <future>\n#include <initializer_list>\n#include <mutex>\n#include <random>\n\
    #include <ratio>\n#include <regex>\n#include <scoped_allocator>\n#include <system_error>\n\
    #include <thread>\n#include <tuple>\n#include <typeindex>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\nusing namespace std;\n#define\
    \ ll long long\n#define rep(i, n) for (int i = 0; i < n; i++)\n#define REP(i,\
    \ n) for (int i = 1; i < n; i++)\n#define rev(i, n) for (int i = n - 1; i >= 0;\
    \ i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n#define all(v) v.begin(),\
    \ v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,int>\n#define len(s) (int)s.size()\n\
    #define compress(v) sort(all(v)); v.erase(unique(all(v)),v.end());\n#define comid(v,x)\
    \ lower_bound(all(v),x)-v.begin()\n\ntemplate <class T, class U>\ninline bool\
    \ chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T\
    \ &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/UnionFind.cpp\"\
    \n\nclass UnionFind {\n    int N;\n    vector<int> par, siz;\n\n   public:\n \
    \   int find(int x) {\n        assert(x < N);\n        return (par[x] == x ? x\
    \ : par[x] = find(par[x]));\n    }\n    void merge(int x, int y) {\n        assert(x\
    \ < N && y < N);\n        x = find(x);\n        y = find(y);\n        if (x ==\
    \ y) return;\n        if (siz[x] > siz[y]) swap(x, y);\n        par[x] = y;\n\
    \        siz[y] += siz[x];\n    }\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n    int size(int x) {\n        return siz[find(x)];\n\
    \    }\n    UnionFind(int N) : N(N), siz(N, 1), par(N) {\n        iota(all(par),\
    \ 0);\n    }\n};\n\n/*\n@brief Union Find\n@docs docs/UnionFind.md\n*/\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nclass UnionFind {\n\
    \    int N;\n    vector<int> par, siz;\n\n   public:\n    int find(int x) {\n\
    \        assert(x < N);\n        return (par[x] == x ? x : par[x] = find(par[x]));\n\
    \    }\n    void merge(int x, int y) {\n        assert(x < N && y < N);\n    \
    \    x = find(x);\n        y = find(y);\n        if (x == y) return;\n       \
    \ if (siz[x] > siz[y]) swap(x, y);\n        par[x] = y;\n        siz[y] += siz[x];\n\
    \    }\n    bool same(int x, int y) {\n        return find(x) == find(y);\n  \
    \  }\n    int size(int x) {\n        return siz[find(x)];\n    }\n    UnionFind(int\
    \ N) : N(N), siz(N, 1), par(N) {\n        iota(all(par), 0);\n    }\n};\n\n/*\n\
    @brief Union Find\n@docs docs/UnionFind.md\n*/"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/UnionFind.cpp
  requiredBy: []
  timestamp: '2021-09-10 20:11:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/UnionFind.test.cpp
documentation_of: structure/UnionFind.cpp
layout: document
redirect_from:
- /library/structure/UnionFind.cpp
- /library/structure/UnionFind.cpp.html
title: Union Find
---
## 概要

素集合データ構造、通称 Union-Find (UF) または Disjoint-Set-Union (DSU) 。

集合のマージ、どこの集合に属しているかの問い合わせを高速に行える。

- ```find(x)``` : ```x``` が属する集合の根を求める
- ```merge(x,y)``` : ```x,y``` をマージする
- ```same(x,y)``` : ```x,y``` が同じ集合に属するかを求める
- ```size(x)``` : ```x``` が属する集合のサイズを求める

## 計算量

これよく分かってないけど、1回のクエリあたり $O(\alpha (N))$ らしい。

$\alpha(N)$ はアッカーマン関数の逆関数と言って、収束がすごく速い関数。定数倍と見て問題ない（？）