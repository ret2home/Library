---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LiChaoTree.test.cpp
    title: test/LiChaoTree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/LiChaoTree.md
    document_title: Li Chao Tree (Convex Hull Trick)
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i <\
    \ n; i++)\n#define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define all(v) v.begin(), v.end()\n#define P pair<ll,\
    \ ll>\n#define len(s) (ll) s.size()\n\ntemplate <class T, class U>\ninline bool\
    \ chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T\
    \ &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/LiChaoTree.cpp\"\
    \n\ntemplate <class T>\nstruct LiChaoTree {\n    struct L {\n        T a, b;\n\
    \        L(T a, T b) : a(a), b(b) {}\n        bool operator==(L l) { return a\
    \ == l.a && b == l.b; };\n    };\n    T f(L line, T x) {\n        return line.a\
    \ * x + line.b;\n    }\n    ll size = 1;\n    L ini = {0, inf};\n    vector<L>\
    \ dat;\n    vector<T> X;\n    void add(ll a, ll b, L li, ll k = 0, ll l = 0, ll\
    \ r = -1) {\n        if (r == -1) r = size;\n        if (r <= a || b <= l) return;\n\
    \        ll m = (l + r) / 2;\n        if (!(a <= l && r <= b)) {\n           \
    \ add(a, b, li, 2 * k + 1, l, m);\n            add(a, b, li, 2 * k + 2, m, r);\n\
    \            return;\n        }\n        if (dat[k] == ini) {\n            dat[k]\
    \ = li;\n            return;\n        }\n        ll lx = X[l], mx = X[m], rx =\
    \ X[r - 1];\n        bool left = f(li, lx) < f(dat[k], lx);\n        bool mid\
    \ = f(li, mx) < f(dat[k], mx);\n        bool right = f(li, rx) < f(dat[k], rx);\n\
    \n        if (left && right) {\n            dat[k] = li;\n            return;\n\
    \        }\n        if (!left && !right) return;\n        if (mid) swap(li, dat[k]);\n\
    \        if (left != mid) {\n            add(a, b, li, 2 * k + 1, l, m);\n   \
    \     } else {\n            add(a, b, li, 2 * k + 2, m, r);\n        }\n    }\n\
    \    T query(ll a, ll k = 0, ll l = 0, ll r = -1) {\n        if (r == -1) r =\
    \ size;\n        if (r - l == 1) return f(dat[k], X[a]);\n        if (a < (l +\
    \ r) / 2)\n            return min(query(a, k * 2 + 1, l, (l + r) / 2), f(dat[k],\
    \ X[a]));\n        else\n            return min(query(a, k * 2 + 2, (l + r) /\
    \ 2, r), f(dat[k], X[a]));\n    }\n    LiChaoTree(vector<T> v) : X(v) {\n    \
    \    ll N = len(v);\n        while (size < N) size *= 2;\n        dat.resize(size\
    \ * 2 - 1, ini);\n        X.resize(size * 2 - 1, 1e9);\n    }\n};\n/*\n@brief\
    \ Li Chao Tree (Convex Hull Trick)\n@docs docs/LiChaoTree.md\n*/\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate <class T>\n\
    struct LiChaoTree {\n    struct L {\n        T a, b;\n        L(T a, T b) : a(a),\
    \ b(b) {}\n        bool operator==(L l) { return a == l.a && b == l.b; };\n  \
    \  };\n    T f(L line, T x) {\n        return line.a * x + line.b;\n    }\n  \
    \  ll size = 1;\n    L ini = {0, inf};\n    vector<L> dat;\n    vector<T> X;\n\
    \    void add(ll a, ll b, L li, ll k = 0, ll l = 0, ll r = -1) {\n        if (r\
    \ == -1) r = size;\n        if (r <= a || b <= l) return;\n        ll m = (l +\
    \ r) / 2;\n        if (!(a <= l && r <= b)) {\n            add(a, b, li, 2 * k\
    \ + 1, l, m);\n            add(a, b, li, 2 * k + 2, m, r);\n            return;\n\
    \        }\n        if (dat[k] == ini) {\n            dat[k] = li;\n         \
    \   return;\n        }\n        ll lx = X[l], mx = X[m], rx = X[r - 1];\n    \
    \    bool left = f(li, lx) < f(dat[k], lx);\n        bool mid = f(li, mx) < f(dat[k],\
    \ mx);\n        bool right = f(li, rx) < f(dat[k], rx);\n\n        if (left &&\
    \ right) {\n            dat[k] = li;\n            return;\n        }\n       \
    \ if (!left && !right) return;\n        if (mid) swap(li, dat[k]);\n        if\
    \ (left != mid) {\n            add(a, b, li, 2 * k + 1, l, m);\n        } else\
    \ {\n            add(a, b, li, 2 * k + 2, m, r);\n        }\n    }\n    T query(ll\
    \ a, ll k = 0, ll l = 0, ll r = -1) {\n        if (r == -1) r = size;\n      \
    \  if (r - l == 1) return f(dat[k], X[a]);\n        if (a < (l + r) / 2)\n   \
    \         return min(query(a, k * 2 + 1, l, (l + r) / 2), f(dat[k], X[a]));\n\
    \        else\n            return min(query(a, k * 2 + 2, (l + r) / 2, r), f(dat[k],\
    \ X[a]));\n    }\n    LiChaoTree(vector<T> v) : X(v) {\n        ll N = len(v);\n\
    \        while (size < N) size *= 2;\n        dat.resize(size * 2 - 1, ini);\n\
    \        X.resize(size * 2 - 1, 1e9);\n    }\n};\n/*\n@brief Li Chao Tree (Convex\
    \ Hull Trick)\n@docs docs/LiChaoTree.md\n*/"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/LiChaoTree.cpp
  requiredBy: []
  timestamp: '2020-12-20 09:59:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LiChaoTree.test.cpp
documentation_of: structure/LiChaoTree.cpp
layout: document
redirect_from:
- /library/structure/LiChaoTree.cpp
- /library/structure/LiChaoTree.cpp.html
title: Li Chao Tree (Convex Hull Trick)
---
## 概要

Convex Hull Trick の Li Chao Treeで実装したバージョン

- ```add(a,b,l)``` : 登録した $x$ 座標の $[a,b)$ に線分 $l$ を追加
- ```query(a)``` : 登録した $x$ 座標の $a$ 番目を含む線分の $y$ 座標の最小値 (線分が存在しない場合はinf)

## 計算量

- ```add(a,b,l)``` : $O(log^2\ N)$
- ```query(a)``` : $O(log\ N)$