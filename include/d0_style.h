#ifndef __D0_STYLE_H
#define __D0_STYLE_H

#include "TLatex.h"
#include "TStyle.h"

TLatex* d0_preliminary = new TLatex(0.17, 0.17, "D\351 Run II preliminary");

void SetD0Style(TStyle* style) {
  style->Reset();
  style->SetCanvasColor(10);
  style->SetPadColor(10);
  style->SetHistLineWidth(2);
  style->SetCanvasBorderMode(0);
  style->SetFrameBorderMode(0);

  style->SetPadLeftMargin(0.13);
  style->SetPadRightMargin(0.07);
  style->SetPadTopMargin(0.07);
  style->SetPadBottomMargin(0.13);
  style->SetTitleOffset(1.1, "X");
  style->SetTitleOffset(1.3, "Y");
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

void SetPhDStyle(TStyle* style) {
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
  style->SetTitleOffset(1.1, "X");
  style->SetTitleOffset(1.3, "Y");
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

#endif /*  __D0_STYLE_H */
