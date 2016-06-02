#include <stdio.h>                                                                                                                                            
#include <ctype.h>                                                                                                                                            
#include <stdlib.h>                                                                                                                                           
#include <string>
#include <time.h>
#include <sstream>

#include <iostream> 
#include <pthread.h>
#include <unistd.h>

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
		s << tmT->tm_year + 1990 << "-" << tmT->tm_mon + 1 << "-" << tmT->tm_mday << "-" << tmT->tm_hour;
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
		
		fprintf(log_file_w, "%d-%d-%d %d:%d:%d : %s\n", tmT->tm_year + 1990, tmT->tm_mon + 1, tmT->tm_mday,
				tmT->tm_hour, tmT->tm_min, tmT->tm_sec, log_value);
		pthread_mutex_unlock( &log_mutex );
		
	}

	MyLogger(string prefix) 
	{

		stringstream s;

		file_prefix = prefix;
		time_t tmNow = time(NULL);
		struct tm *tmT;
		tmT = localtime(&tmNow);

		s << tmT->tm_year + 1990 << "-" << tmT->tm_mon + 1 << "-" << tmT->tm_mday << "-" << tmT->tm_hour;
		yyyymmdd = s.str();
		s.str("");
		
		s << file_prefix << "_" << yyyymmdd << ".log";

		filename = s.str();
		//cout << filename << endl;
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

MyLogger logger = MyLogger("../log/mylogger_test");

void* log_thread(void* ptr)
{
	pthread_t tid = pthread_self();
	for(int i=0; ;i++)
	{
	char *message;
	message = (char *) ptr;
	logger.log(message);
	sleep(1);
	}
}

int main(int argc, char*argv[])                                                                                                                               
{       
	//logger.log("this is a test log.........");

	pthread_t ntids[5];	

	char buff[5][100];
	for(int i=0; i<5; i++)
	{		
		snprintf(buff[i], sizeof(buff[i]), "this is log from thread-%d", i);
		int iret;
		iret = pthread_create(&ntids[i],NULL,log_thread, (void *)buff[i]);
		if(iret)
		{
			fprintf(stderr,"Error - pthread_create() return code: %d\n",iret);
			exit(EXIT_FAILURE);
		}
		cout << "create thead-" << buff[i] << endl;
	}

	for(int i=0; i<5; i++)
	{
		pthread_join( ntids[i], NULL );
	} 

	return 0;
}


