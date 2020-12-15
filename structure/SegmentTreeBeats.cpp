#pragma once
#include "../template/template.cpp"

struct SegtreeBeats {
    int size = 1;

   private:
    vector<ll> mx, smx, mxc;
    vector<ll> mn, smn, mnc;
    vector<ll> sum, lazy;
    vector<bool> flag;

    void update(int k) {
        sum[k] = sum[k * 2 + 1] + sum[k * 2 + 2];

        mx[k] = max(mx[2 * k + 1], mx[2 * k + 2]);
        if (mx[2 * k + 1] < mx[2 * k + 2]) {
            mxc[k] = mxc[2 * k + 2];
            smx[k] = max(mx[2 * k + 1], smx[2 * k + 2]);
        } else if (mx[2 * k + 1] > mx[2 * k + 2]) {
            mxc[k] = mxc[2 * k + 1];
            smx[k] = max(smx[2 * k + 1], mx[2 * k + 2]);
        } else {
            mxc[k] = mxc[2 * k + 1] + mxc[2 * k + 2];
            smx[k] = max(smx[2 * k + 1], smx[2 * k + 2]);
        }

        mn[k] = min(mn[2 * k + 1], mn[2 * k + 2]);
        if (mn[2 * k + 1] < mn[2 * k + 2]) {
            mnc[k] = mnc[2 * k + 1];
            smn[k] = min(smn[2 * k + 1], mn[2 * k + 2]);
        } else if (mn[2 * k + 1] > mn[2 * k + 2]) {
            mnc[k] = mnc[2 * k + 2];
            smn[k] = min(mn[2 * k + 1], smn[2 * k + 2]);
        } else {
            mnc[k] = mnc[2 * k + 1] + mnc[2 * k + 2];
            smn[k] = min(smn[2 * k + 1], smn[2 * k + 2]);
        }
    }
    void updateNodeMax(int k, ll x) {
        sum[k] += (x - mx[k]) * mxc[k];
        if (mx[k] == mn[k]) {
            mx[k] = mn[k] = x;
        } else if (mx[k] == smn[k]) {
            mx[k] = smn[k] = x;
        } else {
            mx[k] = x;
        }
    }
    void updateNodeMin(int k, ll x) {
        sum[k] += (x - mn[k]) * mnc[k];
        if (mx[k] == mn[k]) {
            mx[k] = mn[k] = x;
        } else if (smx[k] == mn[k]) {
            smx[k] = mn[k] = x;
        } else {
            mn[k] = x;
        }
    }
    void updateNodeAdd(int k, int len, ll x) {
        mx[k] += x;
        if (smx[k] != -inf) smx[k] += x;
        mn[k] += x;
        if (smn[k] != inf) smn[k] += x;
        sum[k] += x * len;
        lazy[k] += x;
    }
    void updateNodeAssign(int k, int len, ll x) {
        mx[k] = x;
        smx[k] = -inf;
        mxc[k] = len;
        mn[k] = x;
        smn[k] = inf;
        mnc[k] = len;
        sum[k] = x * len;
        lazy[k] = x;
        flag[k] = true;
    }
    void push(int k, int len) {
        if (k >= size - 1) return;
        if (flag[k] || lazy[k] != 0) {
            if (flag[k]) {
                updateNodeAssign(k * 2 + 1, len / 2, lazy[k]);
                updateNodeAssign(k * 2 + 2, len / 2, lazy[k]);
            } else {
                updateNodeAdd(k * 2 + 1, len / 2, lazy[k]);
                updateNodeAdd(k * 2 + 2, len / 2, lazy[k]);
            }
            lazy[k] = 0;
            flag[k] = false;
        }
        if (mx[k * 2 + 1] > mx[k]) updateNodeMax(k * 2 + 1, mx[k]);
        if (mx[k * 2 + 2] > mx[k]) updateNodeMax(k * 2 + 2, mx[k]);
        if (mn[k * 2 + 1] < mn[k]) updateNodeMin(k * 2 + 1, mn[k]);
        if (mn[k * 2 + 2] < mn[k]) updateNodeMin(k * 2 + 2, mn[k]);
    }

   public:
    void updateMin(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = size;
        if (r <= a || b <= l || mx[k] <= x) return;
        if (a <= l && r <= b && smx[k] < x) {
            updateNodeMax(k, x);
            return;
        }
        push(k, r - l);
        updateMin(a, b, x, k * 2 + 1, l, (l + r) / 2);
        updateMin(a, b, x, k * 2 + 2, (l + r) / 2, r);
        update(k);
    }
    void updateMax(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = size;
        if (r <= a || b <= l || mn[k] >= x) return;
        if (a <= l && r <= b && smn[k] > x) {
            updateNodeMin(k, x);
            return;
        }
        push(k, r - l);
        updateMax(a, b, x, k * 2 + 1, l, (l + r) / 2);
        updateMax(a, b, x, k * 2 + 2, (l + r) / 2, r);
        update(k);
    }
    void updateAdd(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = size;
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            updateNodeAdd(k, r - l, x);
            return;
        }
        push(k, r - l);
        updateAdd(a, b, x, k * 2 + 1, l, (l + r) / 2);
        updateAdd(a, b, x, k * 2 + 2, (l + r) / 2, r);
        update(k);
    }
    void updateAssign(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = size;
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            updateNodeAssign(k, r - l, x);
            return;
        }
        push(k, r - l);
        updateAssign(a, b, x, k * 2 + 1, l, (l + r) / 2);
        updateAssign(a, b, x, k * 2 + 2, (l + r) / 2, r);
        update(k);
    }

    void set(int k, ll x) {
        k += size - 1;
        mx[k] = x;
        mn[k] = x;
        sum[k] = x;
    }
    void init() {
        for (ll i = size - 2; i >= 0; i--) update(i);
    }
    ll queryMin(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = size;
        if (r <= a || b <= l) return inf;
        if (a <= l && r <= b) return mn[k];
        push(k, r - l);
        ll lv = queryMin(a, b, k * 2 + 1, l, (l + r) / 2);
        ll rv = queryMin(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(lv, rv);
    }
    ll queryMax(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = size;
        if (r <= a || b <= l) return -inf;
        if (a <= l && r <= b) return mx[k];
        push(k, r - l);
        ll lv = queryMax(a, b, k * 2 + 1, l, (l + r) / 2);
        ll rv = queryMax(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(lv, rv);
    }
    ll querySum(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = size;
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return sum[k];
        push(k, r - l);
        ll lv = querySum(a, b, k * 2 + 1, l, (l + r) / 2);
        ll rv = querySum(a, b, k * 2 + 2, (l + r) / 2, r);
        return lv + rv;
    }
    SegtreeBeats(int x) {
        while (size < x) size *= 2;
        mx.resize(size * 2 - 1, -inf + 1);
        smx.resize(size * 2 - 1, -inf);
        mxc.resize(size * 2 - 1, 1);
        mn.resize(size * 2 - 1, inf - 1);
        smn.resize(size * 2 - 1, inf);
        mnc.resize(size * 2 - 1, 1);
        sum.resize(size * 2 - 1);
        lazy.resize(size * 2 - 1);
        flag.resize(size * 2 - 1);
    }
};
