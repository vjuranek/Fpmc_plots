#include "mergeData.h"

using namespace std;
//TODO udelat pres std::vector<std::string>
void mergeData(const int nFiles,char** files, char* outFile, int size){
  ifstream dataStream;
  float xData[size], yData[size];
  for(int i=0;i<size;i++){
    xData[i] = 0;
    yData[i] = 0;
  }
  for(int j=0; j<nFiles;j++){
    cout << "otviram soubor " << files[j] << endl;
    dataStream.open(files[j],ios::in);
    float xVal,yVal;
    for(int i=0;i<size;i++){
      dataStream >> xVal >> yVal;
      cout << "hodnota " << i << " " << xVal << " " << yVal << endl;
      xData[i] = xVal;
      yData[i] = yData[i] + yVal;
    }
    dataStream.close();
  }
  ofstream outStream;
  outStream.open(outFile,ios::out);
  std::cout << "================ ZAPISUJI ============" << std::endl; 
  for(int i=0;i<size;i++){
    outStream << xData[i] << "\t" << yData[i] << std::endl;
    std::cout << xData[i] << "\t" << yData[i] << std::endl;
  }
  outStream.close();
}

int main(int argc, char **argv){
  int size = 15;
  int nFiles = 3;
  char** files = new char*[nFiles];
  files[0] = "../data/dijetUUCSFlux11.txt";
  files[1] = "../data/dijetDDCSFlux11.txt";
  files[2] = "../data/dijetSSCSFlux11.txt";
  char* outFile = "../data/dijetLightCSFlux11.txt";
  mergeData(nFiles,files,outFile,size);
  return 0;
}
