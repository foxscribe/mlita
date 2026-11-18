/* 19.2. Пятница 13 (4)
 * Перечислить дни, на которые приходится пятница 13-го числа в заданном 
 * диапазоне лет из интервала 1901-2099 г.г.
 * Гаврилов Я. К.
 * Среда: Debian GNU/Linux 14, g++ 14.2.0; -std=c++23
 * Формула Зеллера: https://sky.pro/wiki/python/kak-uznat-datu-i-den-nedeli-v-proshlom/
 */

#include <iostream>
#include <string>

bool is_friday_13(int year, int month) 
{
    int m = month;
    int y = year;

    if (month == 1) 
    {
        m = 13;
        y--;
    } 
    else if (month == 2) 
    {
        m = 14;
        y--;
    }

    int k = y % 100;
    int j = y / 100;
    
    int h = (13 + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
    
    if (h < 0) 
    {
        h += 7;
    }

    return h == 6;
}

int main() 
{
    int y1, y2;
    if (!(std::cin >> y1 >> y2)) 
    {
        return 0;
    }

    std::string months[] = {
        "", "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
        "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"
    };

    for (int year = y1; year <= y2; year++) 
    {
        for (int month = 1; month <= 12; month++) 
        {
            if (is_friday_13(year, month)) 
            {
                std::cout << year << " " << months[month] << "\n";
            }
        }
    }

    return 0;
}
