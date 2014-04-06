#include <string.h>
#include <iostream>
#include <boost/shared_ptr.hpp>

class implementation
{
    public:
        ~implementation(){std::cout<<"destroying implementation\n";}
        void do_something(){std::cout<<"did something\n";}
};

void test()
{
    boost::shared_ptr<implementation> sp1(new implementation);
    std::cout<< "The Sample now has "<< sp1.use_count()<< " reference(sp1)\n";

    //boost::shared_ptr<implementation> sp2(new implementation);
    boost::shared_ptr<implementation> sp2 = sp1;
    std::cout<< "The Sample now has "<< sp1.use_count()<< " reference(sp1)\n";
    std::cout<< "The Sample now has "<< sp2.use_count()<< " reference(sp2)\n";

    sp1.reset();
    std::cout<<"After Reset sp1. The Sample now has "<<sp1.use_count()<< " reference\n";
    std::cout<<"After Reset sp1. The Sample now has "<<sp2.use_count()<< " reference(sp2)\n";

    sp2.reset();//will call for ~implementation
    std::cout<<"After Reset sp2. The Sample now has "<<sp2.use_count()<< " reference\n";

}

int main(void)
{
    test();
    return 0;
}
