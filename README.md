# Library

[![Actions Status](https://github.com/define0411/Library/workflows/verify/badge.svg)](https://github.com/define0411/Library/actions) [![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://define0411.github.io/Library/) 

[define](https://atcoder.jp/users/define) の競プロライブラリです。

C++17想定なので、C++14だとコンパイル通らないかもしれません。とは言ってもC++14でエラーが出るのはstd::gcdくらいなので大して問題はないかな...

全て0-indexedです。

## Data Structure

- [Union Find](./structure/UnionFind.cpp)
- [Binary Indexed Tree](./structure/BIT.cpp)
- [Lazy Segment Tree](./structure/SegmentTree.cpp)
- [Segment Tree Beats](./structure/SegmentTreeBeats.cpp)
- [Bit Vector](./structure/BitVector.cpp)
- [Wavelet Matrix](./structure/WaveletMatrix.cpp)
- [Heavy Light Decomposition](./structure/HeavyLightDecomposition.cpp)
- [Sparse Table](./structure/SparseTable.cpp)
- [Splay Tree](./structure/SplayTree.cpp)
- [Li Chao Tree](./structure/LiChaoTree.cpp)
- [Persistent Array](./structure/PersistentArray.cpp)
- [Persistent Union Find](./structure/PersistentUnionFind.cpp)
- [Partial Persistent UnionFind](./structure/PartialPersistentUnionFind.cpp)
- [Mo's Algorithm](./structure/Mo.cpp)

## Graph

- [Tree](./graph/Tree.cpp)
- [Min Cost Flow (Primal Dual)](./graph/MinCostFlow.cpp)
- [Max Flow (Dinic)](./graph/MaxFlow.cpp)
- [SCC](./graph/SCC.cpp)

## Math

- [modint](./math/modint.cpp)
- [nCk ( $n \leq 10^7$ 程度) ](./math/Combination.cpp)
- [nCk ( $k$ が小さい時)](./math/combination_big.cpp)
- [Prime Factor (rho + miller rabin)](./math/factor.cpp)
- [Fast Fourier Transform](./math/FFT.cpp)
- [extended Euclid](./math/extgcd.cpp)
- [CRT](./math/CRT.cpp)

## String

- [Z Algorithm](./string/Zalgo.cpp)
- [Rolling Hash (mod 2^61-1)](./string/RollingHash.cpp)
- [Suffix Array (SA-IS)](./string/SuffixArray.cpp)
- [BWT](./string/BWT.cpp)
- [FM-index](./string/FM_index.cpp)