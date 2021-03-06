// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License

#include "tests/network_bandwidth_helper.hpp"

#include <string>

#include <mesos/resources.hpp>

namespace mesos {
namespace internal {
namespace tests {
namespace resources {

// Helper function create any kind of unreserved resource.
mesos::Resource createResource(
  const std::string& resourceName,
  double amount,
  const std::string& role) {
  mesos::Resource resource;
  resource.set_name(resourceName);
  resource.set_type(mesos::Value::SCALAR);
  resource.mutable_scalar()->set_value(amount);
  if (!role.empty()) {
    resource.set_role(role);
  }
  return resource;
}

mesos::Resource CPU(
  double amount,
  const std::string& role) {
  return createResource("cpus", amount, role);
}

mesos::Resource NetworkBandwidth(
  double amount,
  const std::string& role) {
  return createResource("network_bandwidth", amount, role);
}

mesos::Resource Memory(
  double amount,
  const std::string& role) {
  return createResource("mem", amount, role);
}

} // namespace resources {
} // namespace tests {
} // namespace internal {
} // namespace mesos {
