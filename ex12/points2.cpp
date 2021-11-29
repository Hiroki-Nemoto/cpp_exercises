#include <queue>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    Point() : x(0.0), y(0.0), z(0.0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    double x, y, z;
};

vector<Point> find_k_closest2(int k, vector<Point> data)
{
    vector<Point> closest;
    vector<Point>::iterator v = closest.begin();

    auto compare =[](Point point1,Point point2){
        if((sqrt((point1.x * point1.x) + (point1.y * point1.y) + (point1.z * point1.z))) < (sqrt((point2.x * point2.x) + (point2.y * point2.y) + (point2.z * point2.z)))){
            return true;
        }
        else return false;
    };

    priority_queue<Point, vector<Point>, decltype (compare)> queue(compare);

    for(int i = 0; i < k; i++){
        queue.push(data[i]);
    }

    for(int i = k; i < data.size(); i++){
        if(compare(data[i],queue.top())){
        queue.pop();
        queue.push(data[i]);
        }
    }

    for(int i = 0; i < k; i++){
        closest.insert(v,queue.top());
        v = closest.begin();
        queue.pop();
    }

    return closest;
}

int main(void) {
    vector<Point> points;
    points.push_back(Point(0.0,1.0,2.0));
    points.push_back(Point(1.0,2.0,3.0));
    points.push_back(Point(2.0,3.0,4.0));
    points.push_back(Point(3.0,3.0,3.0));
    points.push_back(Point(4.0,3.0,2.0));
    points.push_back(Point(2.0,2.0,2.0));

    vector<Point> closest = find_k_closest2(3, points);
    for (size_t i = 0; i < 3; ++i) {
        cout << closest[i].x << "," << closest[i].y << "," << closest[i].z << endl;
    }

}