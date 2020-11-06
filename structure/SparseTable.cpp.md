---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/SparseTable.test.cpp
    title: test/SparseTable.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/SparseTable.md
    document_title: Sparse Table
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/SparseTable.cpp\"\
    \n\ntemplate<class T,class F>\nstruct SparseTable{\n\tvector<T>table[20];\n\t\
    vector<int>log;\n\tF f;\n\tSparseTable(vector<T>v,F f)\n\t:log(v.size()+1),f(f){\n\
    \t\tint mx=0;\n\t\twhile(1<<(mx+1)<=len(v))++mx;\n\t\trep(i,mx+1){\n\t\t\ttable[i].resize(len(v));\n\
    \t\t\trep(j,v.size()-(1<<i)+1){\n\t\t\t\tif(i)table[i][j]=f(table[i-1][j],table[i-1][j+(1<<(i-1))]);\n\
    \t\t\t\telse table[i][j]=v[j];\n\t\t\t}\n\t\t}\n\t\tfor(int i=2;i<=len(v);i++)log[i]=log[i>>1]+1;\n\
    \t}\n\tT query(int l,int r){\n\t\treturn f(table[log[r-l]][l],table[log[r-l]][r-(1<<log[r-l])]);\n\
    \t}\n};\n/*\n@brief Sparse Table\n@docs docs/SparseTable.md\n*/\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<class T,class\
    \ F>\nstruct SparseTable{\n\tvector<T>table[20];\n\tvector<int>log;\n\tF f;\n\t\
    SparseTable(vector<T>v,F f)\n\t:log(v.size()+1),f(f){\n\t\tint mx=0;\n\t\twhile(1<<(mx+1)<=len(v))++mx;\n\
    \t\trep(i,mx+1){\n\t\t\ttable[i].resize(len(v));\n\t\t\trep(j,v.size()-(1<<i)+1){\n\
    \t\t\t\tif(i)table[i][j]=f(table[i-1][j],table[i-1][j+(1<<(i-1))]);\n\t\t\t\t\
    else table[i][j]=v[j];\n\t\t\t}\n\t\t}\n\t\tfor(int i=2;i<=len(v);i++)log[i]=log[i>>1]+1;\n\
    \t}\n\tT query(int l,int r){\n\t\treturn f(table[log[r-l]][l],table[log[r-l]][r-(1<<log[r-l])]);\n\
    \t}\n};\n/*\n@brief Sparse Table\n@docs docs/SparseTable.md\n*/\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/SparseTable.cpp
  requiredBy: []
  timestamp: '2020-11-06 12:28:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/SparseTable.test.cpp
documentation_of: structure/SparseTable.cpp
layout: document
redirect_from:
- /library/structure/SparseTable.cpp
- /library/structure/SparseTable.cpp.html
title: Sparse Table
---
## 概要

前計算を $O(N\ log N)$,クエリを $O(1)$ で処理するデータ構造。$f(a,f(b,c))=f(f(a,b),f(b,c))=f(f(a,b),c)$ が成り立つようなものしか載せられない。

例えばRMQはOKだが、RSQはNG。

- ```query(l,r)``` : $[l,r)$ の演算の結果

## 計算量

- 構築 : $O(N\ log N)$
- ```query(l,r)``` : $O(1)$