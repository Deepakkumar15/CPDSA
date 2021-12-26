//Move all the negative elements to one side of the array 
//TWO POINTER APPROACH
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std ;

void sort_arr(int *arr, int n){
   int s=0, e=n-1;
   while(s<e){
        while(s<e && arr[s]<0)
            s++ ;
        while(s<e && arr[e]>0)
            e-- ;
        swap(arr[s], arr[e]) ;    
   }
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    int n ;
    cin >> n ;
    int arr[n] ;
    for(int i=0; i<n; i++)
        cin >> arr[i] ;
 
    sort_arr(arr, n) ;       
        
    for(auto it:arr)
        cout << it << " " ;
    cout << endl ;    
    return 0 ;
}

// PARTITION PROCESS OF QUICK SORT

void rearrange(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}