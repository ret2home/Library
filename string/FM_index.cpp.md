---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/BWT.cpp
    title: Burrows Wheeler Transform
  - icon: ':heavy_check_mark:'
    path: string/SuffixArray.cpp
    title: Suffix Array (SA-IS)
  - icon: ':heavy_check_mark:'
    path: structure/BitVector.cpp
    title: Bit Vector
  - icon: ':heavy_check_mark:'
    path: structure/WaveletMatrix.cpp
    title: Wavelet Matrix
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FM_index.test.cpp
    title: test/FM_index.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/FM_index.md
    document_title: FM Index
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
    \ false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/BitVector.cpp\"\n\n\
    class BitVector {\n    vector<ll> sum;\n    vector<uint64_t> bit;\n\n   public:\n\
    \    ll rank(bool val, ll idx) {\n        uint64_t mask = ((uint64_t)1 << (idx\
    \ & ((1 << 6) - 1))) - 1;\n        ll res = sum[idx >> 6] + __builtin_popcountll(bit[idx\
    \ >> 6] & mask);\n        return (val ? res : idx - res);\n    }\n    BitVector(vector<bool>&\
    \ v) {\n        ll sz = (len(v) >> 6) + 1;\n        bit.assign(sz, 0);\n     \
    \   sum.assign(sz, 0);\n        rep(i, len(v)) {\n            bit[i >> 6] |= (uint64_t)(v[i])\
    \ << (i & ((1 << 6) - 1));\n        }\n        rep(i, sz - 1) {\n            sum[i\
    \ + 1] = sum[i] + __builtin_popcountll(bit[i]);\n        }\n    }\n};\n/*\n@brief\
    \ Bit Vector\n@docs docs/BitVector.md\n*/\n#line 4 \"structure/WaveletMatrix.cpp\"\
    \n\ntemplate <class T, class C>\nclass WaveletMatrix {\n    int N, bitlen;\n \
    \   vector<BitVector> index;\n    map<C, int> st;\n\n   public:\n    T body;\n\
    \    int rank(C c, int idx) {\n        if (st.find(c) == st.end()) return 0;\n\
    \        rev(i, bitlen) {\n            if (c >> i & 1)\n                idx =\
    \ index[i].rank(1, idx) + index[i].rank(0, N);\n            else\n           \
    \     idx -= index[i].rank(1, idx);\n        }\n        return max(0, idx - st[c]);\n\
    \    }\n    C quantile(int l, int r, int c) {\n        C res = 0;\n        rev(i,\
    \ bitlen) {\n            ll cnt = (r - l) - (index[i].rank(1, r) - index[i].rank(1,\
    \ l));\n            if (cnt <= c) {\n                c -= cnt;\n             \
    \   l = index[i].rank(0, N) + index[i].rank(1, l);\n                r = index[i].rank(0,\
    \ N) + index[i].rank(1, r);\n                res += 1ll << i;\n            } else\
    \ {\n                l -= index[i].rank(1, l);\n                r -= index[i].rank(1,\
    \ r);\n            }\n        }\n        return res;\n    }\n    WaveletMatrix(T\
    \ V, ll bitlen) : N(len(V)), bitlen(bitlen), body(V) {\n        vector<bool> bit(N);\n\
    \        index.resize(bitlen, bit);\n        rev(i, bitlen) {\n            T newV[2];\n\
    \            rep(j, N) {\n                bit[j] = (V[j] >> i & 1);\n        \
    \        newV[V[j] >> i & 1].push_back(V[j]);\n            }\n            V =\
    \ newV[0];\n            V.insert(V.end(), all(newV[1]));\n            index[i]\
    \ = BitVector(bit);\n        }\n        rep(i, N) if (st.find(V[i]) == st.end())\
    \ st[V[i]] = i;\n    }\n};\n/*\n@brief Wavelet Matrix\n@docs docs/WaveletMatrix.md\n\
    */\n#line 3 \"string/SuffixArray.cpp\"\n\ntemplate <class T>\nclass SuffixArray\
    \ {\n#define typeS make_pair(false, false)\n#define LMS make_pair(false, true)\n\
    #define typeL make_pair(true, true)\n    using TYPE = pair<bool, bool>;\n    vector<TYPE>\
    \ assignType(vector<ll> &S) {\n        vector<TYPE> type(len(S));\n        type[len(S)\
    \ - 1] = LMS;\n        for (ll i = len(S) - 2; i >= 0; i--) {\n            if\
    \ (S[i] < S[i + 1])\n                type[i] = typeS;\n            else if (S[i]\
    \ > S[i + 1]) {\n                type[i] = typeL;\n                if (type[i\
    \ + 1] == typeS) type[i + 1] = LMS;\n            } else\n                type[i]\
    \ = type[i + 1];\n        }\n        return type;\n    }\n    vector<ll> getBucket(vector<ll>\
    \ &S, ll alph) {\n        vector<ll> bucket(alph);\n        for (ll i : S) bucket[i]++;\n\
    \        rep(i, len(bucket) - 1) bucket[i + 1] += bucket[i];\n        return bucket;\n\
    \    }\n    void sortTypeL(vector<ll> &S, vector<ll> &SA, vector<TYPE> &type,\
    \ ll alph) {\n        vector<ll> bucket = getBucket(S, alph);\n        for (ll\
    \ i : SA) {\n            if (i > 0 && type[i - 1] == typeL) SA[bucket[S[i - 1]\
    \ - 1]++] = i - 1;\n        }\n    }\n    void sortTypeS(vector<ll> &S, vector<ll>\
    \ &SA, vector<TYPE> &type, ll alph) {\n        vector<ll> bucket = getBucket(S,\
    \ alph);\n        rev(j, len(S)) {\n            ll i = SA[j];\n            if\
    \ (i > 0 && (type[i - 1] == typeS || type[i - 1] == LMS)) SA[--bucket[S[i - 1]]]\
    \ = i - 1;\n        }\n    }\n    vector<ll> InducedSorting(vector<ll> &S, ll\
    \ alph) {\n        vector<ll> SA(len(S), -1);\n        vector<TYPE> type = assignType(S);\n\
    \        vector<ll> bucket = getBucket(S, alph);\n        vector<ll> nextlms(len(S),\
    \ -1), ordered_lms;\n        ll lastlms = -1;\n        rep(i, len(S)) if (type[i]\
    \ == LMS) {\n            SA[--bucket[S[i]]] = i;\n            if (lastlms != -1)\
    \ nextlms[lastlms] = i;\n            lastlms = i;\n            ordered_lms.emplace_back(i);\n\
    \        }\n        nextlms[lastlms] = lastlms;\n        sortTypeL(S, SA, type,\
    \ alph);\n        sortTypeS(S, SA, type, alph);\n        vector<ll> lmses;\n \
    \       for (ll i : SA)\n            if (type[i] == LMS) lmses.emplace_back(i);\n\
    \        ll nowrank = 0;\n        vector<ll> newS = {0};\n        REP(i, len(lmses))\
    \ {\n            ll pre = lmses[i - 1], now = lmses[i];\n            if (nextlms[pre]\
    \ - pre != nextlms[now] - now)\n                newS.emplace_back(++nowrank);\n\
    \            else {\n                bool flag = false;\n                rep(j,\
    \ nextlms[pre] - pre + 1) {\n                    if (S[pre + j] != S[now + j])\
    \ {\n                        flag = true;\n                        break;\n  \
    \                  }\n                }\n                if (flag)\n         \
    \           newS.emplace_back(++nowrank);\n                else\n            \
    \        newS.emplace_back(nowrank);\n            }\n        }\n        if (nowrank\
    \ + 1 != len(lmses)) {\n            vector<ll> V(len(S), -1);\n            rep(i,\
    \ len(lmses)) {\n                V[lmses[i]] = newS[i];\n            }\n     \
    \       vector<ll> newnewS;\n            rep(i, len(S)) if (V[i] != -1) newnewS.emplace_back(V[i]);\n\
    \            vector<ll> SA_ = InducedSorting(newnewS, nowrank + 1);\n        \
    \    rep(i, len(SA_)) {\n                lmses[i] = ordered_lms[SA_[i]];\n   \
    \         }\n        }\n        SA.assign(len(S), -1);\n        bucket = getBucket(S,\
    \ alph);\n        rev(i, len(lmses)) {\n            SA[--bucket[S[lmses[i]]]]\
    \ = lmses[i];\n        }\n        sortTypeL(S, SA, type, alph);\n        sortTypeS(S,\
    \ SA, type, alph);\n        return SA;\n    }\n    vector<ll> SA;\n    T ST;\n\
    \n   private:\n    ll ismatch(T &S, ll index) {\n        rep(i, len(S)) {\n  \
    \          if (i + index >= len(ST)) return 1;\n            if (ST[i + index]\
    \ < S[i]) return 1;\n            if (ST[i + index] > S[i]) return -1;\n      \
    \  }\n        return 0;\n    }\n\n   public:\n    PL occ(T &S) {\n        ll okl\
    \ = len(ST) + 1, ngl = 0;\n        while (okl - ngl > 1) {\n            ll mid\
    \ = (okl + ngl) / 2;\n            if (ismatch(S, SA[mid]) <= 0)\n            \
    \    okl = mid;\n            else\n                ngl = mid;\n        }\n   \
    \     ll okr = len(ST) + 1, ngr = 0;\n        while (okr - ngr > 1) {\n      \
    \      ll mid = (okr + ngr) / 2;\n            if (ismatch(S, SA[mid]) < 0)\n \
    \               okr = mid;\n            else\n                ngr = mid;\n   \
    \     }\n        return PL(okl, okr);\n    }\n    vector<ll> locate(T &S) {\n\
    \        vector<bool> v(len(ST) + 1);\n        PL range = occ(S);\n        for\
    \ (ll i = range.first; i < range.second; i++) v[SA[i]] = true;\n        vector<ll>\
    \ res;\n        rep(i, len(ST) + 1) if (v[i]) res.emplace_back(i);\n        return\
    \ res;\n    }\n    ll operator[](ll k) { return SA[k]; }\n\n   public:\n    vector<ll>\
    \ LCP;\n\n   private:\n    void constructLCP() {\n        vector<ll> rank(len(ST)\
    \ + 1);\n        LCP.resize(len(ST) + 1);\n        rep(i, len(ST) + 1) rank[SA[i]]\
    \ = i;\n        ll h = 0;\n        rep(i, len(ST)) {\n            ll j = SA[rank[i]\
    \ - 1];\n            if (h > 0) h--;\n            for (j; j + h < len(ST) && i\
    \ + h < len(ST); h++) {\n                if (ST[j + h] != ST[i + h]) break;\n\
    \            }\n            LCP[rank[i] - 1] = h;\n        }\n    }\n\n   public:\n\
    \    SuffixArray(T S) : ST(S) {\n        ll mn = inf, mx = -inf;\n        for\
    \ (auto i : S) {\n            chmin(mn, (ll)i);\n            chmax(mx, (ll)i);\n\
    \        }\n        vector<ll> newS;\n        for (auto i : S) newS.emplace_back(i\
    \ - mn + 1);\n        newS.emplace_back(0);\n        SA = InducedSorting(newS,\
    \ mx - mn + 2);\n        constructLCP();\n    }\n};\n\n/*\n@brief Suffix Array\
    \ (SA-IS)\n@docs docs/SuffixArray.md\n*/\n#line 4 \"string/BWT.cpp\"\n\ntemplate\
    \ <class T>\nT BWT(T S, SuffixArray<T>& SA) {\n    S += '$';\n    T bwt;\n   \
    \ rep(i, len(S)) {\n        bwt.push_back(S[(SA[i] - 1 + len(S)) % len(S)]);\n\
    \    }\n    return bwt;\n}\n\ntemplate <class T>\nT BWTInverse(T S) {\n    vector<ll>\
    \ B(len(S));\n    ll mx = -inf;\n    rep(i, len(S)) {\n        B[i] = (S[i] ==\
    \ '$' ? 0 : (ll)S[i]);\n        chmax(mx, B[i]);\n    }\n    vector<vector<ll>>\
    \ BB(mx + 1), F(mx + 1);\n    vector<PL> V;\n    rep(i, len(S)) {\n        BB[B[i]].push_back(i);\n\
    \        F[B[i]].push_back(i);\n    }\n    ll cnt = 0;\n    rep(i, mx + 1) {\n\
    \        rep(j, len(F[i])) {\n            F[i][j] = cnt++;\n            V.push_back({i,\
    \ j});\n        }\n    }\n    ll now = BB[0][0];\n    T res;\n    rep(i, len(S)\
    \ - 1) {\n        res.push_back(V[now].first);\n        now = BB[V[now].first][V[now].second];\n\
    \    }\n    return res;\n}\n/*\n@brief Burrows Wheeler Transform\n@docs docs/BWT.md\n\
    */\n#line 5 \"string/FM_index.cpp\"\n\ntemplate <class T, class C>\nclass FMIndex\
    \ {\n    ll N, base;\n    T bwt;\n    vector<ll> c;\n    WaveletMatrix<T, C> WM;\n\
    \    SuffixArray<T> SA;\n\n   public:\n    T ST;\n    PL occ(T &S) {\n       \
    \ for (auto i : S)\n            if ((ll)i < base || (ll)i - base >= len(c)) return\
    \ PL(0, 0);\n        ll sp = 0, ep = N;\n        rev(i, len(S)) {\n          \
    \  sp = c[(ll)S[i] - base] + WM.rank(S[i], sp);\n            ep = c[(ll)S[i] -\
    \ base] + WM.rank(S[i], ep);\n            if (sp >= ep) return PL(0, 0);\n   \
    \     }\n        return PL(sp, ep);\n    }\n    vector<ll> locate(T &S) {\n  \
    \      vector<bool> v(len(ST) + 1);\n        PL range = occ(S);\n        for (ll\
    \ i = range.first; i < range.second; i++) v[SA[i]] = true;\n        vector<ll>\
    \ res;\n        rep(i, len(ST) + 1) if (v[i]) res.emplace_back(i);\n        return\
    \ res;\n    }\n    FMIndex(T S) : N(len(S) + 1), ST(S + '$'), WM(\"\", 0), SA(S)\
    \ {\n        bwt = BWT(S, SA);\n        WM = WaveletMatrix<T, C>(bwt, 8);\n  \
    \      ll mn = inf, mx = -inf;\n        for (C i : ST) {\n            chmin(mn,\
    \ (ll)i);\n            chmax(mx, (ll)i);\n        }\n        c.resize(mx - mn\
    \ + 2);\n        for (C i : ST) {\n            c[(ll)i - mn + 1]++;\n        }\n\
    \        rep(i, mx - mn + 1) c[i + 1] += c[i];\n        base = mn;\n    }\n};\n\
    /*\n@brief FM Index\n@docs docs/FM_index.md\n*/\n"
  code: "#pragma once\n#include \"../structure/WaveletMatrix.cpp\"\n#include \"../template/template.cpp\"\
    \n#include \"BWT.cpp\"\n\ntemplate <class T, class C>\nclass FMIndex {\n    ll\
    \ N, base;\n    T bwt;\n    vector<ll> c;\n    WaveletMatrix<T, C> WM;\n    SuffixArray<T>\
    \ SA;\n\n   public:\n    T ST;\n    PL occ(T &S) {\n        for (auto i : S)\n\
    \            if ((ll)i < base || (ll)i - base >= len(c)) return PL(0, 0);\n  \
    \      ll sp = 0, ep = N;\n        rev(i, len(S)) {\n            sp = c[(ll)S[i]\
    \ - base] + WM.rank(S[i], sp);\n            ep = c[(ll)S[i] - base] + WM.rank(S[i],\
    \ ep);\n            if (sp >= ep) return PL(0, 0);\n        }\n        return\
    \ PL(sp, ep);\n    }\n    vector<ll> locate(T &S) {\n        vector<bool> v(len(ST)\
    \ + 1);\n        PL range = occ(S);\n        for (ll i = range.first; i < range.second;\
    \ i++) v[SA[i]] = true;\n        vector<ll> res;\n        rep(i, len(ST) + 1)\
    \ if (v[i]) res.emplace_back(i);\n        return res;\n    }\n    FMIndex(T S)\
    \ : N(len(S) + 1), ST(S + '$'), WM(\"\", 0), SA(S) {\n        bwt = BWT(S, SA);\n\
    \        WM = WaveletMatrix<T, C>(bwt, 8);\n        ll mn = inf, mx = -inf;\n\
    \        for (C i : ST) {\n            chmin(mn, (ll)i);\n            chmax(mx,\
    \ (ll)i);\n        }\n        c.resize(mx - mn + 2);\n        for (C i : ST) {\n\
    \            c[(ll)i - mn + 1]++;\n        }\n        rep(i, mx - mn + 1) c[i\
    \ + 1] += c[i];\n        base = mn;\n    }\n};\n/*\n@brief FM Index\n@docs docs/FM_index.md\n\
    */"
  dependsOn:
  - structure/WaveletMatrix.cpp
  - template/template.cpp
  - structure/BitVector.cpp
  - string/BWT.cpp
  - string/SuffixArray.cpp
  isVerificationFile: false
  path: string/FM_index.cpp
  requiredBy: []
  timestamp: '2021-05-15 13:43:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FM_index.test.cpp
documentation_of: string/FM_index.cpp
layout: document
redirect_from:
- /library/string/FM_index.cpp
- /library/string/FM_index.cpp.html
title: FM Index
---
## 概要

高速な全文検索を提供する FM Indexの実装。JOI 夏季セミナー 2020 の成果物。

- ```occ(T)``` : ```T``` が登場するSuffix Array上の区間
- ```locate(T)``` : ```T``` が登場する index の集合

Suffix Arrayと同じ。

## 計算量

- 構築 : $O(\mid S \mid)$
- クエリ : $O(\mid T \mid log\ \sigma)$ ($\sigma$ は文字の種類数で、26とか)

Suffix Arrayはクエリが $O(\mid T \mid log \mid S \mid)$ なのに対し、こちらの方が速いのが特長。

ただし、Suffix Arrayの方のクエリは定数倍が軽いので実際はあんまり変わらない事もある。