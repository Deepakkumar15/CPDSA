class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        ios_base:: sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        vector<int> res ;
        unordered_map<int, int> umap ;
        
        for(int i = 0 ; i < nums.size() ; i++)
            umap[nums[i]] = i ;
        
        for(int i = 0 ; i < nums.size() ; i++)
            if(umap.find(target - nums[i]) != umap.end() )
            {
                int j = umap[target - nums[i]] ;
                if(j == i)
                    continue ;
                res.push_back(i) ;
                res.push_back(j) ;
                return res ;
            }
        
        return res ;
    }    

};