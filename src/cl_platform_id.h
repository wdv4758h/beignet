/* 
 * Copyright © 2012 Intel Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Benjamin Segovia <benjamin.segovia@intel.com>
 */

#ifndef __CL_PLATFORM_ID_H__
#define __CL_PLATFORM_ID_H__

#include "cl_internals.h"
#include "cl_extensions.h"
#include "cl_khr_icd.h"
#include "CL/cl.h"

#include "src/OCLConfig.h"

struct _cl_platform_id {
  DEFINE_ICD(dispatch)
  const char *profile;
  const char *version;
  const char *name;
  const char *vendor;
  char *extensions;
  const char *icd_suffix_khr;
  size_t profile_sz;
  size_t version_sz;
  size_t name_sz;
  size_t vendor_sz;
  size_t extensions_sz;
  size_t icd_suffix_khr_sz;
  struct cl_extensions *internal_extensions;
};

/* Platform implemented by this run-time */
extern cl_platform_id const intel_platform;

/* Return the valid platform */
extern cl_int cl_get_platform_ids(cl_uint          num_entries,
                                  cl_platform_id * platforms,
                                  cl_uint *        num_platforms);

/* Return information for the current platform */
extern cl_int cl_get_platform_info(cl_platform_id    platform,
                                   cl_platform_info  param_name,
                                   size_t            param_value_size,
                                   void *            param_value,
                                   size_t *          param_value_size_ret);

#define OCL_VERSION_MAJOR 1
#define OCL_VERSION_MINOR 0

#define _STR(x) #x
#define _JOINT(x, y) _STR(x) "." _STR(y)

#define OCL_VERSION_STRING "OpenCL " _JOINT(OCL_VERSION_MAJOR, OCL_VERSION_MINOR)
#define LIBCL_VERSION_STRING _JOINT(LIBCL_VERSION_MAJOR, LIBCL_VERSION_MINOR)

#endif /* __CL_PLATFORM_ID_H__ */

