---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma\
    \ GCC optimization (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\n\
    using namespace std;\n#define int long long\n#define rep(i,n) for(int i=0;i<n;i++)\n\
    #define REP(i,n) for(int i=1;i<n;i++)\n#define rev(i,n) for(int i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<int,int>\n#define len(s) (int)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr int mod = 1e9+7;\nconstexpr long long\
    \ inf = 3e18;\n#line 3 \"structure/SegmentTree.cpp\"\n\ntemplate<typename Monoid,typename\
    \ OperatorMonoid,typename F,typename G,typename H>\nstruct Segtree{\n\tint size=1;\n\
    \tvector<Monoid>dat;\n\tvector<OperatorMonoid>lazy;\n\tconst F f;\n\tconst G g;\n\
    \tconst H h;\n\tMonoid M;\n\tOperatorMonoid OM;\n\tvoid set(int a,Monoid x){\n\
    \t\tdat[a+size-1]=x;\n\t}\n\tvoid init(){\n\t\tfor(int i=size-2;i>=0;i--){\n\t\
    \t\tdat[i]=f(dat[i*2+1],dat[i*2+2]);\n\t\t}\n\t}\n\tvoid eval(int k,int l,int\
    \ r){\n\t\tif(lazy[k]!=OM){\n\t\t\tdat[k]=g(dat[k],lazy[k],(r-l));\n\t\t\tif(r-l>1){\n\
    \t\t\t\tlazy[2*k+1]=h(lazy[2*k+1],lazy[k]);\n\t\t\t\tlazy[2*k+2]=h(lazy[2*k+2],lazy[k]);\n\
    \t\t\t}\n\t\t\tlazy[k]=OM;\n\t\t}\n\t}\n\tvoid update(int a,int b,OperatorMonoid\
    \ M,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l)return;\n\
    \t\tif(a<=l&&r<=b){\n\t\t\tlazy[k]=h(lazy[k],M);\n\t\t\teval(k,l,r);\n\t\t\treturn;\n\
    \t\t}\n\t\tupdate(a,b,M,k*2+1,l,(l+r)/2);\n\t\tupdate(a,b,M,k*2+2,(l+r)/2,r);\n\
    \t\tdat[k]=f(dat[k*2+1],dat[k*2+2]);\n\t}\n\tMonoid query(int a,int b,int k=0,int\
    \ l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l)return\
    \ M;\n\t\tif(a<=l&&r<=b)return dat[k];\n\t\tMonoid lv=query(a,b,k*2+1,l,(l+r)/2);\n\
    \t\tMonoid rv=query(a,b,k*2+2,(l+r)/2,r);\n\t\treturn f(lv,rv);\n\t}\n\ttemplate<class\
    \ C>\n\tint minLeft(int a,int b,C &check,Monoid x,int k=0,int l=0,int r=-1){\n\
    \t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l||!check(dat[k],x))return\
    \ -1;\n\t\tif(r-l==1)return l;\n\t\tint lv=minLeft(a,b,check,x,k*2+1,l,(l+r)/2);\n\
    \t\tif(lv!=-1)return lv;\n\t\treturn minLeft(a,b,check,x,k*2+2,(l+r)/2,r);\n\t\
    }\n\ttemplate<class C>\n\tint maxRight(int a,int b,C &check,Monoid x,int k=0,int\
    \ l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l||!check(dat[k],x))return\
    \ -1;\n\t\tif(r-l==1)return l;\n\t\tint rv=maxRight(a,b,check,x,k*2+2,(l+r)/2,r);\n\
    \t\tif(rv!=-1)return rv;\n\t\treturn maxRight(a,b,check,x,k*2+1,l,(l+r)/2);\n\t\
    }\n\tSegtree(int x,F f,G g,H h,Monoid M,OperatorMonoid OM)\n\t:f(f),g(g),h(h),M(M),OM(OM){\n\
    \t\twhile(size<x)size*=2;\n\t\tdat.resize(size*2-1,M);\n\t\tlazy.resize(size*2-1,OM);\n\
    \t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<typename\
    \ Monoid,typename OperatorMonoid,typename F,typename G,typename H>\nstruct Segtree{\n\
    \tint size=1;\n\tvector<Monoid>dat;\n\tvector<OperatorMonoid>lazy;\n\tconst F\
    \ f;\n\tconst G g;\n\tconst H h;\n\tMonoid M;\n\tOperatorMonoid OM;\n\tvoid set(int\
    \ a,Monoid x){\n\t\tdat[a+size-1]=x;\n\t}\n\tvoid init(){\n\t\tfor(int i=size-2;i>=0;i--){\n\
    \t\t\tdat[i]=f(dat[i*2+1],dat[i*2+2]);\n\t\t}\n\t}\n\tvoid eval(int k,int l,int\
    \ r){\n\t\tif(lazy[k]!=OM){\n\t\t\tdat[k]=g(dat[k],lazy[k],(r-l));\n\t\t\tif(r-l>1){\n\
    \t\t\t\tlazy[2*k+1]=h(lazy[2*k+1],lazy[k]);\n\t\t\t\tlazy[2*k+2]=h(lazy[2*k+2],lazy[k]);\n\
    \t\t\t}\n\t\t\tlazy[k]=OM;\n\t\t}\n\t}\n\tvoid update(int a,int b,OperatorMonoid\
    \ M,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l)return;\n\
    \t\tif(a<=l&&r<=b){\n\t\t\tlazy[k]=h(lazy[k],M);\n\t\t\teval(k,l,r);\n\t\t\treturn;\n\
    \t\t}\n\t\tupdate(a,b,M,k*2+1,l,(l+r)/2);\n\t\tupdate(a,b,M,k*2+2,(l+r)/2,r);\n\
    \t\tdat[k]=f(dat[k*2+1],dat[k*2+2]);\n\t}\n\tMonoid query(int a,int b,int k=0,int\
    \ l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l)return\
    \ M;\n\t\tif(a<=l&&r<=b)return dat[k];\n\t\tMonoid lv=query(a,b,k*2+1,l,(l+r)/2);\n\
    \t\tMonoid rv=query(a,b,k*2+2,(l+r)/2,r);\n\t\treturn f(lv,rv);\n\t}\n\ttemplate<class\
    \ C>\n\tint minLeft(int a,int b,C &check,Monoid x,int k=0,int l=0,int r=-1){\n\
    \t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l||!check(dat[k],x))return\
    \ -1;\n\t\tif(r-l==1)return l;\n\t\tint lv=minLeft(a,b,check,x,k*2+1,l,(l+r)/2);\n\
    \t\tif(lv!=-1)return lv;\n\t\treturn minLeft(a,b,check,x,k*2+2,(l+r)/2,r);\n\t\
    }\n\ttemplate<class C>\n\tint maxRight(int a,int b,C &check,Monoid x,int k=0,int\
    \ l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\teval(k,l,r);\n\t\tif(r<=a||b<=l||!check(dat[k],x))return\
    \ -1;\n\t\tif(r-l==1)return l;\n\t\tint rv=maxRight(a,b,check,x,k*2+2,(l+r)/2,r);\n\
    \t\tif(rv!=-1)return rv;\n\t\treturn maxRight(a,b,check,x,k*2+1,l,(l+r)/2);\n\t\
    }\n\tSegtree(int x,F f,G g,H h,Monoid M,OperatorMonoid OM)\n\t:f(f),g(g),h(h),M(M),OM(OM){\n\
    \t\twhile(size<x)size*=2;\n\t\tdat.resize(size*2-1,M);\n\t\tlazy.resize(size*2-1,OM);\n\
    \t}\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/SegmentTree.cpp
  requiredBy: []
  timestamp: '2020-09-22 11:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/SegmentTree.cpp
layout: document
redirect_from:
- /library/structure/SegmentTree.cpp
- /library/structure/SegmentTree.cpp.html
title: structure/SegmentTree.cpp
---
