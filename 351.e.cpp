#include <iostream>
#include <vector>
#include <algorithm>
 
#define ull unsigned long long
using namespace std;

struct Point {
    ull X;
    ull Y;
};

bool cmp(const Point& a, const Point& b) {
    return a.X < b.X || (a.X == b.X && a.Y < b.Y);
}

int main() {
    int n;
    cin >> n;
    vector<vector<Point>> points(4);
    for (int i = 0; i < n; ++i) {
        ull x, y;
        cin >> x >> y;
        points[0 + ((x + y) % 2)*2].push_back({x + y, x - y});
        points[1 + ((x + y) % 2)*2].push_back({x - y, x + y});
       
    }

    ull answer = 0;
    for (int i = 0; i < 4; ++i) {
        sort(points[i].begin(), points[i].end(), cmp);
        int len = points[i].size();
        for (int j = 0; j < len; ++j) {
            answer += points[i][j].X * (2 * j + 1 - len);
        }
    }

    cout << (answer / 2);
    return 0;
}