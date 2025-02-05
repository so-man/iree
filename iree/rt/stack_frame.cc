// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "iree/rt/stack_frame.h"

#include "absl/strings/str_cat.h"
#include "iree/rt/source_resolver.h"

namespace iree {
namespace rt {

absl::optional<SourceLocation> StackFrame::source_location() const {
  auto* source_resolver = function_.module()->source_resolver();
  if (!source_resolver) return absl::nullopt;
  return source_resolver->ResolveFunctionOffset(function_, offset_);
}

std::string StackFrame::DebugStringShort() const {
  return absl::StrCat(module().name(), ":", function().name(), "@", offset());
}

}  // namespace rt
}  // namespace iree
