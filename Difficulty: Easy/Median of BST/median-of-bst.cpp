//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   
cout << "~" << "\n";
}
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST


vector<float> inorder(struct Node* root, vector<float>&v)
{
    // base case
    if(root==NULL)
    {
        return  v;
    }
    
    //LNR
    //L
    inorder(root->left, v);
    
    //N
    v.push_back(root->data);
    
    //R
    inorder(root->right,v);
    
    return v;
    
}

float findMedian(struct Node *root)
{
      if(root==NULL)
      {
          return NULL; 
      }
      
      float medianIndex;
      float median;
      
      vector<float>vec;
      inorder(root,vec);
      
      int N = vec.size();
      if (N & 1) { 
        // If N is odd, the median is the (N+1)/2-th element (1-based indexing)
        median = vec[(N) / 2];
        } 
        else {
        // If N is even, take the average of the (N/2)-th and (N/2 + 1)-th elements (1-based indexing)
        median = (vec[(N / 2) - 1] + vec[N / 2]) / 2.0;
        }
      
      
    return median;
}

