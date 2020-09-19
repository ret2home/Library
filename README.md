# Library

[define](https://atcoder.jp/users/define) の競プロライブラリです。

勝手に使って大丈夫ですが、バグっている可能性もあります。まぁ一応Verifyはしてるので大丈夫なはず！

C++17想定なので、C++14だとコンパイル通らないかもしれません。とは言ってもC++14でエラーが出るのはstd::gcdくらいなので大して問題はないかな

基本的に0-indexedですが、BITだけ1-indexedです。頭壊れる...

## Data Structure

- Union Find
- Binary Indexed Tree (**1-indexed**)
- Segment Tree
- Segment Tree Beats (Update : chmin,chmax,add Query : sum)
- Bit Vector
- Wavelet Matrix (Rank, Quantile)
- Heavy Light Decomposition
- SparseTable
- Splay Tree (find,lower_bound,upper_bound,insert,erase)
- Convex Hull Trick (Li Chao Tree)
- Persistent Union Find
- Partial Persistent UnionFind

## Graph

- Tree (LCA)
- Min Cost Flow (Primal Dual)
- Max Flow (Dinic)
- SCC

## Math

- nCk (nが小さい場合)
- nCk (kが小さい場合)
- Prime Factor (rho + miller rabin)
- Fast Fourier Transform (Special Thanks : @ageprocpp)

## String

- Z Algorithm
- Rolling Hash (mod 2^61-1)
- Suffix Array (SA-IS)
- BWT
- FM-index