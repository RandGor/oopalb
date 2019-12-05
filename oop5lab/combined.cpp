#include "combined.h"
#include "error.h"

void combined::Draw(HDC hdc) {
	ext.checkSizeT(hdc);
	checkSizeTC();

	ext.Draw(hdc);
	intern.Draw(hdc);
}

void combined::save(const char name1[], const char name2[]) {
	intern.brush::save(name1);
	intern.contour::save(name2);

}void combined::load(const char name1[], const char name2[]) {
	intern.brush::load(name1);
	intern.contour::load(name2);
}

void combined::addExt(painted Ext) {
	ext = Ext;
}

void combined::checkSizeTC() {
	POINT points[3], new_Cpoints[3];
	ext.getPoints(points);
	intern.getPoints(new_Cpoints);
	int a, b, c;
	for (int i = 0; i < 3; i++) {
		a = (points[0].x - new_Cpoints[i].x)*(points[1].y - points[0].y) - (points[1].x - points[0].x)*(points[0].y - new_Cpoints[i].y);
		b = (points[1].x - new_Cpoints[i].x)*(points[2].y - points[1].y) - (points[2].x - points[1].x)*(points[1].y - new_Cpoints[i].y);
		c = (points[2].x - new_Cpoints[i].x)*(points[0].y - points[2].y) - (points[0].x - points[2].x)*(points[2].y - new_Cpoints[i].y);
		if (!((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0)))
			throw ERR_WRONG_CUT_POINTS;
	}
}