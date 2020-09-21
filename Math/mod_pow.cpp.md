---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/combination.cpp
    title: Math/combination.cpp
  - icon: ':warning:'
    path: Math/combination_big.cpp
    title: Math/combination_big.cpp
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
    \ inf = 3e18;\n#line 3 \"Math/mod_pow.cpp\"\n\nint mod_pow(int x,int y,int m=mod){\n\
    \tx%=m;\n\tint res=1;\n\twhile(y>0){\n\t\tif(y&1)(res*=x)%=m;\n\t\t(x*=x)%=m;\n\
    \t\ty>>=1;\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nint mod_pow(int x,int\
    \ y,int m=mod){\n\tx%=m;\n\tint res=1;\n\twhile(y>0){\n\t\tif(y&1)(res*=x)%=m;\n\
    \t\t(x*=x)%=m;\n\t\ty>>=1;\n\t}\n\treturn res;\n}"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: Math/mod_pow.cpp
  requiredBy:
  - Math/combination.cpp
  - Math/combination_big.cpp
  timestamp: '2020-09-09 20:08:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/mod_pow.cpp
layout: document
redirect_from:
- /library/Math/mod_pow.cpp
- /library/Math/mod_pow.cpp.html
title: Math/mod_pow.cpp
---
