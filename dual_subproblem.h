#ifndef DUALSUB_H_
#define DUALSUB_H_

//#include "Bigram.h"
#include "ForestLattice.h"
#include "EdgeCache.h"
#include "GraphDecompose.h"
#include "BigramRescore.h"
#include "NGramCache.h"
//#define NUMWORDS 300

#include<fstream>
#include<set>
using namespace std;
class SkipTrigram;

class Subproblem {
 public: 
  vector <vector<int> > cur_best_one;
  vector <vector<int> > cur_best_two;
  vector <float> cur_best_score;
  vector <int> cur_best_count;

  Subproblem(const ForestLattice *g, NgramCache * lm_in, const SkipTrigram & skip, const GraphDecompose * gd_in, const Cache<LatNode, int> & word_node_cache_in);
  void update_weights(vector <int> u_pos, vector <float> u_values, bool first);
  void solve();
  //void solve_bigram();
  vector <int> get_best_nodes_between(int w1, int w2, bool first);
  float get_best_bigram_weight(int w1, int w2 , bool first);
  float primal_score(int word[], int l);
  
  double word_prob(int, int, int );
  double word_backoff(int );
  double word_backoff_two(int i, int j);
  double word_prob_reverse(int, int, int);
  double word_prob_bigram_reverse(int i, int j);
  int word_bow_reverse(int i, int j, int k);
  int word_bow_bigram_reverse(int i, int j);
 private:
  
  bool first_time;
  
  // PROBLEMS
  
  // The lagragian score associated with a bigram 
  //vector<float> bigram_weights[NUMSTATES][NUMSTATES];

  // current best weight associated with a 
  //float bigram_weights[NUMSTATES][NUMSTATES];
  //vector <int> bigram_path[NUMSTATES][NUMSTATES];



  // BIG
  vector < vector<float > >  best_lm_score;
  // BIG
  vector < vector<float > >  bigram_score_cache;

  vector < vector<float > >  backoff_score_cache;
  
  vector < vector<float > >  bigram_weight_cache_one;
  vector < vector<float > >  bigram_weight_cache_two;

  vector < vector<bool > >   bigram_in_lm;
  // BIG
  vector <vector <vector <int> *> > forward_trigrams;
  //BIG
  vector < vector< vector <double> * > > forward_trigrams_score;
  //Bigram valid_bigrams[NUMSTATES*NUMSTATES];

  const SkipTrigram & skip_tri;
  
  const ForestLattice * graph;
  NgramCache * lm;
  
  const GraphDecompose * gd;
  const Cache<LatNode, int> _word_node_cache;

  BigramRescore * bi_rescore_first;
  BigramRescore * bi_rescore_two;
};

class SkipTrigram {
 public:
  void initialize(const char * filename, NgramCache & lm) {
    int max_size = lm.vocab.numWords();
    _skip_tri.resize(max_size);
    cout << "Start " << max_size << endl;
    
    cout << "Start" << endl;
    ifstream fin(filename ,ios::in);
    while (!fin.eof()) {
      string word1, word2;
      int w1, w2;
      fin >> word1 >> word2;
      if (fin.eof()) break;
      w1 = lm.vocab.getIndex(word1.c_str()); 
      w2 = lm.vocab.getIndex(word2.c_str());
      //cout << w1 << " " << w2 << endl;
      //cout << word1 << " " << word2 << endl;
      assert (w1 != -1 && w1 < max_size);
      assert (w2 != -1 && w2 < max_size);
      _skip_tri[w1][w2] = true; 
    }
    cout << "end" << endl;
    fin.close();
  }

  inline bool is_skip(int i, int j) const  {
    assert(i != -1 );
    assert(j != -1 );
    //return _skip_tri[i].find(j) != _skip_tri[i].end();
    return _skip_tri[i][j];
  }

 private:
  vector < bitset<100000> > _skip_tri;
};

//Subproblem * initialize_subproblem(const char* graph_file, const char* word_file, const char * lm_file );

#endif

