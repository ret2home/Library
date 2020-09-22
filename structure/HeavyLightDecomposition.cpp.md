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
    \ inf = 3e18;\n#line 3 \"structure/HeavyLightDecomposition.cpp\"\n\nstruct HLD{\n\
    \tusing V=vector<pair<int,P>>;\n\tstruct heavy_set{\n\t\tvector<int>ele;\n\t\t\
    int depth,par,cost1=1,cost2=1;\n\t\theavy_set(int v,int d,int par)\n\t\t:ele(1,v),depth(d),par(par){}\n\
    \t};\n\tvector<vector<int>>G;\n\tvector<heavy_set>S;\n\tvector<int>subsize,stidx,eleidx;\n\
    \tint subtree(int v,int p){\n\t\tint &sz=subsize[v];\n\t\tif(sz)return sz;\n\t\
    \tsz=1;\n\t\tfor(int i:G[v])if(i!=p)sz+=subtree(i,v);\n\t\treturn sz;\n\t}\n\t\
    void make_path(int v,int p,int id){\n\t\tstidx[v]=id;\n\t\teleidx[v]=S[id].ele.size()-1;\n\
    \t\tint mxidx,mx=0;\n\t\tfor(int i:G[v])if(i!=p){\n\t\t\tif(mx<subtree(i,v)){\n\
    \t\t\t\tmx=subtree(i,v);mxidx=i;\n\t\t\t}\n\t\t}\n\t\tfor(int i:G[v])if(i!=p){\n\
    \t\t\tif(mxidx==i){\n\t\t\t\tS[id].ele.push_back(i);\n\t\t\t\tmake_path(i,v,id);\n\
    \t\t\t}else {\n\t\t\t\tS.emplace_back(i,S[id].depth+1,v);\n\t\t\t\tmake_path(i,v,S.size()-1);\n\
    \t\t\t}\n\t\t}\n\t}\n\tint st(int v){return stidx[v];}\n\tint el(int v){return\
    \ eleidx[v];}\n\tHLD(vector<vector<int>>&G):G(G){\n\t\tint N=G.size();\n\t\tsubsize.resize(N);\n\
    \t\teleidx.resize(N);\n\t\tstidx.resize(N);\n\t\tS.emplace_back(0,0,0);\n\t\t\
    make_path(0,0,0);\n\t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct HLD{\n\tusing\
    \ V=vector<pair<int,P>>;\n\tstruct heavy_set{\n\t\tvector<int>ele;\n\t\tint depth,par,cost1=1,cost2=1;\n\
    \t\theavy_set(int v,int d,int par)\n\t\t:ele(1,v),depth(d),par(par){}\n\t};\n\t\
    vector<vector<int>>G;\n\tvector<heavy_set>S;\n\tvector<int>subsize,stidx,eleidx;\n\
    \tint subtree(int v,int p){\n\t\tint &sz=subsize[v];\n\t\tif(sz)return sz;\n\t\
    \tsz=1;\n\t\tfor(int i:G[v])if(i!=p)sz+=subtree(i,v);\n\t\treturn sz;\n\t}\n\t\
    void make_path(int v,int p,int id){\n\t\tstidx[v]=id;\n\t\teleidx[v]=S[id].ele.size()-1;\n\
    \t\tint mxidx,mx=0;\n\t\tfor(int i:G[v])if(i!=p){\n\t\t\tif(mx<subtree(i,v)){\n\
    \t\t\t\tmx=subtree(i,v);mxidx=i;\n\t\t\t}\n\t\t}\n\t\tfor(int i:G[v])if(i!=p){\n\
    \t\t\tif(mxidx==i){\n\t\t\t\tS[id].ele.push_back(i);\n\t\t\t\tmake_path(i,v,id);\n\
    \t\t\t}else {\n\t\t\t\tS.emplace_back(i,S[id].depth+1,v);\n\t\t\t\tmake_path(i,v,S.size()-1);\n\
    \t\t\t}\n\t\t}\n\t}\n\tint st(int v){return stidx[v];}\n\tint el(int v){return\
    \ eleidx[v];}\n\tHLD(vector<vector<int>>&G):G(G){\n\t\tint N=G.size();\n\t\tsubsize.resize(N);\n\
    \t\teleidx.resize(N);\n\t\tstidx.resize(N);\n\t\tS.emplace_back(0,0,0);\n\t\t\
    make_path(0,0,0);\n\t}\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/HeavyLightDecomposition.cpp
  requiredBy: []
  timestamp: '2020-09-22 11:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/HeavyLightDecomposition.cpp
layout: document
redirect_from:
- /library/structure/HeavyLightDecomposition.cpp
- /library/structure/HeavyLightDecomposition.cpp.html
title: structure/HeavyLightDecomposition.cpp
---
