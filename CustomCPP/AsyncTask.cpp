#include "../GenCPP/AsyncTask.h"
#include "AsyncTask.h"

void DoTask_(Fabric::EDK::KL::AsyncTask_* task, void* cb_data)
{
	task->doTask(cb_data);
}

void DoTask(Fabric::EDK::KL::AsyncTask* task, void* cb_data)
{
	task->doTask(cb_data);

	// On completion, we set the member variable to complete
	(*task)->complete = true;
}

std::thread* StartAsyncTask(Fabric::EDK::KL::AsyncTask_& task, void* data)
{
	std::thread* taskThread = new std::thread(DoTask_, &task, data);
    return taskThread;
}

bool StartAsyncTask(Fabric::EDK::KL::AsyncTask& task, void* data)
{
	std::thread* taskThread = new std::thread(DoTask, &task, data);
	task->_threadHandle = taskThread;
	return false;
}

bool JoinAsyncTask(const Fabric::EDK::KL::AsyncTask& task)
{
	std::thread* taskThread = reinterpret_cast<std::thread*>(task->_threadHandle);
	if (taskThread != nullptr && taskThread->joinable())
	{
		taskThread->join();
		return true;
	}
    return false;
}
