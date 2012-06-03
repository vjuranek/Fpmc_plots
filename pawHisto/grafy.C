#include "../include/FpmcStyle.h"
#include "TH1F.h"

void grafy(){
  float sigma = 8.4172E+05; //PROCESS CODE IPROC , 11500, PTMIN = 10,  
  //FLUX 9 ... CROSS SECTION (PB) =  8.4172E+05
  //FLUX 11 ...  CROSS SECTION (PB) =  6.3735E+05
  
  //FLUC|X 9
  int NPt = 126076;
  int NMjj = 40925;

  //FLUX 11
  //int NPt = 125466;
  //int NMjj = 41253;

  float binSizePt = 1.;
  float binSizeMjj = 1.;
  float factPt = sigma/(NPt*binSizePt);
  float factMjj = sigma/(NMjj*binSizeMjj); 
  cout << "factPt = " << factPt << endl;
  cout << "factMjj = " << factMjj << endl;

  TFile *f1 = new TFile("./jetyFlux9.root");
  TH1F *hPtJet = (TH1F*)f1->Get("h104");
  TH1F *hDijetMass = (TH1F*)f1->Get("h105");
  
  SetFPMCStyle(gStyle);
  gStyle->SetOptLogy();
  
  hPtJet->Scale(factPt);
  hDijetMass->Scale(factMjj);

  //hPtJet->Fit("pol6","M","E4",10,50);
  //hDijetMass->Fit("pol9","M","E4",20,120);

  TF1 *PtFit = new TF1("PtFit","pol6",20,120);
  PtFit->SetLineColor(2);
  hPtJet->Fit(PtFit,"M","E4",10,50);

  TF1 *MjjFit = new TF1("MjjFit","pol9",20,120);
  MjjFit->SetLineColor(2);
  hDijetMass->Fit(MjjFit,"M","E4",20,120);

  TCanvas* c1 = new TCanvas("c1");
  c1->cd();

  char* xAxisTitle = "p_{T}^{jet} [GeV]";
  char* yAxisTitle = "#frac{d#sigma}{dp_{T}} [pb]";

  hPtJet->SetLineWidth(2);
  hPtJet->SetTitle("");
  hPtJet->SetStats(kFALSE);
  hPtJet->GetXaxis()->SetTitle(xAxisTitle);
  hPtJet->GetYaxis()->SetTitle(yAxisTitle);
  //hPtJet->Draw("C");
  hPtJet->Draw();

  c1->Print("../eps/dsigmaPt.eps");
  
  gStyle->SetOptLogy(0);

  TCanvas* c2 = new TCanvas("c2");
  c2->cd();
  
  char* xAxisTitle = "M_{jj} [GeV]";
  char* yAxisTitle = "#frac{d#sigma}{dM_{jj}} [pb]";

  hDijetMass->SetLineWidth(2);
  hDijetMass->SetTitle("");
  hDijetMass->SetStats(kFALSE);
  hDijetMass->GetXaxis()->SetTitle(xAxisTitle);
  hDijetMass->GetYaxis()->SetTitle(yAxisTitle);
  //hDijetMass->Draw("C");
  hDijetMass->Draw();
  
  c2->Print("../eps/dsigmaMjj.eps");
  

}
