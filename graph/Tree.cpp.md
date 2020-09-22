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
    \ inf = 3e18;\n#line 3 \"graph/Tree.cpp\"\n\nstruct Tree{\n\tvector<int>depth;\n\
    \tvector<vector<int>>G;\n\tvector<int>par[20];\n\tvoid dfs(int x,int p){\n\t\t\
    for(int i:G[x])if(i!=p){\n\t\t\tdepth[i]=depth[x]+1;\n\t\t\tpar[0][i]=x;\n\t\t\
    \tdfs(i,x);\n\t\t}\n\t}\n\tint lca(int x,int y){\n\t\tif(depth[x]>depth[y])swap(x,y);\n\
    \t\trep(i,20)if((depth[y]-depth[x])>>i&1)y=par[i][y];\n\t\tif(x==y)return x;\n\
    \t\tfor(int i=19;i>=0;i--)if(par[i][x]!=par[i][y]){\n\t\t\tx=par[i][x];y=par[i][y];\n\
    \t\t}\n\t\treturn par[0][x];\n\t}\n\tTree(vector<vector<int>>G,int root=0):G(G){\n\
    \t\tint N=G.size();\n\t\tdepth.resize(N);\n\t\trep(i,20)par[i].resize(N);\n\t\t\
    dfs(root,root);\n\t\trep(i,19)rep(j,N){\n\t\t\tif(par[i][j]==-1)par[i+1][j]=-1;\n\
    \t\t\telse par[i+1][j]=par[i][par[i][j]];\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct Tree{\n\tvector<int>depth;\n\
    \tvector<vector<int>>G;\n\tvector<int>par[20];\n\tvoid dfs(int x,int p){\n\t\t\
    for(int i:G[x])if(i!=p){\n\t\t\tdepth[i]=depth[x]+1;\n\t\t\tpar[0][i]=x;\n\t\t\
    \tdfs(i,x);\n\t\t}\n\t}\n\tint lca(int x,int y){\n\t\tif(depth[x]>depth[y])swap(x,y);\n\
    \t\trep(i,20)if((depth[y]-depth[x])>>i&1)y=par[i][y];\n\t\tif(x==y)return x;\n\
    \t\tfor(int i=19;i>=0;i--)if(par[i][x]!=par[i][y]){\n\t\t\tx=par[i][x];y=par[i][y];\n\
    \t\t}\n\t\treturn par[0][x];\n\t}\n\tTree(vector<vector<int>>G,int root=0):G(G){\n\
    \t\tint N=G.size();\n\t\tdepth.resize(N);\n\t\trep(i,20)par[i].resize(N);\n\t\t\
    dfs(root,root);\n\t\trep(i,19)rep(j,N){\n\t\t\tif(par[i][j]==-1)par[i+1][j]=-1;\n\
    \t\t\telse par[i+1][j]=par[i][par[i][j]];\n\t\t}\n\t}\n};"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: graph/Tree.cpp
  requiredBy: []
  timestamp: '2020-09-22 11:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Tree.cpp
layout: document
redirect_from:
- /library/graph/Tree.cpp
- /library/graph/Tree.cpp.html
title: graph/Tree.cpp
---
