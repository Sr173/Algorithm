// dynamic-programming.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "vector"

int price[] = { 1,5,8,9,10,17,17,20,24,30 };

#define max(a,b) (((a) > (b)) ? (a) : (b))

int getMax(int n) {
	if (n <= 0)
		return 0;
	int q = -0x37373737;
	for (int i = 0; i < sizeof(price) / sizeof(price[0]);i++) {
		q = max(q,price[i] + (getMax(n - i - 1)) - 3);
	}
	return q;
}

int getMax1(int n) {

}

int getMax2(int n) {
	std::vector<int> maxArray(n);
	for (int i = 0; i < n; i++) {
		int q = -0x37373737;
		for (auto j = 1; j < sizeof(price) / sizeof(price[0]); j++) {
			q = max(q, price[j]);
		}
	}
}

int main() {
	std::cout << getMax(10) << std::endl; 
}