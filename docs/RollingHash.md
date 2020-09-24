## 概要

$mod\ 2^{61}-1$ のRolling Hash。[解説記事](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)

- ```get(l,r)``` : $[l,r)$ の Hash
- ```lcp(x,y)``` : ```x``` 文字目からと ```y``` 文字目からが最長で何文字一致しているか

## 計算量

- ```get``` : $O(1)$
- ```lcp``` : $O(log \mid S \mid)$