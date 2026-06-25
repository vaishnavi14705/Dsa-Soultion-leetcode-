class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();      // string ki length
        int start = 0;         // longest palindrome ka start index
        int maxLen = 1;        // minimum palindrome length = 1

        // har index ko center bana rahe hain
        for (int i = 0; i < n; i++) {

            // -------- ODD LENGTH PALINDROME (aba) --------
            int left = i;
            int right = i;

            while (left >= 0 && right < n && s[left] == s[right]) {

                int currLen = right - left + 1;   // current palindrome length

                if (currLen > maxLen) {
                    maxLen = currLen;   // longest update
                    start = left;       // start index save
                }

                left--;    // left ko bahar le jao
                right++;   // right ko bahar le jao
            }

            // -------- EVEN LENGTH PALINDROME (abba) --------
            left = i;
            right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {

                int currLen = right - left + 1;

                if (currLen > maxLen) {
                    maxLen = currLen;
                    start = left;
                }

                left--;
                right++;
            }
        }

        // longest palindrome return
        return s.substr(start, maxLen);
    }
};