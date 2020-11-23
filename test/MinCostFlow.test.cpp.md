---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/MinCostFlow.cpp
    title: Min Cost Flow (Primal Dual)
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B
  bundledCode: "#line 1 \"test/MinCostFlow.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B\"\
    \n\n#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n#define REP(i,n)\
    \ for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n#define all(v)\
    \ v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n \ntemplate<class\
    \ T,class U> inline bool chmin(T &a, U b){\n\tif(a>b){a=b;return true;}\n\treturn\
    \ false;\n}\ntemplate<class T,class U> inline bool chmax(T &a, U b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"graph/MinCostFlow.cpp\"\
    \n\nstruct PrimalDual{\n\tstruct edge{\n\t\tll to,cap,cost,rev;\n\t};\n\tvector<vector<edge>>graph;\n\
    \tbool negative=false;\n\tvoid add_edge(ll from,ll to,ll cap,ll cost){\n\t\tgraph[from].push_back({to,cap,cost,len(graph[to])});\n\
    \t\tgraph[to].push_back({from,0ll,-cost,len(graph[from])-1});\n\t\tif(cost<0)negative=true;\n\
    \t}\n\tll minCostFlow(ll s,ll t,ll f){\n\t\tll V=len(graph);\n\t\tvector<ll>potential(V),minCost,prevv(V,-1),preve(V,-1);\n\
    \t\tll res=0;\n\t\tif(negative){\n\t\t\tminCost.assign(V,inf);\n\t\t\tminCost[s]=0;\n\
    \t\t\trep(_,V-1){\n\t\t\t\trep(i,V){\n\t\t\t\t\trep(j,len(graph[i])){\n\t\t\t\t\
    \t\tedge &e=graph[i][j];\n\t\t\t\t\t\tif(e.cap>0&&chmin(minCost[e.to],minCost[i]+e.cost+potential[i]-potential[e.to])){\n\
    \t\t\t\t\t\t\tprevv[e.to]=i;\n\t\t\t\t\t\t\tpreve[e.to]=j;\n\t\t\t\t\t\t}\n\t\t\
    \t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(minCost[t]==inf)return -1;\n\t\t\trep(i,V)potential[i]+=minCost[i];\n\
    \t\t\tfor(ll i=t;i!=s;i=prevv[i]){\n\t\t\t\tgraph[prevv[i]][preve[i]].cap--;\n\
    \t\t\t\tgraph[i][graph[prevv[i]][preve[i]].rev].cap++;\n\t\t\t}\n\t\t\tres+=potential[t];\n\
    \t\t\tf--;\n\t\t}\n\n\t\twhile(f>0){\n\t\t\tminCost.assign(V,inf);\n\t\t\tminCost[s]=0;\n\
    \t\t\tpriority_queue<P,vector<P>,greater<>>que;\n\t\t\tque.push({0,s});\n\t\t\t\
    while(!que.empty()){\n\t\t\t\tP p=que.top();que.pop();\n\t\t\t\tif(minCost[p.second]<p.first)continue;\n\
    \t\t\t\trep(i,len(graph[p.second])){\n\t\t\t\t\tedge &e=graph[p.second][i];\n\t\
    \t\t\t\tif(e.cap>0&&chmin(minCost[e.to],p.first+e.cost+potential[p.second]-potential[e.to])){\n\
    \t\t\t\t\t\tprevv[e.to]=p.second;\n\t\t\t\t\t\tpreve[e.to]=i;\n\t\t\t\t\t\tque.push({minCost[e.to],e.to});\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\n\t\t\tif(minCost[t]==inf)return -1;\n\t\t\t\
    rep(i,V)potential[i]+=minCost[i];\n\t\t\tll addflow=f;\n\t\t\tfor(ll i=t;i!=s;i=prevv[i])chmin(addflow,graph[prevv[i]][preve[i]].cap);\n\
    \t\t\tf-=addflow;\n\t\t\tres+=addflow*potential[t];\n\t\t\tfor(ll i=t;i!=s;i=prevv[i]){\n\
    \t\t\t\tedge &e=graph[prevv[i]][preve[i]];\n\t\t\t\te.cap-=addflow;\n\t\t\t\t\
    graph[i][e.rev].cap+=addflow;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tPrimalDual(ll\
    \ V):graph(V){};\n};\n/*\n@brief Min Cost Flow (Primal Dual)\n@docs docs/MinCostFlow.md\n\
    */\n#line 4 \"test/MinCostFlow.test.cpp\"\nint main(){\n    ll V,E,F;\n    cin>>V>>E>>F;\n\
    \    PrimalDual FL(V);\n    rep(i,E){\n        int u,v,c,d;cin>>u>>v>>c>>d;\n\
    \        FL.add_edge(u,v,c,d);\n    }\n    cout<<FL.minCostFlow(0,V-1,F)<<\"\\\
    n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B\"\
    \n\n#include \"../graph/MinCostFlow.cpp\"\nint main(){\n    ll V,E,F;\n    cin>>V>>E>>F;\n\
    \    PrimalDual FL(V);\n    rep(i,E){\n        int u,v,c,d;cin>>u>>v>>c>>d;\n\
    \        FL.add_edge(u,v,c,d);\n    }\n    cout<<FL.minCostFlow(0,V-1,F)<<\"\\\
    n\";\n}"
  dependsOn:
  - graph/MinCostFlow.cpp
  - template/template.cpp
  isVerificationFile: true
  path: test/MinCostFlow.test.cpp
  requiredBy: []
  timestamp: '2020-11-18 20:02:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/MinCostFlow.test.cpp
layout: document
redirect_from:
- /verify/test/MinCostFlow.test.cpp
- /verify/test/MinCostFlow.test.cpp.html
title: test/MinCostFlow.test.cpp
---
