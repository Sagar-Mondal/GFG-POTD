class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        stack<int> s; 
        vector<int> leaves;
        int n = preorder.size();
    
        // Iterate through the preorder vector
        for (int i = 0, j = 1; j < n; i++, j++) {
            bool found = false;
    
            // Push current node if it's greater than 
            // the next node
            if (preorder[i] > preorder[j]) {
                s.push(preorder[i]);
            } 
            else {
              
                // Pop elements from stack until current node is 
                // less than or equal to top of stack
                while (!s.empty()) {
                    if (preorder[j] > s.top()) {
                        s.pop();
                        found = true; 
                    } 
                    else {
                        break;
                    }
                }
            }
    
            // If a leaf node is found, add it 
            // to the leaves vector
            if (found) {
                leaves.push_back(preorder[i]);
            }
        }
    
        // Since the rightmost element 
        // is always a leaf node
        leaves.push_back(preorder[n - 1]);
    
        return leaves; 
    }
};