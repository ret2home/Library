---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/SegmentTree.test.cpp
    title: test/SegmentTree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/SegmentTree.md
    document_title: Lazy Segment Tree
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T,class U> inline bool chmin(T &a, U b){\n\tif(a>b){a=b;return\
    \ true;}\n\treturn false;\n}\ntemplate<class T,class U> inline bool chmax(T &a,\
    \ U b){\n\tif(a<b){a=b;return true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n\
    #line 3 \"structure/SegmentTree.cpp\"\n\ntemplate<typename Monoid,\n\t\ttypename\
    \ OperatorMonoid,\n\t\tMonoid(*f)(Monoid,Monoid,int),\n\t\tMonoid(*g)(Monoid,OperatorMonoid,int),\n\
    \t\tOperatorMonoid(*h)(OperatorMonoid,OperatorMonoid,int)>\nstruct Segtree{\n\t\
    int size=1;\nprivate:\n\tvector<Monoid>dat;\n\tvector<OperatorMonoid>lazy;\n\t\
    Monoid M;\n\tOperatorMonoid OM;\npublic:\n\tvoid eval(int k,int l,int r){\n\t\t\
    if(lazy[k]!=OM){\n\t\t\tdat[k]=g(dat[k],lazy[k],r-l);\n\t\t\tif(r-l>1){\n\t\t\t\
    \tlazy[(k<<1)+1]=h(lazy[(k<<1)+1],lazy[k],r-l);\n\t\t\t\tlazy[(k<<1)+2]=h(lazy[(k<<1)+2],lazy[k],r-l);\n\
    \t\t\t}\n\t\t\tlazy[k]=OM;\n\t\t}\n\t}\n\tvoid update(int a,int b,OperatorMonoid\
    \ M,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l)return;\n\
    \t\tif(a<=l&&r<=b){\n\t\t\tlazy[k]=h(lazy[k],M,r-l);\n\t\t\teval(k,l,r);\n\t\t\
    \treturn;\n\t\t}\n\t\tupdate(a,b,M,(k<<1)+1,l,(l+r)>>1);\n\t\tupdate(a,b,M,(k<<1)+2,(l+r)>>1,r);\n\
    \t\tdat[k]=f(dat[(k<<1)+1],dat[(k<<1)+2],r-l);\n\t}\n\tMonoid query(int a,int\
    \ b,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l)return\
    \ M;\n\t\tif(a<=l&&r<=b)return dat[k];\n\t\tMonoid lv=query(a,b,(k<<1)+1,l,(l+r)>>1);\n\
    \t\tMonoid rv=query(a,b,(k<<1)+2,(l+r)>>1,r);\n\t\treturn f(lv,rv,r-l);\n\t}\n\
    \ttemplate<class C>\n\tint minLeft(int a,int b,C &check,Monoid x,int k=0,int l=0,int\
    \ r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l||!check(dat[k],x))return\
    \ -1;\n\t\tif(r-l==1)return l;\n\t\tint lv=minLeft(a,b,check,x,(k<<1)+1,l,(l+r)>>1);\n\
    \t\tif(lv!=-1)return lv;\n\t\treturn minLeft(a,b,check,x,(k<<1)+2,(l+r)>>1,r);\n\
    \t}\n\ttemplate<class C>\n\tint maxRight(int a,int b,C &check,Monoid x,int k=0,int\
    \ l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l||!check(dat[k],x))return\
    \ -1;\n\t\tif(r-l==1)return l;\n\t\tint rv=maxRight(a,b,check,x,(k<<1)+2,(l+r)>>1,r);\n\
    \t\tif(rv!=-1)return rv;\n\t\treturn maxRight(a,b,check,x,(k<<1)+1,l,(l+r)>>1);\n\
    \t}\n\tSegtree(int x,Monoid M,OperatorMonoid OM)\n\t:M(M),OM(OM){\n\t\twhile(size<x)size<<=1;\n\
    \t\tdat.resize((size<<1)-1,M);\n\t\tlazy.resize((size<<1)-1,OM);\n\t}\n};\n\n\
    /*\n@brief Lazy Segment Tree\n@docs docs/SegmentTree.md\n*/\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<typename\
    \ Monoid,\n\t\ttypename OperatorMonoid,\n\t\tMonoid(*f)(Monoid,Monoid,int),\n\t\
    \tMonoid(*g)(Monoid,OperatorMonoid,int),\n\t\tOperatorMonoid(*h)(OperatorMonoid,OperatorMonoid,int)>\n\
    struct Segtree{\n\tint size=1;\nprivate:\n\tvector<Monoid>dat;\n\tvector<OperatorMonoid>lazy;\n\
    \tMonoid M;\n\tOperatorMonoid OM;\npublic:\n\tvoid eval(int k,int l,int r){\n\t\
    \tif(lazy[k]!=OM){\n\t\t\tdat[k]=g(dat[k],lazy[k],r-l);\n\t\t\tif(r-l>1){\n\t\t\
    \t\tlazy[(k<<1)+1]=h(lazy[(k<<1)+1],lazy[k],r-l);\n\t\t\t\tlazy[(k<<1)+2]=h(lazy[(k<<1)+2],lazy[k],r-l);\n\
    \t\t\t}\n\t\t\tlazy[k]=OM;\n\t\t}\n\t}\n\tvoid update(int a,int b,OperatorMonoid\
    \ M,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l)return;\n\
    \t\tif(a<=l&&r<=b){\n\t\t\tlazy[k]=h(lazy[k],M,r-l);\n\t\t\teval(k,l,r);\n\t\t\
    \treturn;\n\t\t}\n\t\tupdate(a,b,M,(k<<1)+1,l,(l+r)>>1);\n\t\tupdate(a,b,M,(k<<1)+2,(l+r)>>1,r);\n\
    \t\tdat[k]=f(dat[(k<<1)+1],dat[(k<<1)+2],r-l);\n\t}\n\tMonoid query(int a,int\
    \ b,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l)return\
    \ M;\n\t\tif(a<=l&&r<=b)return dat[k];\n\t\tMonoid lv=query(a,b,(k<<1)+1,l,(l+r)>>1);\n\
    \t\tMonoid rv=query(a,b,(k<<1)+2,(l+r)>>1,r);\n\t\treturn f(lv,rv,r-l);\n\t}\n\
    \ttemplate<class C>\n\tint minLeft(int a,int b,C &check,Monoid x,int k=0,int l=0,int\
    \ r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l||!check(dat[k],x))return\
    \ -1;\n\t\tif(r-l==1)return l;\n\t\tint lv=minLeft(a,b,check,x,(k<<1)+1,l,(l+r)>>1);\n\
    \t\tif(lv!=-1)return lv;\n\t\treturn minLeft(a,b,check,x,(k<<1)+2,(l+r)>>1,r);\n\
    \t}\n\ttemplate<class C>\n\tint maxRight(int a,int b,C &check,Monoid x,int k=0,int\
    \ l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l||!check(dat[k],x))return\
    \ -1;\n\t\tif(r-l==1)return l;\n\t\tint rv=maxRight(a,b,check,x,(k<<1)+2,(l+r)>>1,r);\n\
    \t\tif(rv!=-1)return rv;\n\t\treturn maxRight(a,b,check,x,(k<<1)+1,l,(l+r)>>1);\n\
    \t}\n\tSegtree(int x,Monoid M,OperatorMonoid OM)\n\t:M(M),OM(OM){\n\t\twhile(size<x)size<<=1;\n\
    \t\tdat.resize((size<<1)-1,M);\n\t\tlazy.resize((size<<1)-1,OM);\n\t}\n};\n\n\
    /*\n@brief Lazy Segment Tree\n@docs docs/SegmentTree.md\n*/"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/SegmentTree.cpp
  requiredBy: []
  timestamp: '2020-11-23 14:22:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/SegmentTree.test.cpp
documentation_of: structure/SegmentTree.cpp
layout: document
redirect_from:
- /library/structure/SegmentTree.cpp
- /library/structure/SegmentTree.cpp.html
title: Lazy Segment Tree
---
## 概要

モノイドについて、区間に対する処理を高速に行えるデータ構造。

結合律が成立し、かつ単位元が存在するならモノイドだと思って OK (Minimum や Sum など)。

型は ```Segtree<Monoid,OperatorMonoid,F,G,H>``` のように書く（詳細はTestのソースコード)。
```F``` は要素同士の、```G``` は要素と作用素、```H``` は作用素同士の二項演算。

- ```Segtree(N,M,OM)``` 要素数 ```N``` , 要素の単位元 ```M``` , 作用素の単位元 ```OM``` で初期化する
- ```update(a,b,x)``` : ```[a,b)``` に対して 作用素 ```x``` を適用
- ```query(a,b)``` : ```[a,b)``` の演算の結果
- ```minLeft(a,b,C,x)``` : ```[a,b)``` で ```C(要素,x)``` を満たす最小の index
- ```maxRight(a,b,C,x)``` : ```[a,b)``` で ```C(要素,x)``` を満たす最大の index

## 計算量

- 全て $O(log N)$