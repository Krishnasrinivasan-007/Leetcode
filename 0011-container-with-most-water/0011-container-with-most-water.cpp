class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxa=0;
        int hei;
        int lp=0;
        int rp=height.size() - 1;
        while(rp>lp)
            {
                    int x=rp-lp;
                    hei=min(height[rp],height[lp]);
                    maxa=max(x*hei,maxa);
                    height[lp]<height[rp]?lp++:rp--;
                    
            }                
                
        return maxa;   
        }
        
    
};