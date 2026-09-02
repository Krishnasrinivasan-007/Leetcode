class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        vector<int>ans;
        int i,first,last,sec;
        int n = nums.size();
        for(i=0;i<n;i++){
            first=nums[i];
            sec=target-first;
            if(m.find(sec)!=m.end()){
                ans.push_back(i);
                ans.push_back(m[sec]);
                break;
            }
            m[first]=i;
        

        }
        return ans;
        
    }
};