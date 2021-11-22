#include<bits/stdc++.h>
#define int            long long
#define ll             long long
#define pb          push_back
#define    endl        '\n'
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define dep(i,a,b)    for(int i=a;i>=b;i--)
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
    map<int,int> f;
    for(int i = 0; i < n; i++) {
        f[num[i]]++;
        if(f[num[i]] > k) {
            return 1;
        }
    }
    for(int i = 0; i < k; i++) {
        ok.push_back(num.back());
        f[num.back()]--;
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
        for(int i = sz(ok) - 1, j = it.second; j > 0; j--, i--) {
            m[max(i, 0LL)].pb(it.first);
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



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
	{

		int n;
		cin >> n;

        int k;
        cin >> k;

		vector<int> x(n);
		for(int i = 0; i < n; i++) {
			cin >> x[i];
		}

		

        cout << test_case(x, k, n) << endl;
    }
    return 0;
}