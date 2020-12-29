/*
 * Website: https://leetcode.com/problems/student-attendance-record-i
 * Stuff I learnt: I had to check the result last instead of beginning of the loop because the last result won't be counted. With the if-statement at the end, everything in the string will be counted. 
*/

class Solution {
public:
    bool checkRecord(string s) {
        int numOfAbsent = 0;
        int contLate = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'L') {
                contLate++;
            }
            else {
                contLate = 0;
            }
            numOfAbsent += (s[i] == 'A' ? 1 : 0);
            if(numOfAbsent > 1 || contLate > 2) {
                return false;
            }
        }
        return true;
    }
};
