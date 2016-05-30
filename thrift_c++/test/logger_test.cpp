#include <stdio.h>                                                                                                                                            
#include <ctype.h>                                                                                                                                            
#include <stdlib.h>                                                                                                                                           
#include <string>
#include <time.h>
#include <sstream>

#include <mutex>
#include <iostream> 
#include <pthread.h>

using namespace std;

class MyLogger
{
	string file_prefix;
	string filename;
	int hour;

	FILE *log_file_w;

	pthread_mutex_t log_mutex;

	
	void log(FILE * log_out, string value)
	{
		time_t tmNow = time(NULL);
		struct tm *tmT;
		tmT = localtime(&time);

		int hour_now = tmT->tm_hour;
		printf("now hour: %d\n", hour_now);
		if(hour_now != hour)
		//we are arriving an new hour
		{
			hour = hour_now;
			// concatenate the string and int 
			stringstream s;
			s << file_prefix << "_" << hour << ".log";
			filename = s.str();

			if(log_file_w != NULL)
			{
				fclose(log_file_w);
			}
			//open new log file
			log_file_w = fopen(filename.c_str(), "wa");	
		}
		
	}

	MyLogger(string prefix) 
	{
		file_prefix = prefix;
		time_t tmNow = time(NULL);
		struct tm *tmT;
		tmT = localtime(&time);
		hour = tmT->tm_hour;

		stringstream s;
		s << file_prefix << "_" << hour << ".log";
		filename = s.str();
		log_file_w = fopen(filename.c_str(), "wa");

		log_mutex = PTHREAD_MUTEX_INITIALIZER;
		
	}

	~MyLogger()
	{
		fclose(log_file_w);
	}
};

