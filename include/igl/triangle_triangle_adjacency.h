// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2014 Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_TRIANGLE_TRIANGLE_ADJACENCY_H
#define IGL_TRIANGLE_TRIANGLE_ADJACENCY_H
#include <igl/igl_inline.h>
#include <Eigen/Core>
#include <vector>

namespace igl
{
  // Constructs the triangle-triangle adjacency matrix for a given
  // mesh (V,F).
  //
  // Templates:
  //   Scalar derived type of eigen matrix for V (e.g. derived from
  //     MatirxXd)
  //   Index  derived type of eigen matrix for F (e.g. derived from
  //     MatrixXi)
  // Inputs:
  //   V  #V by dim list of mesh vertex positions
  //   F  #F by simplex_size list of mesh faces (must be triangles)
  // Outputs:
  //   TT   #F by #3 adjacent matrix, the element i,j is the id of the triangle adjacent to the j edge of triangle i
  //   TTi  #F by #3 adjacent matrix, the element i,j is the id of edge of the triangle TT(i,j) that is adjacent with triangle i
  // NOTE: the first edge of a triangle is [0,1] the second [1,2] and the third [2,3].
  //       this convention is DIFFERENT from cotmatrix_entries.h

  template <typename Scalar, typename Index>
  IGL_INLINE void triangle_triangle_adjacency(const Eigen::PlainObjectBase<Scalar>& V,
                     const Eigen::PlainObjectBase<Index>& F,
                     Eigen::PlainObjectBase<Index>& TT);
  // Compute triangle-triangle adjacency with indices
  template <typename Scalar, typename Index>
  IGL_INLINE void triangle_triangle_adjacency(const Eigen::PlainObjectBase<Scalar>& V,
                     const Eigen::PlainObjectBase<Index>& F,
                     Eigen::PlainObjectBase<Index>& TT,
                     Eigen::PlainObjectBase<Index>& TTi);


  // Preprocessing
  template <typename Scalar, typename Index>
  IGL_INLINE void triangle_triangle_adjacency_preprocess(const Eigen::PlainObjectBase<Scalar>& V,
                                const Eigen::PlainObjectBase<Index>& F,
                                std::vector<std::vector<int> >& TTT);
  // Extract the face adjacencies
  template <typename Index>
  IGL_INLINE void triangle_triangle_adjacency_extractTT(const Eigen::PlainObjectBase<Index>& F,
                               std::vector<std::vector<int> >& TTT,
                               Eigen::PlainObjectBase<Index>& TT);
  // Extract the face adjacencies indices (needed for fast traversal)
  template <typename Index>
  IGL_INLINE void triangle_triangle_adjacency_extractTTi(const Eigen::PlainObjectBase<Index>& F,
                                std::vector<std::vector<int> >& TTT,
                                Eigen::PlainObjectBase<Index>& TTi);
}

#ifndef IGL_STATIC_LIBRARY
#  include "triangle_triangle_adjacency.cpp"
#endif

#endif
