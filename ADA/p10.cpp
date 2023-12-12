#include <iostream>
#include <vector>

using namespace std;

int knapsackRecursive(vector<int> &values, vector<int> &weights, int capacity, int currentIndex)
{
    if (currentIndex < 0 || capacity <= 0)
    {
        return 0;
    }

    if (weights[currentIndex] > capacity)
    {
        return knapsackRecursive(values, weights, capacity, currentIndex - 1);
    }

    int includeCurrentItem = values[currentIndex] + knapsackRecursive(values, weights, capacity - weights[currentIndex], currentIndex - 1);
    int excludeCurrentItem = knapsackRecursive(values, weights, capacity, currentIndex - 1);

    return max(includeCurrentItem, excludeCurrentItem);
}

int knapsack(vector<int> &values, vector<int> &weights, int capacity)
{
    return knapsackRecursive(values, weights, capacity, values.size() - 1);
}

int main()
{
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    int maxValue = knapsack(values, weights, capacity);

    cout << "Knapsack Problem Solution:" << endl;
    cout << "Values: {60, 100, 120}" << endl;
    cout << "Weights: {10, 20, 30}" << endl;
    cout << "Knapsack Capacity: 50" << endl;
    cout << "Maximum Achievable Value: " << maxValue << endl;

    return 0;
}
