---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extgcd.cpp
    title: math/extgcd.cpp
  - icon: ':heavy_check_mark:'
    path: math/modint.cpp
    title: mod int
  - icon: ':heavy_check_mark:'
    path: structure/SegmentTree.cpp
    title: Lazy Segment Tree
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/SegmentTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#line 2 \"template/template.cpp\"\n#include <algorithm>\n#include <bitset>\n\
    #include <complex>\n#include <deque>\n#include <exception>\n#include <fstream>\n\
    #include <functional>\n#include <iomanip>\n#include <ios>\n#include <iosfwd>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <locale>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <stdexcept>\n#include <streambuf>\n\
    #include <string>\n#include <typeinfo>\n#include <utility>\n#include <valarray>\n\
    #include <vector>\n#include <array>\n#include <atomic>\n#include <chrono>\n#include\
    \ <codecvt>\n#include <condition_variable>\n#include <forward_list>\n#include\
    \ <future>\n#include <initializer_list>\n#include <mutex>\n#include <random>\n\
    #include <ratio>\n#include <regex>\n#include <scoped_allocator>\n#include <system_error>\n\
    #include <thread>\n#include <tuple>\n#include <typeindex>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\nusing namespace std;\n#define\
    \ ll long long\n#define rep(i, n) for (int i = 0; i < n; i++)\n#define REP(i,\
    \ n) for (int i = 1; i < n; i++)\n#define rev(i, n) for (int i = n - 1; i >= 0;\
    \ i--)\n#define REV(i, n) for (int i = n - 1; i > 0; i--)\n#define all(v) v.begin(),\
    \ v.end()\n#define PL pair<ll, ll>\n#define PI pair<int,int>\n#define len(s) (int)s.size()\n\
    #define compress(v) sort(all(v)); v.erase(unique(all(v)),v.end());\n#define comid(v,x)\
    \ lower_bound(all(v),x)-v.begin()\n\ntemplate <class T, class U>\ninline bool\
    \ chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\ntemplate <class T, class U>\ninline bool chmax(T\
    \ &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\nconstexpr ll inf = 3e18;\n#line 3 \"structure/SegmentTree.cpp\"\
    \n\ntemplate <typename Monoid,\n          typename OperatorMonoid,\n         \
    \ Monoid (*f)(Monoid, Monoid, int),\n          Monoid (*g)(Monoid, OperatorMonoid,\
    \ int),\n          OperatorMonoid (*h)(OperatorMonoid, OperatorMonoid, int)>\n\
    struct Segtree {\n    int size = 1;\n\n   private:\n    vector<Monoid> dat;\n\
    \    vector<OperatorMonoid> lazy;\n    Monoid M;\n    OperatorMonoid OM;\n\n \
    \  public:\n    void eval(int k, int l, int r) {\n        if (lazy[k] != OM) {\n\
    \            dat[k] = g(dat[k], lazy[k], r - l);\n            if (r - l > 1) {\n\
    \                lazy[(k << 1) + 1] = h(lazy[(k << 1) + 1], lazy[k], r - l);\n\
    \                lazy[(k << 1) + 2] = h(lazy[(k << 1) + 2], lazy[k], r - l);\n\
    \            }\n            lazy[k] = OM;\n        }\n    }\n    void update(int\
    \ a, int b, OperatorMonoid M, int k = 0, int l = 0, int r = -1) {\n        if\
    \ (r == -1) r = size;\n        eval(k, l, r);\n        if (r <= a || b <= l) return;\n\
    \        if (a <= l && r <= b) {\n            lazy[k] = h(lazy[k], M, r - l);\n\
    \            eval(k, l, r);\n            return;\n        }\n        update(a,\
    \ b, M, (k << 1) + 1, l, (l + r) >> 1);\n        update(a, b, M, (k << 1) + 2,\
    \ (l + r) >> 1, r);\n        dat[k] = f(dat[(k << 1) + 1], dat[(k << 1) + 2],\
    \ r - l);\n    }\n    Monoid query(int a, int b, int k = 0, int l = 0, int r =\
    \ -1) {\n        if (r == -1) r = size;\n        eval(k, l, r);\n        if (r\
    \ <= a || b <= l) return M;\n        if (a <= l && r <= b) return dat[k];\n  \
    \      Monoid lv = query(a, b, (k << 1) + 1, l, (l + r) >> 1);\n        Monoid\
    \ rv = query(a, b, (k << 1) + 2, (l + r) >> 1, r);\n        return f(lv, rv, r\
    \ - l);\n    }\n    template <class C>\n    int minLeft(int a, int b, C &check,\
    \ Monoid x, int k = 0, int l = 0, int r = -1) {\n        if (r == -1) r = size;\n\
    \        eval(k, l, r);\n        if (r <= a || b <= l || !check(dat[k], x)) return\
    \ -1;\n        if (r - l == 1) return l;\n        int lv = minLeft(a, b, check,\
    \ x, (k << 1) + 1, l, (l + r) >> 1);\n        if (lv != -1) return lv;\n     \
    \   return minLeft(a, b, check, x, (k << 1) + 2, (l + r) >> 1, r);\n    }\n  \
    \  template <class C>\n    int maxRight(int a, int b, C &check, Monoid x, int\
    \ k = 0, int l = 0, int r = -1) {\n        if (r == -1) r = size;\n        eval(k,\
    \ l, r);\n        if (r <= a || b <= l || !check(dat[k], x)) return -1;\n    \
    \    if (r - l == 1) return l;\n        int rv = maxRight(a, b, check, x, (k <<\
    \ 1) + 2, (l + r) >> 1, r);\n        if (rv != -1) return rv;\n        return\
    \ maxRight(a, b, check, x, (k << 1) + 1, l, (l + r) >> 1);\n    }\n    void set(int\
    \ a, Monoid x) {\n        dat[a + size - 1] = x;\n    }\n    void init(int k =\
    \ 0, int l = 0, int r = -1) {\n        if (r == -1) r = size;\n        if (r -\
    \ l == 1) return;\n        init((k << 1) + 1, l, (l + r) >> 1);\n        init((k\
    \ << 1) + 2, (l + r) >> 1, r);\n        dat[k] = f(dat[k * 2 + 1], dat[k * 2 +\
    \ 2], r - l);\n    }\n    Segtree(int x, Monoid M, OperatorMonoid OM)\n      \
    \  : M(M), OM(OM) {\n        while (size < x) size <<= 1;\n        dat.resize((size\
    \ << 1) - 1, M);\n        lazy.resize((size << 1) - 1, OM);\n    }\n};\n\n/*\n\
    @brief Lazy Segment Tree\n@docs docs/SegmentTree.md\n*/\n#line 3 \"math/extgcd.cpp\"\
    \n\nll extGCD(ll a, ll b, ll &x, ll &y) {\n    if (!b) {\n        x = 1;\n   \
    \     y = 0;\n        return a;\n    }\n    ll d = extGCD(b, a % b, y, x);\n \
    \   y -= a / b * x;\n    return d;\n}\n\nll modinv(ll a, ll m) {\n    ll x, y;\n\
    \    extGCD(a, m, x, y);\n    return (x % m + m) % m;\n}\n#line 4 \"math/modint.cpp\"\
    \n\ntemplate <int MOD>\nstruct mint {\n    int32_t n;\n    mint() : n(0) {}\n\
    \    mint(ll x) : n(x >= 0 ? x % MOD : (MOD - (-x) % MOD) % MOD) {}\n\n    mint\
    \ &operator+=(const mint &p) {\n        if ((n += p.n) >= MOD) n -= MOD;\n   \
    \     return *this;\n    }\n    mint &operator-=(const mint &p) {\n        if\
    \ ((n += MOD - p.n) >= MOD) n -= MOD;\n        return *this;\n    }\n    mint\
    \ &operator*=(const mint &p) {\n        n = 1ll * n * p.n % MOD;\n        return\
    \ *this;\n    }\n    mint &operator/=(const mint &p) {\n        *this *= p.inverse();\n\
    \        return *this;\n    }\n    mint operator-() const { return mint(-n); }\n\
    \    mint operator+(const mint &p) const { return mint(*this) += p; }\n    mint\
    \ operator-(const mint &p) const { return mint(*this) -= p; }\n    mint operator*(const\
    \ mint &p) const { return mint(*this) *= p; }\n    mint operator/(const mint &p)\
    \ const { return mint(*this) /= p; }\n    bool operator==(const mint &p) const\
    \ { return n == p.n; }\n    bool operator!=(const mint &p) const { return n !=\
    \ p.n; }\n\n    friend ostream &operator<<(ostream &os, const mint &p) {\n   \
    \     return os << p.n;\n    }\n    friend istream &operator>>(istream &is, mint\
    \ &p) {\n        int x;\n        is >> x;\n        p = mint(x);\n        return\
    \ is;\n    }\n    mint pow(int64_t x) const {\n        mint res(1), mul(n);\n\
    \        while (x > 0) {\n            if (x & 1) res *= mul;\n            mul\
    \ *= mul;\n            x >>= 1;\n        }\n        return res;\n    }\n    mint\
    \ inverse() const {\n        return mint(modinv(n,MOD));\n    }\n};\n/*\n@brief\
    \ mod int\n@docs docs/modint.md\n*/\n#line 5 \"test/SegmentTree.test.cpp\"\n\n\
    constexpr int mod=998244353;\n\nusing modint=mint<mod>;\n \nusing PM=pair<modint,modint>;\n\
    auto f=[](modint a,modint b,int sz)->modint{return a+b;};\nauto g=[](modint a,PM\
    \ b,int sz)->modint{return a*b.first+b.second*modint(sz);};\nauto h=[](PM a,PM\
    \ b,int sz)->PM{return PM(a.first*b.first,a.second*b.first+b.second);};\n \nint\
    \ main(){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q;\n\tcin>>N>>Q;\n\
    \tSegtree<modint,PM,f,g,h>segtree(N,0,PM(1,0));\n\trep(i,N){\n\t\tint a;cin>>a;\n\
    \t\tsegtree.update(i,i+1,PM(1,a));\n\t}\n\twhile(Q--){\n\t\tint t;cin>>t;\n\t\t\
    if(!t){\n\t\t\tint l,r,b,c;cin>>l>>r>>b>>c;\n\t\t\tsegtree.update(l,r,PM(b,c));\n\
    \t\t}else {\n\t\t\tint l,r;cin>>l>>r;\n\t\t\tcout<<segtree.query(l,r)<<\"\\n\"\
    ;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../structure/SegmentTree.cpp\"\n#include \"../math/modint.cpp\"\
    \n\nconstexpr int mod=998244353;\n\nusing modint=mint<mod>;\n \nusing PM=pair<modint,modint>;\n\
    auto f=[](modint a,modint b,int sz)->modint{return a+b;};\nauto g=[](modint a,PM\
    \ b,int sz)->modint{return a*b.first+b.second*modint(sz);};\nauto h=[](PM a,PM\
    \ b,int sz)->PM{return PM(a.first*b.first,a.second*b.first+b.second);};\n \nint\
    \ main(){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q;\n\tcin>>N>>Q;\n\
    \tSegtree<modint,PM,f,g,h>segtree(N,0,PM(1,0));\n\trep(i,N){\n\t\tint a;cin>>a;\n\
    \t\tsegtree.update(i,i+1,PM(1,a));\n\t}\n\twhile(Q--){\n\t\tint t;cin>>t;\n\t\t\
    if(!t){\n\t\t\tint l,r,b,c;cin>>l>>r>>b>>c;\n\t\t\tsegtree.update(l,r,PM(b,c));\n\
    \t\t}else {\n\t\t\tint l,r;cin>>l>>r;\n\t\t\tcout<<segtree.query(l,r)<<\"\\n\"\
    ;\n\t\t}\n\t}\n}"
  dependsOn:
  - structure/SegmentTree.cpp
  - template/template.cpp
  - math/modint.cpp
  - math/extgcd.cpp
  isVerificationFile: true
  path: test/SegmentTree.test.cpp
  requiredBy: []
  timestamp: '2021-09-10 20:11:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/SegmentTree.test.cpp
layout: document
redirect_from:
- /verify/test/SegmentTree.test.cpp
- /verify/test/SegmentTree.test.cpp.html
title: test/SegmentTree.test.cpp
---
