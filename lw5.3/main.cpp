/* 5.3. Число цифр (5)
 * Найти суммарное число цифр во всех целых числах от M до N включительно.
 * Гаврилов Я. К.
 * Среда: Debian GNU/Linux 14, g++ 14.2.0
 */
 
#include <iostream>
#include <fstream>

long long count_digits(long long x) 
{
    if (x <= 0) 
    {
        return 0;
    }
    
    long long result = 0;
    long long p = 1;
    long long len = 1;
    
    while (p * 10 <= x) 
    {
        result += 9 * p * len;
        
        p *= 10;
        len++;
    }
    
    result += (x - p + 1) * len;
    
    return result;
}

int main() 
{
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    
    long long m, n;
    long long answer = 0;
    if (!(input >> m >> n)) 
    {
        goto exit;
    }
    
    answer = count_digits(n) - count_digits(m - 1);
    
    output << answer << '\n';
 
exit:
    input.close();
    output.close();
    
    return 0;
}