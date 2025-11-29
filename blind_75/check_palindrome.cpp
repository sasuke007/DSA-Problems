class Solution {
    public:
        void to_lowercase(string &s){
            transform(s.begin(),s.end(),s.begin(),[](unsigned char b){return tolower(b);});
        }
    
        void remove_non_alphanumeric(string &s){
            auto new_end=remove_if(s.begin(),s.end(),[](unsigned char c){
                return !isalnum(c);
            });
            s.erase(new_end,s.end());
        }
    
    
        bool isPalindrome(string s) {
            to_lowercase(s);
           // cout<<s;
           remove_non_alphanumeric(s);
            auto begin = s.begin();
            auto end = s.end()-1;
            while(begin<end){
                if(*begin!=*end){
                    return false;
                }
                ++begin;
                --end;
            }
            return true;
        }
    };
    // https://leetcode.com/problems/valid-palindrome/


    