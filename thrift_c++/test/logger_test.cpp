#include <stdio.h>                                                                                                                                            
#include <ctype.h>                                                                                                                                            
#include <stdlib.h>                                                                                                                                           
#include <string>
#include <time.h>
#include <sstream>

#include <iostream> 
#include <pthread.h>

using namespace std;

class MyLogger
{
	string file_prefix;
	string filename;
	string yyyymmdd;

	FILE *log_file_w;

	pthread_mutex_t log_mutex;

public:
	
	void log(const char* log_value)
	{
		pthread_mutex_lock( &log_mutex );

		time_t tmNow = time(NULL);
		struct tm *tmT;
		tmT = localtime(&tmNow);

		stringstream s;
		s << tmT->tm_year + 1990 << tmT->tm_mday + 1 << tmT->tm_mday << tmT->tm_hour;
		string now_date = s.str();
		s.str("");
	
		if(now_date != yyyymmdd)
		//we are arriving an new hour
		{
			yyyymmdd = now_date;
			// concatenate the string and int 
			s << file_prefix << "_" << yyyymmdd << ".log";
			filename = s.str();

			if(log_file_w != NULL)
			{
				fclose(log_file_w);
			}
			//open new log file
			log_file_w = fopen(filename.c_str(), "wa");	
		}
		
		fprintf(log_file_w, "%s\n", log_value);
		pthread_mutex_unlock( &log_mutex );
		
	}

	MyLogger(string prefix) 
	{

		stringstream s;

		file_prefix = prefix;
		time_t tmNow = time(NULL);
		struct tm *tmT;
		tmT = localtime(&tmNow);

		s << tmT->tm_year + 1990 << tmT->tm_mon + 1 << tmT->tm_mday << 1 + tmT->tm_hour;
		yyyymmdd = s.str();
		s.str("");
		
		s << file_prefix << "_" << yyyymmdd << ".log";

		filename = s.str();
		cout << filename << endl;
		log_file_w = fopen(filename.c_str(), "wa");
		if(log_file_w == NULL) 
		{
			cout << "can't open log file " << filename << endl;
		}

		pthread_mutex_init(&log_mutex, NULL);	
	}

	~MyLogger()
	{
		if(log_file_w != NULL)
		{
			fclose(log_file_w);
		}
	}
};


int main(int argc, char*argv[])                                                                                                                               
{       
        MyLogger logger = MyLogger("../log/mylogger_test");
        //logger.log("this is a test log.........");
	return 0;
}
