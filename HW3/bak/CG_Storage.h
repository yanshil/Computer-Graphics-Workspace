//!#####################################################################
//! \file CG_Storage.h
//!#####################################################################
// Class CG_Storage
//######################################################################
#ifndef __CG_Storage__
#define __CG_Storage__

#include "string.h"
#include <nova/Tools/Arrays/Array.h>
#include <nova/Tools/Vectors/Vector.h>

namespace Nova
{
template<class T, int d>
class CG_Storage
{
    using TV = Vector<T, d>;

  public:
    int size, m, n;

    Array<TV> _Adiag;
    Array<TV> _Aplusi;
    Array<TV> _Aplusj;

    Array<TV> _rhs; // Right Hand Size
    int *_BF;       // Boundary Flag: -1 for Inertia and 0 for Dirichlet and 1 for Exteria

    CG_Storage() {}

    CG_Storage(int m, int n)
        : m(m), n(n)
    {
        size = m * n;
        _BF = new int[size];
    }
    ~CG_Storage()
    {
        delete[] _BF;
    }

    void initialize()
    {

    }
    
    void initializeBF()
    {
    }

    void calculateA(T scale)
    {
        for (int iy = 0; iy < n; iy++)
        {
            for (int ix = 0; ix < m; ix++)
            {
                int idx = iy * m + ix;
                if (ix < m - 1) // if u.next.valid() !exterior
                {
                    _Adiag(idx) += scale;     // _Adiag() + 1
                    _Adiag(idx + 1) += scale; // _AnextU.diag() + 1
                    _Aplusi(idx) = -scale;
                }
                else
                {
                    _Aplusi(idx) = 0;
                }

                if (iy < n - 1) //if v.next.valid()
                {
                    _Adiag(idx) += scale;
                    _Adiag(idx + m) += scale;
                    _Aplusj(idx) = -scale;
                }
                else
                {
                    _Aplusj(idx) = 0;
                }
            }
        }
    }

    void calculateRHS()
    {
    }

    double Adiag(int idx) const
    {
        return _Adiag(idx);
    }
    double Aplusi(int idx) const
    {
        return _Aplusi(idx);
    }
    double Aplusj(int idx) const
    {
        return _Aplusj(idx);
    }
    double rhs(int idx) const
    {
        return _rhs(idx);
    }

    double &Adiag(int idx)
    {
        return _Adiag(idx);
    }
    double &Aplusi(int idx)
    {
        return _Aplusi(idx);
    }
    double &Aplusj(int idx)
    {
        return _Aplusj(idx);
    }
    double &rhs(int idx)
    {
        return _rhs(idx);
    }
};
} // namespace nova

#endif