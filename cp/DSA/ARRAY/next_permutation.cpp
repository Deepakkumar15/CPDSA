// NEXT GREATER PERMUTATION 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() ;
        int i, j ;
        for(i=n-1; i>0; i--){
           if(nums[i]>nums[i-1]){
                i-- ;
                break ; 
            }
            if(i==1 && nums[0]>nums[1]){
                sort(nums.begin(), nums.end()) ;
                return ;
            }
        }    
        
        for(j=n-1; j>0; j--)
            if(nums[j]>nums[i])
                break ;
        swap(nums[i], nums[j]) ;
        i++ ;
        reverse(nums.begin()+i, nums.end()) ;
    }
};

// INBUILT FUNCTION

next_permutation(nums.begin(), nums.end()) ;