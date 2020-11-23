---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T,class U> inline bool chmin(T &a, U b){\n\tif(a>b){a=b;return\
    \ true;}\n\treturn false;\n}\ntemplate<class T,class U> inline bool chmax(T &a,\
    \ U b){\n\tif(a<b){a=b;return true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n\
    #line 3 \"math/extgcd.cpp\"\n\nll extGCD(ll a,ll b,ll &x,ll &y){\n\tif(!b){\n\t\
    \tx=1;y=0;return a;\n\t}\n\tll d=extGCD(b,a%b,y,x);\n\ty-=a/b*x;\n\treturn d;\n\
    }\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nll extGCD(ll a,ll\
    \ b,ll &x,ll &y){\n\tif(!b){\n\t\tx=1;y=0;return a;\n\t}\n\tll d=extGCD(b,a%b,y,x);\n\
    \ty-=a/b*x;\n\treturn d;\n}"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: math/extgcd.cpp
  requiredBy:
  - math/CRT.cpp
  timestamp: '2020-11-18 20:02:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/extgcd.cpp
layout: document
redirect_from:
- /library/math/extgcd.cpp
- /library/math/extgcd.cpp.html
title: math/extgcd.cpp
---
