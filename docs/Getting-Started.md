# Getting Started with flipl

## Installation

Clone the repo with
```shell script
git clone https://github.com/mayant15/flipl.git --recurse-submodules
```

flipl depends on the GraphicsMagick library and uses vcpkg to manage dependencies. Run `setup.bat` or `setup.sh` (depending on your platform) 
to download all dependencies. You can then use cmake to build the project as usual.
```
mkdir build
cd build
cmake ..
cmake . --build
```
You will now have an executable in `.\build\`.


