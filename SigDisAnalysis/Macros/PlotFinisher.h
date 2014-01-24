/*
 * Plot_Finisher.h
 * Created by Christopher Anelli 1/24/2014
 *To create well formated, final versions of plots.
 *
 */

#include <TH1F.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <TStyle.h>

/*                                                                                                                                                                 
 * Functions to facilitate the creation of historgrams, "make pretty like".                                                                                        
 */

void PlotCreator(TH1F * hist, const char * title, const char * xAxis,const char * yAxis,double xMin, double xMax, int num_binmerge, bool isLogy){

  hist->Sumw2(); // make sure errors are correct before rebinning                                                                                                  
  hist->SetTitle(""); // empty the title                                                                                                                           
  hist->Rebin(num_binmerge);
  hist->GetXaxis()->SetRangeUser(xMin,xMax);

  hist->GetXaxis()->SetTitle(xAxis);
  hist->GetXaxis()->SetTitleFont(42);
  hist->GetXaxis()->SetTitleSize(0.05);
  hist->GetXaxis()->SetTitleOffset(0.9);

  hist->GetYaxis()->SetTitle(yAxis);
  hist->GetYaxis()->SetTitleFont(42);
  hist->GetYaxis()->SetTitleSize(0.05);
  hist->GetYaxis()->SetTitleOffset(1.0);

  hist->SetLineWidth(2);
  hist->SetLineColor(kBlue);

  //TCanvas *c = new TCanvas(Form("c_%s",title),Form("c_%s",title),600,500);                                                                                       
  std::stringstream canvas_name;
  canvas_name <<"c_" << title;
  TCanvas *c = new TCanvas(canvas_name.str().c_str(),canvas_name.str().c_str(),600,500);

  c->SetFillColor(0);
  c->SetBorderSize(0);
  c->cd();
  c->SetLogy(isLogy);
  hist->Draw("e0,hist");
  //hist->Draw("e0,hist");                                                                                                                                         

  // std::cout << Form("../Plots/SwitchtoTree_Plots/%s.png",out_name) << std::endl;                                                                                
  c->SaveAs(Form("../Plots/SwitchtoTree_Plots/%s.png",title));
}

void PlotCreator2D(TH2F* hist, const char* title, const char* xAxis, const char* yAxis, double xMin, double xMax,double yMin, double yMax,int num_xbinmerge, int num_ybinmerge, const char * type){

  //gr = new TGraph();                                                                                                                                             
  hist->RebinX(num_xbinmerge);
  hist->RebinY(num_ybinmerge);

  //std::cout << hist << std::endl;                                                                                                                                

  hist->Sumw2(); // make sure errors are correct before rebinning                                                                                                  
  hist->SetTitle(""); // empty the title                                                                                                                           

  hist->GetXaxis()->SetRangeUser(xMin,xMax);
  hist->GetYaxis()->SetRangeUser(yMin,yMax);

  hist->GetXaxis()->SetTitle(xAxis);
  hist->GetXaxis()->SetTitleFont(42);
  hist->GetXaxis()->SetTitleSize(0.05);
  hist->GetXaxis()->SetTitleOffset(0.9);

  hist->GetYaxis()->SetTitle(yAxis);
  hist->GetYaxis()->SetTitleFont(42);
  hist->GetYaxis()->SetTitleSize(0.05);
  hist->GetYaxis()->SetTitleOffset(1.0);

  //hist->SetLineWidth(2);                                                                                                                                         
  hist->SetMarkerColor(kRed);
  hist->SetMarkerSize(4);
  //hist->SetMarkerStyle(21);                                                                                                                                      

  //Remove Stat Box                                                                                                                                                
  //gStyle->SetOptStat(0);                                                                                                                                         

  TCanvas *c = new TCanvas(Form("c_%s",title),Form("c_%s",title),600,500);
  c->SetFillColor(0);
  c->SetBorderSize(0);
  hist->Draw(type);
  c->SaveAs(Form("../Plots/SwitchtoTree_Plots/%s.png",title));
  //c->Print(Form("p_%s.png",name));                                                                                                                               
  //c->Print(Form("p_%s.eps",name));                                                                                                                               
  //c->Print(Form("p_%s.pdf",name));                                                                                                                               
  return;
}

