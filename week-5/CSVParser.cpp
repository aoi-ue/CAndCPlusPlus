/******************************************************************************
filename CSVParser.h
author Lian Yuhan
email yuhan.lian@digipen.edu
date created 03 Oct 2019
Brief Description: A header file containing CSV file parsing class
******************************************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include "CSVParser.h"

using namespace std; 

CSVParser::RESULT CSVParser::ReadFile(const std::string& filePath) 
{
    fstream newfile;
    // open a file to perform read operation using file object
    newfile.open(filePath,ios::in); 
    if (newfile.is_open())
    {   
        string tp; 
        // read a line from file stream and put it into string.
        while(getline(newfile, tp))
        {  
            CSVParser::CSVRow row;
            stringstream tps; 
            string column; 
            tps.str(tp);  
            while(getline(tps, column, ',')) 
            {
                row.push_back(column);  
            }
            mData.push_back(row); 
        }
        // to print all the content 
        // for (unsigned int i = 0; i < mData.size(); ++i ) {
        //      for(unsigned int j = 0; j < mData.at(i).size(); ++j) {
        //          cout << i << " "<< j << " "<< mData.at(i).at(j) << endl; 
        //      }
        // }
        newfile.close(); 
    } 
    else 
    {
        return FAIL; 
    }
    return OK; 
}
    
string CSVParser::GetEntry(int rowIndex, int colIndex) 
{
    return mData.at(rowIndex).at(colIndex); 
}

void CSVParser::ClearData() 
{
    mData.clear(); 
}
