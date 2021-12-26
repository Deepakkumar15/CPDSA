// ROLLING HASH SWIGGY SDE-1 QUESTION
//VERY IMPORTANT
bool check(vector<int> &arr, int a, int b, int c, int d){
    if(b-a != d-c)
        return false;
    for(int i=a,j=c ; i<=b && j<=d 4; i++,j++){
        if(arr[i]!=arr[j])
            return false;
    }

    return true;
}

ll mod = 1e9 + 9;

int solve(vector<int> numbers, int k){
    int ans = 0;
    int n = numbers.size();

    map<ll,vector<pair<int,int>>> track;

    for(int i=0;i<n;i++){
        int odd =0;
        ll hash = 0;
        ll len = 0;
        
        for(int j=i;j<n;j++){
            
            hash = (hash*251 + numbers[j]) % mod;
            len++;

            if(numbers[j]%2!=0){
                odd++;
            }
            
            if(odd<=k){
                
                ll chash = len*1005l + hash;
                
                if(track.find(chash) == track.end()){
                    ans++;
                    track[chash].push_back({i,j});
                }else{
                    boolean flag = false;
                    for(auto p : track[chash]){
                        if(check(numbers, i, j, p.first, p.second))
                            flag = true;
                    }

                    if(!flag){
                        ans++;
                        track[chash].push_back({i,j});
                    }
                }
            }else{
                break;
            }
        }
    }
    return ans;
}