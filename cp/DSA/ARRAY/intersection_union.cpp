// Find the Union and Intersection of the two sorted arrays
// UNION OF TWO SORTED ARRAYS USING SET DATA STRUCTURE

int doUnion(int a[], int n, int b[], int m)  {
    set<int> s ;
    for(int i=0; i<n; i++)
        s.insert(a[i]) ;
    for(int i=0; i<m; i++)
        s.insert(b[i]) ;
        
    return s.size() ;    
}

// UNION OF TWO SORTED ARRAYS 

int printUnion(int arr1[], int arr2[], int m, int n) 
{ 
    int i = 0, j = 0; 
    while (i < m && j < n) { 
        if (arr1[i] < arr2[j]) 
            cout << arr1[i++] << " "; 
  
        else if (arr2[j] < arr1[i]) 
            cout << arr2[j++] << " "; 
  
        else { 
            cout << arr2[j++] << " "; 
            i++; 
        } 
    } 
  
    /* Print remaining elements of the larger array */
    while (i < m) 
        cout << arr1[i++] << " "; 
  
    while (j < n) 
        cout << arr2[j++] << " "; 
} 

// INTERSECTION OF TWO SORTED ARRAYS

int printIntersection(int arr1[], int arr2[], int m, int n) 
{ 
    int i = 0, j = 0; 
    while (i < m && j < n) { 
        if (arr1[i] < arr2[j]) 
            i++; 
        else if (arr2[j] < arr1[i]) 
            j++; 
        else /* if arr1[i] == arr2[j] */
        { 
            cout << arr2[j] << " "; 
            i++; 
            j++; 
        } 
    } 
} 