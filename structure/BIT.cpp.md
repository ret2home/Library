---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/BIT.test.cpp
    title: test/BIT.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/BIT.md
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma\
    \ GCC optimization (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\n\
    using namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/BIT.cpp\"\
    \n\ntemplate<class T>\nclass BIT{\n\tll N;\n\tvector<T>bit;\n\tvoid add_(ll x,T\
    \ y){\n\t\twhile(x<=N){\n\t\t\tbit[x]+=y;x+=x&-x;\n\t\t}\n\t}\n\tT sum_(ll x){\n\
    \t\tT res=0;\n\t\twhile(x>0){\n\t\t\tres+=bit[x];x-=x&-x;\n\t\t}\n\t\treturn res;\n\
    \t}\npublic:\n\tll lower_bound(T w){\n\t\tif(w<=0)return -1;\n\t\tll x=0;\n\t\t\
    ll k=1;while(k*2<=N)k*=2;\n\t\tfor(;k>0;k/=2){\n\t\t\tif(x+k<=N&&bit[x+k]<w){\n\
    \t\t\t\tw-=bit[x+k];\n\t\t\t\tx+=k;\n\t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n\tvoid\
    \ add(ll x,T y){add_(x+1,y);}\n\tT sum(ll l,ll r){return sum_(r)-sum_(l);}\n\t\
    BIT(ll x):N(x),bit(x+1){}\n};\n/*\n@brief Binary Indexed Tree\n@docs docs/BIT.md\n\
    */\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<class T>\n\
    class BIT{\n\tll N;\n\tvector<T>bit;\n\tvoid add_(ll x,T y){\n\t\twhile(x<=N){\n\
    \t\t\tbit[x]+=y;x+=x&-x;\n\t\t}\n\t}\n\tT sum_(ll x){\n\t\tT res=0;\n\t\twhile(x>0){\n\
    \t\t\tres+=bit[x];x-=x&-x;\n\t\t}\n\t\treturn res;\n\t}\npublic:\n\tll lower_bound(T\
    \ w){\n\t\tif(w<=0)return -1;\n\t\tll x=0;\n\t\tll k=1;while(k*2<=N)k*=2;\n\t\t\
    for(;k>0;k/=2){\n\t\t\tif(x+k<=N&&bit[x+k]<w){\n\t\t\t\tw-=bit[x+k];\n\t\t\t\t\
    x+=k;\n\t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n\tvoid add(ll x,T y){add_(x+1,y);}\n\
    \tT sum(ll l,ll r){return sum_(r)-sum_(l);}\n\tBIT(ll x):N(x),bit(x+1){}\n};\n\
    /*\n@brief Binary Indexed Tree\n@docs docs/BIT.md\n*/"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/BIT.cpp
  requiredBy: []
  timestamp: '2020-09-23 19:41:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/BIT.test.cpp
documentation_of: structure/BIT.cpp
layout: document
redirect_from:
- /library/structure/BIT.cpp
- /library/structure/BIT.cpp.html
title: Binary Indexed Tree
---
## 概要

Binary Indexed Tree (Fenwick Tree)

1点更新区間取得ができるデータ構造。和しか実装してないけど多分それくらいしか使わないはず？

- ```add(x,y)``` : ```x``` 番目の要素に```y``` を足す
- ```sum(l,r)``` : ```[l,r)``` の和
- ```lower_bound(w)``` : [0,x] の和が```w``` 以上となる最小のindex

## 計算量

全て $O(log\ N)$