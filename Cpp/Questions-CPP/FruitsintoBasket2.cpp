#include <bits/stdc++.h>
using namespace std;

int maxFruits(vector<int> &arr, int n)
{
  int maxx = 0;
  for (int i = 0; i < n; i++)
  {
    unordered_set<int> basket;
    for (int j = i; j < n; j++)
    {
      basket.insert(arr[j]);
      if (basket.size() > 2)
      {
        break;
      }
      maxx = max(maxx, j - i + 1);
    }
  }
  return maxx;
}

int main()
{

  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int res = maxFruits(arr, n);
  cout << res;
  return 0;
}