#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int countLines(fstream &);

int main() {
  int intArrayLength, intTotalDistance = 0;
  string strFilePath = "./lists.txt", strCurLine;
  fstream List(strFilePath);
  if (!List.is_open()) {
    cout << endl << "There was an error opening the file";
    return 0;
  }

  intArrayLength = countLines(List);
  cout << "ArrayLength = " << intArrayLength << endl;

  int arrListOne[intArrayLength];
  int arrListTwo[intArrayLength];

  for (int i = 0; i < intArrayLength; i++) {
    List >> arrListOne[i];
    List >> arrListTwo[i];
  }

  sort(arrListOne, arrListOne + intArrayLength);
  sort(arrListTwo, arrListTwo + intArrayLength);

  for (int i = 0; i < intArrayLength; i++) {
    cout << arrListOne[i] << "  " << arrListTwo[i] << endl;
    intTotalDistance += abs(arrListOne[i] - arrListTwo[i]);
  }
  cout << "Total Distance: " << intTotalDistance;

  return 0;
}

int countLines(fstream &File) {
  int intLines = 0;
  string strVoid;

  if (File.is_open()) {

    while (getline(File, strVoid)) {
      intLines++;
    };

    // Resets the File after counting it
    File.clear();
    File.seekg(0);
  } else {
    cout << "There was an error opening the file" << endl;
  }
  return intLines;
}
