#include <queue>
#include <vector>

class MedianFinder {
private:
  priority_queue<int, vector<int>, less<int>> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

public:
  MedianFinder() {}

  void addNum(int num) {
    if (maxHeap.empty() || num < maxHeap.top()) {
      maxHeap.push(num);
    } else {
      minHeap.push(num);
    }

    if (maxHeap.size() > minHeap.size() + 1) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    } else if (minHeap.size() > maxHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  double findMedian() {
    if (minHeap.size() == maxHeap.size()) {
      return (minHeap.top() + maxHeap.top()) / 2.0;
    }

    return maxHeap.top();
  }
};