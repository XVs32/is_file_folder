# Readme

---

###### tags: `course`

---
## Introduction
This is a C program works in Linux. Which tells you your input string is a file or folder name, or it is not exist.

---
## How to build
You could compile the source code by simply using:
```gcc find_file.c -o find_file```

---
## How to use
Execute the executable file with:
```./(path_to_executable)/find_file```

Please replace ```(path_to_executable)``` with your own path. The program with check every folder under your current folder.

Input the string you wish to check:
```shell=
Please input the file/folder name:
(your string)
```

For example, you could enter ```sub_folder```, which is under the ```example_folder```:
```shell=
Please input the file/folder name:
sub_folder
sub_folder is a sub-directory
```

Or ```hello_world.txt```, which is under the ```sub_folder```:
```shell=
Please input the file/folder name:
hello_world.txt
hello_world.txt is a file
```

Or something which is not exist:
```shell=
Please input the file/folder name:
you can't see me
you can't see me does not exist.
```