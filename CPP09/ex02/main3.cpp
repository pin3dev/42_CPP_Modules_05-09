#include <iostream>
#include <vector>



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
}
