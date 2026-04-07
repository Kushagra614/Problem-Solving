/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* dfs(Node* node, unordered_map<Node*, Node*>&mp)
    {
        if(mp.find(node) != mp.end())
        {
            return mp[node];
        }

        Node* clone = new Node(node->val);
        mp[node] = clone;

        for(auto nbr : node->neighbors)
        {
            clone->neighbors.push_back(dfs(nbr, mp));
        }

        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)
        {
            return NULL;
        }

        unordered_map<Node*, Node*>mp;
        return dfs(node, mp);
    }
};