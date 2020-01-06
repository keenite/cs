# GDB with bazel notes
## Run gdb with bazel buld
* bazel build -c dbg :target
* bazel run -c dbg --run\_under=gdb :target
