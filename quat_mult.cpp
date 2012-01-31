#include "quat_mult.h"

#include <cassert>
// http://www.antisphere.com/Wiki/tools:anttweakbar
template <typename Q_type>
IGL_INLINE void igl::quat_mult(
  const Q_type *q1, 
  const Q_type *q2,
  Q_type *out)
{
  // output can't be either of the inputs
  assert(q1 != out);
  assert(q2 != out);

  out[0] = q1[3]*q2[0] + q1[0]*q2[3] + q1[1]*q2[2] - q1[2]*q2[1];
  out[1] = q1[3]*q2[1] + q1[1]*q2[3] + q1[2]*q2[0] - q1[0]*q2[2];
  out[2] = q1[3]*q2[2] + q1[2]*q2[3] + q1[0]*q2[1] - q1[1]*q2[0];
  out[3] = q1[3]*q2[3] - (q1[0]*q2[0] + q1[1]*q2[1] + q1[2]*q2[2]);
}

#ifndef IGL_HEADER_ONLY
// Explicit template specialization
#endif