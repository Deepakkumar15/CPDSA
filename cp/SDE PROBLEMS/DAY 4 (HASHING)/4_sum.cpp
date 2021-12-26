class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res ;
        int n=nums.size() ;
        if(nums.empty())
            return res ;
        sort(nums.begin(), nums.end()); 
        
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                int target_2=target-nums[i]-nums[j] ;
                int s=j+1;
                int e=n-1;
                while(s<e){
                    if(nums[s]+nums[e] < target_2)
                        s++ ;
                    else if(nums[s]+nums[e] > target_2)
                        e-- ;
                    else{
                        vector<int> q_pair(4,0) ;
                        q_pair[0]=nums[i] ;
                        q_pair[1]=nums[j];
                        q_pair[2]=nums[s];
                        q_pair[3]=nums[e];
                        res.push_back(q_pair) ;
                        
                        while(s<e && nums[s]==q_pair[2]) // don't use nums[s] == nums[s+1]
                            s++ ;                        // it'll increase the time complexity and our code will give TLE    
                            
                        while(s<e && nums[e]==q_pair[3])
                            e-- ;
                            
                    }
                    
                }
                while(j+1<n && nums[j+1]==nums[j])
                    j++;
            }
            while(i+1<n && nums[i+1]==nums[i])
                i++ ;
        }
        return res ;
    }
};