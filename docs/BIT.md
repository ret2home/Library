## 概要

Binary Indexed Tree (Fenwick Tree)

1点更新区間取得ができるデータ構造。和しか実装してないけど多分それくらいしか使わないはず？

- ```add(x,y)``` : ```x``` 番目の要素に```y``` を足す
- ```sum(l,r)``` : ```[l,r)``` の和
- ```lower_bound(w)``` : [0,x] の和が```w``` 以上となる最小のindex

## 計算量

全て $O(log\ N)$