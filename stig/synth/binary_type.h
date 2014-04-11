/* <stig/synth/binary_type.h>

   TODO

   Copyright 2010-2014 OrlyAtomics, Inc.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

#pragma once

#include <stig/synth/type.h>

namespace Stig {

  namespace Synth {

    /* TODO */
    class TBinaryType
        : public TType {
      NO_COPY_SEMANTICS(TBinaryType);
      public:

      /* TODO */
      typedef Type::TType (*TGet)(const Type::TType &, const Type::TType &);

      /* TODO */
      TBinaryType(TType *lhs, TType *rhs, TGet get);

      /* TODO */
      virtual ~TBinaryType();

      /* TODO */
      virtual void ForEachRef(const std::function<void (TAnyRef &)> &cb);

      private:

      /* TODO */
      virtual Type::TType ComputeSymbolicType() const;

      /* TODO */
      TGet Get;

      /* TODO */
      TType *Lhs;

      /* TODO */
      TType *Rhs;

    };  // TType

  }  // Synth

}  // Stig
