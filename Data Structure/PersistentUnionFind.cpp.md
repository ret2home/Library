---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  - icon: ':warning:'
    path: Data Structure/PersistentArray.cpp
    title: Data Structure/PersistentArray.cpp
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
    \ inf = 3e18;\n#line 3 \"Data Structure/PersistentArray.cpp\"\n\ntemplate<class\
    \ T>\nstruct PersistentArray{\n\tstruct Node{\n\t\tT val;\n\t\tNode* ch[20];\n\
    \t};\n\tvoid destructive_set(int idx,T val,Node *&t){\n\t\tif(!t)t=new Node();\n\
    \t\tif(idx==0)t->val=val;\n\t\telse destructive_set(idx/20,val,t->ch[idx%20]);\n\
    \t}\n\tNode *set(int idx,T val,Node *t){\n\t\tNode *res=(t?new Node(*t):new Node());\n\
    \t\tif(idx==0)res->val=val;\n\t\telse res->ch[idx%20]=set(idx/20,val,res->ch[idx%20]);\n\
    \t\treturn res;\n\t}\n\tT get(int idx,Node *t){\n\t\tassert(t);\n\t\tif(!idx)return\
    \ t->val;\n\t\treturn get(idx/20,t->ch[idx%20]);\n\t}\n};\n#line 4 \"Data Structure/PersistentUnionFind.cpp\"\
    \n\nstruct PersistentUnionFind{\n\tusing node=PersistentArray<P>::Node;\n\tPersistentArray<P>data;\n\
    \tP find(int x,node *t){\n\t\tP p=data.get(x,t);\n\t\tif(p.first==x)return p;\n\
    \t\tp=find(p.first,t);\n\t\tdata.set(x,p,t);\n\t\treturn p;\n\t}\n\tbool same(int\
    \ x,int y,node *t){\n\t\treturn find(x,t)==find(y,t);\n\t}\n\tint size(int x,node\
    \ *t){\n\t\treturn data.get(find(x,t).first,t).second;\n\t}\n\tnode* merge(int\
    \ x,int y,node *t){\n\t\tP u=find(x,t),v=find(y,t);\n\t\tif(u.first==v.first)return\
    \ new node(*t);\n\t\tif(u.second>v.second)swap(u,v);\n\t\tnode *res=data.set(u.first,{v.first,u.second},t);\n\
    \t\tnode *res2=data.set(v.first,{v.first,u.second+v.second},res);\n\t\tdelete(res);\n\
    \t\treturn res2;\n\t}\n\tnode* init(int x){\n\t\tnode* root=new node();\n\t\t\
    rep(i,x){\n\t\t\tdata.destructive_set(i,{i,1},root);\n\t\t}\n\t\treturn root;\n\
    \t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n#include \"PersistentArray.cpp\"\
    \n\nstruct PersistentUnionFind{\n\tusing node=PersistentArray<P>::Node;\n\tPersistentArray<P>data;\n\
    \tP find(int x,node *t){\n\t\tP p=data.get(x,t);\n\t\tif(p.first==x)return p;\n\
    \t\tp=find(p.first,t);\n\t\tdata.set(x,p,t);\n\t\treturn p;\n\t}\n\tbool same(int\
    \ x,int y,node *t){\n\t\treturn find(x,t)==find(y,t);\n\t}\n\tint size(int x,node\
    \ *t){\n\t\treturn data.get(find(x,t).first,t).second;\n\t}\n\tnode* merge(int\
    \ x,int y,node *t){\n\t\tP u=find(x,t),v=find(y,t);\n\t\tif(u.first==v.first)return\
    \ new node(*t);\n\t\tif(u.second>v.second)swap(u,v);\n\t\tnode *res=data.set(u.first,{v.first,u.second},t);\n\
    \t\tnode *res2=data.set(v.first,{v.first,u.second+v.second},res);\n\t\tdelete(res);\n\
    \t\treturn res2;\n\t}\n\tnode* init(int x){\n\t\tnode* root=new node();\n\t\t\
    rep(i,x){\n\t\t\tdata.destructive_set(i,{i,1},root);\n\t\t}\n\t\treturn root;\n\
    \t}\n};"
  dependsOn:
  - template/template.cpp
  - Data Structure/PersistentArray.cpp
  isVerificationFile: false
  path: Data Structure/PersistentUnionFind.cpp
  requiredBy: []
  timestamp: '2020-09-09 20:08:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structure/PersistentUnionFind.cpp
layout: document
redirect_from:
- /library/Data Structure/PersistentUnionFind.cpp
- /library/Data Structure/PersistentUnionFind.cpp.html
title: Data Structure/PersistentUnionFind.cpp
---
