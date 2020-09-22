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
    \ inf = 3e18;\n#line 3 \"graph/MinCostFlow.cpp\"\n\nstruct PrimalDual{\n\tstruct\
    \ edge{\n\t\tint to,cap,cost,rev;\n\t};\n\tvector<vector<edge>>graph;\n\tbool\
    \ negative=false;\n\tvoid add_edge(int from,int to,int cap,int cost){\n\t\tgraph[from].push_back({to,cap,cost,len(graph[to])});\n\
    \t\tgraph[to].push_back({from,0ll,-cost,len(graph[from])-1});\n\t\tif(cost<0)negative=true;\n\
    \t}\n\tint minCostFlow(int s,int t,int f){\n\t\tint V=len(graph);\n\t\tvector<int>potential(V),minCost,prevv(V,-1),preve(V,-1);\n\
    \t\tint res=0;\n\t\tif(negative){\n\t\t\tminCost.assign(V,inf);\n\t\t\tminCost[s]=0;\n\
    \t\t\trep(_,V-1){\n\t\t\t\trep(i,V){\n\t\t\t\t\trep(j,len(graph[i])){\n\t\t\t\t\
    \t\tedge &e=graph[i][j];\n\t\t\t\t\t\tif(e.cap>0&&chmin(minCost[e.to],minCost[i]+e.cost+potential[i]-potential[e.to])){\n\
    \t\t\t\t\t\t\tprevv[e.to]=i;\n\t\t\t\t\t\t\tpreve[e.to]=j;\n\t\t\t\t\t\t}\n\t\t\
    \t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(minCost[t]==inf)return -1;\n\t\t\trep(i,V)potential[i]+=minCost[i];\n\
    \t\t\tfor(int i=t;i!=s;i=prevv[i]){\n\t\t\t\tgraph[prevv[i]][preve[i]].cap--;\n\
    \t\t\t\tgraph[i][graph[prevv[i]][preve[i]].rev].cap++;\n\t\t\t}\n\t\t\tres+=potential[t];\n\
    \t\t\tf--;\n\t\t}\n\n\t\twhile(f>0){\n\t\t\tminCost.assign(V,inf);\n\t\t\tminCost[s]=0;\n\
    \t\t\tpriority_queue<P,vector<P>,greater<>>que;\n\t\t\tque.push({0,s});\n\t\t\t\
    while(!que.empty()){\n\t\t\t\tP p=que.top();que.pop();\n\t\t\t\tif(minCost[p.second]<p.first)continue;\n\
    \t\t\t\trep(i,len(graph[p.second])){\n\t\t\t\t\tedge &e=graph[p.second][i];\n\t\
    \t\t\t\tif(e.cap>0&&chmin(minCost[e.to],p.first+e.cost+potential[p.second]-potential[e.to])){\n\
    \t\t\t\t\t\tprevv[e.to]=p.second;\n\t\t\t\t\t\tpreve[e.to]=i;\n\t\t\t\t\t\tque.push({minCost[e.to],e.to});\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\n\t\t\tif(minCost[t]==inf)return -1;\n\t\t\t\
    rep(i,V)potential[i]+=minCost[i];\n\t\t\tint addflow=f;\n\t\t\tfor(int i=t;i!=s;i=prevv[i])chmin(addflow,graph[prevv[i]][preve[i]].cap);\n\
    \t\t\tf-=addflow;\n\t\t\tres+=addflow*potential[t];\n\t\t\tfor(int i=t;i!=s;i=prevv[i]){\n\
    \t\t\t\tedge &e=graph[prevv[i]][preve[i]];\n\t\t\t\te.cap-=addflow;\n\t\t\t\t\
    graph[i][e.rev].cap+=addflow;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tPrimalDual(int\
    \ V):graph(V){};\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct PrimalDual{\n\
    \tstruct edge{\n\t\tint to,cap,cost,rev;\n\t};\n\tvector<vector<edge>>graph;\n\
    \tbool negative=false;\n\tvoid add_edge(int from,int to,int cap,int cost){\n\t\
    \tgraph[from].push_back({to,cap,cost,len(graph[to])});\n\t\tgraph[to].push_back({from,0ll,-cost,len(graph[from])-1});\n\
    \t\tif(cost<0)negative=true;\n\t}\n\tint minCostFlow(int s,int t,int f){\n\t\t\
    int V=len(graph);\n\t\tvector<int>potential(V),minCost,prevv(V,-1),preve(V,-1);\n\
    \t\tint res=0;\n\t\tif(negative){\n\t\t\tminCost.assign(V,inf);\n\t\t\tminCost[s]=0;\n\
    \t\t\trep(_,V-1){\n\t\t\t\trep(i,V){\n\t\t\t\t\trep(j,len(graph[i])){\n\t\t\t\t\
    \t\tedge &e=graph[i][j];\n\t\t\t\t\t\tif(e.cap>0&&chmin(minCost[e.to],minCost[i]+e.cost+potential[i]-potential[e.to])){\n\
    \t\t\t\t\t\t\tprevv[e.to]=i;\n\t\t\t\t\t\t\tpreve[e.to]=j;\n\t\t\t\t\t\t}\n\t\t\
    \t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(minCost[t]==inf)return -1;\n\t\t\trep(i,V)potential[i]+=minCost[i];\n\
    \t\t\tfor(int i=t;i!=s;i=prevv[i]){\n\t\t\t\tgraph[prevv[i]][preve[i]].cap--;\n\
    \t\t\t\tgraph[i][graph[prevv[i]][preve[i]].rev].cap++;\n\t\t\t}\n\t\t\tres+=potential[t];\n\
    \t\t\tf--;\n\t\t}\n\n\t\twhile(f>0){\n\t\t\tminCost.assign(V,inf);\n\t\t\tminCost[s]=0;\n\
    \t\t\tpriority_queue<P,vector<P>,greater<>>que;\n\t\t\tque.push({0,s});\n\t\t\t\
    while(!que.empty()){\n\t\t\t\tP p=que.top();que.pop();\n\t\t\t\tif(minCost[p.second]<p.first)continue;\n\
    \t\t\t\trep(i,len(graph[p.second])){\n\t\t\t\t\tedge &e=graph[p.second][i];\n\t\
    \t\t\t\tif(e.cap>0&&chmin(minCost[e.to],p.first+e.cost+potential[p.second]-potential[e.to])){\n\
    \t\t\t\t\t\tprevv[e.to]=p.second;\n\t\t\t\t\t\tpreve[e.to]=i;\n\t\t\t\t\t\tque.push({minCost[e.to],e.to});\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\n\t\t\tif(minCost[t]==inf)return -1;\n\t\t\t\
    rep(i,V)potential[i]+=minCost[i];\n\t\t\tint addflow=f;\n\t\t\tfor(int i=t;i!=s;i=prevv[i])chmin(addflow,graph[prevv[i]][preve[i]].cap);\n\
    \t\t\tf-=addflow;\n\t\t\tres+=addflow*potential[t];\n\t\t\tfor(int i=t;i!=s;i=prevv[i]){\n\
    \t\t\t\tedge &e=graph[prevv[i]][preve[i]];\n\t\t\t\te.cap-=addflow;\n\t\t\t\t\
    graph[i][e.rev].cap+=addflow;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tPrimalDual(int\
    \ V):graph(V){};\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: graph/MinCostFlow.cpp
  requiredBy: []
  timestamp: '2020-09-22 11:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/MinCostFlow.cpp
layout: document
redirect_from:
- /library/graph/MinCostFlow.cpp
- /library/graph/MinCostFlow.cpp.html
title: graph/MinCostFlow.cpp
---
