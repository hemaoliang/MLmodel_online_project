#include <xgboost/learner.h>
#include <xgboost/data.h>
#include <xgboost/logging.h>
#include <dmlc/timer.h>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include "common/sync.h"
#include "common/config.h"


using namespace std;
using namespace xgboost;



struct CLIParam : public dmlc::Parameter<CLIParam> {
    /*! \brief whether silent */
    int silent;
    /*! \brief number of boosting iterations */
    int num_round;
    /*! \brief the path of test model file, or file to restart training */
    std::string model_in;
    std::vector<std::pair<std::string, std::string> > cfg;

    // declare parameters
    DMLC_DECLARE_PARAMETER(CLIParam) {
        // NOTE: declare everything except eval_data_paths.
        DMLC_DECLARE_FIELD(silent).set_default(0).set_range(0, 2)
            .describe("Silent level during the task.");
        DMLC_DECLARE_FIELD(num_round).set_default(10).set_lower_bound(1)
            .describe("Number of boosting iterations");
        DMLC_DECLARE_FIELD(model_in).set_default("NULL")
            .describe("Input model path, if any.");
    }
  
    // customized configure function of CLIParam
    inline void Configure(const std::vector<std::pair<std::string, std::string> >& cfg) {
        this->cfg = cfg;
        this->InitAllowUnknown(cfg);
    }
  
};

class XgboostPredict
{
    public:
        XgboostPredict() {};
        XgboostPredict(string config_file);
        // this function is NOT threadsafe, make sure you only call from one thread.
        void online_predict(const SparseBatch::Inst &inst,
                            std::vector<bst_float> *out_preds);
       // predict for the whole dataset file 
        void dataset_predict(string data_path);
        
    private:
        std::unique_ptr<Learner> learner;
        CLIParam param;
        
};
