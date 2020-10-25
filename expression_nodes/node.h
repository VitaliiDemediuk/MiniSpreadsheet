#ifndef NODE_H
#define NODE_H

#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

class Node{
public:
    virtual cpp_int Calculate() const = 0;
};

#endif // NODE_H
