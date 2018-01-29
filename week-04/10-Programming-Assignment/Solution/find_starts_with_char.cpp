#include <algorithm>
#include <utility>
#include <string>


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end, char prefix) {
      
  // Все строки, начинающиеся с '<prefix>', больше или равны строке "<prefix>"
  auto left = lower_bound(range_begin, range_end, string(1, prefix));
  
  // Составим следующий в алфавите символ.
  // Не страшно, если prefix = 'z':
  // в этом случае мы получим следующий за 'z' символ в таблице символов
  char next_prefix = static_cast<char>(prefix + 1);
  
  // Строка "<next_prefix>" в рамках буквенных строк
  // является точной верхней гранью
  // множества строк, начнающихся с '<prefix>'
  auto right = lower_bound(range_begin, range_end, string(1, next_prefix));
  
  return {left, right};
}
