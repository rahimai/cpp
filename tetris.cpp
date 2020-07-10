//tetris.cpp
#include <iostream> 

using namespace std;

string tetromino[7];
int i_FieldWidth = 12;
int i_FieldHeight = 18;
unsigned char* p_Field = nullptr;


//function for the rotation of the tetrominos 
int rotate(int px, int py, int r){

    switch(r % 4){

        case 0: return py*4+x; //0 degrees
        case 1: return 12 + py - (x*4); //90 degrees
        case 2: return 15 - (py*4) - px; //180 degrees
        case 3: return 3 - py + (px*4) //270 degrees
    }
    return 0;
}

bool DoesPieceFit(int nTetromino, int nRotation, int nPosX, int nPosY)
{
	// All Field cells >0 are occupied
	for (int px = 0; px < 4; px++)
		for (int py = 0; py < 4; py++)
		{
			// Get index into piece
			int pi = Rotate(px, py, nRotation);

			// Get index into field
			int fi = (nPosY + py) * nFieldWidth + (nPosX + px);

			// Check that test is in bounds. Note out of bounds does
			// not necessarily mean a fail, as the long vertical piece
			// can have cells that lie outside the boundary, so we'll
			// just ignore them
			if (nPosX + px >= 0 && nPosX + px < nFieldWidth)
			{
				if (nPosY + py >= 0 && nPosY + py < nFieldHeight)
				{
					// In Bounds so do collision check
					if (tetromino[nTetromino][pi] != L'.' && pField[fi] != 0)
						return false; // fail on first hit
				}
			}
		}

	return true;
}

int main(){

    //Create assetsk 
	tetromino[0].append("..X...X...X...X."); 
	tetromino[1].append("..X..XX...X.....");
	tetromino[2].append(".....XX..XX.....");
	tetromino[3].append("..X..XX..X......");
	tetromino[4].append(".X...XX...X.....");
	tetromino[5].append(".X...X...XX.....");
	tetromino[6].append("..X...X..XX.....");



}