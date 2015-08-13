#pragma once
#include <thread>

#define AT_TRY_STATEMENT(x)
#define AT_CATCH_STATEMENT(x)
#define AT_CATCH_STATEMENT_RETURN(x, y) return y;

extern std::thread* StartAsyncTask(const Fabric::EDK::KL::AsyncTask_& task, void* data);

extern bool StartAsyncTask(const Fabric::EDK::KL::AsyncTask& task, void* data);
extern bool JoinAsyncTask(const Fabric::EDK::KL::AsyncTask& task);

