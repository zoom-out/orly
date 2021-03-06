/* <base/unreachable.cc>

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

#include <base/unreachable.h>

#include <syslog.h>

#include <iostream>

#include <base/thrower.h>
#include <server/daemonize.h>
#include <util/error.h>

using namespace Base;

void Base::Unreachable(const TCodeLocation &loc) {
  DEFINE_ERROR(unreachable_t, std::runtime_error, "Unreachable code");

  Server::BacktraceToLog();

  std::cout << "Reached unreachable location: " << loc << std::endl;

// In release builds, don't abort
#ifdef NDEBUG
  syslog(LOG_ERR, "Entered code location that was supposed to be unreachable.");
  Server::BacktraceToLog();
  TThrower<unreachable_t>{loc};
#else
  Util::Abort(loc);
#endif
}
