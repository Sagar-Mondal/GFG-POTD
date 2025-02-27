//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    stack<int> s;
    int minEle;
  public:
    Solution() { minEle = -1; }
    void push(int x) {
        if (s.empty()) {
            minEle = x;
            s.push(x);
        }
        else if (x < minEle) {
            s.push(2 * x - minEle);
            minEle = x;
        }
        else {
            s.push(x);
        }
    }
    void pop() {
        if (s.empty()) {
            return;
        }
        int top = s.top();
        s.pop();
        if (top < minEle) {
            minEle = 2 * minEle - top;
        }
    }
    int peek() {
        if (s.empty()) {
            return -1;
        }
        int top = s.top();
        return (minEle > top) ? minEle : top;
    }
    int getMin() {
        if (s.empty())
            return -1;
        return minEle;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends