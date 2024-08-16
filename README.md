# Blend2D_Emscripten_Bug_Demo

This repository demonstrates a bug in the Blend2D graphics library when built
with Emscripten. The code only works in debug mode, as release mode causes the
`BLImage(width, height, format)` constructor to fail.

To build and run, run the following commands:

```bash
mkdir build
cd build
emcmake cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build ./
emrun ./Blend2D_Emscripten_Bug_Demo.html
```

Upon running the webpage opened should complain about an exception being thrown.
Now replace `-DCMAKE_BUILD_TYPE=Release` with `-DCMAKE_BUILD_TYPE=Debug`. You
should have a blue circle on the canvas.
