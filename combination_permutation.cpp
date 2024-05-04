#include <iostream>
#include <vector>
void combinations(vector<int>& nums, int start, int k, vector<int>& ans) {
    if (k == 0) { // or using k == nums.size();
        // show result
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        ans.push_back(nums[i]);
        combinations(nums, i + 1, k - 1, ans, result);
        ans.pop_back();
    }
}


// not using vector
void permutation(int n, bool *visited, int k, int *ans) {
    if (k == n) {
    	// show result
        for (int i = 0; i < k; i++) cout << ans[i] << char(32);
        cout << endl;
        return;
    } 

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            // Neu chua duoc chon thi chon
            visited[i] = true;
            ans[k] = i; k++;
            permutation(n, visited, k, ans);

            // Quay lui bo chon
            visited[i] = false;
            k--; ans[k] = 0;
        }
    }
}
