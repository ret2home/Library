---
title: Union Find
documentation_of: ./structure/UnionFind.cpp
---

## 概要

素集合データ構造、通称 Union-Find (UF) または Disjoint-Set-Union (DSU) 。

集合のマージ、どこの集合に属しているかの問い合わせを高速に行える。

- ```find(x)``` : ```x``` が属する集合の根を求める
- ```merge(x,y)``` : ```x,y``` をマージする
- ```same(x,y)``` : ```x,y``` が同じ集合に属するかを求める
- ```size(x)``` : ```x``` が属する集合のサイズを求める

## 計算量

これよく分かってないけど、1回のクエリあたり $O(\alpha (N))$ らしい。

$\alpha(N)$ はアッカーマン関数の逆関数と言って、収束がすごく速い関数。定数倍と見て問題ない（？）