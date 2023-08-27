#ifndef ARGENT_CONTAINER_ARRAY_H
#define ARGENT_CONTAINER_ARRAY_H

#include <stdint.h>
#include <memory.h>

namespace Argent {
namespace Container {

template<typename TValue>
class Array {
public:
    inline Array();
    inline Array(Array& rhs);
    inline Array(Array&& rhs);
    inline Array(size_t capacity) { Reserve(capacity); }
    inline Array(size_t count, const TValue* pData) { Copy(count, pData); }
    
    inline void Reserve(size_t capacity);
    inline void Resize(size_t capacity);
    inline void Copy(size_t count, const TValue* pData);

    inline Array& operator=(Array& rhs) { Reserve(rhs._capacity); Copy(rhs._coun) };
    inline Array& operator=(Array&& rhs) noexcept;

    inline TValue*  Data();
    inline size_t   Count();
    inline size_t   Capacity();

private:
    size_t          _count;
    size_t          _capacity;
    Unique<TValue>  _pData;

};

} // namespace Container
} // namespace Argents


#endif // ARGENT_CONTAINER_ARRAY_H