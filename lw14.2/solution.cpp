#include "solution.hpp"

std::vector<unsigned long> Calculate(unsigned long n)
{
	if (n <= 3)
		return { n };

	std::vector<unsigned long> result;
	unsigned long sum = 0, k = 2;
	while (sum + k <= n)
	{
		result.push_back(k);
    sum += k;
		k++;
	}

	unsigned long remainder = n - sum;

	while (remainder > 0)
	{
	  long len = result.size();
		for (long i = len - 1; i >= 0; i--)
		{
			result[i]++;
			remainder--;
			if (remainder == 0)
				return result;
		}
	}
	
	return result;
}
