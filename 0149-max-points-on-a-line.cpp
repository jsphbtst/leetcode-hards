#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int maxPoints(std::vector<std::vector<int>> &points) {
    int result = 1;

    for (int i = 0; i < points.size(); i++) {
      std::vector<int> p1 = points[i];
      int x1 = p1[0];
      int y1 = p1[1];

      std::unordered_map<float, int> seen;
      for (int j = i + 1; j < points.size(); j++) {
        std::vector<int> p2 = points[j];
        int x2 = p2[0];
        int y2 = p2[1];

        float slope = x1 == x2 ? std::numeric_limits<float>::infinity()
                               : static_cast<float>(y2 - y1) / (x2 - x1);

        seen[slope]++;
        result = std::max(result, seen[slope] + 1);
      }
    }

    return result;
  }
};