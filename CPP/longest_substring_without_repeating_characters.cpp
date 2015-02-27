class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, max = 0;
        int flag[256];
        
        for(int i = 0; i < 256; ++i) flag[i] = -1;
        
        for(int i=0; i < s.length(); ++i){
            if(flag[s[i]] == -1 || flag[s[i]] < start){
                end = i;
                if(end - start >= max) max = end -start + 1;
            }else{
                start = flag[s[i]] + 1;
                end = i;
            }
            flag[s[i]] = i;
        }
        return max;
    }
};
