#include <string>
#include <unordered_map>

class Solution
{
public:
  string minWindow(string s, string t)
  {
    string EMPTY = "";
    if (s.size() < t.size())
    {
      return EMPTY;
    }

    unordered_map<char, int> counts;
    unordered_map<char, int> window;

    for (char c : t)
    {
      counts[c] += 1;
    }

    int have = 0;
    int need = counts.size();
    int windowSize = s.size() + 999;

    int left = 0;
    int committedLeft = -1;
    int committedRight = -1;

    for (int right = 0; right < s.size(); right++)
    {
      char c = s[right];
      window[c] += 1;

      if (counts.find(c) != counts.end() && window[c] == counts[c])
      {
        have++;
      }

      while (need == have)
      {
        int currentWindowSize = right - left + 1;
        if (currentWindowSize < windowSize)
        {
          committedLeft = left;
          committedRight = right;
          windowSize = currentWindowSize;
        }

        window[s[left]] -= 1;
        if (counts.find(s[left]) != counts.end() && window[s[left]] < counts[s[left]])
        {
          have -= 1;
        }

        left += 1;
      }
    }

    if (windowSize > s.size())
    {
      return EMPTY;
    }

    return s.substr(committedLeft, committedRight - committedLeft + 1);
  }
};