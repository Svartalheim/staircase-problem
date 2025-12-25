#include <iostream>
#include <fstream> 
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

unsigned long long countWaysIterative(int n) {
    if (n <= 1) return 1; 
    unsigned long long prev2 = 1;
    unsigned long long prev1 = 1;
    unsigned long long current = 0;

    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

unsigned long long countWaysRecursive(int n) {
    if (n <= 1) return 1;
    return countWaysRecursive(n - 1) + countWaysRecursive(n - 2);
}

int main() {
    ofstream myFile;
    myFile.open("results.csv");
    
    myFile << "InputSize,IterativeTime_us,RecursiveTime_us\n";
    
    vector<int> inputs = {5, 10, 15, 20, 25, 30, 35, 40, 42, 45}; 

    cout << "Benchmarking started... writing to results.csv" << endl;

    for (int n : inputs) {
        cout << "Running for N = " << n << "..." << endl;

        auto startIter = high_resolution_clock::now();
        countWaysIterative(n);
        auto stopIter = high_resolution_clock::now();
        auto durationIter = duration_cast<microseconds>(stopIter - startIter);

        auto startRec = high_resolution_clock::now();
        countWaysRecursive(n);
        auto stopRec = high_resolution_clock::now();
        auto durationRec = duration_cast<microseconds>(stopRec - startRec);

        myFile << n << "," << durationIter.count() << "," << durationRec.count() << "\n";
    }

    int hugeN = 1000000;
    auto startHuge = high_resolution_clock::now();
    countWaysIterative(hugeN);
    auto stopHuge = high_resolution_clock::now();
    auto timeHuge = duration_cast<microseconds>(stopHuge - startHuge);
    
    myFile << hugeN << "," << timeHuge.count() << ",0\n";

    myFile.close();
    cout << "Done! Open 'results.csv' in Excel to see the graph data." << endl;

    return 0;
}