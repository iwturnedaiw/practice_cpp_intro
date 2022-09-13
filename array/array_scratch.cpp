#include "array_scratch.h"

template <typename T, std::size_t N>
typename scratch::array<T, N>::size_type scratch::array<T, N>::size() const {
  return N;
}
template std::size_t scratch::array<int, 5>::size() const; 
template std::size_t scratch::array<int, 3>::size() const; 
