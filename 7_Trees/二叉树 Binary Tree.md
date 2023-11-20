# 二叉树 Binary Tree

### 对称二叉树

100. 相同的树
101. 对称二叉树

572. 另一个树的子树

- 遍历顺序：左右子树遍历方式不同，一个是左右中，一个是右左中；层序遍历

- 遍历思想：用迭代法实现

- 数据结构：辅助数据结构用队列，栈，数组都可以

```C++
// 100. 相同的树

```

求解对称二叉树问题中时，对应位置的两节点，分别先后出栈，用一个指针变量存储来比较是否相同。





### 513 最下层左孩子

一般用递归，都需要创建一个void 返回类型的traversal 函数



### 112 Path Sum 总路径之和

```C++
class Solution {
private:
    bool traversal(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) return true; // 遇到叶子节点，并且计数为0
        if (!cur->left && !cur->right) return false; // 遇到叶子节点直接返回

        if (cur->left) { // 左
            count -= cur->left->val; // 递归，处理节点;
            if (traversal(cur->left, count)) return true;
            count += cur->left->val; // 回溯，撤销处理结果
        }
        if (cur->right) { // 右
            count -= cur->right->val; // 递归，处理节点;
            if (traversal(cur->right, count)) return true;
            count += cur->right->val; // 回溯，撤销处理结果
        }
        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return traversal(root, sum - root->val);
    }
};
```

```c++
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && sum == root->val) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
```

1. 确定递归函数的参数和返回类型