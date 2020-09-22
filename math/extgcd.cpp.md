---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/CRT.cpp
    title: math/CRT.cpp
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
    \ inf = 3e18;\n#line 3 \"math/extgcd.cpp\"\n\nint extGCD(int a,int b,int &x,int\
    \ &y){\n\tif(!b){\n\t\tx=1;y=0;return a;\n\t}\n\tint d=extGCD(b,a%b,y,x);\n\t\
    y-=a/b*x;\n\treturn d;\n}\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nint extGCD(int a,int\
    \ b,int &x,int &y){\n\tif(!b){\n\t\tx=1;y=0;return a;\n\t}\n\tint d=extGCD(b,a%b,y,x);\n\
    \ty-=a/b*x;\n\treturn d;\n}"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: math/extgcd.cpp
  requiredBy:
  - math/CRT.cpp
  timestamp: '2020-09-22 11:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/extgcd.cpp
layout: document
redirect_from:
- /library/math/extgcd.cpp
- /library/math/extgcd.cpp.html
title: math/extgcd.cpp
---
