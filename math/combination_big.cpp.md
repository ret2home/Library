---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  - icon: ':warning:'
    path: math/mod_pow.cpp
    title: math/mod_pow.cpp
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
    \ inf = 3e18;\n#line 3 \"math/mod_pow.cpp\"\n\nint mod_pow(int x,int y,int m=mod){\n\
    \tx%=m;\n\tint res=1;\n\twhile(y>0){\n\t\tif(y&1)(res*=x)%=m;\n\t\t(x*=x)%=m;\n\
    \t\ty>>=1;\n\t}\n\treturn res;\n}\n#line 4 \"math/combination_big.cpp\"\n\nint\
    \ perm(int x,int y){\n\tint res=1;\n\tfor(int i=x-y+1;i<=x;i++)(res*=i%mod)%=mod;\n\
    \treturn res;\n}\nint comb(int x,int y){\n\tif(y>x)return 0;\n\treturn perm(x,y)*mod_pow(perm(y,y),mod-2)%mod;\n\
    }\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n#include \"mod_pow.cpp\"\
    \n\nint perm(int x,int y){\n\tint res=1;\n\tfor(int i=x-y+1;i<=x;i++)(res*=i%mod)%=mod;\n\
    \treturn res;\n}\nint comb(int x,int y){\n\tif(y>x)return 0;\n\treturn perm(x,y)*mod_pow(perm(y,y),mod-2)%mod;\n\
    }\n"
  dependsOn:
  - template/template.cpp
  - math/mod_pow.cpp
  isVerificationFile: false
  path: math/combination_big.cpp
  requiredBy: []
  timestamp: '2020-09-22 11:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination_big.cpp
layout: document
redirect_from:
- /library/math/combination_big.cpp
- /library/math/combination_big.cpp.html
title: math/combination_big.cpp
---
