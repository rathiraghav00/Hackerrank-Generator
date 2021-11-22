#include "testlib.h"
#include<bits/stdc++.h>

#define ll            long long
#define pb          push_back
#define    endl        '\n'
#define pii         pair<ll,l dl>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll i=a;i<b;i++)
#define dep(i,a,b)    for(ll i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ff              first
#define ss              second

using namespace std;

vi a, b;
int q;
vi ok;
map<int,vi> m;


int test_case(vi num, int k, int n)
{
    a.clear();
    b.clear();
    m.clear();
    ok.clear();
    sort(all(num));
    reverse(all(num));
    map<int,int> f, del;
    for(int i = 0; i < n; i++) {
        f[num[i]]++;
        if(f[num[i]] > k) {
            return 1;
        }
    }
    for(int i = 0; i < k; i++) {
        ok.push_back(num.back());
        f[num.back()]--;
        del[num.back()]++;
        if(f[num.back()] == 0) {
            f.erase(num.back());
        }
        num.pop_back();
    }
    for(int i = 0; i < sz(ok); i++) {
        m[i].pb(ok[i]);
    }
    for(typeof(f.begin()) it2 = f.begin(); it2 != f.end() ; it2++) {
        typeof(*f.begin()) it = *it2;
        assert(it.second > 0);

        int en = sz(ok) - 1;
        if(del[it.first] > 0) {
            for(int i = sz(ok) - 1; i >= 0; i--) {
                if(ok[i] != it.first) {
                    en = i;
                    break;
                }
            }
        }
        for(int i = en, j = it.second; j > 0; j--, i--) {
            m[max(i, 0)].pb(it.first);
        }
    }
    ok.clear();
    for(typeof(m.begin()) it2 = m.begin(); it2 != m.end(); it2++) {
        typeof(*m.begin()) it = *it2;
        vi nw;
        for(int i = 0; i < (int)it.second.size(); i++) {
            nw.pb(it.second[i]);
        }
        while(sz(nw)) {
            ok.pb(nw.back());
            nw.pop_back();
        }
    }
    // for(int i : ans) {
    //     db(i);
    // }
    assert(sz(ok) == n);
    vi dp(n, 1);
    for(int i = 0; i < n; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(ok[i] >= ok[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    if(*max_element(dp.begin(), dp.end()) != k) {
       return -1;
    }
    return 2;
}


void create(ll n1, ll n2, ll id) {

    int n = rnd.next(1, 200);
    n = 100;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = rnd.next(1, n);
    }
    int k = rnd.next(1, n);

    while(test_case(a, k, n) != -1) {
        create(n1, n2, id);
    }
    cout << n << '\n';
    cout << k << '\n';
    for(int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }


}




void writeTest(ll test)
{
    startTest(test);

    if(test <= 0) {
        create(5, 5, test);
    } else if (test <= 6) {
        create(5, 5, test);
    } 
    else if (test <= 9) {
        create(1000, 2000, test);
    } else if (test <= 13) {
        create(5e4, 6e4, test);
    } else if(test <= 14) {
        create(1e5, 1e5, test);
    }

}


int main(int argc, char* argv[])
{
    ll tests = atoi(argv[1]);
    for (ll i = 0; i < tests; i++)
        writeTest(i);
    return 0;
}