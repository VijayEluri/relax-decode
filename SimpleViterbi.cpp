#include "Weights.h"
#include "Forest.h"

#include <iostream>
#include <iomanip>
#include "CommandLine.h"
#include "HypergraphAlgorithms.h"
using namespace std;

using namespace Scarab::HG;

DEFINE_string(forest_prefix, "", "prefix of the forest files"); // was 1
DEFINE_string(forest_range, "", "range of forests to use (i.e. '0 10')"); // was 5 6

static const bool forest_dummy = RegisterFlagValidator(&FLAGS_forest_prefix, &ValidateReq);
static const bool range_dummy = RegisterFlagValidator(&FLAGS_forest_range, &ValidateRange);

int main(int argc, char ** argv) {
  srand(0);
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  google::ParseCommandLineFlags(&argc, &argv, true);

  // weights
  wvector * weight = cmd_weights();

  istringstream range(FLAGS_forest_range);
  int start_range, end_range;
  range >> start_range >> end_range;
  for (int i = start_range; i <= end_range; i++) { 

    // Load forest
    stringstream fname;
    fname << FLAGS_forest_prefix << i;
    cout << fname.str();
    Forest f = Forest::from_file(fname.str().c_str());

    HypergraphAlgorithms alg(f);
    EdgeCache * edge_weights = alg.cache_edge_weights(*weight);
    NodeCache score_memo_table(f.num_nodes());
    NodeBackCache back_memo_table(f.num_nodes());
    double score =  alg.best_path(*edge_weights, 
                                  score_memo_table,
                                  back_memo_table);
    cout << " " << i << " " << score << endl; 

    HNodes nodes = alg.construct_best_fringe(back_memo_table);
    HEdges edges = alg.construct_best_edges(back_memo_table);

    foreach (HNode node, f.nodes()) {
      if (!node->is_terminal()) {
        cout << node->id() << " " << " " <<score_memo_table.get_value(*node) << endl;
      }
    }


    foreach (HNode node, nodes) {
      cout << node->label() << endl;
    }

    double total = 0.0;
    foreach (HEdge edge, edges) {
      total += edge_weights->get_value(*edge);
      cout << edge->id() << " " << edge->head_node().label() <<  " " << edge->label() << " " << edge_weights->get_value(*edge) << endl;
    }
    cout << "Total is: " << total << endl; 
    cout << "Score is: " << score << endl; 

    double other_total = 0.0;
    int nums[] = {0, 74, 114823, 88158, 50680, 24783, 2796, 1, 1475, 17457, 422};
    for (int i = 0; i < 11; ++i) {
      const Hyperedge &edge = f.get_edge(nums[i]);
      other_total += edge_weights->get_value(edge);
      cout << nums[i] << " " << edge_weights->get_value(edge)<< " " << ((HyperedgeImpl *)&edge)->feature_string() << endl;
    }    
    cout << "Other is: " << other_total << endl; 
  }


  google::protobuf::ShutdownProtobufLibrary();
  return 0;
}

