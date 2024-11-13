//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */


class Solution {
public:
    bool solve(Node* root, int min, int max, bool &ans) {
        // Base case: if there's no node, return without altering ans
        if (root == NULL) {
            return false;
        }

        // Check for dead end condition
        if (min == max) {
            ans = true;
            return true; // early return to propagate dead end detection
        }

        // Traverse left and right subtrees with updated bounds
        solve(root->left, min, root->data -1 , ans);
        solve(root->right, root->data +1, max, ans);

        return ans;
    }

    bool isDeadEnd(Node *root) {
        int min = 1;  // Start min at 1 since 0 is often used as a base non-BST value
        int max = INT_MAX;
        bool ans = false;
        solve(root, min, max, ans);
        return ans;
    }
};





//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    
cout << "~" << "\n";
}
}


// } Driver Code Ends