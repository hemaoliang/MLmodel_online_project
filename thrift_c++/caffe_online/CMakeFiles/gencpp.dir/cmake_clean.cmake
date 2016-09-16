FILE(REMOVE_RECURSE
  "gen-cpp/caffe_server_constants.cpp"
  "gen-cpp/caffe_server_types.cpp"
  "gen-cpp/CaffeService.cpp"
  "gen-cpp/CaffeService_server.skeleton.cpp"
  "CMakeFiles/gencpp.dir/gen-cpp/caffe_server_constants.o"
  "CMakeFiles/gencpp.dir/gen-cpp/caffe_server_types.o"
  "CMakeFiles/gencpp.dir/gen-cpp/CaffeService.o"
  "lib/libgencpp.pdb"
  "lib/libgencpp.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/gencpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
