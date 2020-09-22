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
    \ inf = 3e18;\n#line 3 \"structure/BIT.cpp\"\n\ntemplate<class T>\nclass BIT{\n\
    \tint N;\n\tvector<T>bit;\n\tvoid add_(int x,T y){\n\t\twhile(x<=N){\n\t\t\tbit[x]+=y;x+=x&-x;\n\
    \t\t}\n\t}\n\tT sum_(int x){\n\t\tT res=0;\n\t\twhile(x>0){\n\t\t\tres+=bit[x];x-=x&-x;\n\
    \t\t}\n\t\treturn res;\n\t}\npublic:\n\tint lower_bound(T w){\n\t\tif(w<=0)return\
    \ -1;\n\t\tint x=0;\n\t\tint k=1;while(k*2<=N)k*=2;\n\t\tfor(;k>0;k/=2){\n\t\t\
    \tif(x+k<=N&&bit[x+k]<w){\n\t\t\t\tw-=bit[x+k];\n\t\t\t\tx+=k;\n\t\t\t}\n\t\t\
    }\n\t\treturn x;\n\t}\n\tvoid add(int x,T y){add_(x+1,y);}\n\tT sum(int l,int\
    \ r){return sum_(r)-sum_(l);}\n\tBIT(int x):N(x),bit(x+1){}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<class T>\n\
    class BIT{\n\tint N;\n\tvector<T>bit;\n\tvoid add_(int x,T y){\n\t\twhile(x<=N){\n\
    \t\t\tbit[x]+=y;x+=x&-x;\n\t\t}\n\t}\n\tT sum_(int x){\n\t\tT res=0;\n\t\twhile(x>0){\n\
    \t\t\tres+=bit[x];x-=x&-x;\n\t\t}\n\t\treturn res;\n\t}\npublic:\n\tint lower_bound(T\
    \ w){\n\t\tif(w<=0)return -1;\n\t\tint x=0;\n\t\tint k=1;while(k*2<=N)k*=2;\n\t\
    \tfor(;k>0;k/=2){\n\t\t\tif(x+k<=N&&bit[x+k]<w){\n\t\t\t\tw-=bit[x+k];\n\t\t\t\
    \tx+=k;\n\t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n\tvoid add(int x,T y){add_(x+1,y);}\n\
    \tT sum(int l,int r){return sum_(r)-sum_(l);}\n\tBIT(int x):N(x),bit(x+1){}\n\
    };\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/BIT.cpp
  requiredBy: []
  timestamp: '2020-09-22 11:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/BIT.cpp
layout: document
redirect_from:
- /library/structure/BIT.cpp
- /library/structure/BIT.cpp.html
title: structure/BIT.cpp
---
