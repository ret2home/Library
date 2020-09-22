---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  - icon: ':warning:'
    path: math/extgcd.cpp
    title: math/extgcd.cpp
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
    \ inf = 3e18;\n#line 3 \"math/extgcd.cpp\"\n\nint extGCD(int a,int b,int &x,int\
    \ &y){\n\tif(!b){\n\t\tx=1;y=0;return a;\n\t}\n\tint d=extGCD(b,a%b,y,x);\n\t\
    y-=a/b*x;\n\treturn d;\n}\n#line 4 \"math/CRT.cpp\"\n\nP CRT(vector<int>b,vector<int>m){\n\
    \tint r=0,M=1;\n\trep(i,len(b)){\n\t\tint p,q;\n\t\tint d=extGCD(M,m[i],p,q);\n\
    \t\tif((b[i]-r)%d)return P(0,-1);\n\t\tint tmp=(b[i]-r)/d*p%(m[i]/d);\n\t\tr+=M*tmp;\n\
    \t\tM*=m[i]/d;\n\t}\n\treturn P((r%M+M)%M,M);\n}\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n#include \"extgcd.cpp\"\
    \n\nP CRT(vector<int>b,vector<int>m){\n\tint r=0,M=1;\n\trep(i,len(b)){\n\t\t\
    int p,q;\n\t\tint d=extGCD(M,m[i],p,q);\n\t\tif((b[i]-r)%d)return P(0,-1);\n\t\
    \tint tmp=(b[i]-r)/d*p%(m[i]/d);\n\t\tr+=M*tmp;\n\t\tM*=m[i]/d;\n\t}\n\treturn\
    \ P((r%M+M)%M,M);\n}"
  dependsOn:
  - template/template.cpp
  - math/extgcd.cpp
  isVerificationFile: false
  path: math/CRT.cpp
  requiredBy: []
  timestamp: '2020-09-22 11:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/CRT.cpp
layout: document
redirect_from:
- /library/math/CRT.cpp
- /library/math/CRT.cpp.html
title: math/CRT.cpp
---
