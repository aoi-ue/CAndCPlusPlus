#include <iostream>
#include "CSVParser.h"

using namespace std;

int main(){
    CSVParser testcsv; 
    string filePath = "MOCK_DATA.csv"; 
    
    testcsv.ReadFile(filePath) == 0 ? cout << "File Exists" << endl << testcsv.GetEntry(15,0) : cout << "Empty" << endl; 
    
    testcsv.ClearData(); 
}

