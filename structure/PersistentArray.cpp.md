---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: structure/PersistentUnionFind.cpp
    title: structure/PersistentUnionFind.cpp
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
    \ inf = 3e18;\n#line 3 \"structure/PersistentArray.cpp\"\n\ntemplate<class T>\n\
    struct PersistentArray{\n\tstruct Node{\n\t\tT val;\n\t\tNode* ch[20];\n\t};\n\
    \tvoid destructive_set(int idx,T val,Node *&t){\n\t\tif(!t)t=new Node();\n\t\t\
    if(idx==0)t->val=val;\n\t\telse destructive_set(idx/20,val,t->ch[idx%20]);\n\t\
    }\n\tNode *set(int idx,T val,Node *t){\n\t\tNode *res=(t?new Node(*t):new Node());\n\
    \t\tif(idx==0)res->val=val;\n\t\telse res->ch[idx%20]=set(idx/20,val,res->ch[idx%20]);\n\
    \t\treturn res;\n\t}\n\tT get(int idx,Node *t){\n\t\tassert(t);\n\t\tif(!idx)return\
    \ t->val;\n\t\treturn get(idx/20,t->ch[idx%20]);\n\t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<class T>\n\
    struct PersistentArray{\n\tstruct Node{\n\t\tT val;\n\t\tNode* ch[20];\n\t};\n\
    \tvoid destructive_set(int idx,T val,Node *&t){\n\t\tif(!t)t=new Node();\n\t\t\
    if(idx==0)t->val=val;\n\t\telse destructive_set(idx/20,val,t->ch[idx%20]);\n\t\
    }\n\tNode *set(int idx,T val,Node *t){\n\t\tNode *res=(t?new Node(*t):new Node());\n\
    \t\tif(idx==0)res->val=val;\n\t\telse res->ch[idx%20]=set(idx/20,val,res->ch[idx%20]);\n\
    \t\treturn res;\n\t}\n\tT get(int idx,Node *t){\n\t\tassert(t);\n\t\tif(!idx)return\
    \ t->val;\n\t\treturn get(idx/20,t->ch[idx%20]);\n\t}\n};"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/PersistentArray.cpp
  requiredBy:
  - structure/PersistentUnionFind.cpp
  timestamp: '2020-09-22 11:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/PersistentArray.cpp
layout: document
redirect_from:
- /library/structure/PersistentArray.cpp
- /library/structure/PersistentArray.cpp.html
title: structure/PersistentArray.cpp
---
