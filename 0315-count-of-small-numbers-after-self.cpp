#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  void updateFenwick(std::vector<int> &fenwick, int index, int delta) {
    while (index < fenwick.size()) {
      fenwick[index] += delta;
      index += index & (-index);
    }
  }

  int queryFenwick(std::vector<int> &fenwick, int index) {
    int sum = 0;
    while (index > 0) {
      sum += fenwick[index];
      index -= index & (-index);
    }
    return sum;
  }

  std::vector<int> countSmaller(std::vector<int> &nums) {
    std::unordered_set<int> set(nums.begin(), nums.end());
    std::vector<int> sortedUnique(set.begin(), set.end());
    std::sort(sortedUnique.begin(), sortedUnique.end());

    std::unordered_map<int, int> rankMap;
    for (int i = 0; i < sortedUnique.size(); ++i) {
      rankMap[sortedUnique[i]] = i + 1;
    }

    std::vector<int> fenwick(sortedUnique.size() + 1, 0);
    std::vector<int> counts(nums.size(), 0);

    for (int i = nums.size() - 1; i >= 0; --i) {
      int rank = rankMap[nums[i]];
      counts[i] = queryFenwick(fenwick, rank - 1);
      updateFenwick(fenwick, rank, 1);
    }

    return counts;
  }
};