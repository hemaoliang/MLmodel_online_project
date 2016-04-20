#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "../gen-cpp/MLOlineService.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace mlmodelserver;


static char *line = NULL;
static int max_line_len;

void exit_with_help()
{
	printf(
	"Usage: svm-predict [options] test_file model_file output_file\n"
	"options:\n"
	"-b probability_estimates: whether to predict probability estimates, 0 or 1 (default 0); for one-class SVM only 0 is supported\n"
	"-q : quiet mode (no outputs)\n"
	);
	exit(1);
}

static char* readline(FILE *input)
{
	int len;

	if(fgets(line,max_line_len,input) == NULL)
		return NULL;

	while(strrchr(line,'\n') == NULL)
	{
		max_line_len *= 2;
		line = (char *) realloc(line,max_line_len);
		len = (int) strlen(line);
		if(fgets(line+len,max_line_len-len,input) == NULL)
			break;
	}
	return line;
}


int main(int argc, char **argv) {
	FILE *input, *output;
	int i,j;
	int predict_probability=0;
	for(i=1;i<argc;i++)
	{
		if(argv[i][0] != '-') break;
		++i;
		switch(argv[i-1][1])
		{
			case 'b':
				predict_probability = atoi(argv[i]);
				break;
			case 'q':
				//info = &print_null;
				i--;
				break;
			default:
				fprintf(stderr,"Unknown option: -%c\n", argv[i-1][1]);

		}
	}

	if(i>=argc-2)
		exit_with_help();

	
	boost::shared_ptr<TTransport> socket(new TSocket("localhost", 8000));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	MLOlineServiceClient client(protocol);
	transport->open();

	//testing for 1000 times for watching whether memory leak
	for(int k=1; ; k++)
	{
	printf("testing for %d times.\n" ,k);

	input = fopen(argv[i],"r");
	if(input == NULL)
	{
	fprintf(stderr,"can't open input file %s\n",argv[i]);
		exit(1);
	}

	output = fopen(argv[i+2],"w");
	if(output == NULL)
	{
		fprintf(stderr,"can't open output file %s\n",argv[i+2]);
		exit(1);
	}

	max_line_len = 1024;
	line = (char *)malloc(max_line_len*sizeof(char));

	//boost::shared_ptr<TTransport> socket(new TSocket("localhost", 8000));
	//boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	//boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	//MLOlineServiceClient client(protocol);
	//transport->open();

	int nr_class = 2;
	vector<int> labels;
	client.getLabel(labels,10010,"test_libsvm");

	fprintf(output,"labels");
	for(j=0;j<nr_class;j++)
		fprintf(output," %d",labels[j]);
	fprintf(output,"\n");

	returnType return_val;

	while(readline(input) != NULL){
		string feature(line);
		client.modelPredict(return_val,10086,"test_libsvm",feature);
		fprintf(output,"%g",return_val.predicted);
		if(predict_probability)
		{
			for(j=0;j<nr_class;j++)
				fprintf(output," %g",return_val.prob[j]);
		}
		fprintf(output,"\n");

	}

	free(line);
	fclose(input);
	fclose(output);
	//transport->close();
	//break;
	}//end for
	
	transport->close();

	return 0;
}
