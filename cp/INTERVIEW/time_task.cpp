#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    int n, m ;
    cin >> n >> m ;
    vector<vector<int>> matrix(n, vector<int> (3)) ;
    multimap<int, int> umap ;
    multimap<int, int> :: iterator it ;

    for(int i=0; i<n ;i++)
    {
        int sum = 0 ;
        for(int j=0; j<3 ;j++)
        {
            int x ;
            cin >> x ;
            matrix[i][j] = x ; 
            sum += x ;
        }
        umap.insert(pair <int, int> (sum, i)) ; 
    }
    
    int index = 0 ; 
    vector<vector<int>> res(m, vector<int> (3)) ;
    for(it=umap.begin(); it!=umap.end(); ++it)
    {
        for(int j=0; j<3; j++)
            res[index][j] = matrix[it->second][j] ;

        if(index++ == m-1)
            break ;
    }
    
    int min_time = 0 ;    
    for(int i=0; i<3; i++)
    {
        int max_element = 0 ;
        for(int j=0; j<m; j++)
            if(max_element < res[j][i])
                max_element = res[j][i] ;
        
        min_time += max_element ; 
    }
    
    cout << min_time << endl ;
    
    return 0 ;
}