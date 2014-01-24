#include "TFile.h"
#include "iostream"
#include "Signal_TreeLoop_Plotter.h"

void SigDistPlotter(const char *file = "root://eoscms//eos/cms/store/group/phys_egamma/cmkuo/job_summer12_WAA_ISR.root"){

  TFile* inFile = TFile::Open(file);
  
  const char* tree_loc = "ggNtuplizer/EventTree";
  TTree* T = (TTree*)inFile->Get(tree_loc);
  cout << T << endl;
  T->Process("Signal_TreeLoop_Plotter.C+");
  cout << "working" << endl;
}
