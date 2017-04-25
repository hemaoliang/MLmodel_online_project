#include "xgboost_online_predict.h"

DMLC_REGISTER_PARAMETER(CLIParam);


XgboostPredict::XgboostPredict(string config_file)
{

    // data struct for config information
    std::vector<std::pair<std::string, std::string> > cfg;
    cfg.push_back(std::make_pair("seed", "0"));
    
    // parse the config information
    common::ConfigIterator itr(config_file.c_str());
    while (itr.Next()) {
        cfg.push_back(std::make_pair(std::string(itr.name()), std::string(itr.val())));
        //std::cout << "config param: " << std::string(itr.name()) << " = " << std::string(itr.val()) << endl;
    }
    
    param.Configure(cfg);

    // load model
    CHECK_NE(param.model_in, "NULL")
        << "Must specify model_in for predict";
    
    learner.reset(Learner::Create({}));
    std::unique_ptr<dmlc::Stream> fi(dmlc::Stream::Create(param.model_in.c_str(), "r")); 

    learner->Configure(param.cfg);
    learner->Load(fi.get());           
    
}


void XgboostPredict::online_predict(const SparseBatch::Inst &inst,
                      std::vector<bst_float> *out_preds) 
{
    learner->Predict(inst,false,out_preds,0);

}

void XgboostPredict::dataset_predict(string data_path)
{
    std::unique_ptr<DMatrix> dtest(DMatrix::Load(data_path, 1, 0));
    
    // test the DMatrix output
    dmlc::DataIter<xgboost::RowBatch> * row_iter = dtest->RowIterator();
    row_iter->BeforeFirst(); row_iter->Next();
    xgboost::SparseBatch::Inst first_row = row_iter->Value()[0];
    std::cout << "dtest matrix first row Inst length " << first_row.length << endl;
    std::cout << "Entry " << first_row[13].index << ":" << first_row[13].fvalue << endl;
    
    
    std::vector<bst_float> preds;
    learner->Predict(dtest.get(), false, &preds, 0);
    std::cout<< data_path << " predict head value; " << preds[3] << endl;
    
    // get test data evaluate
    std::vector<DMatrix*> eval_datasets;
    std::vector<std::string> eval_data_names;
    eval_datasets.push_back(dtest.get());
    eval_data_names.push_back(std::string("test-eval"));

    std::string res = learner->EvalOneIter(param.num_round, eval_datasets, eval_data_names); 
    std::cout << res << endl;
    
}


void online_predict_test()
{
    XgboostPredict pre("./xgboost.config");
    // instance example -- 1:0 2:1 3:40 4:0 5:99 6:0 7:0 8:0 9:0 10:0 11:0 12:0 13:0 14:7
    bst_uint length = 14;
    SparseBatch::Entry en[14] = {SparseBatch::Entry(1,0),SparseBatch::Entry(2,1),SparseBatch::Entry(3,40),SparseBatch::Entry(4,0),SparseBatch::Entry(5,99),
				SparseBatch::Entry(6,0),SparseBatch::Entry(7,0),SparseBatch::Entry(8,0),SparseBatch::Entry(9,0),SparseBatch::Entry(10,0),
				SparseBatch::Entry(11,0),SparseBatch::Entry(12,0),SparseBatch::Entry(13,0),SparseBatch::Entry(14,7)};
    SparseBatch::Inst inst(en,length);

    std::vector<bst_float> res;
    pre.online_predict(inst, &res);
    std::cout << "res value: " << res[0] <<endl;
    

}


int main(int argc, char *argv[]) {
    cout << "hello xgboost !" << endl;
    for (int i=0; i<10000; i++){
        //XgboostPredict pre("./xgboost.config");
        //pre.dataset_predict("/cephfs/person/tracyhe/workspace/data/20160928_test.libsvm");
        online_predict_test();
        if (i % 1000 == 0) std::cout<< "iteration:  " << i<<endl;
    }
}
