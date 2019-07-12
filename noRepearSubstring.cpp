class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if(!s.size()) return 0;
            int max = 0;
            int count = 0;
            int current = -1;
            for(int i = 0; i < 256; ++i) {
                tmp[i] = -1;
            }
            for(int i = 0; i < s.length(); ++i) {
                int step = s[i] - '\0';
                if(tmp[step] == -1 || tmp[step] <= current)
                {
                    tmp[step] = i;
                    ++count;
                }
                else
                {
                    if(count > max)
                       max = count;
                    count = i - tmp[step];
                    current = tmp[step];
                    tmp[step] = i;
                }
                
            }
            if(count > max)
                    max = count;
            return max;
        }
    private:
        int tmp[256];
};