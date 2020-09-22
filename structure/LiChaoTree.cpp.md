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
    \ inf = 3e18;\n#line 3 \"structure/LiChaoTree.cpp\"\n\ntemplate<class T>\nstruct\
    \ LiChaoTree{\n\tstruct L{\n\t\tT a,b;\n\t\tL(T a,T b):a(a),b(b){}\n\t\tbool operator==(L\
    \ l){return a==l.a&&b==l.b;};\n\t};\n\tT f(L line,T x){\n\t\treturn line.a*x+line.b;\n\
    \t}\n\tint size=1;\n\tL ini={0,inf};\n\tvector<L>dat;\n\tvector<T>X;\n\tvoid add(int\
    \ a,int b,L li,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return;\n\
    \t\tint m=(l+r)/2;\n\t\tif(!(a<=l&&r<=b)){\n\t\t\tadd(a,b,li,2*k+1,l,m);\n\t\t\
    \tadd(a,b,li,2*k+2,m,r);\n\t\t\treturn;\n\t\t}\n\t\tif(dat[k]==ini){\n\t\t\tdat[k]=li;\n\
    \t\t\treturn;\n\t\t}\n\t\tint lx=X[l],mx=X[m],rx=X[r-1];\n\t\tbool left=f(li,lx)<f(dat[k],lx);\n\
    \t\tbool mid=f(li,mx)<f(dat[k],mx);\n\t\tbool right=f(li,rx)<f(dat[k],rx);\n\n\
    \t\tif(left&&right){dat[k]=li;return;}\n\t\tif(!left&&!right)return;\n\t\tif(mid)swap(li,dat[k]);\n\
    \t\tif(left!=mid){\n\t\t\tadd(a,b,li,2*k+1,l,m);\n\t\t}else {\n\t\t\tadd(a,b,li,2*k+2,m,r);\n\
    \t\t}\n\t}\n\tT query(int a,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\
    \t\tif(r-l==1)return f(dat[k],X[a]);\n\t\tif(a<(l+r)/2)return min(query(a,k*2+1,l,(l+r)/2),f(dat[k],X[a]));\n\
    \t\telse return min(query(a,k*2+2,(l+r)/2,r),f(dat[k],X[a]));\n\t}\n\tLiChaoTree(vector<T>v):X(v){\n\
    \t\tint N=len(v);\n\t\twhile(size<N)size*=2;\n\t\tdat.resize(size*2-1,ini);\n\t\
    \tX.resize(size*2-1,1e9);\n\t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<class T>\n\
    struct LiChaoTree{\n\tstruct L{\n\t\tT a,b;\n\t\tL(T a,T b):a(a),b(b){}\n\t\t\
    bool operator==(L l){return a==l.a&&b==l.b;};\n\t};\n\tT f(L line,T x){\n\t\t\
    return line.a*x+line.b;\n\t}\n\tint size=1;\n\tL ini={0,inf};\n\tvector<L>dat;\n\
    \tvector<T>X;\n\tvoid add(int a,int b,L li,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\
    \t\tif(r<=a||b<=l)return;\n\t\tint m=(l+r)/2;\n\t\tif(!(a<=l&&r<=b)){\n\t\t\t\
    add(a,b,li,2*k+1,l,m);\n\t\t\tadd(a,b,li,2*k+2,m,r);\n\t\t\treturn;\n\t\t}\n\t\
    \tif(dat[k]==ini){\n\t\t\tdat[k]=li;\n\t\t\treturn;\n\t\t}\n\t\tint lx=X[l],mx=X[m],rx=X[r-1];\n\
    \t\tbool left=f(li,lx)<f(dat[k],lx);\n\t\tbool mid=f(li,mx)<f(dat[k],mx);\n\t\t\
    bool right=f(li,rx)<f(dat[k],rx);\n\n\t\tif(left&&right){dat[k]=li;return;}\n\t\
    \tif(!left&&!right)return;\n\t\tif(mid)swap(li,dat[k]);\n\t\tif(left!=mid){\n\t\
    \t\tadd(a,b,li,2*k+1,l,m);\n\t\t}else {\n\t\t\tadd(a,b,li,2*k+2,m,r);\n\t\t}\n\
    \t}\n\tT query(int a,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r-l==1)return\
    \ f(dat[k],X[a]);\n\t\tif(a<(l+r)/2)return min(query(a,k*2+1,l,(l+r)/2),f(dat[k],X[a]));\n\
    \t\telse return min(query(a,k*2+2,(l+r)/2,r),f(dat[k],X[a]));\n\t}\n\tLiChaoTree(vector<T>v):X(v){\n\
    \t\tint N=len(v);\n\t\twhile(size<N)size*=2;\n\t\tdat.resize(size*2-1,ini);\n\t\
    \tX.resize(size*2-1,1e9);\n\t}\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/LiChaoTree.cpp
  requiredBy: []
  timestamp: '2020-09-22 11:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/LiChaoTree.cpp
layout: document
redirect_from:
- /library/structure/LiChaoTree.cpp
- /library/structure/LiChaoTree.cpp.html
title: structure/LiChaoTree.cpp
---
