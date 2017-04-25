'''
 * @file xgboost_train.py
 * @author tracyhe(tracyhe@tencent.com)
 * @date 2015/03/31 15:38:12
 * @brief 
 *  
 '''

import xgboost as xgb
from operator import itemgetter

param = {'max_depth':2, 'eta':1, 'silent':0, 'objective':'binary:logistic', 'eval_metric':'auc'}

num_round=5

dtrain = xgb.DMatrix('../data/20170224_train.libsvm')
dtest = xgb.DMatrix('../data/20160928_test.libsvm')

bst=xgb.train(param,dtrain,num_round,evals=[(dtest,'eval'),(dtrain,'train')])
#print xgb.cv(param,dtrain,num_round,nfold=5)

bst.save_model('xgboost.model')

importance = bst.get_fscore()
print importance
importance = sorted(importance.items(), key=itemgetter(1),reverse=True)
print importance

