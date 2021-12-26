// MERGE INTERVALS 
// LEETCODE

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size() ;
        vector<vector<int>> res ;
        sort(intervals.begin(), intervals.end()) ;
        for(auto itr:intervals){
            if(res.empty() || res.back()[1] < itr[0])
                res.push_back(itr) ;
            else
                res.back()[1]=max(res.back()[1], itr[1]) ;    
        }
        
        return res ;
    }
};