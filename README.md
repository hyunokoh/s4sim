# s4sim
This software is a simulator for ISSD.

Installation

1. First you need to install gem5 simulator on your machine from http://www.gem5.org

2. No work is required

How to use

1. go to example/hello. "cd example/hello"

2. do a symbolic link of installed gem5. "ln -s ~/project/gem5 ."

3. make

4. ./hello

Result

1. The hello example shows the cycle of arm binary hello

Modify gem5 path

1. In include/s4sim.h, you can change the gem5 execution path and a gem5 platform.

Note

1. In example/hello/m5out/stat.txt, you can find a detailed simulation result.
 
2. All hardware platform change, refer to gem5.

Tested

1. This application is tested on Linux-ubuntu 13.10

2. gem5.opt 2.0 is tested, which is a stable release version.
