#ifndef NODE_H
#define NODE_H

#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

class Node{
public:
    virtual cpp_int Calculate() const = 0;
    virtual void AddReference(size_t row, size_t column) const = 0;
    virtual void RemoveReference(size_t row, size_t column) const = 0;
};

#endif // NODE_H
