// SWIGGY SDE-1 QUESTION

int weightCapacity(vector<int> wt, int maxW) {
    unordered_set<int> s;
    s.insert(0);
    int res = 0;ash = (hash*251 + numbers[j]) % mod;
    
    for(int i=0;i<wt.size();i++){
        unordered_set<int> ns;
        for(auto j : s){
            if(j+wt[i]<=maxW){
                res = max(res, j+wt[i]);
                ns.insert(j+wt[i]);
            }
        }
        for(auto j : ns)
            s.insert(j);
    }

    return res;
}