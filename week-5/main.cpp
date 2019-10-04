#include <iostream>
#include "CSVParser.h"

using namespace std;

int main(){
    CSVParser testcsv; 
    string filePath = "columns.csv"; 
    
    testcsv.ReadFile(filePath) == 0 ? cout << "File Exists" << endl : cout << "Empty" << endl; 
    
    cout << testcsv.GetEntry(15,0) << endl; 

    testcsv.ClearData(); 
}

