---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: structure/WaveletMatrix.cpp
    title: structure/WaveletMatrix.cpp
  - icon: ':warning:'
    path: string/FM_index.cpp
    title: string/FM_index.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma\
    \ GCC optimization (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\n\
    using namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/BitVector.cpp\"\
    \n\nclass BitVector{\n    vector<ll>sum;\n    vector<uint64_t>bit;\npublic:\n\
    \    ll rank(bool val,ll idx){\n        uint64_t mask=((uint64_t)1<<(idx&((1<<6)-1)))-1;\n\
    \        ll res=sum[idx>>6]+__builtin_popcountll(bit[idx>>6]&mask);\n        return\
    \ (val?res:idx-res);\n    }\n    BitVector(vector<bool>&v){\n        ll sz=(len(v)>>6)+1;\n\
    \        bit.assign(sz,0);\n        sum.assign(sz,0);\n        rep(i,len(v)){\n\
    \            bit[i>>6]|=(uint64_t)(v[i])<<(i&((1<<6)-1));\n        }\n       \
    \ rep(i,sz-1){\n            sum[i+1]=sum[i]+__builtin_popcountll(bit[i]);\n  \
    \      }\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nclass BitVector{\n\
    \    vector<ll>sum;\n    vector<uint64_t>bit;\npublic:\n    ll rank(bool val,ll\
    \ idx){\n        uint64_t mask=((uint64_t)1<<(idx&((1<<6)-1)))-1;\n        ll\
    \ res=sum[idx>>6]+__builtin_popcountll(bit[idx>>6]&mask);\n        return (val?res:idx-res);\n\
    \    }\n    BitVector(vector<bool>&v){\n        ll sz=(len(v)>>6)+1;\n       \
    \ bit.assign(sz,0);\n        sum.assign(sz,0);\n        rep(i,len(v)){\n     \
    \       bit[i>>6]|=(uint64_t)(v[i])<<(i&((1<<6)-1));\n        }\n        rep(i,sz-1){\n\
    \            sum[i+1]=sum[i]+__builtin_popcountll(bit[i]);\n        }\n    }\n\
    };"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/BitVector.cpp
  requiredBy:
  - structure/WaveletMatrix.cpp
  - string/FM_index.cpp
  timestamp: '2020-09-23 19:41:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/BitVector.cpp
layout: document
redirect_from:
- /library/structure/BitVector.cpp
- /library/structure/BitVector.cpp.html
title: structure/BitVector.cpp
---
