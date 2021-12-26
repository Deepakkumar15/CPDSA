// 0(n) -> time complexity
// 0(1) -> space complexity
//Find zeroes to be flipped so that number of consecutive 1’s is maximized
// if only m flips are allowed

class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        int max_ones=0 ;
        int start=0; 
        int zeros=0; 
        for(int end=0; end<n; end++){
            if(arr[end]==0)
                zeros++ ;
            while(zeros > m){
                if(arr[start]==0)
                    zeros-- ;
                start++ ;    
            }    
            
            max_ones = max(max_ones, end-start+1) ;
        }
    return max_ones ;
    } 

};    