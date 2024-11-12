//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// class Solution
// {
// public:
//     vector<int> inorder(Node* root, vector<int>& v1)
//     {
//         if (root == NULL) return v1;

//         inorder(root->left, v1);  
//         v1.push_back(root->data); 
//         inorder(root->right, v1); 

//         return v1;
//     }

//     vector<int> Rinorder(Node* root, vector<int>& v2)
//     {
//         if (root == NULL) return v2;

//         Rinorder(root->right, v2); 
//         v2.push_back(root->data);  
//         Rinorder(root->left, v2);  

//         return v2;
//     }

//     int countPairs(Node* root1, Node* root2, int x)
//     {
//         vector<int> v1;
//         vector<int> v2;
//         inorder(root1, v1);
//         Rinorder(root2, v2);

//         // Edge case for empty trees
//         // if (v1.empty() || v2.empty()) return 0;

//         int count = 0;
//         int i = 0;
//         int j = 0;

//         while (i < v1.size() && j < v2.size())
//         {
//             int sum = v1[i] + v2[j];
//             if (sum < x)
//                 i++;
//             else if (sum == x)
//             {
//                 count++;
//                 i++;
//                 j++;
//             }
//             else
//                 j++;
//         }

//         return count;
//     }
// };


// NOW USING STACK




class Solution {
public:
    // Helper function to push all left nodes onto stack
    void pushLeft(Node* root, stack<Node*>& st) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
    
    // Helper function to push all right nodes onto stack
    void pushRight(Node* root, stack<Node*>& st) {
        while (root) {
            st.push(root);
            root = root->right;
        }
    }
    
    int countPairs(Node* root1, Node* root2, int x) {
        // If either tree is empty
        if (!root1 || !root2) return 0;
        
        stack<Node*> st1, st2;
        int count = 0;
        
        // Initialize stacks
        pushLeft(root1, st1);    // for inorder
        pushRight(root2, st2);   // for reverse inorder
        
        while (!st1.empty() && !st2.empty()) {
            Node* top1 = st1.top();
            Node* top2 = st2.top();
            
            int sum = top1->data + top2->data;
            
            if (sum == x) {
                count++;
                
                // Move both pointers
                st1.pop();
                st2.pop();
                
                // Process right subtree for inorder
                pushLeft(top1->right, st1);
                
                // Process left subtree for reverse inorder
                pushRight(top2->left, st2);
            }
            else if (sum < x) {
                // Need larger value, move inorder pointer
                st1.pop();
                pushLeft(top1->right, st1);
            }
            else {
                // Need smaller value, move reverse inorder pointer
                st2.pop();
                pushRight(top2->left, st2);
            }
        }
        
        return count;
    }
};







//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends