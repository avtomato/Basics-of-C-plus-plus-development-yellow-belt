#include <algorithm>
#include <utility>
#include <string>


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
	RandomIt range_begin, RandomIt range_end, string prefix) {
	
  // Все строки, начинающиеся с prefix, больше или равны строке "<prefix>"
  auto left = lower_bound(range_begin, range_end, prefix);
  
  // Составим строку, которая в рамках буквенных строк является
  // точной верхней гранью множества строк, начинающихся с prefix
  string upper_bound = prefix;
  ++upper_bound[upper_bound.size() - 1];
  
  // Первое встреченное слово, не меньшее upper_bound,
  // обязательно является концом полуинтервала
  auto right = lower_bound(range_begin, range_end, upper_bound);
  
  return {left, right};
}
