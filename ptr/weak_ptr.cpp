#include <string.h>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

class parent;
class children;

typedef boost::shared_ptr<parent> parent_ptr;
typedef boost::shared_ptr<children> children_ptr;

class parent
{
    public:
    ~parent(){std::cout<<"destroying parent\n";}
    public:
    boost::weak_ptr<children> child;    //changed from ori blog -- cause there was a complie error if use boost::weak_ptr<children> children
//    children_ptr children;
};

class children
{
    public:
    ~children(){std::cout<<"destroying children\n";}
    public:
    boost::weak_ptr<parent> par;//changed from ori blog for the same reason
//    parent_ptr parent;
};
void test()
{
    parent_ptr father(new parent());
    children_ptr son(new children());

    father->child = son;
    son->par = father;
}

int main(void)
{
    std::cout<<"begin test\n";
    test();
    std::cout<<"end test\n";
    return 0;
}
