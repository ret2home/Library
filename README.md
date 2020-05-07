# Library

defineの競プロライブラリです。

勝手に使って大丈夫ですが、バグっている可能性もあります。

ほとんどは[Library Checker](https://judge.yosupo.jp/)でVerifyしています。

使用例と一緒にそのまま貼っているので、使い方はなんとなく分かるはず。

環境はC++17想定なので、C++14だとコンパイル通らないかもしれません。

とは言ってもC++14でエラーが出るのはstd::gcdくらいなので大して問題はないかな...

## Data Structure

- Union Find
- Binary Indexed Tree (1-indexed)
- Segment Tree
- Segment Tree Beats (Update : chmin,chmax,add Query : sum)
- Wavelet Matrix (Rank, Quantile)
- Heavy Light Decomposition (+Segtree)
- SparseTable
- Splay Tree (find,lower_bound,upper_bound,insert,erase)

## Graph

- Tree (LCA)

## Math

- nCk (nが小さい場合)
- nCk (kが小さい場合)
- Prime Factor (rho + miller rabin)

## String

- ZAlgorithm
- Rolling Hash (mod 2^61-1)
- Suffix Array