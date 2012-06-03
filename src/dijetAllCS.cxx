#include "TApplication.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TMultiGraph.h"
#include "TH2F.h"
#include "TLegend.h"
#include "TLegendEntry.h"

#include "plotFromFile.h"
#include "FpmcStyle.h"

int main(int argc, char **argv){
  TApplication theApp("App", &argc, argv);

  SetFPMCStyle(gStyle);
  gStyle->SetOptLogy();
  TCanvas* c1 = new TCanvas("c1");
  c1->cd();

  char* file = "../data/dijetCSFlux9.txt";
  char* xAxisTitle = "p_{T}^{min} [GeV]";
  char* yAxisTitle = "#sigma(p_{T}) [pb]";

  TGraph* grFlux9 = getPlotFromFile(25,"../data/dijetAllCSFlux9.txt");
  //TGraph* grFlux11 = getPlotFromFile(25,"../data/dijetCSFlux11.txt");
  TGraph* grLightFlux9 = getPlotFromFile(25,"../data/dijetLightCSFlux9.txt");
  //TGraph* grLightFlux11 = getPlotFromFile(25,"../data/dijetLightCSFlux11.txt");
  TGraph* grBBFlux9 = getPlotFromFile(25,"../data/dijetBBCSFlux9.txt");
  grLightFlux9->SetLineColor(kRed);
  grLightFlux9->SetLineStyle(2);
  grBBFlux9->SetLineColor(kBlack);
  grBBFlux9->SetLineStyle(6);
  /*
  grFlux11->SetLineColor(kRed);
  grFlux11->SetLineStyle(2);
  grLightFlux11->SetLineColor(kRed);
  grLightFlux11->SetLineStyle(2);
  */
  //graph->Draw("AC");

  TH2F* hhelp = new TH2F("hhelp","Hepl histo",10,10,400,10,1E-5,1E8);
  hhelp->SetTitle(false);
  hhelp->SetStats(kFALSE);
  hhelp->GetXaxis()->SetTitle(xAxisTitle);
  hhelp->GetYaxis()->SetTitle(yAxisTitle);
  hhelp->Draw();

  TMultiGraph *mg = new TMultiGraph();
  mg->Add(grFlux9);
  //mg->Add(grFlux11);
  mg->Add(grLightFlux9);
  //mg->Add(grLightFlux11);
  mg->Add(grBBFlux9);
  //mg->SetMinimum(0.004);
  //mg->SetMaximum(0.04);
  mg->SetTitle(false);
  mg->Draw("LP");
  
  TLegend *leg = new TLegend(0.33,0.76,0.91,0.88,NULL,"brNDC");
  leg->SetLineColor(0);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(0);
  leg->SetTextSize(0.046);
  TLegendEntry *entry=leg->AddEntry("grFlux9","dijets, factorized model","l"); 
  entry->SetLineStyle(1);
  entry->SetLineWidth(2);
  entry->SetLineColor(kBlue);
 
  entry=leg->AddEntry("grLightFlux9","light quark dijets, factorized model","l");
  entry->SetLineStyle(2);
  entry->SetLineWidth(2);
  entry->SetLineColor(kRed);
 
  entry=leg->AddEntry("grBBFlux9","b-dijets, factorized model","l");
  entry->SetLineStyle(4);
  entry->SetLineWidth(2);
  entry->SetLineColor(kBlack);

  leg->Draw();

  c1->Print("../eps/dijetAllCS.eps");
  

  theApp.Run();
  return 0;
}
