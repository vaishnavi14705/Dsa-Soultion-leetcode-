class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxdepth=0;
        for(char ch:s){
            if(ch=='('){
                count++;
                maxdepth=max(maxdepth,count);
            }
            else if(ch==')'){
                count--;

            }

        }
        return maxdepth;
    }
};