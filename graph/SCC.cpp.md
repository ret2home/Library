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
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma\
    \ GCC optimization (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\n\
    using namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"graph/SCC.cpp\"\
    \n\nstruct SCC{\n\tvector<vector<ll>>G,rG;\n\tvector<bool>used;\n\tvector<ll>vs;\n\
    \tvoid addEdge(ll x,ll y){\n\t\tG[x].push_back(y);\n\t\trG[y].push_back(x);\n\t\
    }\n\tvoid dfs(ll x){\n\t\tused[x]=true;\n\t\tfor(ll i:G[x])if(!used[i])dfs(i);\n\
    \t\tvs.push_back(x);\n\t}\n\tvector<ll>cmp;\n\tvoid rdfs(ll v,ll k){\n\t\tused[v]=true;\n\
    \t\tcmp[v]=k;\n\t\tfor(ll i:rG[v])if(!used[i])rdfs(i,k);\n\t}\n\tvoid scc(){\n\
    \t\tfill(all(used),false);\n\t\trep(i,len(G))if(!used[i])dfs(i);\n\t\tfill(all(used),false);\n\
    \t\tll k=0;\n\t\trev(i,len(vs))if(!used[vs[i]])rdfs(vs[i],k++);\n\t}\n\tSCC(ll\
    \ N):G(N),rG(N),used(N),cmp(N){}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct SCC{\n\tvector<vector<ll>>G,rG;\n\
    \tvector<bool>used;\n\tvector<ll>vs;\n\tvoid addEdge(ll x,ll y){\n\t\tG[x].push_back(y);\n\
    \t\trG[y].push_back(x);\n\t}\n\tvoid dfs(ll x){\n\t\tused[x]=true;\n\t\tfor(ll\
    \ i:G[x])if(!used[i])dfs(i);\n\t\tvs.push_back(x);\n\t}\n\tvector<ll>cmp;\n\t\
    void rdfs(ll v,ll k){\n\t\tused[v]=true;\n\t\tcmp[v]=k;\n\t\tfor(ll i:rG[v])if(!used[i])rdfs(i,k);\n\
    \t}\n\tvoid scc(){\n\t\tfill(all(used),false);\n\t\trep(i,len(G))if(!used[i])dfs(i);\n\
    \t\tfill(all(used),false);\n\t\tll k=0;\n\t\trev(i,len(vs))if(!used[vs[i]])rdfs(vs[i],k++);\n\
    \t}\n\tSCC(ll N):G(N),rG(N),used(N),cmp(N){}\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: graph/SCC.cpp
  requiredBy: []
  timestamp: '2020-09-23 19:41:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/SCC.cpp
layout: document
redirect_from:
- /library/graph/SCC.cpp
- /library/graph/SCC.cpp.html
title: graph/SCC.cpp
---
