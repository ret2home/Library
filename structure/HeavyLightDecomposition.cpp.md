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
    using namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/HeavyLightDecomposition.cpp\"\
    \n\nstruct HLD{\n\tusing V=vector<pair<ll,P>>;\n\tstruct heavy_set{\n\t\tvector<ll>ele;\n\
    \t\tll depth,par,cost1=1,cost2=1;\n\t\theavy_set(ll v,ll d,ll par)\n\t\t:ele(1,v),depth(d),par(par){}\n\
    \t};\n\tvector<vector<ll>>G;\n\tvector<heavy_set>S;\n\tvector<ll>subsize,stidx,eleidx;\n\
    \tll subtree(ll v,ll p){\n\t\tll &sz=subsize[v];\n\t\tif(sz)return sz;\n\t\tsz=1;\n\
    \t\tfor(ll i:G[v])if(i!=p)sz+=subtree(i,v);\n\t\treturn sz;\n\t}\n\tvoid make_path(ll\
    \ v,ll p,ll id){\n\t\tstidx[v]=id;\n\t\teleidx[v]=S[id].ele.size()-1;\n\t\tll\
    \ mxidx,mx=0;\n\t\tfor(ll i:G[v])if(i!=p){\n\t\t\tif(mx<subtree(i,v)){\n\t\t\t\
    \tmx=subtree(i,v);mxidx=i;\n\t\t\t}\n\t\t}\n\t\tfor(ll i:G[v])if(i!=p){\n\t\t\t\
    if(mxidx==i){\n\t\t\t\tS[id].ele.push_back(i);\n\t\t\t\tmake_path(i,v,id);\n\t\
    \t\t}else {\n\t\t\t\tS.emplace_back(i,S[id].depth+1,v);\n\t\t\t\tmake_path(i,v,S.size()-1);\n\
    \t\t\t}\n\t\t}\n\t}\n\tll st(ll v){return stidx[v];}\n\tll el(ll v){return eleidx[v];}\n\
    \tHLD(vector<vector<ll>>&G):G(G){\n\t\tll N=G.size();\n\t\tsubsize.resize(N);\n\
    \t\teleidx.resize(N);\n\t\tstidx.resize(N);\n\t\tS.emplace_back(0,0,0);\n\t\t\
    make_path(0,0,0);\n\t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct HLD{\n\tusing\
    \ V=vector<pair<ll,P>>;\n\tstruct heavy_set{\n\t\tvector<ll>ele;\n\t\tll depth,par,cost1=1,cost2=1;\n\
    \t\theavy_set(ll v,ll d,ll par)\n\t\t:ele(1,v),depth(d),par(par){}\n\t};\n\tvector<vector<ll>>G;\n\
    \tvector<heavy_set>S;\n\tvector<ll>subsize,stidx,eleidx;\n\tll subtree(ll v,ll\
    \ p){\n\t\tll &sz=subsize[v];\n\t\tif(sz)return sz;\n\t\tsz=1;\n\t\tfor(ll i:G[v])if(i!=p)sz+=subtree(i,v);\n\
    \t\treturn sz;\n\t}\n\tvoid make_path(ll v,ll p,ll id){\n\t\tstidx[v]=id;\n\t\t\
    eleidx[v]=S[id].ele.size()-1;\n\t\tll mxidx,mx=0;\n\t\tfor(ll i:G[v])if(i!=p){\n\
    \t\t\tif(mx<subtree(i,v)){\n\t\t\t\tmx=subtree(i,v);mxidx=i;\n\t\t\t}\n\t\t}\n\
    \t\tfor(ll i:G[v])if(i!=p){\n\t\t\tif(mxidx==i){\n\t\t\t\tS[id].ele.push_back(i);\n\
    \t\t\t\tmake_path(i,v,id);\n\t\t\t}else {\n\t\t\t\tS.emplace_back(i,S[id].depth+1,v);\n\
    \t\t\t\tmake_path(i,v,S.size()-1);\n\t\t\t}\n\t\t}\n\t}\n\tll st(ll v){return\
    \ stidx[v];}\n\tll el(ll v){return eleidx[v];}\n\tHLD(vector<vector<ll>>&G):G(G){\n\
    \t\tll N=G.size();\n\t\tsubsize.resize(N);\n\t\teleidx.resize(N);\n\t\tstidx.resize(N);\n\
    \t\tS.emplace_back(0,0,0);\n\t\tmake_path(0,0,0);\n\t}\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/HeavyLightDecomposition.cpp
  requiredBy: []
  timestamp: '2020-09-23 19:41:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/HeavyLightDecomposition.cpp
layout: document
redirect_from:
- /library/structure/HeavyLightDecomposition.cpp
- /library/structure/HeavyLightDecomposition.cpp.html
title: structure/HeavyLightDecomposition.cpp
---
