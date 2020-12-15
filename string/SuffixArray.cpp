#pragma once
#include "../template/template.cpp"

template <class T>
class SuffixArray {
#define typeS make_pair(false, false)
#define LMS make_pair(false, true)
#define typeL make_pair(true, true)
    using TYPE = pair<bool, bool>;
    vector<TYPE> assignType(vector<ll> &S) {
        vector<TYPE> type(len(S));
        type[len(S) - 1] = LMS;
        for (ll i = len(S) - 2; i >= 0; i--) {
            if (S[i] < S[i + 1])
                type[i] = typeS;
            else if (S[i] > S[i + 1]) {
                type[i] = typeL;
                if (type[i + 1] == typeS) type[i + 1] = LMS;
            } else
                type[i] = type[i + 1];
        }
        return type;
    }
    vector<ll> getBucket(vector<ll> &S, ll alph) {
        vector<ll> bucket(alph);
        for (ll i : S) bucket[i]++;
        rep(i, len(bucket) - 1) bucket[i + 1] += bucket[i];
        return bucket;
    }
    void sortTypeL(vector<ll> &S, vector<ll> &SA, vector<TYPE> &type, ll alph) {
        vector<ll> bucket = getBucket(S, alph);
        for (ll i : SA) {
            if (i > 0 && type[i - 1] == typeL) SA[bucket[S[i - 1] - 1]++] = i - 1;
        }
    }
    void sortTypeS(vector<ll> &S, vector<ll> &SA, vector<TYPE> &type, ll alph) {
        vector<ll> bucket = getBucket(S, alph);
        rev(j, len(S)) {
            ll i = SA[j];
            if (i > 0 && (type[i - 1] == typeS || type[i - 1] == LMS)) SA[--bucket[S[i - 1]]] = i - 1;
        }
    }
    vector<ll> InducedSorting(vector<ll> &S, ll alph) {
        vector<ll> SA(len(S), -1);
        vector<TYPE> type = assignType(S);
        vector<ll> bucket = getBucket(S, alph);
        vector<ll> nextlms(len(S), -1), ordered_lms;
        ll lastlms = -1;
        rep(i, len(S)) if (type[i] == LMS) {
            SA[--bucket[S[i]]] = i;
            if (lastlms != -1) nextlms[lastlms] = i;
            lastlms = i;
            ordered_lms.emplace_back(i);
        }
        nextlms[lastlms] = lastlms;
        sortTypeL(S, SA, type, alph);
        sortTypeS(S, SA, type, alph);
        vector<ll> lmses;
        for (ll i : SA)
            if (type[i] == LMS) lmses.emplace_back(i);
        ll nowrank = 0;
        vector<ll> newS = {0};
        REP(i, len(lmses)) {
            ll pre = lmses[i - 1], now = lmses[i];
            if (nextlms[pre] - pre != nextlms[now] - now)
                newS.emplace_back(++nowrank);
            else {
                bool flag = false;
                rep(j, nextlms[pre] - pre + 1) {
                    if (S[pre + j] != S[now + j]) {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    newS.emplace_back(++nowrank);
                else
                    newS.emplace_back(nowrank);
            }
        }
        if (nowrank + 1 != len(lmses)) {
            vector<ll> V(len(S), -1);
            rep(i, len(lmses)) {
                V[lmses[i]] = newS[i];
            }
            vector<ll> newnewS;
            rep(i, len(S)) if (V[i] != -1) newnewS.emplace_back(V[i]);
            vector<ll> SA_ = InducedSorting(newnewS, nowrank + 1);
            rep(i, len(SA_)) {
                lmses[i] = ordered_lms[SA_[i]];
            }
        }
        SA.assign(len(S), -1);
        bucket = getBucket(S, alph);
        rev(i, len(lmses)) {
            SA[--bucket[S[lmses[i]]]] = lmses[i];
        }
        sortTypeL(S, SA, type, alph);
        sortTypeS(S, SA, type, alph);
        return SA;
    }
    vector<ll> SA;
    T ST;

   private:
    ll ismatch(T &S, ll index) {
        rep(i, len(S)) {
            if (i + index >= len(ST)) return 1;
            if (ST[i + index] < S[i]) return 1;
            if (ST[i + index] > S[i]) return -1;
        }
        return 0;
    }

   public:
    P occ(T &S) {
        ll okl = len(ST) + 1, ngl = 0;
        while (okl - ngl > 1) {
            ll mid = (okl + ngl) / 2;
            if (ismatch(S, SA[mid]) <= 0)
                okl = mid;
            else
                ngl = mid;
        }
        ll okr = len(ST) + 1, ngr = 0;
        while (okr - ngr > 1) {
            ll mid = (okr + ngr) / 2;
            if (ismatch(S, SA[mid]) < 0)
                okr = mid;
            else
                ngr = mid;
        }
        return P(okl, okr);
    }
    vector<ll> locate(T &S) {
        vector<bool> v(len(ST) + 1);
        P range = occ(S);
        for (ll i = range.first; i < range.second; i++) v[SA[i]] = true;
        vector<ll> res;
        rep(i, len(ST) + 1) if (v[i]) res.emplace_back(i);
        return res;
    }
    ll operator[](ll k) { return SA[k]; }

   public:
    vector<ll> LCP;

   private:
    void constructLCP() {
        vector<ll> rank(len(ST) + 1);
        LCP.resize(len(ST) + 1);
        rep(i, len(ST) + 1) rank[SA[i]] = i;
        ll h = 0;
        rep(i, len(ST)) {
            ll j = SA[rank[i] - 1];
            if (h > 0) h--;
            for (j; j + h < len(ST) && i + h < len(ST); h++) {
                if (ST[j + h] != ST[i + h]) break;
            }
            LCP[rank[i] - 1] = h;
        }
    }

   public:
    SuffixArray(T S) : ST(S) {
        ll mn = inf, mx = -inf;
        for (auto i : S) {
            chmin(mn, (ll)i);
            chmax(mx, (ll)i);
        }
        vector<ll> newS;
        for (auto i : S) newS.emplace_back(i - mn + 1);
        newS.emplace_back(0);
        SA = InducedSorting(newS, mx - mn + 2);
        constructLCP();
    }
};

/*
@brief Suffix Array (SA-IS)
@docs docs/SuffixArray.md
*/