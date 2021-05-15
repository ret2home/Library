#pragma once
#include "../template/template.cpp"
#include "extgcd.cpp"

PL CRT(vector<ll> b, vector<ll> m) {
    ll r = 0, M = 1;
    rep(i, len(b)) {
        ll p, q;
        ll d = extGCD(M, m[i], p, q);
        if ((b[i] - r) % d) return PL(0, -1);
        ll tmp = (b[i] - r) / d * p % (m[i] / d);
        r += M * tmp;
        M *= m[i] / d;
    }
    return PL((r % M + M) % M, M);
}