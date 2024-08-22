//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class graph {
  public:
    int V;
    list<int> *adj;
    graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }
    void addedge(int v, int u) { adj[v].push_back(u); }
};

class Solution{
    public:
    void dictorder(string str1, string str2, graph *g, int *exist) {
        int n1 = str1.size();
        int n2 = str2.size();
        for (int i = 0; i < n1; i++) exist[(int)str1[i]] = 1;
        for (int i = 0; i < n2; i++) exist[(int)str2[i]] = 1;
        int i = 0;
        while (i < n1 && i < n2) {
            if (str1[i] != str2[i]) {
                g->addedge((int)str1[i], (int)str2[i]);
                return;
            }
            i++;
        }
    }
    void topsort(list<int> *adj, bool *visited, stack<char> &st, int v,
                 int *exist) {
        if (exist[v]) {
            visited[v] = true;
            for (auto u : adj[v])
                if (!visited[u]) topsort(adj, visited, st, u, exist);
            st.push((char)v);
        }
    }
    string findOrder(string dict[], int N, int K) {
        graph *g = new graph(256);
        int exist[256] = {0};
        for (int i = 1; i < N; i++) {
            dictorder(dict[i - 1], dict[i], g, exist);
        }
        bool visited[256] = {0};
        stack<char> st;
        for (int i = 0; i < 256; i++) {
            if (!visited[i]) topsort(g->adj, visited, st, i, exist);
        }
        string final = "";
        while (!st.empty()) {
            final += st.top();
            st.pop();
        }
        return final;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends