/* <stig/expr/lhsrhsable.h>

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

#include <memory>

#include <base/no_copy_semantics.h>
#include <stig/type/impl.h>

namespace Stig {

  namespace Expr {

    class TLhsRhsable {
      NO_COPY_SEMANTICS(TLhsRhsable);
      public:

      typedef std::shared_ptr<TLhsRhsable> TPtr;

      virtual Type::TType GetLhsRhsType() const = 0;

      protected:

      TLhsRhsable() = default;

    };  // TLhsRhsable

  }  // Expr

}  // Stig
