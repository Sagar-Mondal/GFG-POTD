/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int result;
    int DFS(Node* node, int start){
        if(node == NULL) return 0;

        int leftDepth = DFS(node->left, start);
        int rightDepth = DFS(node->right, start);

        if(node->data == start){
            result = std::max(leftDepth, rightDepth);
            return -1;
        }
        else if(leftDepth >= 0 && rightDepth >= 0)
            return std::max(leftDepth, rightDepth)+1;
        
        result = std::max(result, std::abs(leftDepth - rightDepth));
        return std::min(leftDepth, rightDepth) - 1;
    }
    int minTime(Node* root, int target) {
        DFS(root, target);
        return result;
    }
};