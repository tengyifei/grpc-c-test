/*
 *
 * Copyright 2015, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


#ifndef TEST_GRPC_C_CONTEXT_H
#define TEST_GRPC_C_CONTEXT_H

#include "../grpc_c_public.h"
#include "../serialization_public.h"
#include <grpc/grpc.h>
#include "status.h"
#include "message.h"
#include "call_ops.h"
#include <stdbool.h>

typedef struct grpc_call_op_set grpc_call_op_set;

typedef struct grpc_context {
  grpc_metadata *send_metadata_array;
  grpc_metadata_array recv_metadata_array;
  grpc_metadata_array trailing_metadata_array;
  gpr_timespec deadline;

  // serialization mechanism used in this call
  GRPC_serializer serialize;
  GRPC_deserializer deserialize;

  // status of the call
  grpc_status status;

  // state tracking
  bool initial_metadata_received;
  GRPC_method rpc_method;
  grpc_channel *channel;
  grpc_call *call;
} grpc_context;

typedef grpc_context GRPC_context;

#endif //TEST_GRPC_C_CONTEXT_H
