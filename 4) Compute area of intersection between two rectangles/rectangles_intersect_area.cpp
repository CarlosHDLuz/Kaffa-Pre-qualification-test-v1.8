#include <bits/stdc++.h>

using namespace std;

/*

Considering two rectangles in a discrete grid (like pixels on a screen), each defined by two points, return
true if they cross, false otherwise
  |..........+­­­---+
  |..........|.C.|
  |..+­­­­­­­-------#---­­­+
10|..|.......|....
  |..|...A...|....
  |..|.......|....
  |..|...#####­-+..
  |..|...#####.|..
 5|..+­­­---#####.|..
  |......|..B..|..
  |......|.....|..
  |......+-----­­­­­+..
 1|...............
 0+­­­­----|----­­­­|­----­­­|
  0    5    10   15

If a rectangle A intersects a rectangle B, 
there is a rectangle C that is an intersection between A and B

This solution try to find this rectangle C

*/

class Rectangle {
	public:
		int edgeXmin;	// left edge
		int edgeXmax;	// right edge
		int edgeYmin;	// bottom edge
		int edgeYmax;	// top edge
		Rectangle(int x1, int y1, int x2, int y2) {
			if ( x1 <= x2 ) {
				edgeXmin = x1;
				edgeXmax = x2;
			} else {
				edgeXmin = x2;
				edgeXmax = x1;
			}
			if ( y1 <= y2 ) {
				edgeYmin = y1;
				edgeYmax = y2;
			} else {
				edgeYmin = y2;
				edgeYmax = y1;
			}
		}
};

int main() {

	char r1, r2;
	int inputX1, inputX2, inputY1, inputY2;

	// read 2 points for each rectangle

	fflush(stdin); // clean the stdin buffer

	scanf("%c=(%d,%d%*c%d,%d)", &r1, &inputX1, &inputY1, &inputX2, &inputY2);
	// rectangle A
	Rectangle A(inputX1, inputY1, inputX2, inputY2);

	fflush(stdin); // clean the stdin buffer, last scanf leave a '\n' char

	scanf("%c=(%d,%d%*c%d,%d)", &r2, &inputX1, &inputY1, &inputX2, &inputY2);
	// rectangle A
	Rectangle B(inputX1, inputY1, inputX2, inputY2);

	int minX, maxX, minY, maxY;
	
	// get the higher minX
	minX = A.edgeXmin;
	if (minX < B.edgeXmin )
		minX = B.edgeXmin;

	// get the lower maxX
	maxX = A.edgeXmax;
	if (maxX > B.edgeXmax)
		maxX = B.edgeXmax;
	
	// get the higher minY
	minY = A.edgeYmin;
	if (minY < B.edgeYmin)
		minY = B.edgeYmin;
	
	// get the lower maxX
	maxY = A.edgeYmax;
	if (maxY > B.edgeYmax)
		maxY = B.edgeYmax;

	int area = 0;
	cout << "intersects(" << r1 << ", " << r2;
	if (
		(maxX - minX >= 0) &&
		(maxY - minY >= 0)
		) {
		area = (maxX - minX +1) * (maxY - minY +1);
}
	cout << ") = " << area << '\n';
	return 1;
}