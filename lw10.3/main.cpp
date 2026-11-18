/* 10.3. Провода (5)
 * Дано N отрезков провода длиной L1, L2, ..., LN сантиметров. 
 * Требуется с помощью разрезания получить из них K равных отрезков 
 * как можно большей длины, выражающейся целым числом сантиметров. 
 * Если нельзя получить K отрезков длиной даже 1 см, вывести 0.
 * Гаврилов Я. К.
 * Среда: Debian GNU/Linux 14, g++ 14.2.0; -std=c++23
 */

#include <fstream>
#include <vector>
#include <algorithm>

bool check(const std::vector<long long>& wires, long long len, long long K) 
{
    long long count = 0;
    for (long long w : wires) 
    {
        count += w / len;
        
        if (count >= K) 
        {
            return true;
        }
    }
    return count >= K;
}

int main() 
{
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    long long N, K;
    if (!(input >> N >> K)) 
    {
        goto exit;
    }

{
    std::vector<long long> L(N);
    long long max_len = 0;
    
    for (int i = 0; i < N; i++) 
    {
        input >> L[i];
        if (L[i] > max_len) 
        {
            max_len = L[i];
        }
    }

    long long left = 1;
    long long right = max_len;
    long long ans = 0;

    while (left <= right) 
    {
        long long mid = left + (right - left) / 2;
        
        if (check(L, mid, K)) 
        {
            ans = mid;
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }

    output << ans << "\n";
}

exit:
    input.close();
    output.close();

    return 0;
}