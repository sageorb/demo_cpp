#include <cstdlib>
#include <ctime>
#include <iostream>
#include <omp.h>
#include <vector>

int main() {
    // define array size && array
    const int ARRAY_SIZE = 1000 * 1000 *1000;
    std::vector<int> test_array(ARRAY_SIZE);

    // populate with test data
    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        test_array[i] = rand() % 10;
    }

    // to keep a running total 
    long long sum = 0;
    // to track runtime
    double start_time = omp_get_wtime();

    // 
    #pragma omp parallel for reduction(+:sum)
    for (int index = 0; index < ARRAY_SIZE; index++) {
        sum += test_array[index];
    }

    // to track runtime
    double end_time = omp_get_wtime();

    double runtime = end_time - start_time;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Runtime: " << runtime << " seconds" << std::endl;

    return 0;
}