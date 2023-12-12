#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};
bool comparator(Item a, Item b)
{
    double a1 = a.value / a.weight;
    double b1 = b.value / b.weight;

    return a1 > b1;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, comparator);

    int currWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight + currWeight <= W)
        {
            currWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = W - currWeight;
            finalValue += (arr[i].value / arr[i].weight) * remain;
        }
    }
    return finalValue;
}
int main()
{
    int n = 3, weight = 50;
    Item arr[n] = {{100, 20}, {60, 10}, {120, 30}};

    double ans = fractionalKnapsack(weight, arr, n);
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
    return 0;
}