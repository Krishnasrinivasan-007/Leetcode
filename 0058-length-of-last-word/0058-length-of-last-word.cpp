class Solution {
public:
    int lengthOfLastWord(string s) {
        int kk=s.length();
        int j;
        int i;
        int count=0;
        for(i=kk-1;i>=0;i--){
            if(s[i]!=' '){
                count++;
            }
            else if(count>0){
                break;
            }
        }
    return count;  
    }
    
};