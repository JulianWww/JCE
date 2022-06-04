#pragma once

#include <vector>
#include <assert.h>

namespace jce {
    template <typename T>
    class BinarySearchTree {
        public: using Buffer_t                  = std::vector<T>;
        public: using iterator                  = typename Buffer_t::iterator;
        public: using const_iterator            = typename Buffer_t::const_iterator;
        public: using reverse_iterator          = typename Buffer_t::reverse_iterator;
        public: using const_reverse_iterator    = typename Buffer_t::const_reverse_iterator;

        private: Buffer_t buffer;

        // Create an empty BinarySearchTree
        public: constexpr BinarySearchTree();
        // Copy an existing BinarySearchTree
        public: constexpr BinarySearchTree(const BinarySearchTree<T>& other);
        // Move an existing BinarySearchTree to this one and emptys the other one
        public: constexpr BinarySearchTree(const BinarySearchTree<T>&& other);
        // Bild BinarySearchTree using iterator range !!Warning!! dose not order the bitmap
        public: template <typename Iter>
                constexpr BinarySearchTree(Iter& front, Iter& back);
        // Constructs the container with the contents of the initializer list init !!Warning!! dose not order the bitmap
        public: constexpr BinarySearchTree(std::initializer_list<T> init);

        // copy assignment operator
        public: constexpr BinarySearchTree<T>& operator=(const BinarySearchTree<T>&  other);
        // move assignment operator
        public: constexpr BinarySearchTree<T>& operator=(const BinarySearchTree<T>&& other);
        // Replaces the contents with those identified by initializer list ilist.
        public: constexpr BinarySearchTree<T>& operator=(std::initializer_list<T> ilist);

        // Capacity
        // Returns the size of the container
        public: constexpr bool empty() const noexcept;
        // Returns the number of elements in the container
        public: constexpr size_t size() const noexcept;
        // Returns the maximum number of elements the container is able to hold due to system or library implementation limitations
        public: constexpr size_t max_size() const noexcept;
        // Increases the capacity of the underlying vector
        public: constexpr void reserve(size_t new_cap);
        // Returns the number of elements that the container has currently allocated space for. 
        public: constexpr size_t capacity() const noexcept;
        // Requests the removal of unused capacity. 
        public: constexpr void shrink_to_fit();

        //Iterators
        // Returns an iterator to the first element of the container.
        public: constexpr iterator begin() noexcept;
        public: constexpr const_iterator begin() const noexcept;
        public: constexpr const_iterator cbegin() const noexcept;
        // Returns an iterator to the element following the last element of the container.
        public: constexpr iterator end() noexcept;
        public: constexpr const_iterator end() const noexcept;
        public: constexpr const_iterator cend() const noexcept;
        // Returns a reverse iterator to the first element of the reversed container;
        public: constexpr reverse_iterator rbegin() noexcept;
        public: constexpr const_reverse_iterator rbegin() const noexcept;
        public: constexpr const_reverse_iterator crbegin() const noexcept;
        // Returns a reverse iterator to the element following the last element of the reversed container.
        public: constexpr reverse_iterator rend() noexcept;
        public: constexpr const_reverse_iterator rend() const noexcept;
        public: constexpr const_reverse_iterator crend() const noexcept;

        // Element access
        // direct access to the underlying array
        public: constexpr T* data() noexcept;
        public: constexpr const T* data() const noexcept;
        public: constexpr bool contains(const T& value) const;

        // modifyers
        // clears the contents 
        public: constexpr void clear() noexcept;
        // insert element at the right position
        public: constexpr iterator insert(const T& value);
        // swaps the contents
        public: constexpr void swap( BinarySearchTree<T>& other ) noexcept;
        public: constexpr void swap( Buffer_t& other) noexcept;
        // removes an element from the search Tree
        public: constexpr void remove(const T& value);

        // get position of certain value in Tree
        private: constexpr const_iterator getPos(const T& element) const;
        // get center of two pointers
        private: constexpr void static getCenter(const const_iterator& a, const const_iterator& b, const_iterator& center);
    };
}

template <typename T> inline constexpr jce::BinarySearchTree<T>::BinarySearchTree(): buffer() {};
template <typename T> inline constexpr jce::BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other):  buffer(other.buffer) {};
template <typename T> inline constexpr jce::BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>&& other): buffer(other.buffer) {};
template <typename T> template <typename Iter> inline constexpr jce::BinarySearchTree<T>::BinarySearchTree(Iter& front, Iter& back): buffer(front, back) {};
template <typename T> inline constexpr jce::BinarySearchTree<T>::BinarySearchTree(std::initializer_list<T> init): buffer(init) {};

template <typename T> inline constexpr jce::BinarySearchTree<T>& jce::BinarySearchTree<T>::operator=(const jce::BinarySearchTree<T>& other) {
    this->buffer = other.buffer;
    return *this;
}
template <typename T> inline constexpr jce::BinarySearchTree<T>& jce::BinarySearchTree<T>::operator=(const jce::BinarySearchTree<T>&& other) {
    this->buffer = other.buffer;
    return *this;
}
template <typename T> inline constexpr jce::BinarySearchTree<T>& jce::BinarySearchTree<T>::operator=(std::initializer_list<T> ilist) {
    this->buffer = ilist;
    return *this;
}

