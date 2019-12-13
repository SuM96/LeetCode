/*
Problem Website: https://leetcode.com/problems/defanging-an-ip-address
*/
class Solution {
public:
    string defangIPaddr(string address) {
        // Decided to make my own string in this approach. It might be faster if I utilize substr and edit the substring as I go.
        string defangedIP = "";
        for(int i = 0; i < address.length(); i++) {
            if(address[i] == '.') {
                defangedIP += "[.]";
            }
            else {
                defangedIP += address[i];
            }
        }
        return defangedIP;
    }
};
