#include <vector>
#include <unordered_map>
using namespace std;
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
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        if(ans.find(node) == ans.end()){
            ans[node] = new Node(node->val,{});
            for(auto neighbor : node->neighbors){
                ans[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return ans[node];
    }
private:
    unordered_map<Node*, Node*> ans;
};