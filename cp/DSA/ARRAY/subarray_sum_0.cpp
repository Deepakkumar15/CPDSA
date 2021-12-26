// SUBARRAY WITH SUM 0 
// USING SET

bool subArrayExists(int arr[], int n){
    int sum=0 ;
    unordered_set<int> s ;
    for(int i=0; i<n; i++){
        sum+=arr[i] ;
        
        if(sum==0 || (s.find(sum)!=s.end()))
            return true ;
        s.insert(sum) ;    
    }
        
    return false ;    
}