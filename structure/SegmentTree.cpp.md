---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/SegmentTree.test.cpp
    title: test/SegmentTree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/SegmentTree.md
    document_title: Lazy Segment Tree
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma\
    \ GCC optimization (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\n\
    using namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/SegmentTree.cpp\"\
    \n\ntemplate<typename Monoid,typename OperatorMonoid,typename F,typename G,typename\
    \ H>\nclass Segtree{\n\tusing size_type=int32_t;\n\tsize_type size=1;\n\tvector<Monoid>dat;\n\
    \tvector<OperatorMonoid>lazy;\n\tconst F f;\n\tconst G g;\n\tconst H h;\n\tMonoid\
    \ M;\n\tOperatorMonoid OM;\npublic:\n\tvoid set(size_type a,Monoid x){\n\t\tdat[a+size-1]=x;\n\
    \t}\n\tvoid init(){\n\t\tfor(size_type i=size-2;i>=0;i--){\n\t\t\tdat[i]=f(dat[i*2+1],dat[i*2+2]);\n\
    \t\t}\n\t}\n\tvoid eval(size_type k,size_type l,size_type r){\n\t\tif(lazy[k]!=OM){\n\
    \t\t\tdat[k]=g(dat[k],lazy[k],(r-l));\n\t\t\tif(r-l>1){\n\t\t\t\tlazy[2*k+1]=h(lazy[2*k+1],lazy[k]);\n\
    \t\t\t\tlazy[2*k+2]=h(lazy[2*k+2],lazy[k]);\n\t\t\t}\n\t\t\tlazy[k]=OM;\n\t\t\
    }\n\t}\n\tvoid update(size_type a,size_type b,OperatorMonoid M,size_type k=0,size_type\
    \ l=0,size_type r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l)return;\n\
    \t\tif(a<=l&&r<=b){\n\t\t\tlazy[k]=h(lazy[k],M);\n\t\t\teval(k,l,r);\n\t\t\treturn;\n\
    \t\t}\n\t\tupdate(a,b,M,k*2+1,l,(l+r)/2);\n\t\tupdate(a,b,M,k*2+2,(l+r)/2,r);\n\
    \t\tdat[k]=f(dat[k*2+1],dat[k*2+2]);\n\t}\n\tMonoid query(size_type a,size_type\
    \ b,size_type k=0,size_type l=0,size_type r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\
    \t\tif(r<=a||b<=l)return M;\n\t\tif(a<=l&&r<=b)return dat[k];\n\t\tMonoid lv=query(a,b,k*2+1,l,(l+r)/2);\n\
    \t\tMonoid rv=query(a,b,k*2+2,(l+r)/2,r);\n\t\treturn f(lv,rv);\n\t}\n\ttemplate<class\
    \ C>\n\tsize_type minLeft(size_type a,size_type b,C &check,Monoid x,size_type\
    \ k=0,size_type l=0,size_type r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\
    \t\tif(r<=a||b<=l||!check(dat[k],x))return -1;\n\t\tif(r-l==1)return l;\n\t\t\
    size_type lv=minLeft(a,b,check,x,k*2+1,l,(l+r)/2);\n\t\tif(lv!=-1)return lv;\n\
    \t\treturn minLeft(a,b,check,x,k*2+2,(l+r)/2,r);\n\t}\n\ttemplate<class C>\n\t\
    size_type maxRight(size_type a,size_type b,C &check,Monoid x,size_type k=0,size_type\
    \ l=0,size_type r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l||!check(dat[k],x))return\
    \ -1;\n\t\tif(r-l==1)return l;\n\t\tsize_type rv=maxRight(a,b,check,x,k*2+2,(l+r)/2,r);\n\
    \t\tif(rv!=-1)return rv;\n\t\treturn maxRight(a,b,check,x,k*2+1,l,(l+r)/2);\n\t\
    }\n\tSegtree(size_type x,F f,G g,H h,Monoid M,OperatorMonoid OM)\n\t:f(f),g(g),h(h),M(M),OM(OM){\n\
    \t\twhile(size<x)size*=2;\n\t\tdat.resize(size*2-1,M);\n\t\tlazy.resize(size*2-1,OM);\n\
    \t}\n};\n\n/*\n@brief Lazy Segment Tree\n@docs docs/SegmentTree.md\n*/\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<typename\
    \ Monoid,typename OperatorMonoid,typename F,typename G,typename H>\nclass Segtree{\n\
    \tusing size_type=int32_t;\n\tsize_type size=1;\n\tvector<Monoid>dat;\n\tvector<OperatorMonoid>lazy;\n\
    \tconst F f;\n\tconst G g;\n\tconst H h;\n\tMonoid M;\n\tOperatorMonoid OM;\n\
    public:\n\tvoid set(size_type a,Monoid x){\n\t\tdat[a+size-1]=x;\n\t}\n\tvoid\
    \ init(){\n\t\tfor(size_type i=size-2;i>=0;i--){\n\t\t\tdat[i]=f(dat[i*2+1],dat[i*2+2]);\n\
    \t\t}\n\t}\n\tvoid eval(size_type k,size_type l,size_type r){\n\t\tif(lazy[k]!=OM){\n\
    \t\t\tdat[k]=g(dat[k],lazy[k],(r-l));\n\t\t\tif(r-l>1){\n\t\t\t\tlazy[2*k+1]=h(lazy[2*k+1],lazy[k]);\n\
    \t\t\t\tlazy[2*k+2]=h(lazy[2*k+2],lazy[k]);\n\t\t\t}\n\t\t\tlazy[k]=OM;\n\t\t\
    }\n\t}\n\tvoid update(size_type a,size_type b,OperatorMonoid M,size_type k=0,size_type\
    \ l=0,size_type r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l)return;\n\
    \t\tif(a<=l&&r<=b){\n\t\t\tlazy[k]=h(lazy[k],M);\n\t\t\teval(k,l,r);\n\t\t\treturn;\n\
    \t\t}\n\t\tupdate(a,b,M,k*2+1,l,(l+r)/2);\n\t\tupdate(a,b,M,k*2+2,(l+r)/2,r);\n\
    \t\tdat[k]=f(dat[k*2+1],dat[k*2+2]);\n\t}\n\tMonoid query(size_type a,size_type\
    \ b,size_type k=0,size_type l=0,size_type r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\
    \t\tif(r<=a||b<=l)return M;\n\t\tif(a<=l&&r<=b)return dat[k];\n\t\tMonoid lv=query(a,b,k*2+1,l,(l+r)/2);\n\
    \t\tMonoid rv=query(a,b,k*2+2,(l+r)/2,r);\n\t\treturn f(lv,rv);\n\t}\n\ttemplate<class\
    \ C>\n\tsize_type minLeft(size_type a,size_type b,C &check,Monoid x,size_type\
    \ k=0,size_type l=0,size_type r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\
    \t\tif(r<=a||b<=l||!check(dat[k],x))return -1;\n\t\tif(r-l==1)return l;\n\t\t\
    size_type lv=minLeft(a,b,check,x,k*2+1,l,(l+r)/2);\n\t\tif(lv!=-1)return lv;\n\
    \t\treturn minLeft(a,b,check,x,k*2+2,(l+r)/2,r);\n\t}\n\ttemplate<class C>\n\t\
    size_type maxRight(size_type a,size_type b,C &check,Monoid x,size_type k=0,size_type\
    \ l=0,size_type r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l||!check(dat[k],x))return\
    \ -1;\n\t\tif(r-l==1)return l;\n\t\tsize_type rv=maxRight(a,b,check,x,k*2+2,(l+r)/2,r);\n\
    \t\tif(rv!=-1)return rv;\n\t\treturn maxRight(a,b,check,x,k*2+1,l,(l+r)/2);\n\t\
    }\n\tSegtree(size_type x,F f,G g,H h,Monoid M,OperatorMonoid OM)\n\t:f(f),g(g),h(h),M(M),OM(OM){\n\
    \t\twhile(size<x)size*=2;\n\t\tdat.resize(size*2-1,M);\n\t\tlazy.resize(size*2-1,OM);\n\
    \t}\n};\n\n/*\n@brief Lazy Segment Tree\n@docs docs/SegmentTree.md\n*/"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/SegmentTree.cpp
  requiredBy: []
  timestamp: '2020-09-23 19:41:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
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