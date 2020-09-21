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
    \ inf = 3e18;\n#line 3 \"String/RollingHash.cpp\"\n\ntemplate<class T>\nstruct\
    \ RollingHash{\n\tint Base=283;\n\tconst int MASK30=(1ll<<30)-1;\n\tconst int\
    \ MASK31=(1ll<<31)-1;\n\tconst int MOD=(1ll<<61)-1;\n\tvector<int>hash,power;\n\
    \tint calcmod(int v){\n\t\tv=(v&MOD)+(v>>61);\n\t\tif(v>MOD)v-=MOD;\n\t\treturn\
    \ v;\n\t}\n\tint mul(int x,int y){\n\t\tint xu=x>>31,xd=x&MASK31;\n\t\tint yu=y>>31,yd=y&MASK31;\n\
    \t\tint mid=xd*yu+xu*yd,midu=mid>>30,midd=mid&MASK30;\n\t\treturn calcmod(xu*yu*2+midu+(midd<<31)+xd*yd);\n\
    \t}\n\tRollingHash(T s){\n\t\tint sz=s.size();\n\t\thash.resize(sz+1,0);power.resize(sz+1,1);\n\
    \t\trep(i,sz){\n\t\t\thash[i+1]=calcmod(mul(hash[i],Base)+s[i]);\n\t\t\tpower[i+1]=calcmod(mul(power[i],Base));\n\
    \t\t}\n\t}\n\tint get(int l,int r){\n\t\treturn calcmod(hash[r]-mul(hash[l],power[r-l])+MOD);\n\
    \t}\n\tint lcp(int x,int y){\n\t\tint len=min(hash.size()-1-y,hash.size()-1-x);\n\
    \t\tint ok=0,ng=len+1;\n\t\twhile(ng-ok>1){\n\t\t\tint mid=(ok+ng)/2;\n\t\t\t\
    if(get(x,x+mid)==get(y,y+mid))ok=mid;\n\t\t\telse ng=mid;\n\t\t}\n\t\treturn ok;\n\
    \t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<class T>\n\
    struct RollingHash{\n\tint Base=283;\n\tconst int MASK30=(1ll<<30)-1;\n\tconst\
    \ int MASK31=(1ll<<31)-1;\n\tconst int MOD=(1ll<<61)-1;\n\tvector<int>hash,power;\n\
    \tint calcmod(int v){\n\t\tv=(v&MOD)+(v>>61);\n\t\tif(v>MOD)v-=MOD;\n\t\treturn\
    \ v;\n\t}\n\tint mul(int x,int y){\n\t\tint xu=x>>31,xd=x&MASK31;\n\t\tint yu=y>>31,yd=y&MASK31;\n\
    \t\tint mid=xd*yu+xu*yd,midu=mid>>30,midd=mid&MASK30;\n\t\treturn calcmod(xu*yu*2+midu+(midd<<31)+xd*yd);\n\
    \t}\n\tRollingHash(T s){\n\t\tint sz=s.size();\n\t\thash.resize(sz+1,0);power.resize(sz+1,1);\n\
    \t\trep(i,sz){\n\t\t\thash[i+1]=calcmod(mul(hash[i],Base)+s[i]);\n\t\t\tpower[i+1]=calcmod(mul(power[i],Base));\n\
    \t\t}\n\t}\n\tint get(int l,int r){\n\t\treturn calcmod(hash[r]-mul(hash[l],power[r-l])+MOD);\n\
    \t}\n\tint lcp(int x,int y){\n\t\tint len=min(hash.size()-1-y,hash.size()-1-x);\n\
    \t\tint ok=0,ng=len+1;\n\t\twhile(ng-ok>1){\n\t\t\tint mid=(ok+ng)/2;\n\t\t\t\
    if(get(x,x+mid)==get(y,y+mid))ok=mid;\n\t\t\telse ng=mid;\n\t\t}\n\t\treturn ok;\n\
    \t}\n};"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: String/RollingHash.cpp
  requiredBy: []
  timestamp: '2020-09-09 20:08:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/RollingHash.cpp
layout: document
redirect_from:
- /library/String/RollingHash.cpp
- /library/String/RollingHash.cpp.html
title: String/RollingHash.cpp
---
