//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string findOrder(vector<string>& words) {
        vector<vector<int>> graph(26);

        // In-degree of each character
        vector<int> inDegree(26, 0);

        // Tracks which characters are present
        vector<bool> exists(26, false);

        // Mark existing characters
        for (const string& word : words) {
            for (char ch : word) {
                exists[ch - 'a'] = true;
            }
        }
        // Build the graph from adjacent words
        for (int i = 0; i + 1 < words.size(); ++i) {
            const string& w1 = words[i];
            const string& w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            int j = 0;

            while (j < len && w1[j] == w2[j])
                ++j;

            if (j < len) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';
                graph[u].push_back(v);
                inDegree[v]++;
            } else if (w1.size() > w2.size()) {

                // Invalid input
                return "";
            }
        }
        // Topological sort
        queue<int> q;
        for (int i = 0; i < 26; ++i) {
            if (exists[i] && inDegree[i] == 0) {
                q.push(i);
            }
        }

        string result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result += (char)(u + 'a');

            for (int v : graph[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Check, there was a cycle or not
        for (int i = 0; i < 26; ++i) {
            if (exists[i] && inDegree[i] != 0) {
                return "";
            }
        }

        return result;
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends