---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/WaveletMatrix.cpp
    title: Wavelet Matrix
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  - icon: ':heavy_check_mark:'
    path: structure/BitVector.cpp
    title: Bit Vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/WaveletMatrix.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\
    \n\n#line 2 \"template/template.cpp\"\n#include<bits/stdc++.h>\n#pragma GCC optimization\
    \ (\"Ofast\")\n#pragma GCC optimization (\"unroll-loops\")\nusing namespace std;\n\
    #define ll long long\n#define rep(i,n) for(ll i=0;i<n;i++)\n#define REP(i,n) for(ll\
    \ i=1;i<n;i++)\n#define rev(i,n) for(ll i=n-1;i>=0;i--)\n#define all(v) v.begin(),v.end()\n\
    #define P pair<ll,ll>\n#define len(s) (ll)s.size()\n \ntemplate<class T> inline\
    \ bool chmin(T &a, T b){\n\tif(a>b){a=b;return true;}\n\treturn false;\n}\ntemplate<class\
    \ T> inline bool chmax(T &a, T b){\n\tif(a<b){a=b;return true;}\n\treturn false;\n\
    }\nconstexpr ll inf = 3e18;\n#line 3 \"structure/BitVector.cpp\"\n\nclass BitVector{\n\
    \    vector<ll>sum;\n    vector<uint64_t>bit;\npublic:\n    ll rank(bool val,ll\
    \ idx){\n        uint64_t mask=((uint64_t)1<<(idx&((1<<6)-1)))-1;\n        ll\
    \ res=sum[idx>>6]+__builtin_popcountll(bit[idx>>6]&mask);\n        return (val?res:idx-res);\n\
    \    }\n    BitVector(vector<bool>&v){\n        ll sz=(len(v)>>6)+1;\n       \
    \ bit.assign(sz,0);\n        sum.assign(sz,0);\n        rep(i,len(v)){\n     \
    \       bit[i>>6]|=(uint64_t)(v[i])<<(i&((1<<6)-1));\n        }\n        rep(i,sz-1){\n\
    \            sum[i+1]=sum[i]+__builtin_popcountll(bit[i]);\n        }\n    }\n\
    };\n/*\n@brief Bit Vector\n@docs docs/BitVector.md\n*/\n#line 4 \"structure/WaveletMatrix.cpp\"\
    \n\ntemplate<class T,class C>\nclass WaveletMatrix{\n    ll N,bitlen;\n    vector<BitVector>index;\n\
    \    map<C,ll>st;\npublic:\n    T body;\n    ll rank(C c,ll idx){\n        if(st.find(c)==st.end())return\
    \ 0;\n        rev(i,bitlen){\n            if(c>>i&1)idx=index[i].rank(1,idx)+index[i].rank(0,N);\n\
    \            else idx-=index[i].rank(1,idx);\n        }\n        return max(0ll,idx-st[c]);\n\
    \    }\n    C quantile(ll l,ll r,ll c){\n        C res=0;\n        rev(i,bitlen){\n\
    \            ll cnt=(r-l)-(index[i].rank(1,r)-index[i].rank(1,l));\n         \
    \   if(cnt<=c){\n                c-=cnt;\n                l=index[i].rank(0,N)+index[i].rank(1,l);\n\
    \                r=index[i].rank(0,N)+index[i].rank(1,r);\n                res+=1ll<<i;\n\
    \            }else {\n                l-=index[i].rank(1,l);\n               \
    \ r-=index[i].rank(1,r);\n            }\n        }\n        return res;\n    }\n\
    \    WaveletMatrix(T V,ll bitlen):N(len(V)),bitlen(bitlen),body(V){\n        vector<bool>bit(N);\n\
    \        index.resize(bitlen,bit);\n        rev(i,bitlen){\n            T newV[2];\n\
    \            rep(j,N){\n                bit[j]=(V[j]>>i&1);\n                newV[V[j]>>i&1].push_back(V[j]);\n\
    \            }\n            V=newV[0];V.insert(V.end(),all(newV[1]));\n      \
    \      index[i]=BitVector(bit);\n        }\n        rep(i,N)if(st.find(V[i])==st.end())st[V[i]]=i;\n\
    \    }\n};\n/*\n@brief Wavelet Matrix\n@docs docs/WaveletMatrix.md\n*/\n#line\
    \ 4 \"test/WaveletMatrix.test.cpp\"\n\nint main(){\n    int N,Q;\n    cin>>N>>Q;\n\
    \    vector<int>V(N);\n    for(int &i:V)cin>>i;\n    WaveletMatrix<vector<int>,int>WM(V,30);\n\
    \    while(Q--){\n        int l,r,k;cin>>l>>r>>k;\n        cout<<WM.quantile(l,r,k)<<\"\
    \\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../structure/WaveletMatrix.cpp\"\n\nint main(){\n    int N,Q;\n   \
    \ cin>>N>>Q;\n    vector<int>V(N);\n    for(int &i:V)cin>>i;\n    WaveletMatrix<vector<int>,int>WM(V,30);\n\
    \    while(Q--){\n        int l,r,k;cin>>l>>r>>k;\n        cout<<WM.quantile(l,r,k)<<\"\
    \\n\";\n    }\n}"
  dependsOn:
  - structure/WaveletMatrix.cpp
  - template/template.cpp
  - structure/BitVector.cpp
  isVerificationFile: true
  path: test/WaveletMatrix.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 20:22:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/WaveletMatrix.test.cpp
layout: document
redirect_from:
- /verify/test/WaveletMatrix.test.cpp
- /verify/test/WaveletMatrix.test.cpp.html
title: test/WaveletMatrix.test.cpp
---
