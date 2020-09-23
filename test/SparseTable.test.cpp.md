---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/SparseTable.cpp
    title: structure/SparseTable.cpp
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/SparseTable.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma GCC optimization\
    \ (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\nusing namespace std;\n\
    #define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n#define REP(i,n) for(ll\
    \ i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n#define all(v) v.begin(),v.end()\n\
    #define P pair<ll,ll>\n#define len(s) (ll)s.size()\n \ntemplate<class T> inline\
    \ bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\treturn false;\n}\ntemplate<class\
    \ T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return true;}\n\treturn false;\n\
    }\nconstexpr ll inf = 3e18;\n#line 3 \"structure/SparseTable.cpp\"\n\ntemplate<class\
    \ T,class F>\nstruct SparseTable{\n\tvector<T>table[20];\n\tvector<ll>log;\n\t\
    F f;\n\tSparseTable(vector<T>v,F f)\n\t:log(v.size()+1),f(f){\n\t\tll mx=0;\n\t\
    \twhile(1ll<<(mx+1)<=(ll)v.size())++mx;\n\t\trep(i,mx+1){\n\t\t\ttable[i].resize(v.size());\n\
    \t\t\trep(j,v.size()-(1<<i)+1){\n\t\t\t\tif(i)table[i][j]=f(table[i-1][j],table[i-1][j+(1ll<<(i-1))]);\n\
    \t\t\t\telse table[i][j]=v[j];\n\t\t\t}\n\t\t}\n\t\tfor(ll i=2;i<=(ll)v.size();i++)log[i]=log[i>>1]+1;\n\
    \t}\n\tT query(ll l,ll r){\n\t\treturn f(table[log[r-l]][l],table[log[r-l]][r-(1<<log[r-l])]);\n\
    \t}\n};\n#line 4 \"test/SparseTable.test.cpp\"\n\nint main(){\n\tint N,Q;cin>>N>>Q;\n\
    \tvector<int>V(N);\n\tfor(int &i:V)cin>>i;\n\tauto f=[](int a,int b)->int{return\
    \ min(a,b);};\n\tSparseTable<int,decltype(f)>ST(V,f);\n\twhile(Q--){\n\t\tint\
    \ l,r;cin>>l>>r;\n\t\tcout<<ST.query(l,r)<<\"\\n\";\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../structure/SparseTable.cpp\"\n\nint main(){\n\tint N,Q;cin>>N>>Q;\n\tvector<int>V(N);\n\
    \tfor(int &i:V)cin>>i;\n\tauto f=[](int a,int b)->int{return min(a,b);};\n\tSparseTable<int,decltype(f)>ST(V,f);\n\
    \twhile(Q--){\n\t\tint l,r;cin>>l>>r;\n\t\tcout<<ST.query(l,r)<<\"\\n\";\n\t}\n\
    }"
  dependsOn:
  - structure/SparseTable.cpp
  - template/template.cpp
  isVerificationFile: true
  path: test/SparseTable.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 21:18:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/SparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/SparseTable.test.cpp
- /verify/test/SparseTable.test.cpp.html
title: test/SparseTable.test.cpp
---
