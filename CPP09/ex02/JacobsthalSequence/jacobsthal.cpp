#include <iostream>
#include <vector>

// Função para calcular a sequência de Jacobsthal
std::vector<int> jacobsthalSequence(int n) {
    std::vector<int> jacobsthal(n);
    if (n > 0) jacobsthal[0] = 0;
    if (n > 1) jacobsthal[1] = 1;
    for (int i = 2; i < n; ++i) {
        jacobsthal[i] = jacobsthal[i-1] + 2 * jacobsthal[i-2];
    }
    return jacobsthal;
}

// Função principal para demonstrar a sequência de Jacobsthal
int main() {
    int n = 10; // Número de termos a serem calculados
    std::vector<int> jacobsthal = jacobsthalSequence(n);

    std::cout << "Sequência de Jacobsthal até o termo " << n << ":\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "J_" << i << " = " << jacobsthal[i] << std::endl;
    }
    return 0;
}

