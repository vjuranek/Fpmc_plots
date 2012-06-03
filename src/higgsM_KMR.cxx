#include "TApplication.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TMultiGraph.h"
#include "TH2F.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TF1.h"

#include "plotFromFile.h"
#include "FpmcStyle.h"

int main(int argc, char **argv){
  TApplication theApp("App", &argc, argv);


  TFile* pt25 = new TFile("../root/ntuple_pt25N1M.root");
  TH1F* hPt25 = (TH1F*)pt25->Get("h107");
  hPt25->SetLineColor(kRed);

  TFile* pt40 = new TFile("../root/ntuple_pt40N1M.root");
  TH1F* hPt40 = (TH1F*)pt40->Get("h107");
  hPt40->SetLineColor(kBlue);

  TFile* pt70 = new TFile("../root/ntuple_pt70N1M.root");
  TH1F* hPt70 = (TH1F*)pt70->Get("h107");
  hPt70->SetLineColor(kGreen);

  hPt25->Scale(1.67/983153);
  hPt40->Scale(7.095E-2/983214);
  hPt70->Scale(1.2573E-3/982959);
  
  TH1F* a = (TH1F*)hPt25->Clone();
  a->SetLineColor(kBlack);

  a->Add(hPt40);
  a->Add(hPt70);

  TF1* fc = new TF1("fc","[0]+[1]*x+[2]*x**2+[3]*x**3+[4]*x**4+[5]*x**5",115,200);

  a->Fit("fc");

  fc->SetLineColor(kRed);
  fc->SetLineStyle(2);
  fc->SetLineWidth(2);
  //fc->Draw();


  SetFPMCStyle(gStyle);
  gStyle->SetOptLogy();
  TCanvas* c1 = new TCanvas("c1");
  c1->cd();

  char* file = "../data/higgsM_KMR_crossSection.txt";
  char* xAxisTitle = "m_{X} [GeV]";
  char* yAxisTitle = "#sigma(m_{X}) [pb]";

  TGraph* grMKMR = getPlotFromFile(10,file);
 
  grMKMR->SetLineColor(kBlue);
  grMKMR->SetLineStyle(1);
  grMKMR->SetLineWidth(2);

  TH2F* hhelp = new TH2F("hhelp","Hepl histo",10,115,200,10,1E-5,1E-2);
  hhelp->SetTitle(false);
  hhelp->SetStats(kFALSE);
  hhelp->GetXaxis()->SetTitle(xAxisTitle);
  hhelp->GetYaxis()->SetTitle(yAxisTitle);
  hhelp->Draw();

  TMultiGraph *mg = new TMultiGraph();
  mg->Add(grMKMR);
  
  //mg->SetMinimum(0.004);
  //mg->SetMaximum(0.04);
  mg->SetTitle(false);
  mg->Draw("LP");

  fc->Draw("SAME");

  TLegend *leg = new TLegend(0.43,0.76,0.91,0.88,NULL,"brNDC");
  leg->SetLineColor(0);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.046);
  TLegendEntry *entry=leg->AddEntry("grMKMR","CEP Higgs, KMR model","l"); 
  entry->SetLineStyle(1);
  entry->SetLineWidth(2);
  entry->SetLineColor(kBlue);
  
  entry=leg->AddEntry("fc","CEP b-dijets, KMR model","l"); 
  entry->SetLineStyle(2);
  entry->SetLineWidth(2);
  entry->SetLineColor(kRed);
  
 

  leg->Draw();

  c1->Print("../eps/higgsM_KMR.eps");

  theApp.Run();
  return 0;
}
