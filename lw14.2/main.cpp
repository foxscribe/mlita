/* 14.2 Произведение (5)
 * Среди всех наборов различных целых положительных чисел,
 * сумма которых равна заданному числу N (1 ≤ N ≤ 10000),
 * найдите тот, который имеет максимальное произведение входящих в него чисел.
 * Гаврилов Я. К.
 * Среда: Debian GNU/Linux 14, g++ 14.2.0
 */

#include <iostream>
#include "solution.hpp"

int main()
{
	unsigned long N;
	std::cin >> N;

	for (auto n : Calculate(N))
		std::cout << n << ' ';
	std::cout << std::endl;
}
