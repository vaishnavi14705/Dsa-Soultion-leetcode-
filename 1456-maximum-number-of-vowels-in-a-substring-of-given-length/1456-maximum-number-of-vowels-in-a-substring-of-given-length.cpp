class Solution {
public:
  bool isvowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' ||
               ch=='o' || ch=='u';
    }
   int maxVowels(string s, int k) {
        int count=0;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(isvowel (s[i]))
                count++;
            
            if(i>=k){
                if(isvowel(s[i-k]))
                count--;
            }
            maxi=max(maxi,count);
    }
    return maxi;

    }
};