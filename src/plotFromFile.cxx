#include "plotFromFile.h"

using namespace std;
TGraph* getPlotFromFile(const int size, const char* file){
  TGraph* graph = new TGraph(size);
  graph->SetLineWidth(2);
  graph->SetLineColor(kBlue);
  graph->SetTitle(false);
  ifstream dataStream;
  cout << "otviram soubor " << file << endl;
  dataStream.open(file,ios::in);
  float xVal,yVal;
  for(int i=0;i<size;i++){
    dataStream >> xVal >> yVal;
    cout << "hodnota " << i << " " << xVal << " " << yVal << endl;
    graph->SetPoint(i,xVal,yVal);
  }
  dataStream.close();
  return graph;
}

TGraph* getPlotFromFile(const int size,const char* file,const char* xAxisTitle, const char* yAxisTitle){
  TGraph* graph = getPlotFromFile(size,file);
  //To give the axis of a graph a title you need to draw the graph first, only then does it actually have an axis object.
  graph->Draw("AC");
  graph->GetXaxis()->SetTitle(xAxisTitle);
  graph->GetYaxis()->SetTitle(yAxisTitle);
  return graph;
}
