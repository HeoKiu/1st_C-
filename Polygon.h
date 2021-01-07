#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

double cross_product (double x1, double y1, double x2, double y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}


double count_area (const size_t n, const double * const x, const double * const y) {
       double area = 0.0;
       int j = n - 1;
       for ( size_t i = 0; i < n; i++){
           area +=  (*(x+j) + *(x+i) ) * ( *(y+j) - *(y+i) ) ;
           j = i;
       }
       return std :: abs(area/2);
}

double count_perimeter (const size_t n, const double * const x, const double * const y) {
    double perimeter = 0.0;
    for ( size_t i = 1; i < n; i++){
        perimeter += cross_product(*(x+i-1),*(y+i-1),*(x+i),*(y+i));
    }
    perimeter = perimeter + cross_product(*(x),*(y),*(x+n-1),*(y+n-1));
    return perimeter;

}


int main () {
    size_t n;
    cin >> n;

    double *x, *y;
    x = new double[n];
    y = new double[n];

    for (size_t i = 0; i < n; i ++)
        cin >> x[i] >> y[i];

    cout << "Area: " << count_area(n, x, y) << endl;
    cout << "Perimeter: " << count_perimeter(n, x, y) << endl;

    delete[] x;
    delete[] y;

    return 0;
}
