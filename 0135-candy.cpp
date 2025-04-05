#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  int candy(std::vector<int> &ratings) {
    std::vector<int> buckets(ratings.size(), 1);

    for (int i = 1; i < ratings.size(); i++) {
      if (ratings[i - 1] < ratings[i]) {
        buckets[i] = buckets[i - 1] + 1;
      }
    }

    for (int i = 0; i < ratings.size() - 1; i++) {
      int idx = ratings.size() - 2 - i;
      if (ratings[idx] > ratings[idx + 1]) {
        buckets[idx] = std::max(buckets[idx], buckets[idx + 1] + 1);
      }
    }

    return std::accumulate(buckets.begin(), buckets.end(), 0);
  }
};