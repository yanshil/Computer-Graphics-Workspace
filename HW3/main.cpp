#include "CG_Driver.h"


using namespace Nova;

int main(int argc, char const *argv[])
{

    enum
    {
        d = 2
    };
    using T = double;
    using TV = Vector<T, d>;
    using T_INDEX = Vector<int, d>;

    int counts = 16;
    Range<T,d> range(TV(-0.5), TV(0.5));
    Grid<T,d> * grid = new Grid<T,d>(T_INDEX(counts), range);
    CG_Storage<T,d> storage(*grid);
    
    CG_Driver<T,d> driver(storage);

    driver.Execute();

    return 0;
}
