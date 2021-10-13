#include <iostream>
#include <cstdlib>
#include "Windows.h"

using namespace std;

void getProcessPriority(HANDLE hp); //приоритетный класс процесса 
void getThreadPriority(HANDLE ht);
void getAffinityMask(HANDLE hp, HANDLE ht);

int main()
{
	HANDLE hp = GetCurrentProcess();
	HANDLE ht = GetCurrentThread();
	DWORD pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();

	cout << "OS05_01\n\n";
	cout << "PID: " << pid << endl << "TID: " << tid << endl;
	getProcessPriority(hp);
	getThreadPriority(ht);
	getAffinityMask(hp, ht);

	system("pause");
}

void getProcessPriority(HANDLE hp) {
	DWORD prty = GetPriorityClass(hp);

	switch (prty) {
		case IDLE_PRIORITY_CLASS: cout << "ProcessPriority: IDLE_PRIORITY_CLASS\n"; break;
		case BELOW_NORMAL_PRIORITY_CLASS: cout << "ProcessPriority: BELOW_NORMAL_PRIORITY_CLASS\n"; break;
		case NORMAL_PRIORITY_CLASS: cout << "ProcessPriority: NORMAL_PRIORITY_CLASS\n"; break;
		case ABOVE_NORMAL_PRIORITY_CLASS: cout << "ProcessPriority: ABOVE_NORMAL_PRIORITY_CLASS\n"; break;
		case HIGH_PRIORITY_CLASS: cout << "ProcessPriority: HIGH_PRIORITY_CLASS\n"; break;
		case REALTIME_PRIORITY_CLASS: cout << "ProcessPriority: REALTIME_PRIORITY_CLASS\n"; break;
		default: cout << "?\n\n"; break;
	}
}

void getThreadPriority(HANDLE ht) {
	DWORD prty = GetPriorityClass(ht);

	cout << "ThreadPriority: " << GetThreadPriority(ht) << " ";

	switch (prty) {
		case THREAD_PRIORITY_LOWEST: cout << "THREAD_PRIORITY_LOWEST\n" ; break;
		case THREAD_PRIORITY_BELOW_NORMAL: cout << "THREAD_PRIORITY_BELOW_NORMAL\n" ; break;
		case THREAD_PRIORITY_NORMAL: cout << "THREAD_PRIORITY_NORMAL\n" ; break;
		case THREAD_PRIORITY_ABOVE_NORMAL: cout << "THREAD_PRIORITY_ABOVE_NORMAL\n" ; break;
		case THREAD_PRIORITY_HIGHEST: cout << "THREAD_PRIORITY_HIGHEST\n" ; break;
		case THREAD_PRIORITY_IDLE: cout << "THREAD_PRIORITY_IDLE\n" ; break;
		default: cout << "?\n\n"; break;
	}
}

void getAffinityMask(HANDLE hp, HANDLE ht) {
	DWORD pa = NULL, sa = NULL, icpu = -1;
	char buf[10];

	if (!GetProcessAffinityMask(hp, &pa, &sa)) {
		throw "GetProcessAffinityMask";
	}
	_itoa_s(pa, buf, 2);
	cout << "Process affinity Mask: " << buf << endl;
	cout << "Process affinity Mask: " << hex << pa << endl;
	_itoa_s(sa, buf, 2);
	cout << "System affinity Mask: " << buf << endl;
	icpu = SetThreadIdealProcessor(ht, MAXIMUM_PROCESSORS);
	cout << "Thread IdealProcessor: " << dec << icpu<< endl;
	SYSTEM_INFO sys_info;
	GetSystemInfo(&sys_info);
	cout << "Max count processors: " << sys_info.dwNumberOfProcessors << endl << endl;
}