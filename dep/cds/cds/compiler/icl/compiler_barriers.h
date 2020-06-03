/*
    This file is a part of libcds - Concurrent Data Structures library

    (C) Copyright Maxim Khizhinsky (libcds.dev@gmail.com) 2006-2017

    Source code repo: http://github.com/khizmax/libcds/
    Download: http://sourceforge.net/projects/libcds/files/

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this
      list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef CDSLIB_COMPILER_ICL_COMPILER_BARRIERS_H
#define CDSLIB_COMPILER_ICL_COMPILER_BARRIERS_H

#if defined(_MSC_VER) && _MSC_VER < 1700
    // VC++ up to vc10
#   include <intrin.h>

#   pragma intrinsic(_ReadWriteBarrier)
#   pragma intrinsic(_ReadBarrier)
#   pragma intrinsic(_WriteBarrier)

#   define CDS_COMPILER_RW_BARRIER  _ReadWriteBarrier()
#   define CDS_COMPILER_R_BARRIER   _ReadBarrier()
#   define CDS_COMPILER_W_BARRIER   _WriteBarrier()

#else
    // MS VC11+, linux
#   include <atomic>

#   define CDS_COMPILER_RW_BARRIER  std::atomic_thread_fence( std::memory_order_acq_rel )
#   define CDS_COMPILER_R_BARRIER   CDS_COMPILER_RW_BARRIER
#   define CDS_COMPILER_W_BARRIER   CDS_COMPILER_RW_BARRIER
#endif

#endif  // #ifndef CDSLIB_COMPILER_ICL_COMPILER_BARRIERS_H