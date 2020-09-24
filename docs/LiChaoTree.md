## 概要

Convex Hull Trick の Li Chao Treeで実装したバージョン

- ```add(a,b,l)``` : 登録した $x$ 座標の $[a,b)$ に線分 $l$ を追加
- ```query(a)``` : 登録した $x$ 座標の $a$ 番目を含む線分の $y$ 座標の最小値 (線分が存在しない場合はinf)

## 計算量

- ```add(a,b,l)``` : $O(log^2\ N)$
- ```query(a)``` : $O(log\ N)$