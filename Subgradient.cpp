#include "Subgradient.h"
#include "math.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include "util.h"
using namespace std;
void Subgradient::solve() {
  clock_t start=clock();
  clock_t s=clock();
  while(run_one_round() && _round <1000) {
    _round++;
    cout << "ITER TIME "<< double(diffclock(clock(),s)) << endl;
    s=clock();
 }
  clock_t end=clock();
  cout << "FULL TIME "<< double(diffclock(end,start)) << endl;
  if (_round < 1000) {
    //assert (_best_primal == _best_dual);
    cout << "CONVERGED" << endl;
  }
}


bool Subgradient::run_one_round() {
  double primal, dual; 
  wvector subgrad;
  //cout << endl;
  _s->solve(primal, dual, subgrad);
  
  if (primal < _best_primal) {
    _best_primal = primal;
  }

  if (dual > _best_dual) {
    _best_dual = dual;
  } 

  _duals.push_back(dual);
  _primals.push_back(primal);
  
  cout << "BEST PRIMAL" << _best_primal << endl;
  cout << "BEST DUAL" << _best_dual << endl;
  cout << "Round " << _round << endl; 
  assert (_best_primal > _best_dual);

  if (subgrad.normsquared() > 0.0) {
    update_weights(subgrad);
    //cout << endl;
    return true;
  } else {
    return false;
  }

  
}

void print_vec(const wvector & subgrad) {
  for (wvector::const_iterator it = subgrad.begin(); it != subgrad.end(); it++) {
    if (it->second != 0.0) {
      cout << it->first << " " << it->second << endl;
    }
  }
  cout << endl << endl;
}


void Subgradient::update_weights(wvector & subgrad) {
  int dualsize = _duals.size();
  int size = 0;
  for (wvector::const_iterator it = subgrad.begin(); it != subgrad.end(); it++) {
    if (it->second != 0.0) {
      size++;
      //cout << it->first << " " << it->second << endl;
    }
  }

  if  (dualsize > 2 && _duals[dualsize -1] < _duals[dualsize -2]) { 
    _nround += 1;
 } else if ( dualsize == 1) {
    _base_weight = (_primals[_primals.size()-1] - _duals[_duals.size()-1]) / max((double)size,1.0);  
  }

  //double alpha = _base_weight * pow(0.99, 2*(float)_nround);
  if (_nround == 10) {
    _base_weight *= 0.7;
    _nround =0;
  } 
  double alpha = _base_weight;
  //double alpha = _base_weight / ((float)_nround / 10.0);
  svector<int, double> updates = alpha * subgrad;
  
  cout << "DUAL " << _duals[dualsize -1]<<" " << _duals[dualsize -2] <<  endl;

  _weights += updates;
  cout << "CHANGED " << size << endl ;
  cout << "UPDATES" << " " << "Alpha " <<alpha << endl ;
  cout << endl;
  //print_vec(updates) ;
  
  _s->update_weights(updates, &_weights);
}
