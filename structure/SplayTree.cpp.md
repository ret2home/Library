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
    \ inf = 3e18;\n#line 3 \"structure/SplayTree.cpp\"\n\ntemplate<class T>\nclass\
    \ SplayTree{\n\tstruct node{\n\t\tT val;\n\t\tnode *lch,*rch;\n\t};\n\tnode *root=NULL;\n\
    \tint sz=0;\n\tnode *rightRotate(node *x){\n\t\tnode *y=x->lch;\n\t\tx->lch=y->rch;\n\
    \t\ty->rch=x;\n\t\treturn y;\n\t}\n\tnode *leftRotate(node *x){\n\t\tnode *y=x->rch;\n\
    \t\tx->rch=y->lch;\n\t\ty->lch=x;\n\t\treturn y;\n\t}\n\tnode *splay(node *x,T\
    \ v){\n\t\tif(x==NULL||x->val==v)return x;\n\t\tif(v<x->val){\n\t\t\tif(x->lch==NULL)return\
    \ x;\n\t\t\tif(v<x->lch->val){\n\t\t\t\tx->lch->lch=splay(x->lch->lch,v);\n\t\t\
    \t\tx=rightRotate(x);\n\t\t\t}else if(x->lch->val<v){\n\t\t\t\tx->lch->rch=splay(x->lch->rch,v);\n\
    \t\t\t\tif(x->lch->rch!=NULL)\n\t\t\t\t\tx->lch=leftRotate(x->lch);\n\t\t\t}\n\
    \t\t\treturn (x->lch==NULL)?x:rightRotate(x);\n\t\t}else {\n\t\t\tif(x->rch==NULL)return\
    \ x;\n\t\t\tif(v<x->rch->val){\n\t\t\t\tx->rch->lch=splay(x->rch->lch,v);\n\t\t\
    \t\tif(x->rch->lch!=NULL)\n\t\t\t\t\tx->rch=rightRotate(x->rch);\n\t\t\t}else\
    \ if(x->rch->val<v){\n\t\t\t\tx->rch->rch=splay(x->rch->rch,v);\n\t\t\t\tx=leftRotate(x);\n\
    \t\t\t}\n\t\t\treturn (x->rch==NULL)?x:leftRotate(x);\n\t\t}\n\t}\n\tnode *insert(node\
    \ *x,T v){\n\t\tif(x==NULL){\n\t\t\tnode *q=new node;\n\t\t\tq->val=v;\n\t\t\t\
    q->lch=q->rch=NULL;\n\t\t\treturn q;\n\t\t}\n\t\tif(v<x->val)x->lch=insert(x->lch,v);\n\
    \t\telse x->rch=insert(x->rch,v);\n\t\treturn x;\n\t}\n\tnode *erase(node *x,T\
    \ v){\n\t\tif(x==NULL)return NULL;\n\t\tif(v<x->val)x->lch=erase(x->lch,v);\n\t\
    \telse if(x->val<v)x->rch=erase(x->rch,v);\n\t\telse if(x->lch==NULL){\n\t\t\t\
    node *q=x->rch;\n\t\t\tdelete x;\n\t\t\treturn q;\n\t\t}else if(x->lch->rch==NULL){\n\
    \t\t\tnode *q=x->lch;\n\t\t\tq->rch=x->rch;\n\t\t\tdelete x;\n\t\t\treturn q;\n\
    \t\t}else {\n\t\t\tnode *q;\n\t\t\tfor(q=x->lch;q->rch->rch!=NULL;q=q->rch);\n\
    \t\t\tnode *r=q->rch;\n\t\t\tq->rch=r->lch;\n\t\t\tr->lch=x->lch;\n\t\t\tr->rch=x->rch;\n\
    \t\t\tdelete x;\n\t\t\treturn r;\n\t\t}\n\t\treturn x;\n\t}\npublic:\n\tint size(){\n\
    \t\treturn sz;\n\t}\n\tnode *find(T x){\n\t\troot=splay(root,x);\n\t\tif(root==NULL||root->val!=x)return\
    \ NULL;\n\t\treturn root;\n\t}\n\tvoid insert(T x){\n\t\tif(!find(x)){\n\t\t\t\
    root=insert(root,x);sz++;\n\t\t}\n\t}\n\tvoid erase(T x){\n\t\tif(find(x)){\n\t\
    \t\troot=erase(root,x);\n\t\t\tsz--;\n\t\t}\n\t}\n\tnode* lower_bound(T x){\n\t\
    \troot=splay(root,x);\n\t\tif(root==NULL||root->val>=x)return root;\n\t\tif(root->rch==NULL)return\
    \ NULL;\n\t\tnode *q;\n\t\tfor(q=root->rch;q->lch!=NULL;q=q->lch);\n\t\treturn\
    \ q;\n\t}\n\tnode *upper_bound(T x){\n\t\troot=splay(root,x);\n\t\tif(root==NULL||root->val>x)return\
    \ root;\n\t\tif(root->rch==NULL)return NULL;\n\t\tnode *q;\n\t\tfor(q=root->rch;q->lch!=NULL;q=q->lch);\n\
    \t\treturn q;\n\t}\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate<class T>\n\
    class SplayTree{\n\tstruct node{\n\t\tT val;\n\t\tnode *lch,*rch;\n\t};\n\tnode\
    \ *root=NULL;\n\tint sz=0;\n\tnode *rightRotate(node *x){\n\t\tnode *y=x->lch;\n\
    \t\tx->lch=y->rch;\n\t\ty->rch=x;\n\t\treturn y;\n\t}\n\tnode *leftRotate(node\
    \ *x){\n\t\tnode *y=x->rch;\n\t\tx->rch=y->lch;\n\t\ty->lch=x;\n\t\treturn y;\n\
    \t}\n\tnode *splay(node *x,T v){\n\t\tif(x==NULL||x->val==v)return x;\n\t\tif(v<x->val){\n\
    \t\t\tif(x->lch==NULL)return x;\n\t\t\tif(v<x->lch->val){\n\t\t\t\tx->lch->lch=splay(x->lch->lch,v);\n\
    \t\t\t\tx=rightRotate(x);\n\t\t\t}else if(x->lch->val<v){\n\t\t\t\tx->lch->rch=splay(x->lch->rch,v);\n\
    \t\t\t\tif(x->lch->rch!=NULL)\n\t\t\t\t\tx->lch=leftRotate(x->lch);\n\t\t\t}\n\
    \t\t\treturn (x->lch==NULL)?x:rightRotate(x);\n\t\t}else {\n\t\t\tif(x->rch==NULL)return\
    \ x;\n\t\t\tif(v<x->rch->val){\n\t\t\t\tx->rch->lch=splay(x->rch->lch,v);\n\t\t\
    \t\tif(x->rch->lch!=NULL)\n\t\t\t\t\tx->rch=rightRotate(x->rch);\n\t\t\t}else\
    \ if(x->rch->val<v){\n\t\t\t\tx->rch->rch=splay(x->rch->rch,v);\n\t\t\t\tx=leftRotate(x);\n\
    \t\t\t}\n\t\t\treturn (x->rch==NULL)?x:leftRotate(x);\n\t\t}\n\t}\n\tnode *insert(node\
    \ *x,T v){\n\t\tif(x==NULL){\n\t\t\tnode *q=new node;\n\t\t\tq->val=v;\n\t\t\t\
    q->lch=q->rch=NULL;\n\t\t\treturn q;\n\t\t}\n\t\tif(v<x->val)x->lch=insert(x->lch,v);\n\
    \t\telse x->rch=insert(x->rch,v);\n\t\treturn x;\n\t}\n\tnode *erase(node *x,T\
    \ v){\n\t\tif(x==NULL)return NULL;\n\t\tif(v<x->val)x->lch=erase(x->lch,v);\n\t\
    \telse if(x->val<v)x->rch=erase(x->rch,v);\n\t\telse if(x->lch==NULL){\n\t\t\t\
    node *q=x->rch;\n\t\t\tdelete x;\n\t\t\treturn q;\n\t\t}else if(x->lch->rch==NULL){\n\
    \t\t\tnode *q=x->lch;\n\t\t\tq->rch=x->rch;\n\t\t\tdelete x;\n\t\t\treturn q;\n\
    \t\t}else {\n\t\t\tnode *q;\n\t\t\tfor(q=x->lch;q->rch->rch!=NULL;q=q->rch);\n\
    \t\t\tnode *r=q->rch;\n\t\t\tq->rch=r->lch;\n\t\t\tr->lch=x->lch;\n\t\t\tr->rch=x->rch;\n\
    \t\t\tdelete x;\n\t\t\treturn r;\n\t\t}\n\t\treturn x;\n\t}\npublic:\n\tint size(){\n\
    \t\treturn sz;\n\t}\n\tnode *find(T x){\n\t\troot=splay(root,x);\n\t\tif(root==NULL||root->val!=x)return\
    \ NULL;\n\t\treturn root;\n\t}\n\tvoid insert(T x){\n\t\tif(!find(x)){\n\t\t\t\
    root=insert(root,x);sz++;\n\t\t}\n\t}\n\tvoid erase(T x){\n\t\tif(find(x)){\n\t\
    \t\troot=erase(root,x);\n\t\t\tsz--;\n\t\t}\n\t}\n\tnode* lower_bound(T x){\n\t\
    \troot=splay(root,x);\n\t\tif(root==NULL||root->val>=x)return root;\n\t\tif(root->rch==NULL)return\
    \ NULL;\n\t\tnode *q;\n\t\tfor(q=root->rch;q->lch!=NULL;q=q->lch);\n\t\treturn\
    \ q;\n\t}\n\tnode *upper_bound(T x){\n\t\troot=splay(root,x);\n\t\tif(root==NULL||root->val>x)return\
    \ root;\n\t\tif(root->rch==NULL)return NULL;\n\t\tnode *q;\n\t\tfor(q=root->rch;q->lch!=NULL;q=q->lch);\n\
    \t\treturn q;\n\t}\n};"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/SplayTree.cpp
  requiredBy: []
  timestamp: '2020-09-22 11:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/SplayTree.cpp
layout: document
redirect_from:
- /library/structure/SplayTree.cpp
- /library/structure/SplayTree.cpp.html
title: structure/SplayTree.cpp
---
