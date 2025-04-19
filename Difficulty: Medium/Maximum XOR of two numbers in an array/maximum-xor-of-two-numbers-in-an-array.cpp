//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Node {
  public:
    Node* one;
    Node* zero;

    Node() {
        one = nullptr;
        zero = nullptr;
    }
};
class Trie {
  public:
    Node* root;

    Trie() { root = new Node(); }

    // Function to insert in Trie
    void insert(int n) {

        Node* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;

            // Check if the bit is 0
            if (bit == 0) {
                if (curr->zero == NULL) {
                    curr->zero = new Node();
                }
                curr = curr->zero;
            }

            // Else if bit is 1
            else {
                if (curr->one == NULL) {
                    curr->one = new Node();
                }
                curr = curr->one;
            }
        }
    }
    int findXOR(int n) {
        Node* curr = root;
        int res = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;

            // if the bit is 0
            if (bit == 0) {

                // if set bit is present
                if (curr->one) {
                    curr = curr->one;
                    res += (1 << i);
                } else {
                    curr = curr->zero;
                }
            }

            // Else if bit is 1
            else {

                // if unset bit is present
                if (curr->zero) {
                    curr = curr->zero;
                    res += (1 << i);
                } else {
                    curr = curr->one;
                }
            }
        }
        return res;
    }
};

class Solution {
  public:
    int maxXor(vector<int>& arr) {
        int res = 0;

        Trie* t = new Trie();

        // insert the first element in trie
        t->insert(arr[0]);

        for (int i = 1; i < arr.size(); i++) {
            res = max(t->findXOR(arr[i]), res);
            t->insert(arr[i]);
        }
        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends