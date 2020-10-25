---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/MaxFlow.test.cpp
    title: test/MaxFlow.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/MaxFlow.md
    document_title: Max Flow (Dinic)
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"graph/MaxFlow.cpp\"\
    \n\nstruct Dinic{\n\tstruct Edge{\n\t\tll to,cap,rev;\n\t};\n\tvector<vector<Edge>>G;\n\
    \tvector<ll>level,iter;\n\tvoid addEdge(ll from,ll to,ll cap){\n\t\tG[from].push_back({to,cap,len(G[to])});\n\
    \t\tG[to].push_back({from,0,len(G[from])-1});\n\t}\n\tvoid bfs(ll s){\n\t\tfill(all(level),-1);\n\
    \t\tlevel[s]=0;\n\t\tqueue<ll>que;que.push(s);\n\t\twhile(len(que)){\n\t\t\tll\
    \ p=que.front();que.pop();\n\t\t\tfor(Edge e:G[p]){\n\t\t\t\tif(e.cap>0&&level[e.to]==-1){\n\
    \t\t\t\t\tlevel[e.to]=level[p]+1;\n\t\t\t\t\tque.push(e.to);\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t}\n\tll dfs(ll v,ll t,ll f){\n\t\tif(v==t)return f;\n\t\tfor(ll &i=iter[v];i<len(G[v]);i++){\n\
    \t\t\tEdge &e=G[v][i];\n\t\t\tif(e.cap>0&&level[e.to]>level[v]){\n\t\t\t\tll d=dfs(e.to,t,min(f,e.cap));\n\
    \t\t\t\tif(d>0){\n\t\t\t\t\te.cap-=d;\n\t\t\t\t\tG[e.to][e.rev].cap+=d;\n\t\t\t\
    \t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\tll maxFlow(ll\
    \ s,ll t){\n\t\tll flow=0;\n\t\twhile(1){\n\t\t\tbfs(s);\n\t\t\tif(level[t]<0)return\
    \ flow;\n\t\t\tfill(all(iter),0);\n\t\t\tll f=0;\n\t\t\twhile((f=dfs(s,t,inf))>0){\n\
    \t\t\t\tflow+=f;\n\t\t\t}\n\t\t}\n\t}\n\tDinic(ll N):G(N),level(N),iter(N){}\n\
    };\n/*\n@brief Max Flow (Dinic)\n@docs docs/MaxFlow.md\n*/\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct Dinic{\n\t\
    struct Edge{\n\t\tll to,cap,rev;\n\t};\n\tvector<vector<Edge>>G;\n\tvector<ll>level,iter;\n\
    \tvoid addEdge(ll from,ll to,ll cap){\n\t\tG[from].push_back({to,cap,len(G[to])});\n\
    \t\tG[to].push_back({from,0,len(G[from])-1});\n\t}\n\tvoid bfs(ll s){\n\t\tfill(all(level),-1);\n\
    \t\tlevel[s]=0;\n\t\tqueue<ll>que;que.push(s);\n\t\twhile(len(que)){\n\t\t\tll\
    \ p=que.front();que.pop();\n\t\t\tfor(Edge e:G[p]){\n\t\t\t\tif(e.cap>0&&level[e.to]==-1){\n\
    \t\t\t\t\tlevel[e.to]=level[p]+1;\n\t\t\t\t\tque.push(e.to);\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t}\n\tll dfs(ll v,ll t,ll f){\n\t\tif(v==t)return f;\n\t\tfor(ll &i=iter[v];i<len(G[v]);i++){\n\
    \t\t\tEdge &e=G[v][i];\n\t\t\tif(e.cap>0&&level[e.to]>level[v]){\n\t\t\t\tll d=dfs(e.to,t,min(f,e.cap));\n\
    \t\t\t\tif(d>0){\n\t\t\t\t\te.cap-=d;\n\t\t\t\t\tG[e.to][e.rev].cap+=d;\n\t\t\t\
    \t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\tll maxFlow(ll\
    \ s,ll t){\n\t\tll flow=0;\n\t\twhile(1){\n\t\t\tbfs(s);\n\t\t\tif(level[t]<0)return\
    \ flow;\n\t\t\tfill(all(iter),0);\n\t\t\tll f=0;\n\t\t\twhile((f=dfs(s,t,inf))>0){\n\
    \t\t\t\tflow+=f;\n\t\t\t}\n\t\t}\n\t}\n\tDinic(ll N):G(N),level(N),iter(N){}\n\
    };\n/*\n@brief Max Flow (Dinic)\n@docs docs/MaxFlow.md\n*/"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: graph/MaxFlow.cpp
  requiredBy: []
  timestamp: '2020-10-25 14:09:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/MaxFlow.test.cpp
documentation_of: graph/MaxFlow.cpp
layout: document
redirect_from:
- /library/graph/MaxFlow.cpp
- /library/graph/MaxFlow.cpp.html
title: Max Flow (Dinic)
---
## 概要

最大流アルゴリズム、Dinicの実装。~~フロー速いんだけど微妙にバグる~~

- ```addEdge(from,to,cap)``` : ```from``` -> ```to``` に 容量 ```cap``` の辺を張る
- ```maxFlow(from,to)``` : ```from``` -> ```to``` の最大流

## 計算量

- ```addEdge``` : $O(1)$
- ```maxFlow``` : $O(E\ V^2)$ だが、実際にはもっと軽いらしい

Dinic を使った二部マッチングは $O(V \sqrt V)$ 