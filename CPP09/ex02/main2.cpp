#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Função para calcular a sequência de Jacobsthal
std::vector<int> jacobsthalSequence(int n)
{
    std::vector<int> jacobsthal(n);
    if (n > 0) jacobsthal[0] = 0;
    if (n > 1) jacobsthal[1] = 1;
    for (int i = 2; i < n; ++i) {
        jacobsthal[i] = jacobsthal[i-1] + 2 * jacobsthal[i-2];
    }
    return jacobsthal;
}

// Function to perform binary search insertion
void binarySearchInsert(std::vector<int>& main_chain, int b)
{
    int left = 0;
    int right = main_chain.size();
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (main_chain[mid] < b)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    main_chain.insert(main_chain.begin() + left, b);
}

// Function to sort pairs and insert into main chain
void mergeInsertionSort(std::vector<int>& arr)
{
    // Step 1: Group into pairs and sort each pair
    std::vector<std::pair<int, int>> pairs;
    int n = arr.size();
    for (int i = 0; i < n - 1; i += 2)
    {
        pairs.push_back(std::make_pair(std::min(arr[i], arr[i+1]), std::max(arr[i], arr[i+1])));
    }
    if (n % 2 != 0)
    {
        pairs.push_back(std::make_pair(arr[n-1], arr[n-1]));
    }

    // Step 2: Sort pairs based on the first element of each pair
    std::sort(pairs.begin(), pairs.end());

    // Step 3: Create the main chain from the first elements of the pairs
    std::vector<int> main_chain;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        main_chain.push_back(pairs[i].first);
    }

    // Step 4: Insert the second elements of the pairs into the main chain
    std::vector<int> insertion_order = {1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 21, 20, 19, 18}; // Partial Jacobsthal order
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (i < insertion_order.size() && insertion_order[i] - 1 < pairs.size())
        {
            binarySearchInsert(main_chain, pairs[insertion_order[i] - 1].second);
        }
        else
        {
            binarySearchInsert(main_chain, pairs[i].second);
        }
    }

    // Copy the sorted elements back to the original array
    arr = main_chain;
}

// Helper function to print the array
void printArray(const std::vector<int>& arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {1, 5, 3, 4, 2, 7, 6, 10, 9, 8};
    std::cout << "Original array: ";
    printArray(arr);

    mergeInsertionSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}




