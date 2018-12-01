//!#####################################################################
//! \file FluidSolver.h
// https://github.com/OrionQuest/Nova_Examples/blob/master/embedded_deformables/Embedded_Deformables_Example.h
//!#####################################################################
// Class FluidSolver
//######################################################################

#ifndef __FluidSolver__
#define __FluidSolver__

#include "FluidQuantity.h"

namespace Nova
{
template <typename T, int d>
class FluidSolver
{
private:
  using TV = Vector<T, d>;
  using T_INDEX = Vector<int, d>;

  // Velocity Field
  FluidQuantity<T, d> *_v[d];
  // Density Field
  FluidQuantity<T, d> *_d;
  // The inertia grid
  FluidSimulator_Grid<T, d> *grid;

  T rho;
  T hx;

  T *_rhs;
  T *_p;
  int size;

  void calculateRHS();
  void setBoundaryCondition();
  void project(int limit, T timestep);
  void applyPressure(T timestep);
  void advection(T timestep);
  void flip();
  int index2offset(const T_INDEX &index) const
  {
    return grid->index2offset(index, grid->counts);
  }

  T_INDEX offset2index(const int os) const
  {
    return grid->offset2index(os, grid->counts);
  }

public:
  FluidSolver()
  {
    std::cout << "??" << std::endl;
  }
  FluidSolver(FluidSimulator_Grid<T, d> &grid, T rho)
      : grid(&grid), rho(rho)
  {
    this->_d = new FluidQuantity<T, d>(grid, -1);

    for (int axis = 0; axis < d; axis++)
    {
      this->_v[axis] = new FluidQuantity<T, d>(grid, axis);
    }

    this->size = grid.counts.Product();
    this->_rhs = new T[size];
    this->_p = new T[size];

    this->hx = 1.0 / grid.counts.Min();
    memset(_p, 0, size * sizeof(double));
  }
  ~FluidSolver()
  {
  }

  T toRGB(T_INDEX &index) const
  {
    int idx = index2offset(index);
    return std::max(std::min(1.0 - _d->Phi()[idx], 1.0), 0.0);
  }
  void update(T timestep);
  void addInflow(const T_INDEX &min_corner, const T_INDEX &max_corner,
                 const T &input_d, const TV &input_v);

  ////===============================================================
  void printPressure()
  {
    for (int i = 0; i < size; i++)
    {

      printf("%.3f", _p[i]);
      if ((i + 1) % grid->counts[0] == 0)
      {
        printf("\n");
      }
      else
      {
        printf(",");
      }
    }
  }
  void unitTest_tentProjection(T timestep)
  {
    calculateRHS();
    project(1000, timestep);
    applyPressure(timestep);
    printPressure();
  }

  ////===============================================================
};
} // namespace Nova
#endif