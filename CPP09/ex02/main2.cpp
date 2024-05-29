#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <fstream>

typedef std::pair<int, int> Pair;
static     std::ofstream mylogfile;

// Helper function to print the array
std::ostream &printArray(std::ostream &oss, const std::vector<int>& arr)
{
    // Imprime os números com bordas laterais
    oss << "+";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        oss << "----+";
    }
    oss << std::endl;

    // Imprime os números do array
    oss << "|";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        oss << std::setw(3) << arr[i] << " |";
    }
    oss << std::endl;

    // Imprime a linha inferior da tabela
    oss << "+";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        oss << "----+";
    }
    oss << std::endl;

    return oss;
}

// Função para imprimir as posições de left e right em uma tabela fixa
std::ostream &printBinary(std::ostream &oss, const std::vector<int>& arr, int left, int right)
{
    // Imprime os indicadores L e R com bordas laterais
    oss << "|";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (i == left && i == right)
        {
            oss << std::setw(3) << "LR" << " |";
        }
        else if (i == left)
        {
            oss << std::setw(3) << "L" << " |";
        }
        else if (i == right)
        {
            oss << std::setw(3) << "R" << " |";
        }
        else
        {
            oss << std::setw(3) << " " << " |";
        }
    }
    oss << std::endl;

    // Imprime a linha inferior da tabela
    oss << "+";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        oss << "----+";
    }
    oss << std::endl;

    return oss;
}

std::ostream &printPair(std::ostream &oss, const std::vector<Pair>& pair)
{
    for (size_t i = 0; i < pair.size(); ++i)
    {
        oss << "| " << pair[i].first << " " << pair[i].second << " |" << std::endl;
    }
    oss << std::endl;
    return oss;
}


// Function to perform binary search insertion
void binarySearchInsert(std::vector<int>& main_chain, int b)
{
    mylogfile << "---------BINARY INSERTION---------\n";
    mylogfile << "B: " << b << std::endl;
    int left = 0;
    int right = main_chain.size();
    printArray(mylogfile, main_chain);
    printBinary(mylogfile, main_chain, left, right);
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (main_chain[mid] < b)
        {
            left = mid + 1;
            printArray(mylogfile, main_chain);
            printBinary(mylogfile, main_chain, left, right);
        }
        else 
        {
            right = mid;
            printArray(mylogfile, main_chain);
            printBinary(mylogfile, main_chain, left, right);
            //mylogfile << "right size: " << right << std::endl;
        }
    }
    mylogfile << "PUSHING TO MAIN CHAIN [ " << left << " ] = " << b << std::endl;
    main_chain.insert(main_chain.begin() + left, b);
}



// Function to sort pairs and insert into main chain
void mergeInsertionSort(std::vector<int>& arr)
{
    // Step 1: Group into pairs and sort each pair
    std::vector<Pair> pairs;
    int n = arr.size();
    
    mylogfile << "QUANTIDADE DE ELEMENTOS NO VETOR: " << n << std::endl;
    mylogfile << "ORDENAR ATÉ INDEX N - 1: " << n - 1 << std::endl;
    

    for (int i = 0; i < n - 1; i += 2) {
        pairs.push_back(std::make_pair(std::min(arr[i], arr[i+1]), std::max(arr[i], arr[i+1])));
    }
    if (n % 2 != 0) {
        pairs.push_back(std::make_pair(arr[n-1], arr[n-1])); // Unpaired last element
    }

    mylogfile << "------PARES DESORDENADOS------\n";
    printPair(mylogfile, pairs);
    // Step 2: Sort pairs based on the first element of each pair
    std::sort(pairs.begin(), pairs.end());
    mylogfile << "---------PARES ORDENADOS---------\n";
    printPair(mylogfile, pairs);

    // Step 3: Create the main chain from the first elements of the pairs
    std::vector<int> main_chain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        main_chain.push_back(pairs[i].first);
    }
    mylogfile << "---------MAIN CHAIN---------\n";
    printArray(mylogfile, main_chain);

    mylogfile << "---------ESCOLHA DE NUMERO--------\n";
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        binarySearchInsert(main_chain, pairs[i].second);
        mylogfile << "---------MAIN CHAIN---------\n";
        printArray(mylogfile, main_chain);
    }

    // Copy the sorted elements back to the original array
    arr = main_chain;
}




int main()
{
    mylogfile.open("log.txt");

    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(6);
    arr.push_back(10);
    arr.push_back(9);
    arr.push_back(8);
    arr.push_back(13);
    arr.push_back(12);
    arr.push_back(11);


    std::cout << std::setw(20) << "Original array: \n";
    printArray(std::cout, arr);

    mergeInsertionSort(arr);

    std::cout  << std::setw(20) << "Sorted array: \n";
    printArray(std::cout, arr);

    mylogfile.close();
    return 0;
}




