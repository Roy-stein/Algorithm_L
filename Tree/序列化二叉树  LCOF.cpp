// Leetcode: 剑指 Offer 37. 序列化二叉树  LCOF 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void rserialize(TreeNode* root, string& str){
        if(!root){
            str += "None,";
            return ;
        }
        str += to_string(root->val) + ",";
        rserialize(root->left, str);
        rserialize(root->right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {			//序列化 
        string ret = "";
        rserialize(root, ret);
        return ret;
    }

    TreeNode* rdeserialize(list<string>& dataArray) {
        if(dataArray.front() == "None"){
            dataArray.erase(dataArray.begin());
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {		//反序列化 
        list<string> dataArray;
        string str;
        for(auto c : data){
            if(c == ','){
                dataArray.push_back(str);
                str.clear();
            }else{
                str.push_back(c);
            }
        }
        if(!str.empty()){
            dataArray.push_back(str);
            str.clear();
        }
        return rdeserialize(dataArray);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
