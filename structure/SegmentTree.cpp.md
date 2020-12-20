---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/SegmentTree.test.cpp
    title: test/SegmentTree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/SegmentTree.md
    document_title: Lazy Segment Tree
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i <\
    \ n; i++)\n#define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define all(v) v.begin(), v.end()\n#define P pair<ll,\
    \ ll>\n#define len(s) (ll) s.size()\n\ntemplate <class T, class U>\ninline bool\
    \ chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T\
    \ &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/SegmentTree.cpp\"\
    \n\ntemplate <typename Monoid,\n          typename OperatorMonoid,\n         \
    \ Monoid (*f)(Monoid, Monoid, int),\n          Monoid (*g)(Monoid, OperatorMonoid,\
    \ int),\n          OperatorMonoid (*h)(OperatorMonoid, OperatorMonoid, int)>\n\
    struct Segtree {\n    int size = 1;\n\n   private:\n    vector<Monoid> dat;\n\
    \    vector<OperatorMonoid> lazy;\n    Monoid M;\n    OperatorMonoid OM;\n\n \
    \  public:\n    void eval(int k, int l, int r) {\n        if (lazy[k] != OM) {\n\
    \            dat[k] = g(dat[k], lazy[k], r - l);\n            if (r - l > 1) {\n\
    \                lazy[(k << 1) + 1] = h(lazy[(k << 1) + 1], lazy[k], r - l);\n\
    \                lazy[(k << 1) + 2] = h(lazy[(k << 1) + 2], lazy[k], r - l);\n\
    \            }\n            lazy[k] = OM;\n        }\n    }\n    void update(int\
    \ a, int b, OperatorMonoid M, int k = 0, int l = 0, int r = -1) {\n        if\
    \ (r == -1) r = size;\n        eval(k, l, r);\n        if (r <= a || b <= l) return;\n\
    \        if (a <= l && r <= b) {\n            lazy[k] = h(lazy[k], M, r - l);\n\
    \            eval(k, l, r);\n            return;\n        }\n        update(a,\
    \ b, M, (k << 1) + 1, l, (l + r) >> 1);\n        update(a, b, M, (k << 1) + 2,\
    \ (l + r) >> 1, r);\n        dat[k] = f(dat[(k << 1) + 1], dat[(k << 1) + 2],\
    \ r - l);\n    }\n    Monoid query(int a, int b, int k = 0, int l = 0, int r =\
    \ -1) {\n        if (r == -1) r = size;\n        eval(k, l, r);\n        if (r\
    \ <= a || b <= l) return M;\n        if (a <= l && r <= b) return dat[k];\n  \
    \      Monoid lv = query(a, b, (k << 1) + 1, l, (l + r) >> 1);\n        Monoid\
    \ rv = query(a, b, (k << 1) + 2, (l + r) >> 1, r);\n        return f(lv, rv, r\
    \ - l);\n    }\n    template <class C>\n    int minLeft(int a, int b, C &check,\
    \ Monoid x, int k = 0, int l = 0, int r = -1) {\n        if (r == -1) r = size;\n\
    \        eval(k, l, r);\n        if (r <= a || b <= l || !check(dat[k], x)) return\
    \ -1;\n        if (r - l == 1) return l;\n        int lv = minLeft(a, b, check,\
    \ x, (k << 1) + 1, l, (l + r) >> 1);\n        if (lv != -1) return lv;\n     \
    \   return minLeft(a, b, check, x, (k << 1) + 2, (l + r) >> 1, r);\n    }\n  \
    \  template <class C>\n    int maxRight(int a, int b, C &check, Monoid x, int\
    \ k = 0, int l = 0, int r = -1) {\n        if (r == -1) r = size;\n        eval(k,\
    \ l, r);\n        if (r <= a || b <= l || !check(dat[k], x)) return -1;\n    \
    \    if (r - l == 1) return l;\n        int rv = maxRight(a, b, check, x, (k <<\
    \ 1) + 2, (l + r) >> 1, r);\n        if (rv != -1) return rv;\n        return\
    \ maxRight(a, b, check, x, (k << 1) + 1, l, (l + r) >> 1);\n    }\n    Segtree(int\
    \ x, Monoid M, OperatorMonoid OM)\n        : M(M), OM(OM) {\n        while (size\
    \ < x) size <<= 1;\n        dat.resize((size << 1) - 1, M);\n        lazy.resize((size\
    \ << 1) - 1, OM);\n    }\n};\n\n/*\n@brief Lazy Segment Tree\n@docs docs/SegmentTree.md\n\
    */\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate <typename\
    \ Monoid,\n          typename OperatorMonoid,\n          Monoid (*f)(Monoid, Monoid,\
    \ int),\n          Monoid (*g)(Monoid, OperatorMonoid, int),\n          OperatorMonoid\
    \ (*h)(OperatorMonoid, OperatorMonoid, int)>\nstruct Segtree {\n    int size =\
    \ 1;\n\n   private:\n    vector<Monoid> dat;\n    vector<OperatorMonoid> lazy;\n\
    \    Monoid M;\n    OperatorMonoid OM;\n\n   public:\n    void eval(int k, int\
    \ l, int r) {\n        if (lazy[k] != OM) {\n            dat[k] = g(dat[k], lazy[k],\
    \ r - l);\n            if (r - l > 1) {\n                lazy[(k << 1) + 1] =\
    \ h(lazy[(k << 1) + 1], lazy[k], r - l);\n                lazy[(k << 1) + 2] =\
    \ h(lazy[(k << 1) + 2], lazy[k], r - l);\n            }\n            lazy[k] =\
    \ OM;\n        }\n    }\n    void update(int a, int b, OperatorMonoid M, int k\
    \ = 0, int l = 0, int r = -1) {\n        if (r == -1) r = size;\n        eval(k,\
    \ l, r);\n        if (r <= a || b <= l) return;\n        if (a <= l && r <= b)\
    \ {\n            lazy[k] = h(lazy[k], M, r - l);\n            eval(k, l, r);\n\
    \            return;\n        }\n        update(a, b, M, (k << 1) + 1, l, (l +\
    \ r) >> 1);\n        update(a, b, M, (k << 1) + 2, (l + r) >> 1, r);\n       \
    \ dat[k] = f(dat[(k << 1) + 1], dat[(k << 1) + 2], r - l);\n    }\n    Monoid\
    \ query(int a, int b, int k = 0, int l = 0, int r = -1) {\n        if (r == -1)\
    \ r = size;\n        eval(k, l, r);\n        if (r <= a || b <= l) return M;\n\
    \        if (a <= l && r <= b) return dat[k];\n        Monoid lv = query(a, b,\
    \ (k << 1) + 1, l, (l + r) >> 1);\n        Monoid rv = query(a, b, (k << 1) +\
    \ 2, (l + r) >> 1, r);\n        return f(lv, rv, r - l);\n    }\n    template\
    \ <class C>\n    int minLeft(int a, int b, C &check, Monoid x, int k = 0, int\
    \ l = 0, int r = -1) {\n        if (r == -1) r = size;\n        eval(k, l, r);\n\
    \        if (r <= a || b <= l || !check(dat[k], x)) return -1;\n        if (r\
    \ - l == 1) return l;\n        int lv = minLeft(a, b, check, x, (k << 1) + 1,\
    \ l, (l + r) >> 1);\n        if (lv != -1) return lv;\n        return minLeft(a,\
    \ b, check, x, (k << 1) + 2, (l + r) >> 1, r);\n    }\n    template <class C>\n\
    \    int maxRight(int a, int b, C &check, Monoid x, int k = 0, int l = 0, int\
    \ r = -1) {\n        if (r == -1) r = size;\n        eval(k, l, r);\n        if\
    \ (r <= a || b <= l || !check(dat[k], x)) return -1;\n        if (r - l == 1)\
    \ return l;\n        int rv = maxRight(a, b, check, x, (k << 1) + 2, (l + r) >>\
    \ 1, r);\n        if (rv != -1) return rv;\n        return maxRight(a, b, check,\
    \ x, (k << 1) + 1, l, (l + r) >> 1);\n    }\n    Segtree(int x, Monoid M, OperatorMonoid\
    \ OM)\n        : M(M), OM(OM) {\n        while (size < x) size <<= 1;\n      \
    \  dat.resize((size << 1) - 1, M);\n        lazy.resize((size << 1) - 1, OM);\n\
    \    }\n};\n\n/*\n@brief Lazy Segment Tree\n@docs docs/SegmentTree.md\n*/"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/SegmentTree.cpp
  requiredBy: []
  timestamp: '2020-12-20 09:59:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/SegmentTree.test.cpp
documentation_of: structure/SegmentTree.cpp
layout: document
redirect_from:
- /library/structure/SegmentTree.cpp
- /library/structure/SegmentTree.cpp.html
title: Lazy Segment Tree
---
## 概要

モノイドについて、区間に対する処理を高速に行えるデータ構造。

結合律が成立し、かつ単位元が存在するならモノイドだと思って OK (Minimum や Sum など)。

型は ```Segtree<Monoid,OperatorMonoid,F,G,H>``` のように書く（詳細はTestのソースコード)。
```F``` は要素同士の、```G``` は要素と作用素、```H``` は作用素同士の二項演算。

- ```Segtree(N,M,OM)``` 要素数 ```N``` , 要素の単位元 ```M``` , 作用素の単位元 ```OM``` で初期化する
- ```update(a,b,x)``` : ```[a,b)``` に対して 作用素 ```x``` を適用
- ```query(a,b)``` : ```[a,b)``` の演算の結果
- ```minLeft(a,b,C,x)``` : ```[a,b)``` で ```C(要素,x)``` を満たす最小の index
- ```maxRight(a,b,C,x)``` : ```[a,b)``` で ```C(要素,x)``` を満たす最大の index

## 計算量

- 全て $O(log N)$