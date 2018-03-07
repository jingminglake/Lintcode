#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
 };

class Solution {
public:
    /*
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> points, Point origin, int k) {
        // write your code here
        vector<Point> res;
        if (points.size() == 0 || k <= 0)
            return res;
        originP = origin;
        auto compare = [&](const Point& p1, const Point& p2) {
            if (getDistance(p1) == getDistance(p2)) {
                if (p1.x == p2.x)
                    return p1.y < p2.y;
                else
                    return p1.x < p2.x;
            } else
                return getDistance(p1) < getDistance(p2);
        };
        typedef priority_queue<Point, vector<Point>, decltype(compare) > my_pq;
        my_pq pq(compare);
        for (Point& p : points) {
            if (pq.size() < k) {
                pq.push(p);
            } else if (getDistance(pq.top()) > getDistance(p)){
                pq.pop();
                pq.push(p);
            }
        }
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int getDistance(const Point& p) {
        return (p.x - originP.x) * (p.x - originP.x) + (p.y - originP.y) * (p.y - originP.y);
    }
    Point originP;
};

int main() {
  Solution s;
  vector<Point> points = {Point(-435,-347),Point(-435,-347),Point(609,613),Point(-348,-267),Point(-174,-107),Point(87,133),Point(-87,-27),Point(-609,-507),Point(435,453),Point(-870,-747),Point(-783,-667),Point(0,53),Point(-174,-107)};
			Point orgin(-11,199);
			for (Point& p : s.kClosest(points, orgin, 5)) {
			  cout << "(" << p.x << ", " << p.y << ") ";
			}
			cout << endl;
		 }
