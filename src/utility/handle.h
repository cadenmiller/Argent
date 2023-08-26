#ifndef ARGENT_UTILITY_HANDLE_H
#define ARGENT_UTILITY_HANDLE_H

namespace Argent {
namespace Utility {

template<typename TValue>
class Handle {
public:
    Handle();
    Handle(Handle& rhs);

    inline TValue* operator->() { return _pValue; }
    inline const TValue* operator->() const { return _pValue; }

private:
    TValue* _pValue;

};

} // namespace Utility
} // namespace Argent

#endif // ARGENT_UTILITY_HANDLE_H