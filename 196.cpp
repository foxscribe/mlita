/* 19.6. Змейка (3)
 * Змей Горыныч убедительно просит расположить N^2 чисел от 1 до N^2 в квадрате змейкой.
 * Гаврилов Я. К.
 * Среда: Debian GNU/Linux 14, g++ 14.2.0
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    if (!(std::cin >> n)) 
    {
        return 0;
    }

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    int current = 1;

    for (int sum = 0; sum <= 2 * n - 2; sum++) 
    {
        int min_r = std::max(0, sum - n + 1);
        int max_r = std::min(sum, n - 1);

        if (sum % 2 == 1)
        {
            for (int r = min_r; r <= max_r; r++) 
            {
                int c = sum - r;
                matrix[r][c] = current++;
            }
        } 
        else 
        {
            for (int r = max_r; r >= min_r; r--) 
            {
                int c = sum - r;
                matrix[r][c] = current++;
            }
        }
    }

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            std::cout << matrix[i][j] << (j == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}