---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define ll long long\n#define rep(i, n) for (int i = 0; i <\
    \ n; i++)\n#define REP(i, n) for (int i = 1; i < n; i++)\n#define rev(i, n) for\
    \ (int i = n - 1; i >= 0; i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n\
    #define all(v) v.begin(), v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,int>\n\
    #define len(s) (int)s.size()\n\ntemplate <class T, class U>\ninline bool chmin(T\
    \ &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T &a, U\
    \ b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/SplayTree.cpp\"\n\n\
    template <class T>\nclass SplayTree {\n    struct node {\n        T val;\n   \
    \     node *lch, *rch;\n    };\n    node *root = NULL;\n    ll sz = 0;\n    node\
    \ *rightRotate(node *x) {\n        node *y = x->lch;\n        x->lch = y->rch;\n\
    \        y->rch = x;\n        return y;\n    }\n    node *leftRotate(node *x)\
    \ {\n        node *y = x->rch;\n        x->rch = y->lch;\n        y->lch = x;\n\
    \        return y;\n    }\n    node *splay(node *x, T v) {\n        if (x == NULL\
    \ || x->val == v) return x;\n        if (v < x->val) {\n            if (x->lch\
    \ == NULL) return x;\n            if (v < x->lch->val) {\n                x->lch->lch\
    \ = splay(x->lch->lch, v);\n                x = rightRotate(x);\n            }\
    \ else if (x->lch->val < v) {\n                x->lch->rch = splay(x->lch->rch,\
    \ v);\n                if (x->lch->rch != NULL)\n                    x->lch =\
    \ leftRotate(x->lch);\n            }\n            return (x->lch == NULL) ? x\
    \ : rightRotate(x);\n        } else {\n            if (x->rch == NULL) return\
    \ x;\n            if (v < x->rch->val) {\n                x->rch->lch = splay(x->rch->lch,\
    \ v);\n                if (x->rch->lch != NULL)\n                    x->rch =\
    \ rightRotate(x->rch);\n            } else if (x->rch->val < v) {\n          \
    \      x->rch->rch = splay(x->rch->rch, v);\n                x = leftRotate(x);\n\
    \            }\n            return (x->rch == NULL) ? x : leftRotate(x);\n   \
    \     }\n    }\n    node *insert(node *x, T v) {\n        if (x == NULL) {\n \
    \           node *q = new node;\n            q->val = v;\n            q->lch =\
    \ q->rch = NULL;\n            return q;\n        }\n        if (v < x->val)\n\
    \            x->lch = insert(x->lch, v);\n        else\n            x->rch = insert(x->rch,\
    \ v);\n        return x;\n    }\n    node *erase(node *x, T v) {\n        if (x\
    \ == NULL) return NULL;\n        if (v < x->val)\n            x->lch = erase(x->lch,\
    \ v);\n        else if (x->val < v)\n            x->rch = erase(x->rch, v);\n\
    \        else if (x->lch == NULL) {\n            node *q = x->rch;\n         \
    \   delete x;\n            return q;\n        } else if (x->lch->rch == NULL)\
    \ {\n            node *q = x->lch;\n            q->rch = x->rch;\n           \
    \ delete x;\n            return q;\n        } else {\n            node *q;\n \
    \           for (q = x->lch; q->rch->rch != NULL; q = q->rch)\n              \
    \  ;\n            node *r = q->rch;\n            q->rch = r->lch;\n          \
    \  r->lch = x->lch;\n            r->rch = x->rch;\n            delete x;\n   \
    \         return r;\n        }\n        return x;\n    }\n\n   public:\n    ll\
    \ size() {\n        return sz;\n    }\n    node *find(T x) {\n        root = splay(root,\
    \ x);\n        if (root == NULL || root->val != x) return NULL;\n        return\
    \ root;\n    }\n    void insert(T x) {\n        if (!find(x)) {\n            root\
    \ = insert(root, x);\n            sz++;\n        }\n    }\n    void erase(T x)\
    \ {\n        if (find(x)) {\n            root = erase(root, x);\n            sz--;\n\
    \        }\n    }\n    node *lower_bound(T x) {\n        root = splay(root, x);\n\
    \        if (root == NULL || root->val >= x) return root;\n        if (root->rch\
    \ == NULL) return NULL;\n        node *q;\n        for (q = root->rch; q->lch\
    \ != NULL; q = q->lch)\n            ;\n        return q;\n    }\n    node *upper_bound(T\
    \ x) {\n        root = splay(root, x);\n        if (root == NULL || root->val\
    \ > x) return root;\n        if (root->rch == NULL) return NULL;\n        node\
    \ *q;\n        for (q = root->rch; q->lch != NULL; q = q->lch)\n            ;\n\
    \        return q;\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.cpp\"\n\ntemplate <class T>\n\
    class SplayTree {\n    struct node {\n        T val;\n        node *lch, *rch;\n\
    \    };\n    node *root = NULL;\n    ll sz = 0;\n    node *rightRotate(node *x)\
    \ {\n        node *y = x->lch;\n        x->lch = y->rch;\n        y->rch = x;\n\
    \        return y;\n    }\n    node *leftRotate(node *x) {\n        node *y =\
    \ x->rch;\n        x->rch = y->lch;\n        y->lch = x;\n        return y;\n\
    \    }\n    node *splay(node *x, T v) {\n        if (x == NULL || x->val == v)\
    \ return x;\n        if (v < x->val) {\n            if (x->lch == NULL) return\
    \ x;\n            if (v < x->lch->val) {\n                x->lch->lch = splay(x->lch->lch,\
    \ v);\n                x = rightRotate(x);\n            } else if (x->lch->val\
    \ < v) {\n                x->lch->rch = splay(x->lch->rch, v);\n             \
    \   if (x->lch->rch != NULL)\n                    x->lch = leftRotate(x->lch);\n\
    \            }\n            return (x->lch == NULL) ? x : rightRotate(x);\n  \
    \      } else {\n            if (x->rch == NULL) return x;\n            if (v\
    \ < x->rch->val) {\n                x->rch->lch = splay(x->rch->lch, v);\n   \
    \             if (x->rch->lch != NULL)\n                    x->rch = rightRotate(x->rch);\n\
    \            } else if (x->rch->val < v) {\n                x->rch->rch = splay(x->rch->rch,\
    \ v);\n                x = leftRotate(x);\n            }\n            return (x->rch\
    \ == NULL) ? x : leftRotate(x);\n        }\n    }\n    node *insert(node *x, T\
    \ v) {\n        if (x == NULL) {\n            node *q = new node;\n          \
    \  q->val = v;\n            q->lch = q->rch = NULL;\n            return q;\n \
    \       }\n        if (v < x->val)\n            x->lch = insert(x->lch, v);\n\
    \        else\n            x->rch = insert(x->rch, v);\n        return x;\n  \
    \  }\n    node *erase(node *x, T v) {\n        if (x == NULL) return NULL;\n \
    \       if (v < x->val)\n            x->lch = erase(x->lch, v);\n        else\
    \ if (x->val < v)\n            x->rch = erase(x->rch, v);\n        else if (x->lch\
    \ == NULL) {\n            node *q = x->rch;\n            delete x;\n         \
    \   return q;\n        } else if (x->lch->rch == NULL) {\n            node *q\
    \ = x->lch;\n            q->rch = x->rch;\n            delete x;\n           \
    \ return q;\n        } else {\n            node *q;\n            for (q = x->lch;\
    \ q->rch->rch != NULL; q = q->rch)\n                ;\n            node *r = q->rch;\n\
    \            q->rch = r->lch;\n            r->lch = x->lch;\n            r->rch\
    \ = x->rch;\n            delete x;\n            return r;\n        }\n       \
    \ return x;\n    }\n\n   public:\n    ll size() {\n        return sz;\n    }\n\
    \    node *find(T x) {\n        root = splay(root, x);\n        if (root == NULL\
    \ || root->val != x) return NULL;\n        return root;\n    }\n    void insert(T\
    \ x) {\n        if (!find(x)) {\n            root = insert(root, x);\n       \
    \     sz++;\n        }\n    }\n    void erase(T x) {\n        if (find(x)) {\n\
    \            root = erase(root, x);\n            sz--;\n        }\n    }\n   \
    \ node *lower_bound(T x) {\n        root = splay(root, x);\n        if (root ==\
    \ NULL || root->val >= x) return root;\n        if (root->rch == NULL) return\
    \ NULL;\n        node *q;\n        for (q = root->rch; q->lch != NULL; q = q->lch)\n\
    \            ;\n        return q;\n    }\n    node *upper_bound(T x) {\n     \
    \   root = splay(root, x);\n        if (root == NULL || root->val > x) return\
    \ root;\n        if (root->rch == NULL) return NULL;\n        node *q;\n     \
    \   for (q = root->rch; q->lch != NULL; q = q->lch)\n            ;\n        return\
    \ q;\n    }\n};"
  dependsOn:
  - template/template.cpp
  isVerificationFile: false
  path: structure/SplayTree.cpp
  requiredBy: []
  timestamp: '2021-05-15 13:43:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/SplayTree.cpp
layout: document
redirect_from:
- /library/structure/SplayTree.cpp
- /library/structure/SplayTree.cpp.html
title: structure/SplayTree.cpp
---
