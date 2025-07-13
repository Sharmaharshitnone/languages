#include<iostream>
using namespace std;

int main(){
	auto add = [](int a, int b){
		return a + b;
	};

	cout << "5 + 3 = " << add(5, 3) << endl;
	return 0;
}
