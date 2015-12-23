#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3;
double error_threshold = 0.00001f;

void gaussSeidel(double A[N][N], double x[], const double b[], int N)
{

    bool solved = false;

    int n = 0;

    while(!solved)
    {
        std::vector<double> x_previous (&x[0], &x[N]);

        for(int i = 0; i < N; ++i)
        {
            //std::cout << n << "     in iteration: " << x[0] << " " << x[1] << " " << x[2] << std::endl;

            double sum = 0;
            for(int j=0; j < N; ++j)
            {
                if(j != i)
                {
                    sum += A[i][j] * x[j];
                }
            }


            x[i] = (b[i] - sum) / A[i][i];
        }

        double max_error = 0.0f;
        for(int i = 0; i < N; ++i)
        {
            if(((x[i] - x_previous[i]) / x[i]) > max_error) max_error = x[i];
        }

        solved = max_error <= error_threshold ? true : false;

        //std::cout << n << ". iteration: " << x[0] << " " << x[1] << " " << x[2] << " | Max error: " << max_error << std::endl;

        n = n + 1;
    }

    std::cout << "x: <" << x[0] << " " << x[1] << " " << x[2] << ">" << std::endl;


}


int main()
{
    double A[N][N] = {{4.0f, -1.0f, -1.0f},{-2.0f, 6.0f, 1.0f},{-1.0f, 1.0f, 7.0f}};
    const double b[N] = {3.0f, 9.0f, -6.0f};

    //init values for vector x
    double x[N] = {0.0f, 0.0f, 0.0f};

    for(int i=0; i<N; i++)
    {
        for(int j=0; j < N; j++)
        {
            std::cout << A[i][j] << " ";
        }

        std::cout << std::endl;
    }

    gaussSeidel(A, x, b, N);

    cout << "Hello world!" << endl;
    return 0;
}
