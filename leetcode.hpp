#include <ostream>
#include <string>
#include <vector>

using namespace std;

// vector
vector<int> stringToIntegerVector(string input);
vector<vector<int>> stringToIntegerMatrix(string input);
vector<string> stringToStringVector(string input);
vector<vector<string>> stringToStringMatrix(string input);
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
  for (auto& x : v) {
    os << ' ' << x;
  }
  os << endl;
  return os;
}

// list
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
ListNode* stringToListNode(string input);
ostream& operator<<(ostream& os, ListNode* node);

// tree
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* left_, TreeNode* right_)
      : val(x), left(left_), right(right_) {}
};
string treeNodeToString(TreeNode* root);
TreeNode* stringToTreeNode(string input);
ostream& operator<<(ostream& os, TreeNode* node);