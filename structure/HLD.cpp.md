---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T,class U> inline bool chmin(T &a, U b){\n\tif(a>b){a=b;return\
    \ true;}\n\treturn false;\n}\ntemplate<class T,class U> inline bool chmax(T &a,\
    \ U b){\n\tif(a<b){a=b;return true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n\
    #line 3 \"structure/HLD.cpp\"\n\nstruct HLD{\n\tstruct heavy_set{\n\t\tvector<int>ele;\n\
    \t\tint depth,par,cost1=0,cost2=0;\n\t\theavy_set(int v,int d,int par)\n\t\t:ele(1,v),depth(d),par(par){}\n\
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
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct HLD{\n\tstruct\
    \ heavy_set{\n\t\tvector<int>ele;\n\t\tint depth,par,cost1=0,cost2=0;\n\t\theavy_set(int\
    \ v,int d,int par)\n\t\t:ele(1,v),depth(d),par(par){}\n\t};\n\tvector<vector<int>>G;\n\
    \tvector<heavy_set>S;\n\tvector<int>subsize,stidx,eleidx;\n\tint subtree(int v,int\
    \ p){\n\t\tint &sz=subsize[v];\n\t\tif(sz)return sz;\n\t\tsz=1;\n\t\tfor(int i:G[v])if(i!=p)sz+=subtree(i,v);\n\
    \t\treturn sz;\n\t}\n\tvoid make_path(int v,int p,int id){\n\t\tstidx[v]=id;\n\
    \t\teleidx[v]=S[id].ele.size()-1;\n\t\tint mxidx,mx=0;\n\t\tfor(int i:G[v])if(i!=p){\n\
    \t\t\tif(mx<subtree(i,v)){\n\t\t\t\tmx=subtree(i,v);mxidx=i;\n\t\t\t}\n\t\t}\n\
    \t\tfor(int i:G[v])if(i!=p){\n\t\t\tif(mxidx==i){\n\t\t\t\tS[id].ele.push_back(i);\n\
    \t\t\t\tmake_path(i,v,id);\n\t\t\t}else {\n\t\t\t\tS.emplace_back(i,S[id].depth+1,v);\n\
    \t\t\t\tmake_path(i,v,S.size()-1);\n\t\t\t}\n\t\t}\n\t}\n\tint st(int v){return\
    \ stidx[v];}\n\tint el(int v){return eleidx[v];}\n\tHLD(vector<vector<int>>&G):G(G){\n\
    \t\tint N=G.size();\n\t\tsubsize.resize(N);\n\t\teleidx.resize(N);\n\t\tstidx.resize(N);\n\
    \t\tS.emplace_back(0,0,0);\n\t\tmake_path(0,0,0);\n\t}\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/HLD.cpp
  requiredBy: []
  timestamp: '2020-11-18 20:02:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/HLD.cpp
layout: document
redirect_from:
- /library/structure/HLD.cpp
- /library/structure/HLD.cpp.html
title: structure/HLD.cpp
---
