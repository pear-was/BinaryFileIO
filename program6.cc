// Perry Lee
// pxl172630@utdallas.edu
// CS3377.002

#include <iostream>
#include "cdk.h"
#include <fstream>
#include <iomanip>
//#include "program6.h"

using namespace std;

#define MATRIX_WIDTH 4
#define MATRIX_HEIGHT 3
#define BOX_WIDTH 15
#define MATRIX_NAME_STRING "Test Matrix"

const int maxRecordStringLength = 25;

/*class BinaryFileRecord {
	public:
		double myVal;
		//uint8_t strLength;
		char stringBuffer[maxRecordStringLength];
};*/

int main() {
	/*BinaryFileRecord *myRecord = new BinaryFileRecord();
	myRecord->myVal = 123.4567;

	ofstream binOutfile("binaryfile.bin", ios::out | ios::binary);

	binOutfile.write((char *) myRecord, sizeOf(BinaryFileRecord));

	binOutfile.close();
	*/
	WINDOW *window;
	CDKSCREEN *cdkscreen;
	CDKMATRIX *myMatrix;

	const char *rowTitles[] = {"R0", "R1", "R2", "R3", "R4", "R5"};
	const char *columnTitles[] = {"C0", "C1", "C2", "C3", "C4", "C5"};
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

	drawCDKMatrix(myMatrix, true);

	setCDKMatrixCell(myMatrix, 2, 2, "Test Message");
	drawCDKMatrix(myMatrix, true);

	unsigned char x;
	cin >> x;

	endCDK();
}
