#include "FindFunction.h"

const int threadCount = 8;
mutex mtx;
int numberOfThreads;
vector<thread> myThreads[threadCount];

bool find_file(const path & dir_path, const string & file_name, path & path_found)
{
	if (!exists(dir_path)) return false;
	directory_iterator end_itr;
	for (directory_iterator itr(dir_path); itr != end_itr; ++itr)
	{
		if (is_directory(itr->status()))
		{
			if (find_file(itr->path(), file_name, path_found))
			{
				thread thrd(find_file, itr->path(), file_name, path_found);
				myThreads->push_back(thrd);
				return true;
			}
		}
		else if (itr->path().leaf() == file_name)
		{
			path_found = itr->path();
			return true;
		}
	}
	return false;
}