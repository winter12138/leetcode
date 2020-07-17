#include "leetcode.hpp"
#include <algorithm>
#include <iostream>
#include <queue>
#include <regex>
#include <string>
#include <vector>

using namespace std;

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}

vector<int> stringToIntegerVector(string input) {
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(stoi(item));
  }
  return output;
}

vector<vector<int>> stringToIntegerMatrix(string input) {
  vector<vector<int>> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  //[[1,4,7,11,15], [2,5,8,12,19], [3,6,9,16,22],
  //[10,13,14,17,24],[18,21,23,26,30]]
  regex re(", *(?=\\[)");
  vector<string> v(sregex_token_iterator(begin(input), end(input), re, -1),
                   sregex_token_iterator());
  for (auto &item : v) {
    output.push_back(stringToIntegerVector(item));
  }
  return output;
}

vector<string> stringToStringVector(string input) {
  vector<string> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(item.substr(1, item.size() - 2));
  }
  return output;
}

ListNode *stringToListNode(string input) {
  // Generate list from the input
  vector<int> list = stringToIntegerVector(input);

  // Now convert that list into linked list
  ListNode *dummyRoot = new ListNode(0);
  ListNode *ptr = dummyRoot;
  for (int item : list) {
    ptr->next = new ListNode(item);
    ptr = ptr->next;
  }
  ptr = dummyRoot->next;
  delete dummyRoot;
  return ptr;
}

void prettyPrintLinkedList(ListNode *node) {
  while (node && node->next) {
    cout << node->val << "->";
    node = node->next;
  }

  if (node) {
    cout << node->val << endl;
  } else {
    cout << "Empty LinkedList" << endl;
  }
}

ostream &operator<<(ostream &os, ListNode *node) {
  prettyPrintLinkedList(node);
  return os;
}

string treeNodeToString(TreeNode *root) {
  if (root == nullptr) {
    return "[]";
  }

  string output = "";
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    if (node == nullptr) {
      output += "null, ";
      continue;
    }

    output += to_string(node->val) + ", ";
    q.push(node->left);
    q.push(node->right);
  }
  return "[" + output.substr(0, output.length() - 2) + "]";
}

TreeNode *stringToTreeNode(string input) {
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  if (!input.size()) {
    return nullptr;
  }

  string item;
  stringstream ss;
  ss.str(input);

  getline(ss, item, ',');
  TreeNode *root = new TreeNode(stoi(item));
  queue<TreeNode *> nodeQueue;
  nodeQueue.push(root);

  while (true) {
    TreeNode *node = nodeQueue.front();
    nodeQueue.pop();

    if (!getline(ss, item, ',')) {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int leftNumber = stoi(item);
      node->left = new TreeNode(leftNumber);
      nodeQueue.push(node->left);
    }

    if (!getline(ss, item, ',')) {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int rightNumber = stoi(item);
      node->right = new TreeNode(rightNumber);
      nodeQueue.push(node->right);
    }
  }
  return root;
}

void prettyPrintTree(TreeNode *node, string prefix = "", bool isLeft = true) {
  if (node == nullptr) {
    cout << "Empty tree";
    return;
  }

  if (node->right) {
    prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
  }

  cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

  if (node->left) {
    prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
  }
}

ostream &operator<<(ostream &os, TreeNode *node) {
  prettyPrintTree(node);
  return os;
}
// int main() { cout << "hello" << endl; }
