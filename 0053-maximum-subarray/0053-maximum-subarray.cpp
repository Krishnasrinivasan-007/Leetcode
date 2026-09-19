class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i;
        int sum=0;
        int maxsum=INT_MIN;
        for(i=0;i<nums.size();i++){
            sum+=nums[i];
            maxsum=max(sum,maxsum);
            if(sum<0)
                sum=0;
        }
        return maxsum;
        
    }
};