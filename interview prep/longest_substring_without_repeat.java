class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> alreadyPresent = new HashSet<>();
    int i = 0, j = 0;
    int n = s.length();
    int answer =0;
    while(j < n){
      char ch = s.charAt(j);
      if(!alreadyPresent.contains(ch)){
        alreadyPresent.add(ch);
        ++j;
      }
      else{
        int len=j-i;
        answer=Math.max(answer,len);
        while(s.charAt(i)!=s.charAt(j)){
          alreadyPresent.remove(s.charAt(i));
          ++i;
        }
        alreadyPresent.remove(s.charAt(i));
        ++i;
      }
    }
    answer=Math.max(j-i,answer);
    return answer;
    }
}