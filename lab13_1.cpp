#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[], int, double[]);

int main()
{
    double A[] = {1.2, 3.5, 6.9, 7.8, 12.5, 0.5};
    int N = sizeof(A) / sizeof(A[0]);
    double B[6];
    stat(A, N, B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}
void stat(const double value[], int N, double result[])
{
    // mean
    double sum = 0,Mean=0;
    for (int i = 0; i < N; i++)
    {
        sum += value[i];
        
    }
    Mean = sum / N;
    result[0] = Mean;

    // SD
    double SDs;
    for (int i = 0; i < N; i++)
    {
        SDs += (value[i]-Mean)*(value[i]-Mean);
    }
    result[1] = sqrt(SDs/N);
    

    // GM
    double CsX = value[0],GM;
    for (int i = 1; i < N ; i++)
    {   
        CsX = CsX * value[i];
    }
    GM = pow(CsX,(1.0/N));
    result[2] = GM;

    // HM
    double inX = 0;
    for (int i = 0; i < N; i++)
    {
        inX += (1 / value[i]);
    }
    result[3] = N/inX;

    // Max/Min
    double Max = value[0], Min = value[0];
    for (int i = 0; i < N; i++)
    {
        if (Max < value[i])
            Max = value[i];
        if (Min > value[i])
            Min = value[i];
    }
    result[4] = Max;
    result[5] = Min;
}
