#ifndef FPMCSTYLE__H
#define FPMCSTYLE__H

#include <TROOT.h>
#include <TStyle.h>
#include "TLatex.h"


////////////////////////////////////////////////////////////////////
// FPMC style
////////////////////////////////////////////////////////////////////
void SetFPMCStyle(TStyle* style) {
  style->Reset();
  style->SetCanvasColor(10);
  style->SetPadColor(10);
  style->SetHistLineWidth(1);
  style->SetCanvasBorderMode(0);
  style->SetFrameBorderMode(0);

  
  style->SetPadLeftMargin(0.13);
  style->SetPadRightMargin(0.07);
  style->SetPadTopMargin(0.07);
  style->SetPadBottomMargin(0.13);
  //style->SetTitleOffset(10.1, "X");
  //style->SetTitleOffset(10.3, "Y");
  style->SetTitleFont(42, "XYZ");
  style->SetTitleSize(0.048, "xyz");
  
  style->SetLabelFont(42, "X");
  style->SetLabelFont(42, "Y");
  style->SetLabelSize(0.045, "xyz");
  
  /* global text poperties */
  style->SetTextFont(42);

  //style->SetStatColor(10);
  //style->SetStatBorderSize(0);

  style->SetEndErrorSize(3);

  style->SetLineStyleString(2, "[24 24]");
  style->SetLineStyleString(3, "[6 18]");
  style->SetLineStyleString(4, "[24 24 6 24]");

  style->cd();
}

#endif  // FPMCSTYLE_H
