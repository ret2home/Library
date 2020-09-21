---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: String/FM_index.cpp
    title: String/FM_index.cpp
  - icon: ':warning:'
    path: Data Structure/WaveletMatrix.cpp
    title: Data Structure/WaveletMatrix.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma\
    \ GCC optimization (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\n\
    using namespace std;\n#define int long long\n#define rep(i,n) for(int i=0;i<n;i++)\n\
    #define REP(i,n) for(int i=1;i<n;i++)\n#define rev(i,n) for(int i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<int,int>\n#define len(s) (int)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr int mod = 1e9+7;\nconstexpr long long\
    \ inf = 3e18;\n#line 3 \"Data Structure/BitVector.cpp\"\n\nclass BitVector{\n\
    \    vector<int>sum;\n    vector<uint64_t>bit;\npublic:\n    int rank(bool val,int\
    \ idx){\n        uint64_t mask=((uint64_t)1<<(idx&((1<<6)-1)))-1;\n        int\
    \ res=sum[idx>>6]+__builtin_popcountll(bit[idx>>6]&mask);\n        return (val?res:idx-res);\n\
    \    }\n    BitVector(vector<bool>&v){\n        int sz=(len(v)>>6)+1;\n      \
    \  bit.assign(sz,0);\n        sum.assign(sz,0);\n        rep(i,len(v)){\n    \
    \        bit[i>>6]|=(uint64_t)(v[i])<<(i&((1<<6)-1));\n        }\n        rep(i,sz-1){\n\
    \            sum[i+1]=sum[i]+__builtin_popcountll(bit[i]);\n        }\n    }\n\
    };\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nclass BitVector{\n\
    \    vector<int>sum;\n    vector<uint64_t>bit;\npublic:\n    int rank(bool val,int\
    \ idx){\n        uint64_t mask=((uint64_t)1<<(idx&((1<<6)-1)))-1;\n        int\
    \ res=sum[idx>>6]+__builtin_popcountll(bit[idx>>6]&mask);\n        return (val?res:idx-res);\n\
    \    }\n    BitVector(vector<bool>&v){\n        int sz=(len(v)>>6)+1;\n      \
    \  bit.assign(sz,0);\n        sum.assign(sz,0);\n        rep(i,len(v)){\n    \
    \        bit[i>>6]|=(uint64_t)(v[i])<<(i&((1<<6)-1));\n        }\n        rep(i,sz-1){\n\
    \            sum[i+1]=sum[i]+__builtin_popcountll(bit[i]);\n        }\n    }\n\
    };"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: Data Structure/BitVector.cpp
  requiredBy:
  - String/FM_index.cpp
  - Data Structure/WaveletMatrix.cpp
  timestamp: '2020-09-09 20:08:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structure/BitVector.cpp
layout: document
redirect_from:
- /library/Data Structure/BitVector.cpp
- /library/Data Structure/BitVector.cpp.html
title: Data Structure/BitVector.cpp
---
