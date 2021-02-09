/* ------------------------------------------------------------------|
假设按照升序排序的数组在预先未知的某个点上进行了旋转。例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] 。

请找出其中最小的元素。

 

示例 1：

输入：nums = [3,4,5,1,2]
输出：1
示例 2：

输入：nums = [4,5,6,7,0,1,2]
输出：0
示例 3：

输入：nums = [1]
输出：1
 

提示：

1 <= nums.length <= 5000
-5000 <= nums[i] <= 5000
nums 中的所有整数都是 唯一 的
nums 原来是一个升序排序的数组，但在预先未知的某个点上进行了旋转

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：9.9 MB, 在所有 C++ 提交中击败了74.03%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


/*  O(n)复杂度
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：9.9 MB, 在所有 C++ 提交中击败了74.03%的用户
*/

int findMin(vector<int>& nums) {
    int n = nums.size();
    int res = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i - 1]) {
            return nums[i];
        }
    }
    return res;
}

/*  二分查找O(logn)
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：9.9 MB, 在所有 C++ 提交中击败了83.77%的用户
*/
int findMin(vector<int>& nums) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    //可以规避最坏的情况
    if (n == 1 || nums[r] > nums[l]) {
        return nums[0];
    }

    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] > nums[r]) {
            l = mid + 1;
            continue;
        }
        else {
            r = mid;
        }
    }
    return nums[l];
}