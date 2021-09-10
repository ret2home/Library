---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i <\
    \ n; i++)\n#define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n\
    #define all(v) v.begin(), v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,int>\n\
    #define len(s) (int)s.size()\n#define compress(v) sort(all(v)); v.erase(unique(all(v)),v.end());\n\
    #define comid(v,x) lower_bound(all(v),x)-v.begin()\n\ntemplate <class T, class\
    \ U>\ninline bool chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n     \
    \   return true;\n    }\n    return false;\n}\ntemplate <class T, class U>\ninline\
    \ bool chmax(T &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/HLD.cpp\"\
    \n\nstruct HLD{\n    vector<vector<int>>G;\n    vector<int>sz,in,out,top,par,depth;\n\
    \    void dfs_sz(int x,int p){\n        sz[x]=1;\n        int mx=0;\n        for(int\
    \ &i:G[x])if(i!=p){\n            dfs_sz(i,x);\n            sz[x]+=sz[i];\n   \
    \         if(chmax(mx,sz[i]))swap(G[x][0],i);\n        }\n    }\n    int t=0;\n\
    \    void dfs_hld(int x,int p){\n        in[x]=t++;\n        for(int i:G[x])if(i!=p){\n\
    \            if(i!=G[x][0]){\n                par[i]=x;\n                top[i]=i;\n\
    \                depth[i]=depth[x]+1;\n            }else {\n                par[i]=par[x];\n\
    \                top[i]=top[x];\n                depth[i]=depth[x];\n        \
    \    }\n            dfs_hld(i,x);\n        }\n        out[x]=t;\n    }\n    HLD(vector<vector<int>>&G):G(G){\n\
    \        int N=len(G);\n        sz.resize(N);\n        in.resize(N);out.resize(N);\n\
    \        par.resize(N);top.resize(N);depth.resize(N);\n        dfs_sz(0,0);dfs_hld(0,0);\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct HLD{\n    vector<vector<int>>G;\n\
    \    vector<int>sz,in,out,top,par,depth;\n    void dfs_sz(int x,int p){\n    \
    \    sz[x]=1;\n        int mx=0;\n        for(int &i:G[x])if(i!=p){\n        \
    \    dfs_sz(i,x);\n            sz[x]+=sz[i];\n            if(chmax(mx,sz[i]))swap(G[x][0],i);\n\
    \        }\n    }\n    int t=0;\n    void dfs_hld(int x,int p){\n        in[x]=t++;\n\
    \        for(int i:G[x])if(i!=p){\n            if(i!=G[x][0]){\n             \
    \   par[i]=x;\n                top[i]=i;\n                depth[i]=depth[x]+1;\n\
    \            }else {\n                par[i]=par[x];\n                top[i]=top[x];\n\
    \                depth[i]=depth[x];\n            }\n            dfs_hld(i,x);\n\
    \        }\n        out[x]=t;\n    }\n    HLD(vector<vector<int>>&G):G(G){\n \
    \       int N=len(G);\n        sz.resize(N);\n        in.resize(N);out.resize(N);\n\
    \        par.resize(N);top.resize(N);depth.resize(N);\n        dfs_sz(0,0);dfs_hld(0,0);\n\
    \    }\n};"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/HLD.cpp
  requiredBy: []
  timestamp: '2021-09-10 20:00:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/HLD.cpp
layout: document
redirect_from:
- /library/structure/HLD.cpp
- /library/structure/HLD.cpp.html
title: structure/HLD.cpp
---
