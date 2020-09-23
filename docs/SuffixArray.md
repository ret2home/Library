## 概要

SA-IS を使ってSuffix Arrayを $O(\mid S \mid)$ で構築する。JOI夏季セミ2020 の成果物でもある。

- ```[i]``` : Suffix Arrayの```i``` 番目 (0番目は末尾である事に注意)
- ```occ(T)``` : ```T``` が登場するSuffix Array上の区間
- ```locate(T)``` : ```T``` が登場する index の集合
- ```LCP``` : 高さ配列

## 計算量

- 構築 : $O(\mid S \mid)$
- ```occ,locate``` : $O(\mid T \mid log \mid S \mid)$