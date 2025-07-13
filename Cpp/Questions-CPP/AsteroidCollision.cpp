#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    stack <int> st;

    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            st.push(arr[i]);
        }
        else{
            while(!st.empty() && st.top() > 0 && abs(arr[i]) > st.top()){
                st.pop();
            }
            if(!st.empty() && st.top() > 0 && abs(arr[i]) == st.top()){
                st.pop();
            }
            else if(st.empty() || st.top() < 0){
                st.push(arr[i]);
            }
        }
    }

    if(st.empty()){
        cout << "Everything Destroyed";
    }

    else{

        stack <int> ans;
    
        while(!st.empty()){
            ans.push(st.top());
            st.pop();
        }
    
        while(!ans.empty()){
            cout << ans.top() << " ";
            ans.pop();
        }
    }



    return 0;
}