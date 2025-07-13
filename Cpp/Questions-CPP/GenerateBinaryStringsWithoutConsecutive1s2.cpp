#include <bits/stdc++.h>
using namespace std;

void ansHelper(string current, int n, vector<string> &result, bool isLastOne)
{
  if (current.length() == n)
  {
    result.push_back(current);
    return;
  }

  ansHelper(current + '0', n, result, false);

  if (!isLastOne)
  {
    ansHelper(current + '1', n, result, true);
  }
}

vector<string> ans(int num)
{
  vector<string> result; //string vector formation

  ansHelper("", num, result, false);
  return result;
}

int main()
{
  int n;
  cin >> n;

  vector<string> binary = ans(n);

  for (int i = 0; i < binary.size(); i++)
  {
    cout << binary[i] << " ";
  }

  return 0;
}