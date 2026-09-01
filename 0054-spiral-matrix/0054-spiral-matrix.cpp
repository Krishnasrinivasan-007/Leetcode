class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m= mat.size(), n=mat[0].size();
        int srow=0, erow=m-1, scol=0, ecol=n-1;
        int i,j;
        vector<int> ans;
        while(srow<=erow && scol<=ecol){
            for(j=scol;j<=ecol;j++){
                    ans.push_back(mat[srow][j]);
            }
            for(j=srow+1;j<=erow;j++){
                    ans.push_back(mat[j][ecol]);
            }
            for(j=ecol-1;j>=scol;j--){
                if(srow==erow){
                    break;
                }
                ans.push_back(mat[erow][j]);
            }
            for(j=erow-1;j>=srow+1;j--){
                if(scol==ecol){
                    break;
                }
                ans.push_back(mat[j][scol]);
            }
            srow++;scol++;
            erow--;ecol--;

        }
        return ans;
        }
    };
