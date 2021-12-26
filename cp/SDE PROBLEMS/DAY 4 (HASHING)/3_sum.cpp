class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target=0 ;
        vector<vector<int>> res ;
        int n=nums.size() ;
        if(nums.empty())
            return res ;
        sort(nums.begin(), nums.end()); 
        
        for(int i=0; i<n-2; i++){
                int target_2=target-nums[i] ;
                int s=i+1;
                int e=n-1;
                while(s<e){
                    if(nums[s]+nums[e] < target_2)
                        s++ ;
                    else if(nums[s]+nums[e] > target_2)
                        e-- ;
                    else{
                        vector<int> q_pair(3,0) ;
                        q_pair[0]=nums[i] ;
                        q_pair[1]=nums[s];
                        q_pair[2]=nums[e];
                        res.push_back(q_pair) ;
                        
                        while(s<e && nums[s]==q_pair[1])
                            s++ ;
                            
                        while(s<e && nums[e]==q_pair[2])
                            e-- ;
                            
                    }
                    
                }
                
            while(i+1<n && nums[i+1]==nums[i])
                i++ ;
        }
        return res ;
        
    }
};