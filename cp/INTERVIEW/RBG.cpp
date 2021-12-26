#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1000000007LL

bool check(unordered_map<ll, map<ll, ll>> &cmap, ll a, ll b, ll c){
    // cout << a << " " << b << " " << c << endl;
    if(cmap.find(a) == cmap.end()){
        // cout << "first" << endl;
        return false;
    }

    auto last = prev(cmap[a].end());
    if(b < cmap[a].begin()->first ){
        // cout << "second" << endl;
        return false;
    }

    auto it = cmap[a].upper_bound(b);
    if(it == cmap[a].end() || it->first > b)
        it = prev(it);
    
    // cout << it->first << " " << it->second << endl;
    
    if(it->first <= b && it->second <= c)
        return true;

    return false;
}

int main() {
    ll n,q;
    cin >> n >> q;
    vector<pair<ll,pair<ll,ll>>> rarr;
    vector<pair<ll,pair<ll,ll>>> garr;
    vector<pair<ll,pair<ll,ll>>> barr;

    for(int i=0;i<n;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        rarr.push_back({a,{b,c}});
        garr.push_back({b,{a,c}});
        barr.push_back({c,{a,b}});
    }

    sort(rarr.begin(), rarr.end());
    sort(garr.begin(), garr.end());
    sort(barr.begin(), barr.end());

    unordered_map<ll, map<ll, ll>> rmap;
    unordered_map<ll, map<ll, ll>> gmap;
    unordered_map<ll, map<ll, ll>> bmap;

    ll prev_min = inf;
    ll prev = -1;
    for(pair<ll,pair<ll,ll>> cur : rarr){
        ll a = cur.first;
        ll b = cur.second.first;
        ll c = cur.second.second;
        if(prev!=a){
            prev_min = inf;
        }
        // cout << a << " " << b << " " << c << "\n";
        prev_min = min(c, prev_min);
        rmap[a][b] = prev_min;
        prev = a;
    }
    
    // cout << "\n";
    
    prev_min = inf;
    prev = -1;
    for(pair<ll,pair<ll,ll>> cur : garr){
        ll a = cur.first;
        ll b = cur.second.first;
        ll c = cur.second.second;
        if(prev!=a){
            prev_min = inf;
        }
        // cout << a << " " << b << " " << c << "\n";
        prev_min = min(c, prev_min);
        gmap[a][b] = prev_min;
        prev = a;
    }
    // cout << "\n";
    
    prev_min = inf;
    prev = -1;
    for(pair<ll,pair<ll,ll>> cur : barr){
        ll a = cur.first;
        ll b = cur.second.first;
        ll c = cur.second.second;
        if(prev!=a){
            prev_min = inf;
        }
        // cout << a << " " << b << " " << c << "\n";
        prev_min = min(c, prev_min);
        bmap[a][b] = prev_min;
        prev = a;
    }
    // cout << "\n";
    
    while(q--){
        ll qa, qb, qc;
        cin >> qa >> qb >> qc;
        
        // cout << check(rmap, qa, qb, qc) << endl;
        // cout << check(gmap, qb, qa, qc) << endl;
        // cout << check(bmap, qc, qa, qb) << endl;
            
        if( check(rmap, qa, qb, qc) &&
            check(gmap, qb, qa, qc) &&
            check(bmap, qc, qa, qb))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

    return 0;
}