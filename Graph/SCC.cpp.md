---
data:
  _extendedDependsOn:
  - icon: ':warning:'
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
    \ inf = 3e18;\n#line 3 \"Graph/SCC.cpp\"\n\nstruct SCC{\n\tvector<vector<int>>G,rG;\n\
    \tvector<bool>used;\n\tvector<int>vs;\n\tvoid addEdge(int x,int y){\n\t\tG[x].push_back(y);\n\
    \t\trG[y].push_back(x);\n\t}\n\tvoid dfs(int x){\n\t\tused[x]=true;\n\t\tfor(int\
    \ i:G[x])if(!used[i])dfs(i);\n\t\tvs.push_back(x);\n\t}\n\tvector<int>cmp;\n\t\
    void rdfs(int v,int k){\n\t\tused[v]=true;\n\t\tcmp[v]=k;\n\t\tfor(int i:rG[v])if(!used[i])rdfs(i,k);\n\
    \t}\n\tvoid scc(){\n\t\tfill(all(used),false);\n\t\trep(i,len(G))if(!used[i])dfs(i);\n\
    \t\tfill(all(used),false);\n\t\tint k=0;\n\t\trev(i,len(vs))if(!used[vs[i]])rdfs(vs[i],k++);\n\
    \t}\n\tSCC(int N):G(N),rG(N),used(N),cmp(N){}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct SCC{\n\tvector<vector<int>>G,rG;\n\
    \tvector<bool>used;\n\tvector<int>vs;\n\tvoid addEdge(int x,int y){\n\t\tG[x].push_back(y);\n\
    \t\trG[y].push_back(x);\n\t}\n\tvoid dfs(int x){\n\t\tused[x]=true;\n\t\tfor(int\
    \ i:G[x])if(!used[i])dfs(i);\n\t\tvs.push_back(x);\n\t}\n\tvector<int>cmp;\n\t\
    void rdfs(int v,int k){\n\t\tused[v]=true;\n\t\tcmp[v]=k;\n\t\tfor(int i:rG[v])if(!used[i])rdfs(i,k);\n\
    \t}\n\tvoid scc(){\n\t\tfill(all(used),false);\n\t\trep(i,len(G))if(!used[i])dfs(i);\n\
    \t\tfill(all(used),false);\n\t\tint k=0;\n\t\trev(i,len(vs))if(!used[vs[i]])rdfs(vs[i],k++);\n\
    \t}\n\tSCC(int N):G(N),rG(N),used(N),cmp(N){}\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: Graph/SCC.cpp
  requiredBy: []
  timestamp: '2020-09-19 18:34:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/SCC.cpp
layout: document
redirect_from:
- /library/Graph/SCC.cpp
- /library/Graph/SCC.cpp.html
title: Graph/SCC.cpp
---
