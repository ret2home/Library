---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/MaxFlow.cpp
    title: Max Flow (Dinic)
  - icon: ':heavy_check_mark:'
    path: graph/MinCostFlow.cpp
    title: Min Cost Flow (Primal Dual)
  - icon: ':warning:'
    path: graph/SCC.cpp
    title: graph/SCC.cpp
  - icon: ':warning:'
    path: graph/Tree.cpp
    title: graph/Tree.cpp
  - icon: ':warning:'
    path: math/CRT.cpp
    title: math/CRT.cpp
  - icon: ':heavy_check_mark:'
    path: math/Combination.cpp
    title: Combination (nCk)
  - icon: ':warning:'
    path: math/FFT.cpp
    title: math/FFT.cpp
  - icon: ':warning:'
    path: math/combination_big.cpp
    title: math/combination_big.cpp
  - icon: ':question:'
    path: math/extgcd.cpp
    title: math/extgcd.cpp
  - icon: ':heavy_check_mark:'
    path: math/factor.cpp
    title: Fast Prime Factorization
  - icon: ':question:'
    path: math/modint.cpp
    title: mod int
  - icon: ':heavy_check_mark:'
    path: string/BWT.cpp
    title: Burrows Wheeler Transform
  - icon: ':heavy_check_mark:'
    path: string/FM_index.cpp
    title: FM Index
  - icon: ':heavy_check_mark:'
    path: string/RollingHash.cpp
    title: Rolling Hash (mod 2^61-1)
  - icon: ':heavy_check_mark:'
    path: string/SuffixArray.cpp
    title: Suffix Array (SA-IS)
  - icon: ':warning:'
    path: string/Zalgo.cpp
    title: string/Zalgo.cpp
  - icon: ':heavy_check_mark:'
    path: structure/BIT.cpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: structure/BitVector.cpp
    title: Bit Vector
  - icon: ':warning:'
    path: structure/HLD.cpp
    title: structure/HLD.cpp
  - icon: ':heavy_check_mark:'
    path: structure/LiChaoTree.cpp
    title: Li Chao Tree (Convex Hull Trick)
  - icon: ':warning:'
    path: structure/Mo.cpp
    title: structure/Mo.cpp
  - icon: ':warning:'
    path: structure/PartialPersistentUnionFind.cpp
    title: structure/PartialPersistentUnionFind.cpp
  - icon: ':warning:'
    path: structure/PersistentArray.cpp
    title: structure/PersistentArray.cpp
  - icon: ':warning:'
    path: structure/PersistentUnionFind.cpp
    title: structure/PersistentUnionFind.cpp
  - icon: ':x:'
    path: structure/SegmentTree.cpp
    title: Lazy Segment Tree
  - icon: ':warning:'
    path: structure/SegmentTreeBeats.cpp
    title: structure/SegmentTreeBeats.cpp
  - icon: ':x:'
    path: structure/SparseTable.cpp
    title: Sparse Table
  - icon: ':warning:'
    path: structure/SplayTree.cpp
    title: structure/SplayTree.cpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.cpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: structure/WaveletMatrix.cpp
    title: Wavelet Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/BIT.test.cpp
    title: test/BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Combination.test.cpp
    title: test/Combination.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/FM_index.test.cpp
    title: test/FM_index.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LiChaoTree.test.cpp
    title: test/LiChaoTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/MaxFlow.test.cpp
    title: test/MaxFlow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/MinCostFlow.test.cpp
    title: test/MinCostFlow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/RollingHash.test.cpp
    title: test/RollingHash.test.cpp
  - icon: ':x:'
    path: test/SegmentTree.test.cpp
    title: test/SegmentTree.test.cpp
  - icon: ':x:'
    path: test/SparseTable.test.cpp
    title: test/SparseTable.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/SuffixArray.LCP.test.cpp
    title: test/SuffixArray.LCP.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/SuffixArray.matching.test.cpp
    title: test/SuffixArray.matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/SuffixArray.test.cpp
    title: test/SuffixArray.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/UnionFind.test.cpp
    title: test/UnionFind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/WaveletMatrix.test.cpp
    title: test/WaveletMatrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/factor.test.cpp
    title: test/factor.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i <\
    \ n; i++)\n#define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define all(v) v.begin(), v.end()\n#define P pair<ll,\
    \ ll>\n#define len(s) (ll) s.size()\n\ntemplate <class T, class U>\ninline bool\
    \ chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T\
    \ &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\nconstexpr ll inf = 3e18;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n#define ll\
    \ long long\n#define rep(i, n) for (int i = 0; i < n; i++)\n#define REP(i, n)\
    \ for (int i = 1; i < n; i++)\n#define rev(i, n) for (int i = n - 1; i >= 0; i--)\n\
    #define all(v) v.begin(), v.end()\n#define P pair<ll, ll>\n#define len(s) (ll)\
    \ s.size()\n\ntemplate <class T, class U>\ninline bool chmin(T &a, U b) {\n  \
    \  if (a > b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\ntemplate <class T, class U>\ninline bool chmax(T &a, U b) {\n    if (a < b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\nconstexpr\
    \ ll inf = 3e18;"
  dependsOn: []
  isVerificationFile: false
  path: template/template.cpp
  requiredBy:
  - structure/PersistentUnionFind.cpp
  - structure/WaveletMatrix.cpp
  - structure/SegmentTreeBeats.cpp
  - structure/SparseTable.cpp
  - structure/SplayTree.cpp
  - structure/PartialPersistentUnionFind.cpp
  - structure/LiChaoTree.cpp
  - structure/Mo.cpp
  - structure/UnionFind.cpp
  - structure/BitVector.cpp
  - structure/BIT.cpp
  - structure/HLD.cpp
  - structure/SegmentTree.cpp
  - structure/PersistentArray.cpp
  - string/RollingHash.cpp
  - string/BWT.cpp
  - string/FM_index.cpp
  - string/Zalgo.cpp
  - string/SuffixArray.cpp
  - graph/MaxFlow.cpp
  - graph/Tree.cpp
  - graph/MinCostFlow.cpp
  - graph/SCC.cpp
  - math/extgcd.cpp
  - math/modint.cpp
  - math/CRT.cpp
  - math/factor.cpp
  - math/FFT.cpp
  - math/combination_big.cpp
  - math/Combination.cpp
  timestamp: '2020-12-20 09:59:48+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/WaveletMatrix.test.cpp
  - test/MaxFlow.test.cpp
  - test/MinCostFlow.test.cpp
  - test/UnionFind.test.cpp
  - test/SegmentTree.test.cpp
  - test/LiChaoTree.test.cpp
  - test/SparseTable.test.cpp
  - test/factor.test.cpp
  - test/SuffixArray.LCP.test.cpp
  - test/SuffixArray.matching.test.cpp
  - test/Combination.test.cpp
  - test/FM_index.test.cpp
  - test/RollingHash.test.cpp
  - test/BIT.test.cpp
  - test/SuffixArray.test.cpp
documentation_of: template/template.cpp
layout: document
redirect_from:
- /library/template/template.cpp
- /library/template/template.cpp.html
title: template/template.cpp
---
