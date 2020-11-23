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
    #line 3 \"structure/SegmentTreeBeats.cpp\"\n\nstruct SegtreeBeats{\n\tint size=1;\n\
    private:\n\tvector<ll>mx,smx,mxc;\n\tvector<ll>mn,smn,mnc;\n\tvector<ll>sum,lazy;\n\
    \tvector<bool>flag;\n\t\n\tvoid update(int k){\n\t\tsum[k]=sum[k*2+1]+sum[k*2+2];\n\
    \n\t\tmx[k]=max(mx[2*k+1],mx[2*k+2]);\n\t\tif(mx[2*k+1]<mx[2*k+2]){\n\t\t\tmxc[k]=mxc[2*k+2];\n\
    \t\t\tsmx[k]=max(mx[2*k+1],smx[2*k+2]);\n\t\t}else if(mx[2*k+1]>mx[2*k+2]){\n\t\
    \t\tmxc[k]=mxc[2*k+1];\n\t\t\tsmx[k]=max(smx[2*k+1],mx[2*k+2]);\n\t\t}else {\n\
    \t\t\tmxc[k]=mxc[2*k+1]+mxc[2*k+2];\n\t\t\tsmx[k]=max(smx[2*k+1],smx[2*k+2]);\n\
    \t\t}\n\n\t\tmn[k]=min(mn[2*k+1],mn[2*k+2]);\n\t\tif(mn[2*k+1]<mn[2*k+2]){\n\t\
    \t\tmnc[k]=mnc[2*k+1];\n\t\t\tsmn[k]=min(smn[2*k+1],mn[2*k+2]);\n\t\t}else if(mn[2*k+1]>mn[2*k+2]){\n\
    \t\t\tmnc[k]=mnc[2*k+2];\n\t\t\tsmn[k]=min(mn[2*k+1],smn[2*k+2]);\n\t\t}else {\n\
    \t\t\tmnc[k]=mnc[2*k+1]+mnc[2*k+2];\n\t\t\tsmn[k]=min(smn[2*k+1],smn[2*k+2]);\n\
    \t\t}\n\t}\n\tvoid updateNodeMax(int k,ll x){\n\t\tsum[k]+=(x-mx[k])*mxc[k];\n\
    \t\tif(mx[k]==mn[k]){\n\t\t\tmx[k]=mn[k]=x;\n\t\t}else if(mx[k]==smn[k]){\n\t\t\
    \tmx[k]=smn[k]=x;\n\t\t}else {\n\t\t\tmx[k]=x;\n\t\t}\n\t}\n\tvoid updateNodeMin(int\
    \ k,ll x){\n\t\tsum[k]+=(x-mn[k])*mnc[k];\n\t\tif(mx[k]==mn[k]){\n\t\t\tmx[k]=mn[k]=x;\n\
    \t\t}else if(smx[k]==mn[k]){\n\t\t\tsmx[k]=mn[k]=x;\n\t\t}else {\n\t\t\tmn[k]=x;\n\
    \t\t}\n\t}\n\tvoid updateNodeAdd(int k,int len,ll x){\n\t\tmx[k]+=x;\n\t\tif(smx[k]!=-inf)smx[k]+=x;\n\
    \t\tmn[k]+=x;\n\t\tif(smn[k]!=inf)smn[k]+=x;\n\t\tsum[k]+=x*len;\n\t\tlazy[k]+=x;\n\
    \t}\n\tvoid updateNodeAssign(int k,int len,ll x){\n\t\tmx[k]=x;smx[k]=-inf;mxc[k]=len;\n\
    \t\tmn[k]=x;smn[k]=inf;mnc[k]=len;\n\t\tsum[k]=x*len;\n\t\tlazy[k]=x;flag[k]=true;\n\
    \t}\n\tvoid push(int k,int len){\n\t\tif(k>=size-1)return;\n\t\tif(flag[k]||lazy[k]!=0){\n\
    \t\t\tif(flag[k]){\n\t\t\t\tupdateNodeAssign(k*2+1,len/2,lazy[k]);\n\t\t\t\tupdateNodeAssign(k*2+2,len/2,lazy[k]);\n\
    \t\t\t}else {\n\t\t\t\tupdateNodeAdd(k*2+1,len/2,lazy[k]);\n\t\t\t\tupdateNodeAdd(k*2+2,len/2,lazy[k]);\n\
    \t\t\t}\n\t\t\tlazy[k]=0;flag[k]=false;\n\t\t}\n\t\tif(mx[k*2+1]>mx[k])updateNodeMax(k*2+1,mx[k]);\n\
    \t\tif(mx[k*2+2]>mx[k])updateNodeMax(k*2+2,mx[k]);\n\t\tif(mn[k*2+1]<mn[k])updateNodeMin(k*2+1,mn[k]);\n\
    \t\tif(mn[k*2+2]<mn[k])updateNodeMin(k*2+2,mn[k]);\n\t}\n\npublic:\n\n\tvoid updateMin(int\
    \ a,int b,ll x,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l||mx[k]<=x)return;\n\
    \t\tif(a<=l&&r<=b&&smx[k]<x){\n\t\t\tupdateNodeMax(k,x);\n\t\t\treturn;\n\t\t\
    }\n\t\tpush(k,r-l);\n\t\tupdateMin(a,b,x,k*2+1,l,(l+r)/2);\n\t\tupdateMin(a,b,x,k*2+2,(l+r)/2,r);\n\
    \t\tupdate(k);\n\t}\n\tvoid updateMax(int a,int b,ll x,int k=0,int l=0,int r=-1){\n\
    \t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l||mn[k]>=x)return;\n\t\tif(a<=l&&r<=b&&smn[k]>x){\n\
    \t\t\tupdateNodeMin(k,x);\n\t\t\treturn;\n\t\t}\n\t\tpush(k,r-l);\n\t\tupdateMax(a,b,x,k*2+1,l,(l+r)/2);\n\
    \t\tupdateMax(a,b,x,k*2+2,(l+r)/2,r);\n\t\tupdate(k);\n\t}\n\tvoid updateAdd(int\
    \ a,int b,ll x,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return;\n\
    \t\tif(a<=l&&r<=b){\n\t\t\tupdateNodeAdd(k,r-l,x);\n\t\t\treturn;\n\t\t}\n\t\t\
    push(k,r-l);\n\t\tupdateAdd(a,b,x,k*2+1,l,(l+r)/2);\n\t\tupdateAdd(a,b,x,k*2+2,(l+r)/2,r);\n\
    \t\tupdate(k);\n\t}\n\tvoid updateAssign(int a,int b,ll x,int k=0,int l=0,int\
    \ r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return;\n\t\tif(a<=l&&r<=b){\n\
    \t\t\tupdateNodeAssign(k,r-l,x);\n\t\t\treturn;\n\t\t}\n\t\tpush(k,r-l);\n\t\t\
    updateAssign(a,b,x,k*2+1,l,(l+r)/2);\n\t\tupdateAssign(a,b,x,k*2+2,(l+r)/2,r);\n\
    \t\tupdate(k);\n\t}\n\n\tvoid set(int k,ll x){\n\t\tk+=size-1;\n\t\tmx[k]=x;mn[k]=x;sum[k]=x;\n\
    \t}\n\tvoid init(){\n\t\tfor(ll i=size-2;i>=0;i--)update(i);\n\t}\n\tll queryMin(int\
    \ a,int b,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return\
    \ inf;\n\t\tif(a<=l&&r<=b)return mn[k];\n\t\tpush(k,r-l);\n\t\tll lv=queryMin(a,b,k*2+1,l,(l+r)/2);\n\
    \t\tll rv=queryMin(a,b,k*2+2,(l+r)/2,r);\n\t\treturn min(lv,rv);\n\t}\n\tll queryMax(int\
    \ a,int b,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return\
    \ -inf;\n\t\tif(a<=l&&r<=b)return mx[k];\n\t\tpush(k,r-l);\n\t\tll lv=queryMax(a,b,k*2+1,l,(l+r)/2);\n\
    \t\tll rv=queryMax(a,b,k*2+2,(l+r)/2,r);\n\t\treturn max(lv,rv);\n\t}\n\tll querySum(int\
    \ a,int b,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return\
    \ 0;\n\t\tif(a<=l&&r<=b)return sum[k];\n\t\tpush(k,r-l);\n\t\tll lv=querySum(a,b,k*2+1,l,(l+r)/2);\n\
    \t\tll rv=querySum(a,b,k*2+2,(l+r)/2,r);\n\t\treturn lv+rv;\n\t}\n\tSegtreeBeats(int\
    \ x){\n\t\twhile(size<x)size*=2;\n\t\tmx.resize(size*2-1,-inf+1);smx.resize(size*2-1,-inf);mxc.resize(size*2-1,1);\n\
    \t\tmn.resize(size*2-1,inf-1);smn.resize(size*2-1,inf);mnc.resize(size*2-1,1);\n\
    \t\tsum.resize(size*2-1);lazy.resize(size*2-1);flag.resize(size*2-1);\n\t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\nstruct SegtreeBeats{\n\
    \tint size=1;\nprivate:\n\tvector<ll>mx,smx,mxc;\n\tvector<ll>mn,smn,mnc;\n\t\
    vector<ll>sum,lazy;\n\tvector<bool>flag;\n\t\n\tvoid update(int k){\n\t\tsum[k]=sum[k*2+1]+sum[k*2+2];\n\
    \n\t\tmx[k]=max(mx[2*k+1],mx[2*k+2]);\n\t\tif(mx[2*k+1]<mx[2*k+2]){\n\t\t\tmxc[k]=mxc[2*k+2];\n\
    \t\t\tsmx[k]=max(mx[2*k+1],smx[2*k+2]);\n\t\t}else if(mx[2*k+1]>mx[2*k+2]){\n\t\
    \t\tmxc[k]=mxc[2*k+1];\n\t\t\tsmx[k]=max(smx[2*k+1],mx[2*k+2]);\n\t\t}else {\n\
    \t\t\tmxc[k]=mxc[2*k+1]+mxc[2*k+2];\n\t\t\tsmx[k]=max(smx[2*k+1],smx[2*k+2]);\n\
    \t\t}\n\n\t\tmn[k]=min(mn[2*k+1],mn[2*k+2]);\n\t\tif(mn[2*k+1]<mn[2*k+2]){\n\t\
    \t\tmnc[k]=mnc[2*k+1];\n\t\t\tsmn[k]=min(smn[2*k+1],mn[2*k+2]);\n\t\t}else if(mn[2*k+1]>mn[2*k+2]){\n\
    \t\t\tmnc[k]=mnc[2*k+2];\n\t\t\tsmn[k]=min(mn[2*k+1],smn[2*k+2]);\n\t\t}else {\n\
    \t\t\tmnc[k]=mnc[2*k+1]+mnc[2*k+2];\n\t\t\tsmn[k]=min(smn[2*k+1],smn[2*k+2]);\n\
    \t\t}\n\t}\n\tvoid updateNodeMax(int k,ll x){\n\t\tsum[k]+=(x-mx[k])*mxc[k];\n\
    \t\tif(mx[k]==mn[k]){\n\t\t\tmx[k]=mn[k]=x;\n\t\t}else if(mx[k]==smn[k]){\n\t\t\
    \tmx[k]=smn[k]=x;\n\t\t}else {\n\t\t\tmx[k]=x;\n\t\t}\n\t}\n\tvoid updateNodeMin(int\
    \ k,ll x){\n\t\tsum[k]+=(x-mn[k])*mnc[k];\n\t\tif(mx[k]==mn[k]){\n\t\t\tmx[k]=mn[k]=x;\n\
    \t\t}else if(smx[k]==mn[k]){\n\t\t\tsmx[k]=mn[k]=x;\n\t\t}else {\n\t\t\tmn[k]=x;\n\
    \t\t}\n\t}\n\tvoid updateNodeAdd(int k,int len,ll x){\n\t\tmx[k]+=x;\n\t\tif(smx[k]!=-inf)smx[k]+=x;\n\
    \t\tmn[k]+=x;\n\t\tif(smn[k]!=inf)smn[k]+=x;\n\t\tsum[k]+=x*len;\n\t\tlazy[k]+=x;\n\
    \t}\n\tvoid updateNodeAssign(int k,int len,ll x){\n\t\tmx[k]=x;smx[k]=-inf;mxc[k]=len;\n\
    \t\tmn[k]=x;smn[k]=inf;mnc[k]=len;\n\t\tsum[k]=x*len;\n\t\tlazy[k]=x;flag[k]=true;\n\
    \t}\n\tvoid push(int k,int len){\n\t\tif(k>=size-1)return;\n\t\tif(flag[k]||lazy[k]!=0){\n\
    \t\t\tif(flag[k]){\n\t\t\t\tupdateNodeAssign(k*2+1,len/2,lazy[k]);\n\t\t\t\tupdateNodeAssign(k*2+2,len/2,lazy[k]);\n\
    \t\t\t}else {\n\t\t\t\tupdateNodeAdd(k*2+1,len/2,lazy[k]);\n\t\t\t\tupdateNodeAdd(k*2+2,len/2,lazy[k]);\n\
    \t\t\t}\n\t\t\tlazy[k]=0;flag[k]=false;\n\t\t}\n\t\tif(mx[k*2+1]>mx[k])updateNodeMax(k*2+1,mx[k]);\n\
    \t\tif(mx[k*2+2]>mx[k])updateNodeMax(k*2+2,mx[k]);\n\t\tif(mn[k*2+1]<mn[k])updateNodeMin(k*2+1,mn[k]);\n\
    \t\tif(mn[k*2+2]<mn[k])updateNodeMin(k*2+2,mn[k]);\n\t}\n\npublic:\n\n\tvoid updateMin(int\
    \ a,int b,ll x,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l||mx[k]<=x)return;\n\
    \t\tif(a<=l&&r<=b&&smx[k]<x){\n\t\t\tupdateNodeMax(k,x);\n\t\t\treturn;\n\t\t\
    }\n\t\tpush(k,r-l);\n\t\tupdateMin(a,b,x,k*2+1,l,(l+r)/2);\n\t\tupdateMin(a,b,x,k*2+2,(l+r)/2,r);\n\
    \t\tupdate(k);\n\t}\n\tvoid updateMax(int a,int b,ll x,int k=0,int l=0,int r=-1){\n\
    \t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l||mn[k]>=x)return;\n\t\tif(a<=l&&r<=b&&smn[k]>x){\n\
    \t\t\tupdateNodeMin(k,x);\n\t\t\treturn;\n\t\t}\n\t\tpush(k,r-l);\n\t\tupdateMax(a,b,x,k*2+1,l,(l+r)/2);\n\
    \t\tupdateMax(a,b,x,k*2+2,(l+r)/2,r);\n\t\tupdate(k);\n\t}\n\tvoid updateAdd(int\
    \ a,int b,ll x,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return;\n\
    \t\tif(a<=l&&r<=b){\n\t\t\tupdateNodeAdd(k,r-l,x);\n\t\t\treturn;\n\t\t}\n\t\t\
    push(k,r-l);\n\t\tupdateAdd(a,b,x,k*2+1,l,(l+r)/2);\n\t\tupdateAdd(a,b,x,k*2+2,(l+r)/2,r);\n\
    \t\tupdate(k);\n\t}\n\tvoid updateAssign(int a,int b,ll x,int k=0,int l=0,int\
    \ r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return;\n\t\tif(a<=l&&r<=b){\n\
    \t\t\tupdateNodeAssign(k,r-l,x);\n\t\t\treturn;\n\t\t}\n\t\tpush(k,r-l);\n\t\t\
    updateAssign(a,b,x,k*2+1,l,(l+r)/2);\n\t\tupdateAssign(a,b,x,k*2+2,(l+r)/2,r);\n\
    \t\tupdate(k);\n\t}\n\n\tvoid set(int k,ll x){\n\t\tk+=size-1;\n\t\tmx[k]=x;mn[k]=x;sum[k]=x;\n\
    \t}\n\tvoid init(){\n\t\tfor(ll i=size-2;i>=0;i--)update(i);\n\t}\n\tll queryMin(int\
    \ a,int b,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return\
    \ inf;\n\t\tif(a<=l&&r<=b)return mn[k];\n\t\tpush(k,r-l);\n\t\tll lv=queryMin(a,b,k*2+1,l,(l+r)/2);\n\
    \t\tll rv=queryMin(a,b,k*2+2,(l+r)/2,r);\n\t\treturn min(lv,rv);\n\t}\n\tll queryMax(int\
    \ a,int b,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return\
    \ -inf;\n\t\tif(a<=l&&r<=b)return mx[k];\n\t\tpush(k,r-l);\n\t\tll lv=queryMax(a,b,k*2+1,l,(l+r)/2);\n\
    \t\tll rv=queryMax(a,b,k*2+2,(l+r)/2,r);\n\t\treturn max(lv,rv);\n\t}\n\tll querySum(int\
    \ a,int b,int k=0,int l=0,int r=-1){\n\t\tif(r==-1)r=size;\n\t\tif(r<=a||b<=l)return\
    \ 0;\n\t\tif(a<=l&&r<=b)return sum[k];\n\t\tpush(k,r-l);\n\t\tll lv=querySum(a,b,k*2+1,l,(l+r)/2);\n\
    \t\tll rv=querySum(a,b,k*2+2,(l+r)/2,r);\n\t\treturn lv+rv;\n\t}\n\tSegtreeBeats(int\
    \ x){\n\t\twhile(size<x)size*=2;\n\t\tmx.resize(size*2-1,-inf+1);smx.resize(size*2-1,-inf);mxc.resize(size*2-1,1);\n\
    \t\tmn.resize(size*2-1,inf-1);smn.resize(size*2-1,inf);mnc.resize(size*2-1,1);\n\
    \t\tsum.resize(size*2-1);lazy.resize(size*2-1);flag.resize(size*2-1);\n\t}\n};\n"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/SegmentTreeBeats.cpp
  requiredBy: []
  timestamp: '2020-11-18 20:02:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/SegmentTreeBeats.cpp
layout: document
redirect_from:
- /library/structure/SegmentTreeBeats.cpp
- /library/structure/SegmentTreeBeats.cpp.html
title: structure/SegmentTreeBeats.cpp
---
