## 概要

高速な全文検索を提供する FM Indexの実装。JOI 夏季セミナー 2020 の成果物。

- ```occ(T)``` : ```T``` が登場するSuffix Array上の区間
- ```locate(T)``` : ```T``` が登場する index の集合

Suffix Arrayと同じ。

## 計算量

- 構築 : $O(\mid S \mid)$
- クエリ : $O(\mid T \mid log\ \sigma)$ ($\sigma$ は文字の種類数で、26とか)

Suffix Arrayはクエリが $O(\mid T \mid log \mid S \mid)$ なのに対し、こちらの方が速いのが特長。

ただし、Suffix Arrayの方のクエリは定数倍が軽いので実際はあんまり変わらない事もある。