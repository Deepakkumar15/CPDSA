//MERGE SORT ALGORITHM (DIVIDE AND CONQUER ALGORITHM)
//DIVIDE THE ARRAY INTO TWO , SORT AND THEN MERGE
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std ;

void Merge(int *arr, int s, int mid, int e)
{
    //FIRST CALCULATING THE MIDDLE OF ARRAY
    // int mid = (s+e)/2 ;
    //MERGING THE TWO SORTED HALF USING THREE POINTERS
    int i = s ;
    int j = mid+1 ;
    int k = s ;
    
    int temp[100] ;//TEMPORARY ARRAY FOR STORING THE RESULTANT 
    while(i<=mid && j<=e)//COMPARISON BETWEEN BOTH SORTED HALFS
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++] ;
        else
            temp[k++] = arr[j++] ;
    }
    
    while(i<=mid)
        temp[k++] = arr[i++] ;
    while(j<=e)
        temp[k++] = arr[j++] ;
        
    //UPDATE THE EXISTING ARRAY    
    for(int i=s; i<=e; i++)
        arr[i] = temp[i] ;
    
}

void MergeSort(int *arr, int n)
{
    int p, s, e, i ;
    int mid ;

    for(p=2; p<=n; p*=2)
    {
        for(i=0; i+p-1<n; i+=p)
        {
            s = i ;
            e = i+p-1 ;
            mid = (s+e)/2 ;
            Merge(arr, s, mid, e) ;
        }
    }

    if(p/2 < n)
        Merge(arr, 0 , p/2, n-1) ;
    
}

int randomize()
{
    //GENERATING 100 DIFFERENT NUMBERS USING rand() FUNCTION
    //BETWEEN RANGE OF upper AND lower
    return (rand() % 901 + 100) ; // (rand() % (upper-lower+1)) + lower
}

int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    srand(time(NULL)) ; // FOR DIFFERENT VALUES FOR EACH TIME WE RUN THE CODE
    
    int n=100 ;
    int arr[n] ;
    
    generate(arr, arr+n, randomize) ; // FILL ALL THE GENERATED ELEMENTS USING randomize() FUNCTION INTO THE ARRAY
    
    cout << "THE RANDOM ARRAY GENERATED IS :" << endl ; // RANDOM ARRAY GENERATED
    for(int i=0; i<n; i++)
        cout << arr[i] << " " ;
    
    MergeSort(arr, n-1) ;// CALLING MergeSort() FUNCTION TO SORT THE ARRAY
    cout << endl << "THE SORTED ARRAY USING MERGE SORT IS :" << endl ;// SORTED ARRAY USING MERGE SORT
    for(int i=0; i<n; i++)
        cout << arr[i] << " " ;
    
return 0 ;        
        
}        
        