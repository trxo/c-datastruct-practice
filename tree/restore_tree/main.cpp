#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    char v;
    TreeNode *l;
    TreeNode *r;
    TreeNode(char x) : v(x), l(NULL), r(NULL) {}
};

class Solution
{
public:
    TreeNode *getTree(vector<char> &pre_order, vector<char> &in_order, int pre_begin, int pre_end, int in_begin, int in_end)
    {
        if (in_end <= in_begin)
        {
            return NULL;
        }
        TreeNode *r = new TreeNode(pre_order[pre_begin]);

        int tmp_index = in_begin;
        while (tmp_index < in_end)
        {
            if (in_order[tmp_index] == pre_order[pre_begin])
            {
                break;
            }
            tmp_index++;
        }

        int len = tmp_index - in_begin;

        r->l = getTree(pre_order, in_order, pre_begin + 1, pre_begin + len + 1, in_begin, in_begin + len);
        r->r = getTree(pre_order, in_order, pre_begin + len + 1, pre_end, in_begin + len + 1, in_end);
        return r;
    }

    TreeNode *buildTree(vector<char> &pre_order, vector<char> &in_order)
    {
        return getTree(pre_order, in_order, 0, pre_order.size(), 0, in_order.size());
    } 

    TreeNode *getTree1(vector<char> &pre_order, vector<char> &in_order, int pre_begin, int pre_end, int in_begin, int in_end)
    {
        if (pre_end <= pre_begin || pre_end < 0)
        {
            return NULL;
        }
        TreeNode *r = new TreeNode(pre_order[pre_end-1]);

        int tmp_index = in_begin;
        while (tmp_index < in_end)
        {
            if (in_order[tmp_index] == pre_order[pre_end-1])
            {
                break;
            }
            tmp_index++;
        }

        int len = tmp_index - in_begin;

        r->l = getTree1(pre_order, in_order, pre_begin, pre_begin + len, in_begin, in_begin + len);
        r->r = getTree1(pre_order, in_order, pre_begin + len, pre_end - 1, in_begin + len + 1, in_end);
        return r;
    }

    TreeNode *buildTree1(vector<char> &pre_order, vector<char> &in_order)
    {
        return getTree1(pre_order, in_order, 0, pre_order.size(), 0, in_order.size());
    } 

};



void test_pre(){
    //根据前序和中序还原二叉树
    vector<char> pre_order = {'A','B','D','F','G','H','I','E','C'};
    vector<char> in_order =  {'F','D','H','G','I','B','E','A','C'};
    // vector<char> pre_order = {'A', 'B', 'C'};
    // vector<char> in_order = {'B', 'A', 'C'};
    Solution s;
    TreeNode *tree = s.buildTree(pre_order, in_order);
    cout << "pre process end." << endl;
}


void test_after(){
    //根据后序和中序还原二叉树
    vector<char> after_order = {'F','H','I','G','D','E','B','C','A'};
    vector<char> in_order =  {'F','D','H','G','I','B','E','A','C'};
    // vector<char> after_order = {'B', 'C', 'A'};
    // vector<char> in_order =  {'B', 'A', 'C'};
    Solution s;
    TreeNode *tree = s.buildTree1(after_order, in_order);
    cout << "after process end." << endl;
}


int main(int, char **)
{
    
    // ABDFGHIEC  前序遍历
    // FDHGIBEAC  中序遍历
    // FHIGDEBCA  
    // test_pre();
    test_after();
}



