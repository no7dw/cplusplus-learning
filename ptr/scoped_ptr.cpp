#include <string.h>
#include <iostream>
#include <boost/scoped_ptr.hpp>

class implementation
{
    public:
        ~implementation(){std::cout<<"destroying implementation\n";}
        void do_something(){std::cout<<"did something\n";}
};

void test()
{
    boost::scoped_ptr<implementation> impl(new implementation());
    impl->do_something();
}

int main(void)
{
    std::cout<<"begin\n";
    test();
    std::cout<<"End\n";
    return 0;
}
