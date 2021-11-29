#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double compute_median(vector<double> &data) {
    size_t k = data.size() / 2;
    nth_element(data.begin(), data.begin() + k, data.end());
    return data[k];
}

double compute_k_closest(vector<double> &data, int k) {
    compute_median(data);
}

int main() {
    vector<double> data = {7.0,14.0,10.0,12.0,2.0,11.0,29.0,3.0,4.0};
    int k = 3;
    cout << compute_k_closest(data,k) << endl;
}