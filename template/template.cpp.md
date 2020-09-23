---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: structure/SegmentTreeBeats.cpp
    title: structure/SegmentTreeBeats.cpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.cpp
    title: Union Find
  - icon: ':warning:'
    path: structure/SplayTree.cpp
    title: structure/SplayTree.cpp
  - icon: ':warning:'
    path: structure/SparseTable.cpp
    title: structure/SparseTable.cpp
  - icon: ':warning:'
    path: structure/PartialPersistentUnionFind.cpp
    title: structure/PartialPersistentUnionFind.cpp
  - icon: ':warning:'
    path: structure/WaveletMatrix.cpp
    title: structure/WaveletMatrix.cpp
  - icon: ':warning:'
    path: structure/LiChaoTree.cpp
    title: structure/LiChaoTree.cpp
  - icon: ':heavy_check_mark:'
    path: structure/BIT.cpp
    title: Binary Indexed Tree
  - icon: ':warning:'
    path: structure/PersistentArray.cpp
    title: structure/PersistentArray.cpp
  - icon: ':heavy_check_mark:'
    path: structure/SegmentTree.cpp
    title: Lazy Segment Tree
  - icon: ':warning:'
    path: structure/PersistentUnionFind.cpp
    title: structure/PersistentUnionFind.cpp
  - icon: ':warning:'
    path: structure/HeavyLightDecomposition.cpp
    title: structure/HeavyLightDecomposition.cpp
  - icon: ':warning:'
    path: structure/BitVector.cpp
    title: structure/BitVector.cpp
  - icon: ':warning:'
    path: math/CRT.cpp
    title: math/CRT.cpp
  - icon: ':warning:'
    path: math/extgcd.cpp
    title: math/extgcd.cpp
  - icon: ':warning:'
    path: math/FFT.cpp
    title: math/FFT.cpp
  - icon: ':warning:'
    path: math/factor.cpp
    title: math/factor.cpp
  - icon: ':heavy_check_mark:'
    path: math/Combination.cpp
    title: Combination (nCk)
  - icon: ':heavy_check_mark:'
    path: math/modint.cpp
    title: mod int
  - icon: ':warning:'
    path: math/combination_big.cpp
    title: math/combination_big.cpp
  - icon: ':warning:'
    path: string/FM_index.cpp
    title: string/FM_index.cpp
  - icon: ':warning:'
    path: string/Zalgo.cpp
    title: string/Zalgo.cpp
  - icon: ':warning:'
    path: string/RollingHash.cpp
    title: string/RollingHash.cpp
  - icon: ':warning:'
    path: string/BWT.cpp
    title: string/BWT.cpp
  - icon: ':warning:'
    path: string/SuffixArray.cpp
    title: string/SuffixArray.cpp
  - icon: ':warning:'
    path: graph/MaxFlow.cpp
    title: graph/MaxFlow.cpp
  - icon: ':warning:'
    path: graph/SCC.cpp
    title: graph/SCC.cpp
  - icon: ':warning:'
    path: graph/MinCostFlow.cpp
    title: graph/MinCostFlow.cpp
  - icon: ':warning:'
    path: graph/Tree.cpp
    title: graph/Tree.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Combination.test.cpp
    title: test/Combination.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/BIT.test.cpp
    title: test/BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/SegmentTree.test.cpp
    title: test/SegmentTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/UnionFind.test.cpp
    title: test/UnionFind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n"
  code: "#pragma once\n#include<bits/stdc++.h>\n#pragma GCC optimization (\"Ofast\"\
    )\n#pragma GCC optimization (\"unroll-loops\")\nusing namespace std;\n#define\
    \ ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n#define REP(i,n) for(ll\
    \ i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n#define all(v) v.begin(),v.end()\n\
    #define P pair<ll,ll>\n#define len(s) (ll)s.size()\n \ntemplate<class T> inline\
    \ bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\treturn false;\n}\ntemplate<class\
    \ T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return true;}\n\treturn false;\n\
    }\nconstexpr ll inf = 3e18;"
  dependsOn: []
  isVerificationFile: false
  path: template/template.cpp
  requiredBy:
  - structure/SegmentTreeBeats.cpp
  - structure/UnionFind.cpp
  - structure/SplayTree.cpp
  - structure/SparseTable.cpp
  - structure/PartialPersistentUnionFind.cpp
  - structure/WaveletMatrix.cpp
  - structure/LiChaoTree.cpp
  - structure/BIT.cpp
  - structure/PersistentArray.cpp
  - structure/SegmentTree.cpp
  - structure/PersistentUnionFind.cpp
  - structure/HeavyLightDecomposition.cpp
  - structure/BitVector.cpp
  - math/CRT.cpp
  - math/extgcd.cpp
  - math/FFT.cpp
  - math/factor.cpp
  - math/Combination.cpp
  - math/modint.cpp
  - math/combination_big.cpp
  - string/FM_index.cpp
  - string/Zalgo.cpp
  - string/RollingHash.cpp
  - string/BWT.cpp
  - string/SuffixArray.cpp
  - graph/MaxFlow.cpp
  - graph/SCC.cpp
  - graph/MinCostFlow.cpp
  - graph/Tree.cpp
  timestamp: '2020-09-23 19:41:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Combination.test.cpp
  - test/BIT.test.cpp
  - test/SegmentTree.test.cpp
  - test/UnionFind.test.cpp
documentation_of: template/template.cpp
layout: document
redirect_from:
- /library/template/template.cpp
- /library/template/template.cpp.html
title: template/template.cpp
---
