#include <string>
#include <iostream>
#include <boost/shared_ptr.hpp>

class implementation
{
public:
    ~implementation() { std::cout <<"destroying implementation\n"; }
    void do_something() { std::cout << "did something\n"; }
};

void test()
{
    boost::shared_ptr<implementation> sp1(new implementation());
    std::cout<<"The Sample now has "<<sp1.use_count()<<" references\n";

    boost::shared_ptr<implementation> sp2 = sp1;
    std::cout<<"The Sample now has "<<sp2.use_count()<<" references\n";
    
    //sp1.reset();
    std::cout<<"After Reset sp1. The Sample now has "<<sp2.use_count()<<" references\n";

    //sp2.reset();
    std::cout<<"After Reset sp2.\n";
}

int main()
{
    test();
}
/*
if neither sp1.reset() nor sp2.reset() is commented out
$ ./a.out 
The Sample now has 1 references
The Sample now has 2 references
After Reset sp1. The Sample now has 1 references
destroying implementation
After Reset sp2.

if both sp1.reset() and sp2.reset() are commented out
$ ./a.out 
The Sample now has 1 references
The Sample now has 2 references
After Reset sp1. The Sample now has 2 references
After Reset sp2.
destroying implementation

Check my post for more details:
    http://stackoverflow.com/questions/14108794/something-unclear-in-this-shared-ptr-example#comment19522907_14108794
 * */
