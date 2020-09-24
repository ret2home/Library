## 概要

最小費用流のアルゴリズム Primal Dual の実装。負のコストの辺にも対応。

- ```addEdge(from,to,cap,cost)``` : ```from``` -> ```to``` に容量 ```cap``` , コスト ```cost``` の辺を張る
- ```minCostFlow(from,to,F)``` : ```from``` -> ```to``` に流量 ```f``` を流す時のコストの最小値（流せない場合は -1）

## 計算量

- ```addEdge``` : $O(1)$
- ```minCostFlow``` : $O(F\ E\ log V)$ (ただし、負の辺がある場合は 追加で $O(VE)$ がかかる)