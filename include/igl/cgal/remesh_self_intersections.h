// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2014 Alec Jacobson <alecjacobson@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_REMESH_SELF_INTERSECTIONS_H
#define IGL_REMESH_SELF_INTERSECTIONS_H
#include <igl/igl_inline.h>

#include <Eigen/Dense>

#ifdef MEX
#  include <mex.h>
#  include <cassert>
#  undef assert
#  define assert( isOK ) ( (isOK) ? (void)0 : (void) mexErrMsgTxt(C_STR(__FILE__<<":"<<__LINE__<<": failed assertion `"<<#isOK<<"'"<<std::endl) ) )
#endif

namespace igl
{
  // Optional Parameters
  //   DetectOnly  Only compute IF, leave VV and FF alone
  struct RemeshSelfIntersectionsParam
  {
    bool detect_only;
    bool first_only;
    RemeshSelfIntersectionsParam():detect_only(false),first_only(false){};
  };
  
  // Given a triangle mesh (V,F) compute a new mesh (VV,FF) which is the same as
  // (V,F) except that any self-intersecting triangles in (V,F) have been
  // subdivided (new vertices and face created) so that the self-intersection
  // contour lies exactly on edges in (VV,FF). New vertices will appear in
  // original faces or on original edges. New vertices on edges are "merged" only
  // across original faces sharing that edge. This means that if the input
  // triangle mesh is a closed manifold the output will be too.
  //
  // Inputs:
  //   V  #V by 3 list of vertex positions
  //   F  #F by 3 list of triangle indices into V
  //   params  struct of optional parameters
  // Outputs:
  //   VV  #VV by 3 list of vertex positions
  //   FF  #FF by 3 list of triangle indices into V
  //   IF  #intersecting face pairs by 2  list of intersecting face pairs,
  //     indexing F
  //   J  #FF list of indices into F denoting birth triangle
  //   IM  #VV list of indices into VV of unique vertices.
  //
  // Known bugs: If an existing edge in (V,F) lies exactly on another face then
  // any resulting additional vertices along that edge may not get properly
  // connected so that the output mesh has the same global topology. This is
  // because 
  IGL_INLINE void remesh_self_intersections(
    const Eigen::MatrixXd & V,
    const Eigen::MatrixXi & F,
    const RemeshSelfIntersectionsParam & params,
    Eigen::MatrixXd & VV,
    Eigen::MatrixXi & FF,
    Eigen::MatrixXi & IF,
    Eigen::VectorXi & J,
    Eigen::VectorXi & IM);
}

#ifndef IGL_STATIC_LIBRARY
#  include "remesh_self_intersections.cpp"
#endif
  
#endif
