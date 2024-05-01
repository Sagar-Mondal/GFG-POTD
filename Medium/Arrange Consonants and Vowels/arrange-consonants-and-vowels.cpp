//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
     bool isVowel(char ch){
        if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')
            return true;
        return false;
    }
  public:
    struct Node* arrangeCV(Node *head)
    {
        if(head == NULL)
            return head;
            
        vector<char> vows;
        vector<char> cons;
        while(head != NULL){
            if(isVowel(head->data))
                vows.push_back(head->data);
            else
                cons.push_back(head->data);
            head = head->next;
        }
        struct Node* ans = new Node(0);
        struct Node* curr = ans;
        
        for(int i=0; i<vows.size(); i++){
            curr->next = new Node(vows[i]);
            curr = curr->next;
        }
        for(int i=0; i<cons.size(); i++){
            curr->next = new Node(cons[i]);
            curr = curr->next;
        }
        
        return ans->next;
        
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends