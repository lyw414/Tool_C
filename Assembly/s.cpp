#include <iostream>
#include <stdlib.h>

class Test
{
    public:
        int m_a;
        Test(int a = 1 )
        {
            m_a = a;
            std::cout << "this is in Test()" << std::endl;
        }
};

Test * z ( Test * s)
{
    return s;
}

int main ()
{
    int s = 2;
    Test * d = (Test *)malloc ( sizeof ( Test ) );;
    new ( d ) Test(2);
    std::cout << d->m_a << std::endl;
    return 0;
}
