#include "matrix.h"
#include "unit_tests.h"
#include <iomanip>
#include <chrono>

using namespace std;

void Benchmark()
{
    cout << white << "Multiplication matrixes" << endl;
    cout << blue << setw(20) << "Number of elements" << yellow << setw(20) << "Simple algorithm" << green << setw(20) << "Parallel algorithm" << endl;
    for (int n = 10; n < 100; n *= 2)
    {
        cout << blue << setw(20) << n;
        Matrix A = AutoGenerateMatrix(n);
        Matrix B = AutoGenerateMatrix(n);
        time_t start = clock();
        Matrix Simple = A * B;
        time_t finish = clock();
        cout << yellow << setw(20) << finish - start;
        start = clock();
        Matrix Parallel = MultiplyParallel(A, B);
        finish = clock();
        cout << green << setw(20) << finish - start << endl;
    }
    for (int n = 100; n < 600; n += 100)
    {
        cout << blue << setw(20) << n;
        Matrix A = AutoGenerateMatrix(n);
        Matrix B = AutoGenerateMatrix(n);
        time_t start = clock();
        Matrix Simple = A * B;
        time_t finish = clock();
        cout << yellow << setw(20) << finish - start;
        start = clock();
        Matrix Parallel = MultiplyParallel(A, B);
        finish = clock();
        cout << green << setw(20) << finish - start << endl;
    }
}

int main()
{
    TestAll();
    srand(static_cast<int>(time(NULL)));
    Benchmark();
}
