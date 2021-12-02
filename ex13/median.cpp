#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

double compute_median(vector<double> data) {
    size_t k;

    if (data.size() % 2 == 1) {
        k = data.size() / 2;
        nth_element(data.begin(), data.begin() + k, data.end());
        return data[k];

    }
    if (data.size() % 2 == 0) {
        k = data.size() / 2-1;

        nth_element(data.begin(), data.begin() + k, data.end());
        size_t m =k+1;

        return (data[k]+data[m])/2;

    }

    nth_element(data.begin(), data.begin() + k, data.end());
    return data[k];

}


vector<double> compute_k_closest(int k, const vector<double> &data) {
    auto med = compute_median(data);
    auto temp = data;
    double result;
    auto compare = [med](int lhs, int rhs) {
        auto l = abs(lhs - med);
        auto r = abs(rhs - med);
        return l < r;
    };
    nth_element(temp.begin(), temp.begin() + data.size() / 2, temp.end(), compare);
        return temp;
}

int main() {
    vector<double> num;
    num.push_back(7.0);
    num.push_back(14.0);
    num.push_back(10.0);
    num.push_back(12.0);
    num.push_back(2.0);
    num.push_back(11.0);
    num.push_back(29.0);
    num.push_back(3.0);
    num.push_back(4.0);
    num.push_back(5.0);

    double median = compute_median(num);
    cout << "Median: " << median << endl;

    vector<double> closest = compute_k_closest(3, num);
    cout << "The three numbers closest to the median are: " << endl;
    for (size_t i = 0; i < 3; ++i) {
        cout << closest[i] << endl;
    }
    return 0;
}