# How to use tester

_current `a` and `tester` are compiled for MACOS ARM_64_

## How to use the given file structure with the makefile

The `makefile` and `tester` is designed to work in the following folder structure:

```
.
├── Assignment_4_test_cases/
│   ├── test1.txt
│   ├── test1o.txt
│   ├── test2.txt
│   ├── test2o.txt
│   ├── test3.txt
│   ├── test3o.txt
│   ├── test4.txt
│   ├── test4o.txt
│   ├── test5.txt
│   └── test5o.txt
├── obj/
├── include/
│   └── example.h
├── src/
│   ├── example.c
│   └── main.c
├── readme.md
├── Makefile
├── a
├── input.txt
└── output.txt
```

Put your local headers in `include/` and in your program files as
`#include "../include/example.h"`

Put your local program files into `src`
make sure you have a `main(){}` in `main.c`

_Of course if you only use c files and ignore the header file convention just use_
`#include "example.c"`

Run the `makefile` while in the top directory, _one above src_, with the command `make`. This will generate a program named `a`. Run that program with `./a`.

To use `tester` run `./tester`.
Tester requires that `a`, `Assignment_4_test_cases/`, `input.txt`, and `output.txt` to be in the same location as `tester`.

If a test fails, `tester` will put failed test results into file folder `Bad_Output/`. It does not display which lines failed, just the inputed file, the correct output which is `testxo.txt` and the program `a`'s output which will be `outputx.txt`. Use an online file difference checker to see what the file differences are. _I advise https://www.diffchecker.com_

_Before using tester, compile `tester` for your respective machine, see how below._

**Do not modify the `Assignment_4_test_cases/` folder or its contents. Do not move `input.txt` or `ouput.txt` files, you can modify their contents**

**If you modify the `makefile`, insure that the resulting program is named `a`**

## Compiling Tester for computer

Open `./tester_src_` in a terminal and run `make`
Move the resulting `tester` program that is generated into the location that your program is created. Make sure your program is named `a`. _By default the program in the provided makefile creates program`a`._

# How to test on server

Use `Filezilla` to connect to the ssh server to upload your files to a directory in your profile folder.
_see below if you do not know how to use filezilla_

Connect to the ssh server on in terminal or command line.
`ssh://ashackelford@ecs-pa-coding1.ecs.csus.edu:22`
_remember to first connect with your Global Protect VPN_

Then follow the instruction above.

## Installing filezilla and connecting with filezilla

Go to at https://filezilla-project.org/download.php?type=client and download the non manual version. It is free.

Once installed go to the ECS coding server
Connect to the server with the `Global Protect VPN` _assumption is that you already know how to do that_

Go to `File > Site Manager` and select protocol `SFTP - SSH FIle Transfer Protocol`
Host is `ecs-pa-coding1.ecs.csus.edu`
Port is `22`
User is `csus_username`
Password is `csus_password`
