#define ll int

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ll n = nums.size() ;
        map<ll, ll, greater<int>> count ;
        vector<ll> ans ;
        
        for(ll i=0; i<k; i++)
            count[nums[i]]++ ;
        
        for(ll i=0; i<n-k; i++){
            //calculate the ans
            ans.push_back(count.begin()->first) ;
            //slide the window
            count[nums[i+k]]++ ;
            count[nums[i]]-- ;
            if(count[nums[i]] == 0)
                count.erase(nums[i]) ;
        }
        
        ans.push_back(count.begin()->first) ;
        return ans;
    }
};