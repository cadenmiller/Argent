#ifndef ARGENT_UTILITY_UNIQUE_H
#define ARGENT_UTILITY_UNIQUE_H

namespace Argent {
namespace Utility {

template<typename TValue>
class Unique {
public:
    Unique();
    ~Unique();

    inline TValue* Release() { auto temp = _pValue; _pValue = nullptr; return _pValue; }
    

    inline explicit operator bool() const { return _pValue != nullptr; }

private:
    TValue* _pValue;
};

} // namespace Utility
} // namespace Argent

#endif // ARGENT_UTILITY_UNIQUE_H