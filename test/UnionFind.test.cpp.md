---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.cpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/UnionFind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma GCC optimization\
    \ (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\nusing namespace std;\n\
    #define int long long\n#define rep(i,n) for(int i=0;i<n;i++)\n#define REP(i,n)\
    \ for(int i=1;i<n;i++)\n#define rev(i,n) for(int i=n-1;i>=0;i--)\n#define all(v)\
    \ v.begin(),v.end()\n#define P pair<int,int>\n#define len(s) (int)s.size()\n \n\
    template<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr int mod = 1e9+7;\nconstexpr long long\
    \ inf = 3e18;\n#line 3 \"structure/UnionFind.cpp\"\n\nclass UnionFind{\n\tusing\
    \ size_type=int32_t;\n\tsize_type N;\n\tvector<size_type>par,siz;\npublic:\n\t\
    size_type find(size_type x){\n\t\tassert(x<N);\n\t\treturn (par[x]==x?x:par[x]=find(par[x]));\n\
    \t}\n\tvoid merge(size_type x,size_type y){\n\t\tassert(x<N&&y<N);\n\t\tx=find(x);y=find(y);\n\
    \t\tif(x==y)return;\n\t\tif(siz[x]>siz[y])swap(x,y);\n\t\tpar[x]=y;siz[y]+=siz[x];\n\
    \t}\n\tbool same(size_type x,size_type y){\n\t\treturn find(x)==find(y);\n\t}\n\
    \tsize_type size(size_type x){\n\t\treturn siz[find(x)];\n\t}\n\tUnionFind(size_type\
    \ N):N(N),siz(N,1),par(N){\n\t\tiota(all(par),0);\n\t}\n};\n#line 4 \"test/UnionFind.test.cpp\"\
    \n\nint N,Q;\nsigned main(){\n    cin>>N>>Q;\n    UnionFind uf(N);\n    while(Q--){\n\
    \        int t,u,v;cin>>t>>u>>v;\n        if(!t)uf.merge(u,v);\n        else cout<<uf.same(u,v)<<\"\
    \\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../structure/UnionFind.cpp\"\n\nint N,Q;\nsigned main(){\n    cin>>N>>Q;\n\
    \    UnionFind uf(N);\n    while(Q--){\n        int t,u,v;cin>>t>>u>>v;\n    \
    \    if(!t)uf.merge(u,v);\n        else cout<<uf.same(u,v)<<\"\\n\";\n    }\n}"
  dependsOn:
  - structure/UnionFind.cpp
  - template/template.cpp
  isVerificationFile: true
  path: test/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 12:45:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/UnionFind.test.cpp
- /verify/test/UnionFind.test.cpp.html
title: test/UnionFind.test.cpp
---
