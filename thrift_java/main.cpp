#include <boost/program_options.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace  boost::program_options;
int main(int argc, char* argv[])
{
  string one ; // 外部变量 存储 参数one的值
  vector<string> mult;
  boost::program_options::options_description opts("test options");
  opts.add_options()
    ("help,h","help info")
    ("test1,t",value<string>(),"test aaa ")
    ("one,o",value<string>(&one)->default_value("one"),"test one default") // 默认值 
    ("mult,m",value<vector<string> >(&mult)->multitoken(),"mult test"); //多个参数

  variables_map vm;
  try
  {
    store(parse_command_line(argc,argv,opts),vm); // 分析参数
  }
  catch(boost::program_options::error_with_no_option_name &ex)
  {
    cout<<ex.what()<<endl;
  }

  notify(vm); // 将解析的结果存储到外部变量
  if (vm.count("help"))
  {
    cout<<opts<<endl;
    return -1;
  }
  if(vm.count("test1"))
  {
   cout<<vm["test1"].as<string>()<<endl;
  }
  
  cout<<one<<endl;
  cout<<mult.size()<<endl;
  
  getchar();

  return 0;
}

