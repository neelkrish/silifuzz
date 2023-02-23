// Copyright 2022 The SiliFuzz Authors.
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

#include "./runner/default_snap_corpus.h"
#include "./snap/snap.h"
#include "./snap/snap_corpus_util.h"

namespace silifuzz {

const SnapCorpus* LoadCorpus(const char* filename, int* corpus_fd) {
  if (filename == nullptr) {
    if (corpus_fd != nullptr) {
      *corpus_fd = -1;
    }
    return nullptr;
  }
  // Release the pointer -- it is ok to leak memory since the runner always
  // runs to completion and then exits.
  return LoadCorpusFromFile(filename, true, corpus_fd).release();
}

}  // namespace silifuzz
