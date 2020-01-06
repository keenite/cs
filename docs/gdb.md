# GDB with bazel notes
Try the commands with [gdb_test/gdb_sample.cc](https://github.com/keenite/cppstudy/blob/master/gdb_test/gdb_sample.cc)

## Run gdb with bazel build
```
 bazel build -c dbg :gdb_sample
 bazel run -c dbg --run_under=gdb :gdb_sample
```
## Frently use commands - break, run, list, frame, print, next, info, backtrace
### Setting break point
```
(gdb) b 21 //Setting the break point at line 21
(gdb) b main //Setting the break point at function main

(gdb) r  //run: the code
(gdb) l //list: the code around 25

(gdb) f //frame: show where the code is

(gdb) n //next: go to the next line
(gdb) p v0 //print: the variable v0
```
* next command will not enter the function, need to use step to jump in

```
(gdb) b main //Setting the break point at function main
(gdb) r  //run: the code
(gdb) n
(gdb) n //Just in fun1() line
(gdb) s //step: into the fun1()
.... Jump to fun3()
(gdb) bt //backtrace: shows the function heap
(gdb) i b //info: shows the break points list
(gdb) d # //delete: a break points showed in info
.... Rerun the program
(gdb) c //continue: run to the next break point
... Jump to fun3()
(gdb) bt //backtrace: shows the frames have been called
(gdb) f 2 //frame: with number will switch to the context of a frame, here we jump back to frame 2 fun1()
(gdb) p v1
(gdb) info locals //shows all the local variable number
```
