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
        cout << pre_order[pre_begin] << endl;
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
};

int main(int, char **)
{
    // ABDFGHIEC
    // FDHGIBEAC
    vector<char> pre_order = {'A','B','D','F','G','H','I','E','C'};
    vector<char> in_order =  {'F','D','H','G','I','B','E','A','C'};
    // vector<char> pre_order = {'A', 'B', 'C'};
    // vector<char> in_order = {'B', 'A', 'C'};
    Solution s;
    TreeNode *tree = s.buildTree(pre_order, in_order);
    cout << "process end." << endl;
}
