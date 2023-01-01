#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        std::vector<bool> used(nums.size(), false);

        dfs(nums, path, used, res);

        return res;
    }

private:
    void dfs(std::vector<int> &nums, std::vector<int> &path, std::vector<bool> &used, std::vector<std::vector<int>> &res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, path, used, res);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};