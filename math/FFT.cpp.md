---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma\
    \ GCC optimization (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\n\
    using namespace std;\n#define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n\
    #define REP(i,n) for(ll i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n\
    #define all(v) v.begin(),v.end()\n#define P pair<ll,ll>\n#define len(s) (ll)s.size()\n\
    \ \ntemplate<class T> inline bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\
    \treturn false;\n}\ntemplate<class T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return\
    \ true;}\n\treturn false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"math/FFT.cpp\"\
    \n\nvoid dft(vector<complex<double>>&func,ll inv){\n\tll sz=func.size();\n\tif(sz==1)return;\n\
    \tvector<complex<double>>va,vb;\n\trep(i,sz/2){\n\t\tva.push_back(func[2*i]);\n\
    \t\tvb.push_back(func[2*i+1]);\n\t}\n\tdft(va,inv);dft(vb,inv);\n\tcomplex<double>now=1,zeta=polar(1.0,inv*2.0*acos(-1)/sz);\n\
    \trep(i,sz){\n\t\tfunc[i]=va[i%(sz/2)]+now*vb[i%(sz/2)];\n\t\tnow*=zeta;\n\t}\n\
    }\ntemplate<class T>\nvector<double>fft(vector<T>f,vector<T>g){\n\tvector<complex<double>>nf,ng;\n\
    \tll sz=1;\n\twhile(sz<len(f)+len(g))sz*=2;\n\tnf.resize(sz);ng.resize(sz);\n\t\
    rep(i,len(f)){\n\t\tnf[i]=f[i];\n\t}\n\trep(i,len(g)){\n\t\tng[i]=g[i];\n\t}\n\
    \tdft(nf,1);dft(ng,1);\n\trep(i,sz)nf[i]*=ng[i];\n\tdft(nf,-1);\n\tvector<double>res;\n\
    \trep(i,sz)res.push_back(nf[i].real()/sz);\n\treturn res;\n}\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nvoid dft(vector<complex<double>>&func,ll\
    \ inv){\n\tll sz=func.size();\n\tif(sz==1)return;\n\tvector<complex<double>>va,vb;\n\
    \trep(i,sz/2){\n\t\tva.push_back(func[2*i]);\n\t\tvb.push_back(func[2*i+1]);\n\
    \t}\n\tdft(va,inv);dft(vb,inv);\n\tcomplex<double>now=1,zeta=polar(1.0,inv*2.0*acos(-1)/sz);\n\
    \trep(i,sz){\n\t\tfunc[i]=va[i%(sz/2)]+now*vb[i%(sz/2)];\n\t\tnow*=zeta;\n\t}\n\
    }\ntemplate<class T>\nvector<double>fft(vector<T>f,vector<T>g){\n\tvector<complex<double>>nf,ng;\n\
    \tll sz=1;\n\twhile(sz<len(f)+len(g))sz*=2;\n\tnf.resize(sz);ng.resize(sz);\n\t\
    rep(i,len(f)){\n\t\tnf[i]=f[i];\n\t}\n\trep(i,len(g)){\n\t\tng[i]=g[i];\n\t}\n\
    \tdft(nf,1);dft(ng,1);\n\trep(i,sz)nf[i]*=ng[i];\n\tdft(nf,-1);\n\tvector<double>res;\n\
    \trep(i,sz)res.push_back(nf[i].real()/sz);\n\treturn res;\n}\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: math/FFT.cpp
  requiredBy: []
  timestamp: '2020-09-23 19:41:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/FFT.cpp
layout: document
redirect_from:
- /library/math/FFT.cpp
- /library/math/FFT.cpp.html
title: math/FFT.cpp
---
