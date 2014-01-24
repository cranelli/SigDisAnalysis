///////////////////////////////////////////////
// Made this class to hold Plot Creator
// functions, and turn generic histograms
// in to well formatted, final version plots
///////////////////////////////////////////////



#ifndef Plot_Finisher_h
#define Plot_Finisher_h

#include <TROOT.h>
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>


class Plot_Finisher{
 public:
  void PlotCreator(TH1F * hist,const char * title, const char * xAxis, const char * yAxis,
			   double xMin, double xMax, int num_binmerge=1, bool isLogy=false);
  
  void PlotCreator2D(TH2F* hist, const char* title, const char* xAxis, const char* yAxis, 
			     double xMin, double xMax,double yMin, double yMax,
			     int num_xbinmerge=1, int num_ybinmerge=1, const char * type="box");

 private:
};
#endif
