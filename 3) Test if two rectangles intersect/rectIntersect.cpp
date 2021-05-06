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


It is possible to simplify the problem in two other simpler problems:

a rectangle B intersects a rectangle A if and only if:
I. at least one vertex of B is within A or a vertex of A is within B
OR
II. an edge of A crosses an edge of B

a point (or vertex) of B is inside A if at least one vertex of B has its coordinates between the edges of A
i.e.

an edge of A crosses an edge of B if a point inside an edge of A is inside an edge of B as well

*/

class Rectangle {
	public:
		int edgeXmin;	// bottom edge
		int edgeXmax;	// top edge
		int edgeYmin;	// left edge
		int edgeYmax;	// right edge
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

bool didFirstintersectsSecond(Rectangle First, Rectangle Second) {
	int x, y;
	/*
	First has 4 vertics:
	1st vertex: edgeXmin, edgeYmin
	2nd vertex: edgeXmin, edgeYmax
	3rd vertex: edgeXmax, edgeYmin
	4th vertex: edgeXmax, edgeYmax
	*/

	// is 1st vertex between rectangular Second
	x = First.edgeXmin;
	y = First.edgeYmin;

	if (
		(x >= Second.edgeXmin && x <= Second.edgeXmax) &&
		(y >= Second.edgeYmin && y <= Second.edgeYmax)
		)
		return true;

	// is 2nd vertex between rectangular Second
	y = First.edgeYmax;

	if (
		(x >= Second.edgeXmin && x <= Second.edgeXmax) &&
		(y >= Second.edgeYmin && y <= Second.edgeYmax)
		)
		return true;

	// is 3rd vertex between rectangular Second
	x = First.edgeXmax;
	y = First.edgeYmin;

	if (
		(x >= Second.edgeXmin && x <= Second.edgeXmax) &&
		(y >= Second.edgeYmin && y <= Second.edgeYmax)
		)
		return true;

	// is 4th vertex between rectangular Second
	y = First.edgeYmax;

	if (
		(x >= Second.edgeXmin && x <= Second.edgeXmax) &&
		(y >= Second.edgeYmin && y <= Second.edgeYmax)
		)
		return true;

	// if none of the above
	
	// 

	return false;
}

bool intersects(Rectangle A, Rectangle B) {
	if ( didFirstintersectsSecond(A, B) && didFirstintersectsSecond(B, A) )
		return true;
	return false;
}

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

	if (intersects(A, B)) {
		cout << "intersects(" << r1 << ", " << r2 <<')' << " => true\n";
		return true;
	}
	cout << "intersects(" << r1 << ", " << r2 <<')' << " => false\n";
	return false;
}