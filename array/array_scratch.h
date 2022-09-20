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
    array_iterator & operator += (std::size_t n) {
      i += n;
      return *this; 
    }
    array_iterator operator + (std::size_t n) const {
      array_iterator copy = *this;
      copy += n;
      return copy; 
    }
    array_iterator & operator -= (std::size_t n) {
      i -= n;
      return *this; 
    }
    array_iterator operator - (std::size_t n) const {
      array_iterator copy = *this;
      copy -= n;
      return copy; 
    }

    typename Array::reference operator [] (std::size_t n) const {
      return *( *this + n) ;
    }

    bool operator == (array_iterator const& right) {
      return i == right.i;
    }
    bool operator != (array_iterator const& right) {
      return i != right.i;
    }

    bool operator < (array_iterator const & right ) const {
      return i < right.i;
    }
    bool operator <= (array_iterator const & right ) const {
      return i <= right.i;
    }
    bool operator > (array_iterator const & right ) const {
      return i > right.i;
    }
    bool operator >= (array_iterator const & right ) const {
      return i >= right.i;
    }
  };


  template <typename Array >
  struct array_const_iterator {
    Array const & a;
    std::size_t i;

    array_const_iterator (Array const& a, std::size_t i) : a(a), i(i) { }
    array_const_iterator(typename Array::iterator const & iter ): a( iter.a ), i( iter.i ) { }

    typename Array::const_reference operator * () const {
      return a[i];
    }

    array_const_iterator & operator ++ () {
      ++i;
      return *this;
    }
    array_const_iterator operator ++ (int) {
      array_const_iterator copy = *this;
      ++*this;
      return copy;
    }
    array_const_iterator operator -- () {
      --i;
      return *this;
    }
    array_const_iterator operator -- (int) {
      array_const_iterator copy = *this;
      --*this;
      return copy; 
    }
    array_const_iterator & operator += (std::size_t n) {
      i += n;
      return *this; 
    }
    array_const_iterator operator + (std::size_t n) const {
      array_const_iterator copy = *this;
      copy += n;
      return copy; 
    }
    array_const_iterator & operator -= (std::size_t n) {
      i -= n;
      return *this; 
    }
    array_const_iterator operator - (std::size_t n) const {
      array_const_iterator copy = *this;
      copy -= n;
      return copy; 
    }

    typename Array::const_reference operator [] (std::size_t i) const {
      return *(*this+ i);
    }

    bool operator == (array_const_iterator const& right) {
      return i == right.i;
    }
    bool operator != (array_const_iterator const& right) {
      return i != right.i;
    }

    bool operator < (array_const_iterator const & right ) const {
      return i < right.i;
    }
    bool operator <= (array_const_iterator const & right ) const {
      return i <= right.i;
    }
    bool operator > (array_const_iterator const & right ) const {
      return i > right.i;
    }
    bool operator >= (array_const_iterator const & right ) const {
      return i >= right.i;
    }
  };

  template <typename T, std::size_t N>
  struct array {
    using value_type = T;
    using reference = T & ;
    using const_reference = T const &;
    using size_type = std::size_t;
    using iterator = array_iterator<array>;
    using const_iterator = array_const_iterator<array>;

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

    const_iterator begin() const {
      return const_iterator(*this, 0);
    }
    const_iterator end() const {
      return const_iterator(*this, N);
    }
    const_iterator cbegin() const {
      return const_iterator(*this, 0);
    }
    const_iterator cend() const {
      return const_iterator(*this, N);
    }
  };
};
