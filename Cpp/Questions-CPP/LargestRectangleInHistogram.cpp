#include <bits/stdc++.h>
using namespace std;

int largestArea(vector <int> arr){
    int n = arr.size();
    arr.push_back(0);
    int max_area = 0;
    stack <int> st;
    
    for(int i = 0; i <= n; i++){
        while(!st.empty() && arr[i] < arr[st.top()]){
            int h = arr[st.top()];
            st.pop();

            int w = st.empty() ? i : i-st.top()-1;

            max_area = max(max_area, h*w);
        }
        st.push(i);
    }
 
    return max_area;
}

int main(){
    int n;
    cin >> n;

    vector <int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int area = largestArea(arr);

    cout << area;

    return 0;
}