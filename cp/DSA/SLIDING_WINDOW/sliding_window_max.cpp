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






// most optimal solution i.e dequeue method

#define ll int

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ll n = nums.size() ;
        deque<ll> q ;
        vector<ll> ans ;
        ll l=0, r=0 ;
        while(l<=r && r<n){
            while(!q.empty() && q.back() < nums[r])
                q.pop_back() ;
            q.push_back(nums[r]) ;
            
            if(r-l+1 == k){
                ans.push_back(q.front()) ;
                r++ ;
                if(nums[l] == q.front())
                    q.pop_front() ;
                l++ ;
            }
            
            else
                r++ ;
            
        }
        return ans;
    }
};