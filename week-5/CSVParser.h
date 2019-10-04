/******************************************************************************
filename CSVParser.h
author Howard Sin
email howard.sin@digipen.edu
date created 22 May 2019
Brief Description: A header file containing CSV file parsing class
******************************************************************************/
#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <string>
#include <vector>

class CSVParser
{
	typedef std::vector<std::string> CSVRow;
	typedef std::vector<CSVRow> CSVData;
public:
	enum RESULT
	{
		OK,
		FAIL
	};
	
	/* Reads the CSV contents of a file, writes to result and return OK/FAIL */
	RESULT ReadFile(const std::string& filePath);
	
	/* Gets an entry in the CSV data given the row and column index */
	std::string GetEntry(int rowIndex, int colIndex);
	
	/* Removes all data stored */
	void ClearData(void);
	
private:
	CSVData mData; // The container for all the data
};

#endif /* CSVPARSER_H */
/*****************************************************************************/
