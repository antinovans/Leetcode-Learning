#include <unordered_set>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        cur.insert(root);
        while (!cur.empty())
        {
            for ( auto it = cur.begin(); it != cur.end(); ++it ){
                if((*it)->left!=nullptr) next.insert((*it)->left);
                if((*it)->right!=nullptr) next.insert((*it)->right);
            }
            std::swap(cur,next);
            next.clear();
            depth++;
        }
        return --depth;
    }
private:
    std::unordered_set<TreeNode*> cur;
    std::unordered_set<TreeNode*> next;
    int depth = 1;
};