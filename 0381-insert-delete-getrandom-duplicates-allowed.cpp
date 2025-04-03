#include <unordered_map>
#include <unordered_set>
#include <vector>

class RandomizedCollection {
private:
  vector<int> list;
  unordered_map<int, unordered_set<int>> hash;

public:
  RandomizedCollection() {}

  bool insert(int val) {
    list.push_back(val);

    int idx = list.size() - 1;
    hash[val].insert(idx);

    return hash[val].size() == 1;
  }

  bool remove(int val) {
    if (hash.find(val) == hash.end() || hash[val].size() == 0) {
      return false;
    }

    int idx = *hash[val].begin();
    hash[val].erase(idx);

    int lastIdx = list.size() - 1;
    int lastEl = list[lastIdx];

    if (lastIdx != idx) {
      list[idx] = lastEl;
      hash[lastEl].erase(lastIdx);
      hash[lastEl].insert(idx);
    }

    list.pop_back();

    if (hash[val].size() == 0) {
      hash.erase(val);
    }

    return true;
  }

  int getRandom() {
    int idx = rand() % list.size();
    return list[idx];
  }
};
