---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
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
    #line 3 \"string/Zalgo.cpp\"\n\ntemplate<class T>\nvector<ll>zalgo(T v){\n\tvector<ll>res(v.size());\n\
    \tll c=0;\n\tREP(i,(ll)v.size()){\n\t\tif(i+res[i-c]<c+res[c])res[i]=res[i-c];\n\
    \t\telse {\n\t\t\tll j=max(0ll,c+res[c]-i);\n\t\t\twhile(i+j<(ll)v.size()&&v[j]==v[i+j])++j;\n\
    \t\t\tres[i]=j;c=i;\n\t\t}\n\t}res[0]=v.size();\n\treturn res;\n}\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<class T>\n\
    vector<ll>zalgo(T v){\n\tvector<ll>res(v.size());\n\tll c=0;\n\tREP(i,(ll)v.size()){\n\
    \t\tif(i+res[i-c]<c+res[c])res[i]=res[i-c];\n\t\telse {\n\t\t\tll j=max(0ll,c+res[c]-i);\n\
    \t\t\twhile(i+j<(ll)v.size()&&v[j]==v[i+j])++j;\n\t\t\tres[i]=j;c=i;\n\t\t}\n\t\
    }res[0]=v.size();\n\treturn res;\n}"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: string/Zalgo.cpp
  requiredBy: []
  timestamp: '2020-11-18 20:02:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/Zalgo.cpp
layout: document
redirect_from:
- /library/string/Zalgo.cpp
- /library/string/Zalgo.cpp.html
title: string/Zalgo.cpp
---