template <typename T> inline constexpr bool jce::BinarySearchTree<T>::empty() const noexcept { return this->buffer.empty(); }
template <typename T> inline constexpr size_t jce::BinarySearchTree<T>::size() const noexcept { return this->buffer.size(); }
template <typename T> inline constexpr size_t jce::BinarySearchTree<T>::max_size() const noexcept { return this->buffer.max_size(); }
template <typename T> inline constexpr void jce::BinarySearchTree<T>::reserve(size_t new_cap) { this->buffer.reserve(new_cap); }
template <typename T> inline constexpr size_t jce::BinarySearchTree<T>::capacity() const noexcept { return this->buffer.capacity(); }
template <typename T> inline constexpr void jce::BinarySearchTree<T>::shrink_to_fit() { this->buffer.shrink_to_fit(); }

template <typename T> inline constexpr typename jce::BinarySearchTree<T>::iterator jce::BinarySearchTree<T>::begin()  noexcept { return this->buffer.begin(); }
template <typename T> inline constexpr typename jce::BinarySearchTree<T>::const_iterator jce::BinarySearchTree<T>::begin()  const noexcept { return this->buffer.begin(); }
template <typename T> inline constexpr typename jce::BinarySearchTree<T>::const_iterator jce::BinarySearchTree<T>::cbegin() const noexcept { return this->buffer.cbegin(); }
template <typename T> inline constexpr typename jce::BinarySearchTree<T>::iterator jce::BinarySearchTree<T>::end()  noexcept { return this->buffer.end(); }
template <typename T> inline constexpr typename jce::BinarySearchTree<T>::const_iterator jce::BinarySearchTree<T>::end()  const noexcept { return this->buffer.end(); }
template <typename T> inline constexpr typename jce::BinarySearchTree<T>::const_iterator jce::BinarySearchTree<T>::cend() const noexcept { return this->buffer.cend(); }
template <typename T> inline constexpr typename jce::BinarySearchTree<T>::reverse_iterator       jce::BinarySearchTree<T>::rbegin()  noexcept { return this->buffer.rbegin(); }
template <typename T> inline constexpr typename jce::BinarySearchTree<T>::const_reverse_iterator jce::BinarySearchTree<T>::rbegin()  const noexcept { return this->buffer.rbegin(); }
template <typename T> inline constexpr typename jce::BinarySearchTree<T>::const_reverse_iterator jce::BinarySearchTree<T>::crbegin() const noexcept { return this->buffer.crbegin(); }
template <typename T> inline constexpr typename jce::BinarySearchTree<T>::reverse_iterator       jce::BinarySearchTree<T>::rend()  noexcept { return this->buffer.rend(); }
template <typename T> inline constexpr typename jce::BinarySearchTree<T>::const_reverse_iterator jce::BinarySearchTree<T>::rend()  const noexcept { return this->buffer.rend(); }
template <typename T> inline constexpr typename jce::BinarySearchTree<T>::const_reverse_iterator jce::BinarySearchTree<T>::crend() const noexcept { return this->buffer.crend(); }

template <typename T> inline constexpr T*       jce::BinarySearchTree<T>::data()       noexcept {return this->buffer.data();}
template <typename T> inline constexpr const T* jce::BinarySearchTree<T>::data() const noexcept {return this->buffer.data();}
template <typename T> inline constexpr bool     jce::BinarySearchTree<T>::contains(const T& value) const {
    if (empty()) { return false; }
    const_iterator pos = getPos(value);
    return *pos == value;
}

template <typename T> inline constexpr void jce::BinarySearchTree<T>::clear() noexcept { this->buffer.clear(); }
template <typename T> inline constexpr typename jce::BinarySearchTree<T>::iterator jce::BinarySearchTree<T>::insert(const T& value) {
    const_iterator it;
    if (empty()) {
        it = begin();
    }
    else {
        it = this->getPos(value);
        if (*it < value) {
            it++;
        }
    }
    return this->buffer.insert(it, value);
}
template <typename T> inline constexpr void jce::BinarySearchTree<T>::swap(jce::BinarySearchTree<T>& other) noexcept { this->swap(other.buffer); }
template <typename T> inline constexpr void jce::BinarySearchTree<T>::swap(Buffer_t& other) noexcept { this->buffer.swap(other); }
template <typename T> inline constexpr void jce::BinarySearchTree<T>::remove(const T& value) {
    const_iterator front = this->getPos(value);
    const_iterator back = front;
    while (*front == value && front >= this->begin()) {
        front--;
    }
    while (*back == value && back != this->end()) {
        back++;
    }
    this->buffer.erase(front+1, back);
}

// Privates
template <typename T> inline constexpr typename jce::BinarySearchTree<T>::const_iterator jce::BinarySearchTree<T>::getPos(const T& element) const {
    assert(buffer.size());
    const_iterator front = buffer.cbegin();
    const_iterator back  = std::next(front, buffer.size()-1);
    const_iterator center;
    while (std::distance(front, back) > 1) {
        getCenter(front, back, center);
        if (*center < element) {
            front = center;
        }
        else {
            back = center;
        }
    }
    if (*front == element) {
        return front;
    }
    return back;
}
template <typename T> inline constexpr void jce::BinarySearchTree<T>::getCenter(const jce::BinarySearchTree<T>::const_iterator& a, const jce::BinarySearchTree<T>::const_iterator& b, jce::BinarySearchTree<T>::const_iterator& center) {
    typename const_iterator::difference_type dist = std::distance(a, b)/2;
    center = a + dist;
}