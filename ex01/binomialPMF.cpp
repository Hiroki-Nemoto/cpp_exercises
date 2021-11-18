#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double binomialPMF( int n, int k ){
    double v = 1.0;

    if ((1 <= k) && (k < n))
    for (double i = k; i > 0.99; i -= 1.0)
    v *= (n + 1.0 - i) / i;
    return v;

}

int main()
{
    double p;

    while(true){
        cout << endl << "p = ";
        cin >> p;
        if ((p > 0.0) && (p < 1.0)) 
        break;
    }

    int n;

    while(true){
        cout << "n = ";
        cin >> n;
         if(n > 0) 
         break;

    }

    cout << endl;
    cout << "p = " << p << "    n = " << n << endl;
    cout << setw(12) << "k" << "   P(k) =" << endl;

    double sum_p = 0.0;

    for (int k = 0; k <= n; k++){
        double v = binomialPMF(n, k) * pow(p, k) * pow(1.0 - p, n - k);
        sum_p += v;
        cout << setw(12) << k << ":  "
            << setprecision(12) << fixed << v << endl;
    }
    cout << endl << "Check_sum_p = " << sum_p << endl << endl;

    return 0;

}