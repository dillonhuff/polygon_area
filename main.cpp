#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct point {
  double x, y;

  point(const double p_x, const double p_y) :
    x(p_x), y(p_y) {}

};

double signed_area(const std::vector<point>& polygon) {
  double area = 0.0;

  unsigned j = 1;
  for (unsigned i = 0; i < polygon.size(); i++, j++) {
    j = j % polygon.size();

    area += (polygon[j].x - polygon[i].x)*(polygon[j].y + polygon[i].y);
  }

  return area / 2.0;
}

int main() {
  std::vector<point> square;
  square.push_back(point(0, 0));
  square.push_back(point(1, 0));
  square.push_back(point(1, 1));
  square.push_back(point(0, 1));

  double area = signed_area(square);
  cout << "Signed area = " << area << endl;

  std::reverse(begin(square), end(square));

  area = signed_area(square);
  cout << "Signed area after reversal = " << area << endl;
}
