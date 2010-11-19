#include <cpptest.h>
#include <string>
#include <cpptest-suite.h>
#include "Forest.h"
#include "CubePruning.h"
#include "ForestAlgorithms.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <cy_svector.hpp>
#include <svector.hpp>
#include "hypergraph.pb.h"
#include "EdgeCache.h"
using namespace Test;
using namespace std;

class LocalTestSuite : public Test::Suite
{
public:
  
  LocalTestSuite() {
    TEST_ADD(LocalTestSuite::load_test);        
  }
  

  void load_test() {


    GOOGLE_PROTOBUF_VERIFY_VERSION;

    Hypergraph hgraph;
    string forest_file =  "test_data/t2s.forest";
    
    {
      // Read the existing address book.
      fstream input(forest_file.c_str(), ios::in | ios::binary);
      if (!hgraph.ParseFromIstream(&input)) {
        TEST_ASSERT_MSG(false, "Failed to parse");
      }

    }


    Forest f (hgraph);

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    svector<int, double> * weight;
    {
      fstream input("test_data/config.ini", ios::in );
      char buf[1000];
      input.getline(buf, 100000);
      string s (buf);
      weight = svector_from_str<int, double>(s);
    }
    Cache<ForestEdge, double> * w = cache_edge_weights(f, *weight);
    NodeBackCache bcache(f.num_nodes());
    NodeCache ncache(f.num_nodes());

    CubePruning p(f, *w, BlankNonLocal(), 100, 5);
    vector <Hyp> kbest;
    //p.run(f.root(), kbest);
    p.parse();
    double best = best_path(f, *w, ncache, bcache);
    cout << best << endl;
  }
    
};


int main(int argc, const char * argv[]) {
  //Test::TextOutput output(Test::TextOutput::Verbose);
  LocalTestSuite ets;
   ets.load_test();
   return 0;
}
