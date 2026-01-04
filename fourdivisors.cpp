#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSumDiv(int num) {
        int div = 0;
        int sum = 0;

        for (int fact = 1; fact * fact <= num; fact++) {
            if (num % fact == 0) {
                int other = num / fact;
                if (other == fact) {
                    div += 1;
                    sum += fact;
                } else {
                    div += 2;
                    sum += (fact + other);
                }
            }
            if (div > 4) return 0;
        }
        return div == 4 ? sum : 0;
    }

    int fourDiv(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            res += findSumDiv(num);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {21, 2, 3};
    Solution s;
    cout << s.fourDiv(nums);
    return 0;
}
