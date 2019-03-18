// SearchBlackMemory.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "windows.h"
#include "compare"

int main()
{
	std::string a = "1";
	std::string b = "12";
	auto hNtdll = GetModuleHandle(L"Ntdll.dll");
	std::cout << std::hex << hNtdll << std::endl;
	MEMORY_BASIC_INFORMATION memInfo;
	PAGE_EXECUTE_READ;
	for (VirtualQuery(hNtdll, &memInfo, sizeof(memInfo)); VirtualQuery((LPVOID)((int)memInfo.BaseAddress + memInfo.RegionSize), &memInfo, sizeof(memInfo));) {
		if ((memInfo.Protect & 0xF0) != 0) {
			for (int i = reinterpret_cast<int>(memInfo.BaseAddress), lenth = 0; i < reinterpret_cast<int>(memInfo.BaseAddress) + memInfo.RegionSize; i++) {
				if (*(byte*)i == 0) {
					lenth++;
				}
				else {
					lenth = 0;
				}

				if (lenth >= 339) {
					std::cout << std::hex << i << std::endl;
					lenth = 0;
				}
			}
		}
	}
}