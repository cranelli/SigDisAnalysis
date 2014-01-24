/*
 *Test File to Check whether Plot_Finisher.h works.
 */

//#include <Plot_Finisher.h>
#include <PlotFinisher.h>
#include <TCanvas.h>
#include <TTree.h>
#include <TFile.h>
#include "iostream"
#include <TH1F.h>

void test(const char *file = "root://eoscms//eos/cms/store/group/phys_egamma/cmkuo/job_summer12_WAA_ISR.root"){

  TFile* inFile = TFile::Open(file);
  
  const char* tree_loc = "ggNtuplizer/EventTree";
  TTree* T = (TTree*)inFile->Get(tree_loc);
  cout << T << endl;
  T->Draw("elePt>>htemp()","","hist goff");
  TH1F* h_elePt;
  h_elePt = htemp;
  //Plot_Finisher F;
  //F.
  PlotCreator(h_elePt, "Electron Pt", "Pt", "Counts", -10.0, 400.0, 1, true);
//h_elePt->Draw();
  
  cout << "working" << endl;
}
