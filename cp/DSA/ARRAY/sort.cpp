//Given an array which consists of only 0, 1 and 2
//Sort the array without using any sorting algo
//Alternative of DUTCH NATIONAL FLAG ALGORITHM
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std ;

void sort_arr(int *arr, int n){
    int i, c0=0, c1=0, c2=0 ;
    for(i=0; i<n; i++){
        switch(arr[i]){
            case 0:
                c0++ ;
                break ;
            case 1:
                c1++ ;
                break ;
            case 2:
                c2++ ;
                break ;
        }
    }
    
    i=0 ;
    // inserting the number of 0's, 1's and 2's 
    // starting from the index 0 ;
    while(c0--)
        arr[i++]=0 ;
    while(c1--)
        arr[i++]=1 ;
    while(c2--)
        arr[i++]=2 ;
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
    
    for(auto it: arr)
        cout << it << " " ;
    cout << endl ;    
    return 0 ;
}


// DUTCH NATIONAL FLAG ALGORIHTM 
// WITHOUT USING ANY SORTING ALGORITHM 

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int low=0, mid=0;
        int high = nums.size()-1 ;

        while(mid <= high)
            switch(nums[mid])
            {
                case 0:
                    swap(nums[low++], nums[mid++]) ;
                    break;
                case 1:
                    mid++ ;
                    break ;
                case 2:
                    swap(nums[mid], nums[high--]) ;
                    break ;     
            }
    }
};