#include <iostream>
#include <queue>
#include <sstream>
using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    // DFS to check if linked list matches a downward path
    bool dfs(TreeNode* root, ListNode* head)
    {
        if (!head) return true;
        if (!root) return false;
        if (root->val != head->val) return false;
        return dfs(root->left, head->next) || dfs(root->right, head->next);
    }
    // Try every node as starting point
    bool isSubPath(ListNode* head, TreeNode* root)
    {
        if (!root) return false;
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
// Function to build linked list from user input
ListNode* buildLinkedList() {
    int n;
    cout << "Enter number of nodes in linked list: ";
    cin >> n;
    if (n == 0) return nullptr;
    cout << "Enter linked list values: "<<endl;
    int val;
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* curr = head;
    for (int i = 1; i < n; i++)
    {
        cin >> val;
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return head;
}
// Function to build binary tree level-wise using -1 as null marker
TreeNode* buildTree() {
    cout << "\nEnter tree nodes in level order (use -1 for NULL):\n";
    cout << "Example: 1 4 4 -1 2 2 -1 -1 6 8\n";
    cout << "Enter: ";
    string line;
    cin.ignore(); // clear leftover newline
    getline(cin, line);
    stringstream ss(line);
    vector<int> values;
    int val;
    while (ss >> val) values.push_back(val);
    if (values.empty() || values[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* curr = q.front();
        q.pop();
        // Left child
        if (i < values.size() && values[i] != -1)
        {
            curr->left = new TreeNode(values[i]);
            q.push(curr->left);
        }
        i++;
        // Right child
        if (i < values.size() && values[i] != -1)
        {
            curr->right = new TreeNode(values[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
int main()
{
    cout << "=== Linked List in Binary Tree ===\n";
    // Build linked list and binary tree
    ListNode* head = buildLinkedList();
    TreeNode* root = buildTree();
    Solution sol;
    bool result = sol.isSubPath(head, root);
    cout << "\nOutput: " << (result ? "true" : "false") << endl;
    return 0;
}
