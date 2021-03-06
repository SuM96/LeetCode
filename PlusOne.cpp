/*
 * Problem link: https://leetcode.com/problems/plus-one/
 * Reflection: This took way too long. I initially had a complicated solution, but it was simplified after a day of thinking.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // New placing is used for numbers like 9, 99, 999, ...
        bool newPlacing = false;
        // Placing refers to the ones, tens, thousands, etc. place
        // Started at the "zeroth" place, so that the loops actually works
        int placing = digits.size();
        // This loop solves the leading 9 problem. Like 1199, 1999, etc will make it overlap to 1200 and 2000. 
        // If the leading 0, then just add 1.
        do {
            placing--;
            if(placing == 0 && digits[placing] == 9) {
                newPlacing = true;
            }
            digits[placing] = (digits[placing] + 1) % 10; 
        } while(placing > 0 && digits[placing] == 0);
        // Just some dirty shifting because for numbers like 9999 + 1 will lead to 00001, then swap 10000
        if(newPlacing) {
            digits.push_back(1);
            swap(digits[0], digits[digits.size() - 1]);
        }
        return digits;
    }
};
