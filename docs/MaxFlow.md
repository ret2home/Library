## 概要

最大流アルゴリズム、Dinicの実装。~~フロー速いんだけど微妙にバグる~~

- ```addEdge(from,to,cap)``` : ```from``` -> ```to``` に 容量 ```cap``` の辺を張る
- ```maxFlow(from,to)``` : ```from``` -> ```to``` の最大流

## 計算量

- ```addEdge``` : $O(1)$
- ```maxFlow``` : $O(E\ V^2)$ だが、実際にはもっと軽いらしい

Dinic を使った二部マッチングは $O(V \sqrt V)$ 