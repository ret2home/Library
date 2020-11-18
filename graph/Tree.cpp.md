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
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T,class U> inline bool chmin(T &a, U b){\n\tif(a>b){a=b;return\
    \ true;}\n\treturn false;\n}\ntemplate<class T,class U> inline bool chmax(T &a,\
    \ U b){\n\tif(a<b){a=b;return true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n\
    #line 3 \"graph/Tree.cpp\"\n\nstruct Tree{\n\tvector<int>depth,sub;\n\tvector<vector<int>>G;\n\
    \tvector<int>par[20];\n\tvoid dfs(int x,int p){\n\t\tsub[x]=1;\n\t\tfor(int i:G[x])if(i!=p){\n\
    \t\t\tdepth[i]=depth[x]+1;\n\t\t\tpar[0][i]=x;\n\t\t\tdfs(i,x);\n\t\t\tsub[x]+=sub[i];\n\
    \t\t}\n\t}\n\tint lca(int x,int y){\n\t\tif(depth[x]>depth[y])swap(x,y);\n\t\t\
    rep(i,20)if((depth[y]-depth[x])>>i&1)y=par[i][y];\n\t\tif(x==y)return x;\n\t\t\
    for(int i=19;i>=0;i--)if(par[i][x]!=par[i][y]){\n\t\t\tx=par[i][x];y=par[i][y];\n\
    \t\t}\n\t\treturn par[0][x];\n\t}\n\tTree(vector<vector<int>>G,int root=0):G(G){\n\
    \t\tint N=G.size();\n\t\tdepth.resize(N);sub.resize(N);\n\t\trep(i,20)par[i].resize(N);\n\
    \t\tdfs(root,root);\n\t\trep(i,19)rep(j,N){\n\t\t\tif(par[i][j]==-1)par[i+1][j]=-1;\n\
    \t\t\telse par[i+1][j]=par[i][par[i][j]];\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct Tree{\n\tvector<int>depth,sub;\n\
    \tvector<vector<int>>G;\n\tvector<int>par[20];\n\tvoid dfs(int x,int p){\n\t\t\
    sub[x]=1;\n\t\tfor(int i:G[x])if(i!=p){\n\t\t\tdepth[i]=depth[x]+1;\n\t\t\tpar[0][i]=x;\n\
    \t\t\tdfs(i,x);\n\t\t\tsub[x]+=sub[i];\n\t\t}\n\t}\n\tint lca(int x,int y){\n\t\
    \tif(depth[x]>depth[y])swap(x,y);\n\t\trep(i,20)if((depth[y]-depth[x])>>i&1)y=par[i][y];\n\
    \t\tif(x==y)return x;\n\t\tfor(int i=19;i>=0;i--)if(par[i][x]!=par[i][y]){\n\t\
    \t\tx=par[i][x];y=par[i][y];\n\t\t}\n\t\treturn par[0][x];\n\t}\n\tTree(vector<vector<int>>G,int\
    \ root=0):G(G){\n\t\tint N=G.size();\n\t\tdepth.resize(N);sub.resize(N);\n\t\t\
    rep(i,20)par[i].resize(N);\n\t\tdfs(root,root);\n\t\trep(i,19)rep(j,N){\n\t\t\t\
    if(par[i][j]==-1)par[i+1][j]=-1;\n\t\t\telse par[i+1][j]=par[i][par[i][j]];\n\t\
    \t}\n\t}\n};"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: graph/Tree.cpp
  requiredBy: []
  timestamp: '2020-11-18 20:02:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Tree.cpp
layout: document
redirect_from:
- /library/graph/Tree.cpp
- /library/graph/Tree.cpp.html
title: graph/Tree.cpp
---
