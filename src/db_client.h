// Copyright 2023 Greptime Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <memory>  // std::shared_ptr
#include <string>  // std::string

#include "greptime/v1/database.grpc.pb.h"  // greptime database
#include "greptime/v1/database.pb.h"       // greptime response
#include "grpcpp/channel.h"                // channel
#include "stream_inserter.h"               // stream inserter

namespace greptime {

using greptime::v1::GreptimeDatabase;
using greptime::v1::GreptimeResponse;

class DbClient {
  const std::string db_name_;
  const std::shared_ptr<grpc::Channel> channel_;
  const std::shared_ptr<GreptimeDatabase::Stub> stub_;

 public:
  DbClient(const std::string& db_name, const std::string& db_grpc_endpoint);

  StreamInserter new_stream_inserter(const GreptimeResponse* response);
};

}  // namespace greptime