#include <cstddef>
namespace scratch {

  template <typename Array>
  struct array_iterator {
    Array & a;
    std::size_t i;

    array_iterator (Array &a, std::size_t i) : a(a), i(i) {}

    typename Array::reference operator * () {
      return a[i];
    }

    array_iterator operator ++ () {
      ++i;
      return *this;
    }
    array_iterator operator ++ (int) {
      array_iterator copy = *this;
      ++*this;
      return copy;
    }
    array_iterator operator -- () {
      --i;
      return *this;
    }
    array_iterator operator -- (int) {
      array_iterator copy = *this;
      --*this;
      return copy; 
    }


    bool operator == (array_iterator const& right) {
      return i == right.i;
    }
    bool operator != (array_iterator const& right) {
      return i != right.i;
    }
  };


  template <typename T, std::size_t N>
  struct array {
    using value_type = T;
    using reference = T & ;
    using const_reference = T const &;
    using size_type = std::size_t;
    using iterator = array_iterator<array>;

    value_type storage[N];

    reference operator [] (std::size_t i) {
      return storage[i];
    };

    const_reference operator [] (std::size_t i) const {
      return storage[i];
    };

    size_type size() const {
      return N;
    };

    void fill(T const & v) {
      for (int i = 0; i < N; ++i) {
        storage[i] = v; 
      }
    }

    iterator begin() {
      return iterator(*this, 0);
    }
    iterator end() {
      return iterator(*this, N);
    }
  };
};
