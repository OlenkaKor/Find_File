#pragma once

#include "boost/filesystem.hpp" 
#include <thread>
#include <mutex>
#include <vector>

using namespace boost::filesystem;
using namespace std;

extern const int threadCount;
extern mutex mtx;
extern int numberOfThreads;
extern vector<thread> myThreads[threadCount];

bool find_file(const path & dir_path, const string & file_name, path & path_found);

