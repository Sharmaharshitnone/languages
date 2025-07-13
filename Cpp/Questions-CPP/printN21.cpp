// #include <bits/stdc++.h>
// using namespace std;

// int print(int n){
//     if (n < 1) return 0;

//     int sum = n + print(n-1);

//     return sum;
// }

// int main(){

//     int n;
//     cin >> n;

//     int res = print(n);

//     cout << res;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int print(int n)
{

    if (n < 1)
        return 0;
    int sum = n + print(n - 1);
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int res = print(n);
    cout << res;

    return 0;
}