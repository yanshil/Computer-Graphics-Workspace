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

    // (const T_INDEX &counts_input, const Range<T, d> &domain_input)
    // TODO: Parse Arg

    // Range<T,d> range(TV(-0.5), TV(0.5));

    int counts = 16;
    CG_Storage<T, d> *storage = new CG_Storage<T, d>(counts, counts);
    // Grid<T,d> * grid = new Grid<T,d>(T_INDEX(counts), range);

    return 0;
}
