#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

namespace PL4{
    template <class FwdIt>
    void sort(FwdIt begin, FwdIt end) {
        for(FwdIt i=begin; i!=end; ++i){
            for(FwdIt j=begin; j<i; ++j){
                if(*i < *j){
                    iter_swap(i, j);
                }
            }
        }
    }
}

int main(){
    vector<int> v{3, 7, 5, 1, 9};
    PL4::sort(v.begin(),v.end());
    for(int i=0; i<5; i++){
        cout << v[i] << endl;
    }
    return 0;
}
