// This program prints numbers from m to n using recursion.

#include <bits/stdc++.h>
using namespace std;

void oneToN(int m, int n){
    if(m > n) return;

    cout << m << endl;
    oneToN(m+1, n);
}


int main(){

    int m,n;
    cin >> m >> n;

    // print(str, n);

    oneToN(m,n);



    return 0;
}


