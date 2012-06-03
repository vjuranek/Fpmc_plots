#ifndef PLOT_FROM_FILE_H
#define PLOT_FROM_FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include "TGraph.h"
#include "TAxis.h"

TGraph* getPlotFromFile(const int size, const char* file);
TGraph* getPlotFromFile(const int size, const char* file,const char* xAxisTitle, const char* yAxixTitle);

#endif  //PLOT_FROM_FILE_H
