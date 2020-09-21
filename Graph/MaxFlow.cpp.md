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
    \ inf = 3e18;\n#line 3 \"Graph/MaxFlow.cpp\"\n\nstruct Dinic{\n\tstruct Edge{int\
    \ to,cap,rev;};\n\tvector<vector<Edge>>G;\n\tvector<int>level,iter;\n\tvoid addEdge(int\
    \ from,int to,int cap){\n\t\tG[from].push_back({to,cap,len(G[to])});\n\t\tG[to].push_back({from,0,len(G[from])-1});\n\
    \t}\n\tvoid bfs(int s){\n\t\tfill(all(level),-1);\n\t\tlevel[s]=0;\n\t\tqueue<int>que;que.push(s);\n\
    \t\twhile(len(que)){\n\t\t\tint p=que.front();que.pop();\n\t\t\tfor(Edge e:G[p]){\n\
    \t\t\t\tif(e.cap>0&&level[e.to]==-1){\n\t\t\t\t\tlevel[e.to]=level[p]+1;\n\t\t\
    \t\t\tque.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tint dfs(int v,int t,int\
    \ f){\n\t\tif(v==t)return f;\n\t\tfor(int &i=iter[v];i<len(G[v]);i++){\n\t\t\t\
    Edge &e=G[v][i];\n\t\t\tif(e.cap>0&&level[e.to]>level[v]){\n\t\t\t\tint d=dfs(e.to,t,min(f,e.cap));\n\
    \t\t\t\tif(d>0){\n\t\t\t\t\te.cap-=d;\n\t\t\t\t\tG[e.to][e.rev].cap+=d;\n\t\t\t\
    \t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\tint maxFlow(int\
    \ s,int t){\n\t\tint flow=0;\n\t\twhile(1){\n\t\t\tbfs(s);\n\t\t\tif(level[t]<0)return\
    \ flow;\n\t\t\tfill(all(iter),0);\n\t\t\tint f=0;\n\t\t\twhile((f=dfs(s,t,inf))>0){\n\
    \t\t\t\tflow+=f;\n\t\t\t}\n\t\t}\n\t}\n\tDinic(int N):G(N),level(N),iter(N){}\n\
    };\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct Dinic{\n\t\
    struct Edge{int to,cap,rev;};\n\tvector<vector<Edge>>G;\n\tvector<int>level,iter;\n\
    \tvoid addEdge(int from,int to,int cap){\n\t\tG[from].push_back({to,cap,len(G[to])});\n\
    \t\tG[to].push_back({from,0,len(G[from])-1});\n\t}\n\tvoid bfs(int s){\n\t\tfill(all(level),-1);\n\
    \t\tlevel[s]=0;\n\t\tqueue<int>que;que.push(s);\n\t\twhile(len(que)){\n\t\t\t\
    int p=que.front();que.pop();\n\t\t\tfor(Edge e:G[p]){\n\t\t\t\tif(e.cap>0&&level[e.to]==-1){\n\
    \t\t\t\t\tlevel[e.to]=level[p]+1;\n\t\t\t\t\tque.push(e.to);\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t}\n\tint dfs(int v,int t,int f){\n\t\tif(v==t)return f;\n\t\tfor(int\
    \ &i=iter[v];i<len(G[v]);i++){\n\t\t\tEdge &e=G[v][i];\n\t\t\tif(e.cap>0&&level[e.to]>level[v]){\n\
    \t\t\t\tint d=dfs(e.to,t,min(f,e.cap));\n\t\t\t\tif(d>0){\n\t\t\t\t\te.cap-=d;\n\
    \t\t\t\t\tG[e.to][e.rev].cap+=d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t\treturn 0;\n\t}\n\tint maxFlow(int s,int t){\n\t\tint flow=0;\n\t\twhile(1){\n\
    \t\t\tbfs(s);\n\t\t\tif(level[t]<0)return flow;\n\t\t\tfill(all(iter),0);\n\t\t\
    \tint f=0;\n\t\t\twhile((f=dfs(s,t,inf))>0){\n\t\t\t\tflow+=f;\n\t\t\t}\n\t\t\
    }\n\t}\n\tDinic(int N):G(N),level(N),iter(N){}\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: Graph/MaxFlow.cpp
  requiredBy: []
  timestamp: '2020-09-09 21:48:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/MaxFlow.cpp
layout: document
redirect_from:
- /library/Graph/MaxFlow.cpp
- /library/Graph/MaxFlow.cpp.html
title: Graph/MaxFlow.cpp
---
