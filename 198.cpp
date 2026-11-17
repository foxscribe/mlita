/* 19.8. Сапер (3)
 * В некоторых клетках прямоугольной таблицы M×N (0 < M, N ≤ 10) 
 * имеются “мины” (игра Minesweeper). Проставить во всех клетках 
 * таблицы либо символ мины ‘*’, либо число от 0 до 8, показывающее 
 * число мин в соседних клетках по горизонтали, вертикали или диагонали.
 * Гаврилов Я. К.
 * Среда: Debian GNU/Linux 14, g++ 14.2.0
 */

#include <iostream>
#include <vector>
#include <string>

int main() 
{
    int m, n;
    if (!(std::cin >> m >> n)) 
    {
        return 0;
    }

    std::vector<std::string> grid(m);
    for (int i = 0; i < m; ++i) 
    {
        std::cin >> grid[i];
    }

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (grid[i][j] == '*') 
            {
                std::cout << '*';
            } 
            else 
            {
                int mines_count = 0;
                for (int k = 0; k < 8; k++) 
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) 
                    {
                        if (grid[ni][nj] == '*') 
                        {
                            mines_count++;
                        }
                    }
                }
                std::cout << mines_count;
            }
        }
        std::cout << "\n";
    }

    return 0;
}