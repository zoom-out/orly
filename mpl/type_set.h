/* <mpl/type_set.h>

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

#include <mpl/type_list.h>
#include <mpl/get_unique.h>

namespace Mpl {

  /* Forward declaration. */
  template <typename TList>
  struct TTypeSetImpl;

  /* TODO. */
  template <typename... TElems>
  struct TTypeSetImpl<TTypeList<TElems...>> {

    using TList = TTypeList<TElems...>;
    using TSet = TRoot<TNode<TElems>...>;

  };  // TTypeSetImpl<TTypeList<TElems...>>

  /* TODO */
  template <typename... TElems>
  struct TTypeSet : public TTypeSetImpl<TGetUnique<TTypeList<TElems...>>> {};

  /* GetList. */
  template <typename TContainer>
  struct GetList;

  template <typename... TElems>
  struct GetList<TTypeSet<TElems...>> : public c14::identity<typename TTypeSet<TElems...>::TList> {};

  template <typename TContainer>
  using TGetList = typename GetList<TContainer>::type;

}  // Mpl
