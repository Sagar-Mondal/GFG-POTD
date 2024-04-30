//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node *head){
        Node *newHead=NULL;
        while(head){
            Node *temp=head->next;
            head->next=newHead;
            newHead=head;
            head=temp;
        }
        return newHead;
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        Node *n1=reverse(num1), *n2=reverse(num2), *ans=new Node(-1), *dummy=ans;
        int carry=0;
        while(n1 || n2 || carry){
            int sum=(n1?n1->data:0)+(n2?n2->data:0)+carry;
            carry=sum/10;
            ans->next=new Node(sum%10);
            ans=ans->next;
            if(n1) n1=n1->next;
            if(n2) n2=n2->next;
        }
        ans = reverse(dummy->next);
        while(ans->data==0 && ans->next)
            ans=ans->next;
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends