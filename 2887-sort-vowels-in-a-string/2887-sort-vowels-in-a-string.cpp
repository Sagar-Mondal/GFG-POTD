class Solution {
public:
    bool isVowel(char c){
        return c =='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
        c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string sortVowels(string s) {
        string vowels;
        for(char c : s){
            if(isVowel(c)){
                vowels += c;
            }
        }
        sort(vowels.begin(), vowels.end());
        int j = 0;
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                ans += vowels[j];
                j++;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};