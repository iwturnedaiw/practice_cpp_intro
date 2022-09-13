#include <cstddef>
namespace scratch {
  template <typename T, std::size_t N>
  struct array {
    using value_type = T;
    using reference = T & ;
    using const_reference = T const &;
    using size_type = std::size_t;

    value_type storage[N];

    reference operator [] (std::size_t i) {
      return storage[i];
    };

    const_reference operator [] (std::size_t i) const {
      return storage[i];
    };

    size_type size() const;
/*
    size_type size() const {
      return N;
    };
*/
  };
};
