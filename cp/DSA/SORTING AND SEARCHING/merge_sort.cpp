//MERGE SORT ALGORITHM (DIVIDE AND CONQUER ALGORITHM)
//DIVIDE THE ARRAY INTO TWO , SORT AND THEN MERGE   
        
void merge(int *arr, int l, int r, int mid){ // 2 4 5     3 1
    vi temp ;
    
    int i=l, n = mid;
    int j = mid+1, m = r ;
    
    // temp -> 1 2 
    while(i<=n && j<=m){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]) ;
            i++ ;
        }
        
        else{
            temp.push_back(arr[j]) ;
            j++ ;
        }
    }
    
    while(i<=n){
        temp.push_back(arr[i]) ;
        i++ ;
    }
    
    while(j<=m){
        temp.push_back(arr[j]) ;
        j++ ;
    }
    
    int k=0 ;
    for(ll i=l; i<=r; i++)
        arr[i] = temp[k++] ; // merging part
        
    return ;    
}


void mergeSort(int *arr, int l, int r){
    if(l >= r)
        return ;
    if(l < r){
        int mid = (l+r) >> 1 ;
        
        mergeSort(arr, l, mid) ;
        mergeSort(arr, mid+1, r) ;
        
        merge(arr, l , r, mid) ;
        
    }
    
    return ;
}
