#include <iostream>
#include <vector>

using namespace std;

bool isAllocationPossible(const vector<int> &books, int k, int max_books)
{
    int volunteers = 1;
    int current_books = 0;
    for (int i = 0; i < books.size(); ++i)
    {
        if (current_books + books[i] <= max_books)
        {
            current_books += books[i];
        }
        else
        {
            volunteers++;
            current_books = books[i];
        }
    }
    return volunteers <= k;
}

string allocateCartons(const vector<int> &books, int k)
{
    int left = 0, right = 0;
    for (int i = 0; i < books.size(); ++i)
    {
        right += books[i];
    }

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (isAllocationPossible(books, k, mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    // Allocate cartons to volunteers
    int current_books = 0;
    string result;
    int volunteers = 0;
    for (int i = 0; i < books.size(); ++i)
    {
        if (current_books + books[i] <= left && k - volunteers <= books.size() - i)
        {
            current_books += books[i];
            result += to_string(books[i]) + " ";
        }
        else
        {
            result += "/ ";
            volunteers++;
            current_books = books[i];
            result += to_string(books[i]) + " ";
        }
    }

    // Remove trailing space and slash
    result.pop_back();
    if (result.back() == '/')
    {
        result.pop_back();
    }

    return result;
}

int main()
{
    int m, k;
    cout << "Enter the Number of cartons: ";
    cin >> m;
    cout << "\nEnter number of student volunteers: ";
    cin >> k;
    vector<int> books(m);
    cout << "\nEnter number of books in each carton: ";
    for (int i = 0; i < m; ++i)
    {
        cin >> books[i];
    }

    string allocation = allocateCartons(books, k);
    cout << "\n\nAllocated Cartons for Volunteers:\n";
    cout << allocation << endl;

    return 0;
}
