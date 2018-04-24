// Perry Lee
// pxl172630@utdallas.edu
// CS3377.002

#include <iostream>
#include <fstream>
#include <sstream>
#include "cdk.h"

using namespace std;

// Matrix definitions
#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

const int maxRecordStringLength = 25;

// Setup binary classes
class BinaryFileHeader {
	public:
		uint32_t magicNumber;
		uint32_t versionNumber;
		uint64_t numRecords;
};
class BinaryFileRecord {
	public:
		uint8_t strLength;
		char stringBuffer[maxRecordStringLength];
};

int main(int argc, char* argv[]) {
	
	// Accept user input for binary file
	string binaryfile = "cs3377.bin";
	if(argc == 2)
		binaryfile = argv[1];

	WINDOW *window;
	CDKSCREEN *cdkscreen;
	CDKMATRIX *myMatrix;
	
	// Setup CDK matrix
	const char *rowTitles[] = {"0", "a", "b", "c", "d", "e"};
	const char *columnTitles[] = {"0", "a", "b", "c", "d", "e"};
	int boxWidths[] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
	int boxTypes[] = {vMIXED, vMIXED, vMIXED, vMIXED, vMIXED, vMIXED};

	window = initscr();
	cdkscreen = initCDKScreen(window);

	initCDKColor();

	myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths, boxTypes, 1, 1, ' ', ROW, true, true, false);

	if(myMatrix == NULL) {
		printf("Error reating Matrix\n");
		_exit(1);
	}
	
	// Draw matrix
	drawCDKMatrix(myMatrix, true);
	
	// Create binary file readers
	BinaryFileRecord *myRecord = new BinaryFileRecord();
	BinaryFileHeader *myHeader = new BinaryFileHeader();

	ifstream binInfile(binaryfile, ios::out | ios::binary);

	// Read in header
	binInfile.read((char *) myHeader, sizeof(BinaryFileHeader));
	
	stringstream feedhex;
	feedhex << hex << uppercase << myHeader->magicNumber;
	string feedmagic = "Magic: 0x" + feedhex.str();
	string version = "Version: " + to_string(myHeader->versionNumber);
	string records = "Records: " + to_string(myHeader->numRecords);

	// Write header information to matrix
	setCDKMatrixCell(myMatrix, 1, 1, feedmagic.c_str());
	setCDKMatrixCell(myMatrix, 1, 2, version.c_str());
	setCDKMatrixCell(myMatrix, 1, 3, records.c_str());

	// Loop through char array and display length and string
	for(int i = 0; i < (int64_t)myHeader->numRecords; i++) {
		binInfile.read((char *) myRecord, sizeof(BinaryFileRecord));
		string strlength = to_string(myRecord->strLength);
		string lengthdisplay = "strlen: " + strlength;
		string contents = string(myRecord->stringBuffer, stoi(strlength));
		setCDKMatrixCell(myMatrix, i+2, 1, lengthdisplay.c_str());
		setCDKMatrixCell(myMatrix, i+2, 2, contents.c_str()); 
	}
	binInfile.close();
	
	drawCDKMatrix(myMatrix, true);

	// Read input from user for program exit
	unsigned char x;
	cin >> x;

	endCDK();
}
