#pragma once
#include "../template/template.cpp"

ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll modinv(ll a, ll m) {
    ll x, y;
    extGCD(a, m, x, y);
    return (x % m + m) % m;
}