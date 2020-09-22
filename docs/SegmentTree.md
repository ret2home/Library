---
title: Segment Tree
documentation_of: ./structure/SegmentTree.cpp
---

## 概要

モノイドについて、区間に対する処理を高速に行えるデータ構造。

結合律が成立し、かつ単位元が存在するならモノイドだと思って OK (Minimum や Sum など)。

型は ```Segtree<Monoid,OperatorMonoid,decltype(F),decltype(G),decltype(H)>``` のように書く（詳細はTestのソースコード)

（初期化関連）

- ```Segtree(N,f,g,h,M,OM)``` 要素数 ```N``` , 要素同士の演算 ```f``` , 要素と作用素の演算 ```g``` , 作用素同士の二項演算 ```h``` , 要素の単位元 ```M``` , 作用素の単位元 ```OM``` で初期化する
- ```set(a,x)``` : ```a``` 番目の要素に ```x``` を代入
- ```init()``` : 一通り ```set``` が終わったらこれを呼んで初期化（```set```を呼ばなかったらしなくてOK)

（クエリ関連）

- ```update(a,b,x)``` : ```[a,b)``` に対して 作用素 ```x``` を適用
- ```query(a,b)``` : ```[a,b)``` の演算の結果
- ```minLeft(a,b,C,x)``` : ```[a,b)``` で ```C(要素,x)``` を満たす最小の index
- ```maxRight(a,b,C,x)``` : ```[a,b)``` で ```C(要素,x)``` を満たす最大の index

## 計算量

- ```set``` : $O(1)$
- ```init``` : $O(N)$
- それ以外は全て $O(log N)$