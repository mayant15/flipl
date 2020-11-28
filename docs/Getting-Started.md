# Getting Started with flipl

## Installation

Clone the repo with
```shell script
git clone https://github.com/mayant15/flipl.git --recurse-submodules
```

Dependencies:
- Graphics Magick
- yaml-cpp

flipl uses vcpkg to manage dependencies. Run `setup.bat` or `setup.sh` (depending on your platform) to download them. 
You can then use cmake to build the project as usual.
```
mkdir build
cd build
cmake ..
cmake . --build
```
You will now have an executable in `.\build\`. The `newton.fl`example demonstrates all features of this tool. 
Compile it with `.\flipl.exe newton.fl` to get a file named `sample.gif` in the build directory.

## Timeline

The one essential component that every flipl program must have is a timeline. Imagine it as a 2D grid where the horizontal axis represents the flow of time and the vertical axis represents the layers in your GIF (imagine PhotoShop layers). A *channel* is the fundamental unit on the vertical axis. Only one channel is supported for now. Each channel has *slots*, which mark the time interval that a picture will be shown on that channel. Consider the example below

```yaml
timeline:
  fps: 12
  channel:
    - start: 0
      end: 12
      source: frame.png
```

This defines a GIF that runs at 12 frames per second, has one channel with one slot. The slot starts at frame 0, that is, when the GIF starts, and ends at frame 12. For these 12 frames, `frames.png` will be shown in the channel. For a more detailed description of the language see `Specification.md`.
