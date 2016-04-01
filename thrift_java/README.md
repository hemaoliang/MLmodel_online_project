compile
------------------------------
g++ tuple.cpp evaluate.cpp cart.cpp aggregation.cpp  -lboost_thread -lboost_system -lpthread
./a.out -f 699 -z -v -a 0.5 -t 10 -d 4 -T 0 data/small.txt data/small.txt data/small.txt.out

input format(data type like libsvm or svm-rank)
1.format 1
<label> qid:1 index:value
numberFeature = max(index) + 1

2.format 2
<label> index:value
numberFeature = max(index) + 1


