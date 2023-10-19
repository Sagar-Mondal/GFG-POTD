class Solution {
public:
    string build(string str){
        stack<char> ans;
        string res;
        for(char c : str){
            if(c != '#'){
                ans.push(c);
            }
            else if(!ans.empty()){
                ans.pop();
            }
        }
        while(!ans.empty()){
            res += ans.top();
            ans.pop();
        }
        return res;
    }
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};