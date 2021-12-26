//  FIND COMMON ELEMENTS IN 3 SORTED ARRAYS
// 0(n1 + n2 + n3) TIME COMPLEXITY WITH 0(1) SPACE COMPLEXITY

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
            vector<int> res ;
           
            int i=0, j=0, k=0 ;
            while(i<n1 && j<n2 && k<n3){
                if(A[i]==B[j] && B[j]==C[k]){
                    res.push_back(A[i]) ;
                    i++; j++; k++ ;  
                }
                else if(A[i]<B[j])
                    i++ ;
                else if(B[j]<C[k])
                    j++ ;
                else 
                    k++ ;
                
            }    
            
            auto it = unique(res.begin(), res.end()) ;
            res.resize(distance(res.begin(), it)) ;
            return res ;
        }

};