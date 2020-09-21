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
    \ inf = 3e18;\n#line 3 \"Math/factor.cpp\"\n\nint mod_pow(int x,int y,int m=mod){\n\
    \tint res=1;\n\twhile(y>0){\n\t\tif(y&1)res=(__int128_t(res)*x)%m;\n\t\ty>>=1;x=(__int128_t(x)*x)%m;\n\
    \t}\n\treturn res;\n}\n\nbool prime(int n){\n\tif(n<2||n%2==0)return n==2;\n\t\
    int d=n-1;while(d%2==0)d>>=1;\n\tfor(int x:{2,325,9375,28178,450775,9780504,1795265022}){\n\
    \t\tif(n<=x)break;\n\t\tint t=d,y=mod_pow(x,t,n);\n\t\twhile(t!=n-1&&y!=1&&y!=n-1){\n\
    \t\t\ty=(__int128_t(y)*y)%n;t<<=1;\n\t\t}\n\t\tif(y!=n-1&&t%2==0)return false;\n\
    \t}return true;\n}\nint rho(int n){\n\tif(n%2==0)return 2;\n\tint MOD=n;\n\tauto\
    \ f=[&](int x){return ((__int128_t)x*x+1)%MOD;};\n\tauto g=[](int x,int y){\n\t\
    \tif(x<y)return y-x;\n\t\treturn x-y;\n\t};\n\tfor(int x1=0;;x1++){\n\t\tfor(int\
    \ x=x1,y=f(x);;x=f(x),y=f(f(y))){\n\t\t\tint d=gcd(g(y,x),n);\n\t\t\tif(1<d&&d<n)return\
    \ d;\n\t\t\tif(d==n)break;\n\t\t}\n\t}\n}\nvector<int>factor(int n){\n\tif(n==1)return\
    \ {};\n\tif(prime(n))return {n};\n\tint d=rho(n);\n\tvector<int>res=factor(d);\n\
    \tfor(int i:factor(n/d))res.push_back(i);\n\treturn res;\n}\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nint mod_pow(int x,int\
    \ y,int m=mod){\n\tint res=1;\n\twhile(y>0){\n\t\tif(y&1)res=(__int128_t(res)*x)%m;\n\
    \t\ty>>=1;x=(__int128_t(x)*x)%m;\n\t}\n\treturn res;\n}\n\nbool prime(int n){\n\
    \tif(n<2||n%2==0)return n==2;\n\tint d=n-1;while(d%2==0)d>>=1;\n\tfor(int x:{2,325,9375,28178,450775,9780504,1795265022}){\n\
    \t\tif(n<=x)break;\n\t\tint t=d,y=mod_pow(x,t,n);\n\t\twhile(t!=n-1&&y!=1&&y!=n-1){\n\
    \t\t\ty=(__int128_t(y)*y)%n;t<<=1;\n\t\t}\n\t\tif(y!=n-1&&t%2==0)return false;\n\
    \t}return true;\n}\nint rho(int n){\n\tif(n%2==0)return 2;\n\tint MOD=n;\n\tauto\
    \ f=[&](int x){return ((__int128_t)x*x+1)%MOD;};\n\tauto g=[](int x,int y){\n\t\
    \tif(x<y)return y-x;\n\t\treturn x-y;\n\t};\n\tfor(int x1=0;;x1++){\n\t\tfor(int\
    \ x=x1,y=f(x);;x=f(x),y=f(f(y))){\n\t\t\tint d=gcd(g(y,x),n);\n\t\t\tif(1<d&&d<n)return\
    \ d;\n\t\t\tif(d==n)break;\n\t\t}\n\t}\n}\nvector<int>factor(int n){\n\tif(n==1)return\
    \ {};\n\tif(prime(n))return {n};\n\tint d=rho(n);\n\tvector<int>res=factor(d);\n\
    \tfor(int i:factor(n/d))res.push_back(i);\n\treturn res;\n}"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: Math/factor.cpp
  requiredBy: []
  timestamp: '2020-09-09 20:08:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/factor.cpp
layout: document
redirect_from:
- /library/Math/factor.cpp
- /library/Math/factor.cpp.html
title: Math/factor.cpp
---
