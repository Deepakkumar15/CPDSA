//SUBSET WITH A GIVEN SUM VALUE K/TARGET
// TIME COMPLEXITY - 0(N*2) SOLUTION 
// SPACE COMPLEXITY - 0(1) 
#include <bits/stdc++.h>

using namespace std;

int fn(int *a,int n, int target){
    int sum=0; 
    for(int i=0; i<n; i++){
        sum=a[i] ;
        for(int j=i+1; j<n; j++){
            if(sum==target)
                return 1 ;
            if(sum>target)
                break ;
            sum+=a[j] ;    
        }
    }
    
    return 0 ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0);
    cout.tie(0) ;
    
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++)
        cin >> a[i] ;
    int target ;
    cin >> target ;
    
    if(fn(a, n, target)==1)
        cout << "SUM FOUND" ;
    else
        cout << "SUM NOT FOUND" ;
    return 0 ;
}



//SUBSET WITH A GIVEN SUM VALUE K
// TIME COMPLEXITY - O(N)
// SPACE COMPEXITY - O(N) FOR USING UNORDERED_MAP FOR STORING N VALUES IN THE WORST CASE
 
#include <bits/stdc++.h>

using namespace std ;

int fn(int *a, int n, int target){
    int sum=0 ;
    unordered_map<int, int> mp ;
    for(int i=0; i<n; i++){
        sum+=a[i] ;
        if(sum==target)
            return 1 ;
        if(mp.find(sum-target)!=mp.end())
            return 1 ;
        mp[sum]=i ;    
    }
    
    return 0 ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++)
        cin >> a[i] ;
        
    int target ;
    cin >> target ;
    
    if(fn(a, n, target)==1)
        cout << "SUM FOUND" ;
    else
        cout << "SUM NOT FOUND" ;
    return 0 ;
}