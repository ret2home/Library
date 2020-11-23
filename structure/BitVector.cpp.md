---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/FM_index.cpp
    title: FM Index
  - icon: ':heavy_check_mark:'
    path: structure/WaveletMatrix.cpp
    title: Wavelet Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FM_index.test.cpp
    title: test/FM_index.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/WaveletMatrix.test.cpp
    title: test/WaveletMatrix.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/BitVector.md
    document_title: Bit Vector
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T,class U> inline bool chmin(T &a, U b){\n\tif(a>b){a=b;return\
    \ true;}\n\treturn false;\n}\ntemplate<class T,class U> inline bool chmax(T &a,\
    \ U b){\n\tif(a<b){a=b;return true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n\
    #line 3 \"structure/BitVector.cpp\"\n\nclass BitVector{\n    vector<ll>sum;\n\
    \    vector<uint64_t>bit;\npublic:\n    ll rank(bool val,ll idx){\n        uint64_t\
    \ mask=((uint64_t)1<<(idx&((1<<6)-1)))-1;\n        ll res=sum[idx>>6]+__builtin_popcountll(bit[idx>>6]&mask);\n\
    \        return (val?res:idx-res);\n    }\n    BitVector(vector<bool>&v){\n  \
    \      ll sz=(len(v)>>6)+1;\n        bit.assign(sz,0);\n        sum.assign(sz,0);\n\
    \        rep(i,len(v)){\n            bit[i>>6]|=(uint64_t)(v[i])<<(i&((1<<6)-1));\n\
    \        }\n        rep(i,sz-1){\n            sum[i+1]=sum[i]+__builtin_popcountll(bit[i]);\n\
    \        }\n    }\n};\n/*\n@brief Bit Vector\n@docs docs/BitVector.md\n*/\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nclass BitVector{\n\
    \    vector<ll>sum;\n    vector<uint64_t>bit;\npublic:\n    ll rank(bool val,ll\
    \ idx){\n        uint64_t mask=((uint64_t)1<<(idx&((1<<6)-1)))-1;\n        ll\
    \ res=sum[idx>>6]+__builtin_popcountll(bit[idx>>6]&mask);\n        return (val?res:idx-res);\n\
    \    }\n    BitVector(vector<bool>&v){\n        ll sz=(len(v)>>6)+1;\n       \
    \ bit.assign(sz,0);\n        sum.assign(sz,0);\n        rep(i,len(v)){\n     \
    \       bit[i>>6]|=(uint64_t)(v[i])<<(i&((1<<6)-1));\n        }\n        rep(i,sz-1){\n\
    \            sum[i+1]=sum[i]+__builtin_popcountll(bit[i]);\n        }\n    }\n\
    };\n/*\n@brief Bit Vector\n@docs docs/BitVector.md\n*/"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/BitVector.cpp
  requiredBy:
  - string/FM_index.cpp
  - structure/WaveletMatrix.cpp
  timestamp: '2020-11-18 20:02:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/WaveletMatrix.test.cpp
  - test/FM_index.test.cpp
documentation_of: structure/BitVector.cpp
layout: document
redirect_from:
- /library/structure/BitVector.cpp
- /library/structure/BitVector.cpp.html
title: Bit Vector
---
## 概要

ビットベクトル。64bitに畳み込んでいる。

- ```rank(c,x)``` : ```c``` が $[0,x)$ に何回登場したか

## 計算量

$O(1)$

```__builtin_popcountll``` の部分は QCFium法をすると速くなる。