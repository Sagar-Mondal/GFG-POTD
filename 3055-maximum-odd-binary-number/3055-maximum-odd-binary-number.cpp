class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=count(s.begin(),s.end(),'1');
        return string(ones-1,'1')+string(s.size()-ones,'0')+"1";
    }
};