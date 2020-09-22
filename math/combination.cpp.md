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
    \t\ty>>=1;\n\t}\n\treturn res;\n}\n#line 4 \"math/combination.cpp\"\n\nvector<int>perm,inv;\n\
    void init_perm(){\n\tint x=1e6+1;perm.resize(x);inv.resize(x);\n\tperm[0]=1;\n\
    \tREP(i,x+1)perm[i]=perm[i-1]*i%mod;\n\tinv[x]=mod_pow(perm[x],mod-2);\n\tfor(int\
    \ i=x-1;i>=0;i--){\n\t\tinv[i]=inv[i+1]*(i+1)%mod;\n\t}\n}\nint nCk(int x,int\
    \ y){\n\tif(x<y)return 0;\n\treturn perm[x]*inv[x-y]%mod*inv[y]%mod;\n}\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n#include \"mod_pow.cpp\"\
    \n\nvector<int>perm,inv;\nvoid init_perm(){\n\tint x=1e6+1;perm.resize(x);inv.resize(x);\n\
    \tperm[0]=1;\n\tREP(i,x+1)perm[i]=perm[i-1]*i%mod;\n\tinv[x]=mod_pow(perm[x],mod-2);\n\
    \tfor(int i=x-1;i>=0;i--){\n\t\tinv[i]=inv[i+1]*(i+1)%mod;\n\t}\n}\nint nCk(int\
    \ x,int y){\n\tif(x<y)return 0;\n\treturn perm[x]*inv[x-y]%mod*inv[y]%mod;\n}\n"
  dependsOn:
  - template/template.cpp
  - math/mod_pow.cpp
  isVerificationFile: false
  path: math/combination.cpp
  requiredBy: []
  timestamp: '2020-09-22 11:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.cpp
layout: document
redirect_from:
- /library/math/combination.cpp
- /library/math/combination.cpp.html
title: math/combination.cpp
---
