---
data:
  _extendedDependsOn:
  - icon: ':warning:'
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
    \ inf = 3e18;\n#line 3 \"String/Zalgo.cpp\"\n\ntemplate<class T>\nvector<int>zalgo(T\
    \ v){\n\tvector<int>res(v.size());\n\tint c=0;\n\tREP(i,(int)v.size()){\n\t\t\
    if(i+res[i-c]<c+res[c])res[i]=res[i-c];\n\t\telse {\n\t\t\tint j=max(0ll,c+res[c]-i);\n\
    \t\t\twhile(i+j<(int)v.size()&&v[j]==v[i+j])++j;\n\t\t\tres[i]=j;c=i;\n\t\t}\n\
    \t}res[0]=v.size();\n\treturn res;\n}\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<class T>\n\
    vector<int>zalgo(T v){\n\tvector<int>res(v.size());\n\tint c=0;\n\tREP(i,(int)v.size()){\n\
    \t\tif(i+res[i-c]<c+res[c])res[i]=res[i-c];\n\t\telse {\n\t\t\tint j=max(0ll,c+res[c]-i);\n\
    \t\t\twhile(i+j<(int)v.size()&&v[j]==v[i+j])++j;\n\t\t\tres[i]=j;c=i;\n\t\t}\n\
    \t}res[0]=v.size();\n\treturn res;\n}"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: String/Zalgo.cpp
  requiredBy: []
  timestamp: '2020-09-09 20:08:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Zalgo.cpp
layout: document
redirect_from:
- /library/String/Zalgo.cpp
- /library/String/Zalgo.cpp.html
title: String/Zalgo.cpp
---
