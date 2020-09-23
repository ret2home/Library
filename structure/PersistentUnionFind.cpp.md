---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  - icon: ':warning:'
    path: structure/PersistentArray.cpp
    title: structure/PersistentArray.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma\
    \ GCC optimization (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\n\
    using namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/PersistentArray.cpp\"\
    \n\ntemplate<class T>\nstruct PersistentArray{\n\tstruct Node{\n\t\tT val;\n\t\
    \tNode* ch[20];\n\t};\n\tvoid destructive_set(ll idx,T val,Node *&t){\n\t\tif(!t)t=new\
    \ Node();\n\t\tif(idx==0)t->val=val;\n\t\telse destructive_set(idx/20,val,t->ch[idx%20]);\n\
    \t}\n\tNode *set(ll idx,T val,Node *t){\n\t\tNode *res=(t?new Node(*t):new Node());\n\
    \t\tif(idx==0)res->val=val;\n\t\telse res->ch[idx%20]=set(idx/20,val,res->ch[idx%20]);\n\
    \t\treturn res;\n\t}\n\tT get(ll idx,Node *t){\n\t\tassert(t);\n\t\tif(!idx)return\
    \ t->val;\n\t\treturn get(idx/20,t->ch[idx%20]);\n\t}\n};\n#line 4 \"structure/PersistentUnionFind.cpp\"\
    \n\nstruct PersistentUnionFind{\n\tusing node=PersistentArray<P>::Node;\n\tPersistentArray<P>data;\n\
    \tP find(ll x,node *t){\n\t\tP p=data.get(x,t);\n\t\tif(p.first==x)return p;\n\
    \t\tp=find(p.first,t);\n\t\tdata.set(x,p,t);\n\t\treturn p;\n\t}\n\tbool same(ll\
    \ x,ll y,node *t){\n\t\treturn find(x,t)==find(y,t);\n\t}\n\tll size(ll x,node\
    \ *t){\n\t\treturn data.get(find(x,t).first,t).second;\n\t}\n\tnode* merge(ll\
    \ x,ll y,node *t){\n\t\tP u=find(x,t),v=find(y,t);\n\t\tif(u.first==v.first)return\
    \ new node(*t);\n\t\tif(u.second>v.second)swap(u,v);\n\t\tnode *res=data.set(u.first,{v.first,u.second},t);\n\
    \t\tnode *res2=data.set(v.first,{v.first,u.second+v.second},res);\n\t\tdelete(res);\n\
    \t\treturn res2;\n\t}\n\tnode* init(ll x){\n\t\tnode* root=new node();\n\t\trep(i,x){\n\
    \t\t\tdata.destructive_set(i,{i,1},root);\n\t\t}\n\t\treturn root;\n\t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n#include \"PersistentArray.cpp\"\
    \n\nstruct PersistentUnionFind{\n\tusing node=PersistentArray<P>::Node;\n\tPersistentArray<P>data;\n\
    \tP find(ll x,node *t){\n\t\tP p=data.get(x,t);\n\t\tif(p.first==x)return p;\n\
    \t\tp=find(p.first,t);\n\t\tdata.set(x,p,t);\n\t\treturn p;\n\t}\n\tbool same(ll\
    \ x,ll y,node *t){\n\t\treturn find(x,t)==find(y,t);\n\t}\n\tll size(ll x,node\
    \ *t){\n\t\treturn data.get(find(x,t).first,t).second;\n\t}\n\tnode* merge(ll\
    \ x,ll y,node *t){\n\t\tP u=find(x,t),v=find(y,t);\n\t\tif(u.first==v.first)return\
    \ new node(*t);\n\t\tif(u.second>v.second)swap(u,v);\n\t\tnode *res=data.set(u.first,{v.first,u.second},t);\n\
    \t\tnode *res2=data.set(v.first,{v.first,u.second+v.second},res);\n\t\tdelete(res);\n\
    \t\treturn res2;\n\t}\n\tnode* init(ll x){\n\t\tnode* root=new node();\n\t\trep(i,x){\n\
    \t\t\tdata.destructive_set(i,{i,1},root);\n\t\t}\n\t\treturn root;\n\t}\n};"
  dependsOn:
  - template/template.cpp
  - structure/PersistentArray.cpp
  isVerificationFile: false
  path: structure/PersistentUnionFind.cpp
  requiredBy: []
  timestamp: '2020-09-23 19:41:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/PersistentUnionFind.cpp
layout: document
redirect_from:
- /library/structure/PersistentUnionFind.cpp
- /library/structure/PersistentUnionFind.cpp.html
title: structure/PersistentUnionFind.cpp
---
