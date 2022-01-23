// find minimum number of changes required to convert an array into AP
// We don't know d -> arithmetic difference


#define ll long double

ll minchanges(vi arr, ll  n){
    if(n < 3)
        return 0LL; 
    ll minCost = n;
    for(ll i = 0; i < n - 1; i++) {
        for(ll j = i + 1; j < n; j++) {
            ll delta = (arr[j] - arr[i]) / (j - i);
            ll cost = 0;
            for(ll k = 0; k < n; k++) {
                if(k == i) { continue; }
                if((arr[k] + delta * (i - k)) != arr[i]) { cost++; }
            }
            if(cost < minCost) { minCost = cost; }
        }
    }
    return minCost;
}

