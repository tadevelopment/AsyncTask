#include "../GenCPP/AsyncTask.h"
#include "AsyncTask.h"

template<typename TASK>
struct TaskData
{
	TASK& m_task;
	void* m_data;

	TaskData(const TASK& task, void* data) : m_task(const_cast<TASK&>(task)), m_data(data) {}
};

void DoTask_(TaskData<Fabric::EDK::KL::AsyncTask_> *data)
{
	data->m_task.doTask(data->m_data);
}

void DoTask(TaskData<Fabric::EDK::KL::AsyncTask> *data)
{
	data->m_task.doTask(data->m_data);
}

std::thread* StartAsyncTask(const Fabric::EDK::KL::AsyncTask_& task, void* data)
{
	TaskData<Fabric::EDK::KL::AsyncTask_> td(task, data);
	std::thread* taskThread = new std::thread(DoTask_, &td);
    return taskThread;
}

bool StartAsyncTask(const Fabric::EDK::KL::AsyncTask& task, void* data)
{
	TaskData<Fabric::EDK::KL::AsyncTask> td(task, data);
	std::thread* taskThread = new std::thread(DoTask, &td);
	td.m_task->_threadHandle = taskThread;
	return false; //taskThread;
}

bool JoinAsyncTask(const Fabric::EDK::KL::AsyncTask& task)
{
    return false;
}
