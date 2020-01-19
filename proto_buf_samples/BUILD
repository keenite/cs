load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_proto_library")
load("@rules_java//java:defs.bzl", "java_binary", "java_lite_proto_library", "java_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
   name = "addressbook_proto",
   srcs = ["addressbook.proto"],
   deps = ["@com_google_protobuf//:timestamp_proto"],
)

cc_proto_library(
   name = "addressbook_cc_proto",
   deps = [":addressbook_proto"],
)

cc_binary(
   name = "add_person_cpp",
   srcs = ["add_person.cc"],
   deps = [":addressbook_cc_proto"],
)

cc_binary(
   name = "list_person_cpp",
   srcs = ["list_person.cc"],
   deps = [":addressbook_cc_proto"],
)
