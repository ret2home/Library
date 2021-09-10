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
    \    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"graph/Tree.cpp\"\n\n\
    struct Tree {\n    vector<int> depth, sub;\n    vector<vector<int>> G;\n    vector<int>\
    \ par[20];\n    void dfs(int x, int p) {\n        sub[x] = 1;\n        for (int\
    \ i : G[x])\n            if (i != p) {\n                depth[i] = depth[x] +\
    \ 1;\n                par[0][i] = x;\n                dfs(i, x);\n           \
    \     sub[x] += sub[i];\n            }\n    }\n    int lca(int x, int y) {\n \
    \       if (depth[x] > depth[y]) swap(x, y);\n        rep(i, 20) if ((depth[y]\
    \ - depth[x]) >> i & 1) y = par[i][y];\n        if (x == y) return x;\n      \
    \  for (int i = 19; i >= 0; i--)\n            if (par[i][x] != par[i][y]) {\n\
    \                x = par[i][x];\n                y = par[i][y];\n            }\n\
    \        return par[0][x];\n    }\n    Tree(vector<vector<int>> G, int root =\
    \ 0) : G(G) {\n        int N = G.size();\n        depth.resize(N);\n        sub.resize(N);\n\
    \        rep(i, 20) par[i].resize(N);\n        dfs(root, root);\n        rep(i,\
    \ 19) rep(j, N) {\n            if (par[i][j] == -1)\n                par[i + 1][j]\
    \ = -1;\n            else\n                par[i + 1][j] = par[i][par[i][j]];\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct Tree {\n  \
    \  vector<int> depth, sub;\n    vector<vector<int>> G;\n    vector<int> par[20];\n\
    \    void dfs(int x, int p) {\n        sub[x] = 1;\n        for (int i : G[x])\n\
    \            if (i != p) {\n                depth[i] = depth[x] + 1;\n       \
    \         par[0][i] = x;\n                dfs(i, x);\n                sub[x] +=\
    \ sub[i];\n            }\n    }\n    int lca(int x, int y) {\n        if (depth[x]\
    \ > depth[y]) swap(x, y);\n        rep(i, 20) if ((depth[y] - depth[x]) >> i &\
    \ 1) y = par[i][y];\n        if (x == y) return x;\n        for (int i = 19; i\
    \ >= 0; i--)\n            if (par[i][x] != par[i][y]) {\n                x = par[i][x];\n\
    \                y = par[i][y];\n            }\n        return par[0][x];\n  \
    \  }\n    Tree(vector<vector<int>> G, int root = 0) : G(G) {\n        int N =\
    \ G.size();\n        depth.resize(N);\n        sub.resize(N);\n        rep(i,\
    \ 20) par[i].resize(N);\n        dfs(root, root);\n        rep(i, 19) rep(j, N)\
    \ {\n            if (par[i][j] == -1)\n                par[i + 1][j] = -1;\n \
    \           else\n                par[i + 1][j] = par[i][par[i][j]];\n       \
    \ }\n    }\n};"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: graph/Tree.cpp
  requiredBy: []
  timestamp: '2021-09-10 20:11:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Tree.cpp
layout: document
redirect_from:
- /library/graph/Tree.cpp
- /library/graph/Tree.cpp.html
title: graph/Tree.cpp
---
