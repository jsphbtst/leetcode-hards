class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < 0) {
        nums[i] = 0;
      }
    }

    for (int i = 0; i < nums.size(); i++) {
      int current = abs(nums[i]);
      if (1 <= current && current <= nums.size()) {
        int i = current - 1;
        if (nums[i] > 0) {
          nums[i] *= -1;
        } else if (nums[i] == 0) {
          nums[i] = -1 * (nums.size() + 1);
        }
      }
    }

    for (int i = 1; i < nums.size() + 1; i++) {
      if (nums[i - 1] >= 0) {
        return i;
      }
    }

    return nums.size() + 1;
  }
};