
#load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

local_repository(
# Name of the Abseil repository. This name is defined within Abseil's
# WORKSPACE file, in its `workspace()` metadata
name = "com_google_absl",

# NOTE: Bazel paths must be absolute paths. E.g., you can't use ~/Source
path = "/home/wenji/source/abseil-cpp",
)

local_repository(
# Name of the Abseil repository. This name is defined within Abseil's
# WORKSPACE file, in its `workspace()` metadata
name = "com_google_test",

# NOTE: Bazel paths must be absolute paths. E.g., you can't use ~/Source
path = "/home/wenji/googletest",
)

local_repository(
   name = "com_google_protobuf",
   path = "/home/wenji/protobuf",
)

local_repository(
   name = "protobuf_examples",
   path = "proto_buf_samples",
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")

protobuf_deps()
