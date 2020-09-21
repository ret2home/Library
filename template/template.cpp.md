---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/combination.cpp
    title: Math/combination.cpp
  - icon: ':warning:'
    path: Math/CRT.cpp
    title: Math/CRT.cpp
  - icon: ':warning:'
    path: Math/extgcd.cpp
    title: Math/extgcd.cpp
  - icon: ':warning:'
    path: Math/FFT.cpp
    title: Math/FFT.cpp
  - icon: ':warning:'
    path: Math/factor.cpp
    title: Math/factor.cpp
  - icon: ':warning:'
    path: Math/modint.cpp
    title: Math/modint.cpp
  - icon: ':warning:'
    path: Math/combination_big.cpp
    title: Math/combination_big.cpp
  - icon: ':warning:'
    path: Math/mod_pow.cpp
    title: Math/mod_pow.cpp
  - icon: ':warning:'
    path: String/FM_index.cpp
    title: String/FM_index.cpp
  - icon: ':warning:'
    path: String/Zalgo.cpp
    title: String/Zalgo.cpp
  - icon: ':warning:'
    path: String/RollingHash.cpp
    title: String/RollingHash.cpp
  - icon: ':warning:'
    path: String/BWT.cpp
    title: String/BWT.cpp
  - icon: ':warning:'
    path: String/SuffixArray.cpp
    title: String/SuffixArray.cpp
  - icon: ':warning:'
    path: Data Structure/SegmentTreeBeats.cpp
    title: Data Structure/SegmentTreeBeats.cpp
  - icon: ':warning:'
    path: Data Structure/UnionFind.cpp
    title: Data Structure/UnionFind.cpp
  - icon: ':warning:'
    path: Data Structure/SplayTree.cpp
    title: Data Structure/SplayTree.cpp
  - icon: ':warning:'
    path: Data Structure/SparseTable.cpp
    title: Data Structure/SparseTable.cpp
  - icon: ':warning:'
    path: Data Structure/PartialPersistentUnionFind.cpp
    title: Data Structure/PartialPersistentUnionFind.cpp
  - icon: ':warning:'
    path: Data Structure/WaveletMatrix.cpp
    title: Data Structure/WaveletMatrix.cpp
  - icon: ':warning:'
    path: Data Structure/LiChaoTree.cpp
    title: Data Structure/LiChaoTree.cpp
  - icon: ':warning:'
    path: Data Structure/BIT.cpp
    title: Data Structure/BIT.cpp
  - icon: ':warning:'
    path: Data Structure/PersistentArray.cpp
    title: Data Structure/PersistentArray.cpp
  - icon: ':warning:'
    path: Data Structure/SegmentTree.cpp
    title: Data Structure/SegmentTree.cpp
  - icon: ':warning:'
    path: Data Structure/PersistentUnionFind.cpp
    title: Data Structure/PersistentUnionFind.cpp
  - icon: ':warning:'
    path: Data Structure/HeavyLightDecomposition.cpp
    title: Data Structure/HeavyLightDecomposition.cpp
  - icon: ':warning:'
    path: Data Structure/BitVector.cpp
    title: Data Structure/BitVector.cpp
  - icon: ':warning:'
    path: Graph/MaxFlow.cpp
    title: Graph/MaxFlow.cpp
  - icon: ':warning:'
    path: Graph/SCC.cpp
    title: Graph/SCC.cpp
  - icon: ':warning:'
    path: Graph/MinCostFlow.cpp
    title: Graph/MinCostFlow.cpp
  - icon: ':warning:'
    path: Graph/Tree.cpp
    title: Graph/Tree.cpp
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
    \ inf = 3e18;\n"
  code: "#pragma once\n#include<bits/stdc++.h>\n#pragma GCC optimization (\"Ofast\"\
    )\n#pragma GCC optimization (\"unroll-loops\")\nusing namespace std;\n#define\
    \ int long long\n#define rep(i,n) for(int i=0;i<n;i++)\n#define REP(i,n) for(int\
    \ i=1;i<n;i++)\n#define rev(i,n) for(int i=n-1;i>=0;i--)\n#define all(v) v.begin(),v.end()\n\
    #define P pair<int,int>\n#define len(s) (int)s.size()\n \ntemplate<class T> inline\
    \ bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\treturn false;\n}\ntemplate<class\
    \ T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return true;}\n\treturn false;\n\
    }\nconstexpr int mod = 1e9+7;\nconstexpr long long inf = 3e18;"
  dependsOn: []
  isVerificationFile: false
  path: template/template.cpp
  requiredBy:
  - Math/combination.cpp
  - Math/CRT.cpp
  - Math/extgcd.cpp
  - Math/FFT.cpp
  - Math/factor.cpp
  - Math/modint.cpp
  - Math/combination_big.cpp
  - Math/mod_pow.cpp
  - String/FM_index.cpp
  - String/Zalgo.cpp
  - String/RollingHash.cpp
  - String/BWT.cpp
  - String/SuffixArray.cpp
  - Data Structure/SegmentTreeBeats.cpp
  - Data Structure/UnionFind.cpp
  - Data Structure/SplayTree.cpp
  - Data Structure/SparseTable.cpp
  - Data Structure/PartialPersistentUnionFind.cpp
  - Data Structure/WaveletMatrix.cpp
  - Data Structure/LiChaoTree.cpp
  - Data Structure/BIT.cpp
  - Data Structure/PersistentArray.cpp
  - Data Structure/SegmentTree.cpp
  - Data Structure/PersistentUnionFind.cpp
  - Data Structure/HeavyLightDecomposition.cpp
  - Data Structure/BitVector.cpp
  - Graph/MaxFlow.cpp
  - Graph/SCC.cpp
  - Graph/MinCostFlow.cpp
  - Graph/Tree.cpp
  timestamp: '2020-09-09 20:08:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template.cpp
layout: document
redirect_from:
- /library/template/template.cpp
- /library/template/template.cpp.html
title: template/template.cpp
---
