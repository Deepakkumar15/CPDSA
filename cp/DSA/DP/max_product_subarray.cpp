// MODIFIED KADANE'S ALGORITHM
// MAX. PRODUCT SUBARRAY
#define ll long long int
#define vi vector<ll> 
class Solution {
public:
    int max(ll a, ll b){
        if(a>b)
            return a ;
        return b ;
    }
    
    int min(ll a, ll b){
        if(a>b)
            return b ;
        return a ;
    }
    
    int maxProduct(vector<int>& nums) {
        ll n = nums.size() ;
        if(n==1)
            return nums[0] ;
        // keep track of local maxima and local minima
        ll mn = nums[0], mx = nums[0], ans = nums[0] ;
    
        for(ll i=1; i<n; i++){
            // if nums[i] < 0, then we swap the local maxima and local minima
            if(nums[i] < 0)
                swap(mx, mn) ;
            mx = max(nums[i], mx*nums[i]) ;
            mn = min(nums[i], mn*nums[i]) ;
            
            ans = max(ans, mx);
        }
        
        return ans ;
    }
};