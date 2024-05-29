#include <iostream>
#include <vector>


/* 
void	mergeVec(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vector)
{
	size_t l = 0, r = 0, v = 0;
	while(l < left.size() && r < right.size())
	{
		if(left[l] < right[r])
		{
			vector[v] = left[l];
			v++;
			l++;
		}
		else
		{
			vector[v] = right[r];
			v++;
			r++;
		}
	}
	while(l < left.size())
	{
		vector[v] = left[l];
		v++;
		l++;
	}
	while(r < right.size())
	{
		vector[v] = right[r];
		v++;
		r++;
	}
}


void	mergeInsertVector(std::vector<int> &vector)
{
	if(vector.size() == 1)
		return;

	int	mid = vector.size() / 2;

	std::vector<int> left = std::vector<int>(vector.begin(), vector.begin() + mid);
	std::vector<int> right = std::vector<int>(vector.begin() + mid, vector.end());

	mergeInsertVector(left);
	mergeInsertVector(right);
	mergeVec(left, right, vector);
}



int main()
{
    // Vetor de entrada
    std::vector<int> vec;
    vec.push_back(12);
    vec.push_back(11);
    vec.push_back(13);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    // Tamanho do vetor
    int vec_size = vec.size();

    std::cout << "Vetor original: ";
    for (int i = 0; i < vec_size; i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    // Chama a função de ordenação Merge Sort
    mergeInsertVector(vec);

    std::cout << "Vetor ordenado: ";
    for (int i = 0; i < vec_size; i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    return 0;
} */
#include <iostream>
#include <vector>
#include <iomanip>

// Função para imprimir o array
std::ostream &printArray(std::ostream &oss, const std::vector<int>& arr, const std::string& label = "")
{
    if (!label.empty())
    {
        oss << label << ": ";
    }

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

// Função merge para combinar dois vetores
void mergeVec(std::vector<int> &left, std::vector<int> &right, std::vector<int> &vector)
{
    size_t l = 0, r = 0, v = 0;
    while (l < left.size() && r < right.size())
    {
        if (left[l] < right[r])
        {
            vector[v] = left[l];
            v++;
            l++;
        }
        else
        {
            vector[v] = right[r];
            v++;
            r++;
        }
    }
    while (l < left.size())
    {
        vector[v] = left[l];
        v++;
        l++;
    }
    while (r < right.size())
    {
        vector[v] = right[r];
        v++;
        r++;
    }
}

// Função recursiva para ordenar o vetor usando merge sort
void mergeInsertVector(std::vector<int> &vector)
{
    if (vector.size() <= 1)
        return;

    int mid = vector.size() / 2;

    std::vector<int> left(vector.begin(), vector.begin() + mid);
    std::vector<int> right(vector.begin() + mid, vector.end());

    std::cout << "Dividindo: \n";
	
	printArray(std::cout, vector);
    printArray(std::cout, left);
    printArray(std::cout, right);
	
    mergeInsertVector(left);
    mergeInsertVector(right);

    std::cout << "Mesclando: \n";
	printArray(std::cout, left);
    printArray(std::cout, right);

    mergeVec(left, right, vector);
	
	std::cout << "Unido: \n";
    printArray(std::cout, vector);
}

// Função principal para testar o algoritmo
int main()
{
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    std::cout << "Array inicial: \n";
    printArray(std::cout, arr);

    mergeInsertVector(arr);

    std::cout << "Array ordenado: \n";
    printArray(std::cout, arr);

    return 0;
}
