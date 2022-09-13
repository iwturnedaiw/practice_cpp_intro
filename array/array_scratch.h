#include <cstddef>
namespace scratch {
  template <typename T, std::size_t N>
  struct array {
    T storage[N];

    T & operator [] (std::size_t i) {
      return storage[i];
    };
  };
};
