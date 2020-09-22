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
    \ inf = 3e18;\n#line 3 \"structure/SparseTable.cpp\"\n\ntemplate<class T>\nstruct\
    \ SparseTable{\n\tusing F=function<T(T,T)>;\n\tvector<T>table[20];\n\tvector<int>log;\n\
    \tF f;\n\tSparseTable(vector<T>v,F f)\n\t:log(v.size()+1),f(f){\n\t\tint mx=0;\n\
    \t\twhile(1ll<<(mx+1)<=(int)v.size())++mx;\n\t\trep(i,mx+1){\n\t\t\ttable[i].resize(v.size());\n\
    \t\t\trep(j,v.size()-(1<<i)+1){\n\t\t\t\tif(i)table[i][j]=f(table[i-1][j],table[i-1][j+(1ll<<(i-1))]);\n\
    \t\t\t\telse table[i][j]=v[j];\n\t\t\t}\n\t\t}\n\t\tfor(int i=2;i<=(int)v.size();i++)log[i]=log[i>>1]+1;\n\
    \t}\n\tT query(int l,int r){\n\t\treturn f(table[log[r-l]][l],table[log[r-l]][r-(1<<log[r-l])]);\n\
    \t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<class T>\n\
    struct SparseTable{\n\tusing F=function<T(T,T)>;\n\tvector<T>table[20];\n\tvector<int>log;\n\
    \tF f;\n\tSparseTable(vector<T>v,F f)\n\t:log(v.size()+1),f(f){\n\t\tint mx=0;\n\
    \t\twhile(1ll<<(mx+1)<=(int)v.size())++mx;\n\t\trep(i,mx+1){\n\t\t\ttable[i].resize(v.size());\n\
    \t\t\trep(j,v.size()-(1<<i)+1){\n\t\t\t\tif(i)table[i][j]=f(table[i-1][j],table[i-1][j+(1ll<<(i-1))]);\n\
    \t\t\t\telse table[i][j]=v[j];\n\t\t\t}\n\t\t}\n\t\tfor(int i=2;i<=(int)v.size();i++)log[i]=log[i>>1]+1;\n\
    \t}\n\tT query(int l,int r){\n\t\treturn f(table[log[r-l]][l],table[log[r-l]][r-(1<<log[r-l])]);\n\
    \t}\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/SparseTable.cpp
  requiredBy: []
  timestamp: '2020-09-22 11:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/SparseTable.cpp
layout: document
redirect_from:
- /library/structure/SparseTable.cpp
- /library/structure/SparseTable.cpp.html
title: structure/SparseTable.cpp
---
