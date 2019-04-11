# Window Creation

Creating windows in CrossWindow starts by describing exactly what kind of window you want from the start:

```cpp
xwin::WindowDesc wdesc;
wdesc.title = "My Window Title";
// ...
```

Then passing that descriptor struct as an argument to the `xwin::Window::create(xwin::WindowDesc desc)` function.

```cpp
// 🖼️ First create a Window
xwin::Window window;

// 🚅 Create an event queue to process events from that window
xwin::EventQueue eventQueue;

// 🌟 Then initialize the window with OS specific data:
window.create(wdesc, eventQueue);
```

## Getting Started

Be sure to have the following installed:

- [CMake](https://cmake.org/)

- An IDE such as [Visual Studio](https://visualstudio.microsoft.com/downloads/), [XCode](https://developer.apple.com/xcode/), or a compiler such as [GCC](https://gcc.gnu.org/).

Then type the following in your terminal from this folder:

```bash
# 👷 Make a build folder
mkdir build
cd build

# 🖼️ To build your Visual Studio solution on Windows x64
cmake .. -A x64

# 🍎 To build your XCode project on Mac OS
cmake .. -G Xcode

# 🐧 To build your .make file on Linux
cmake ..

# 🔨 Build on any platform:
cmake --build .
```

### WebAssembly & Android

For WebAssembly you'll need to have [Emscripten](http://kripken.github.io/emscripten-site/docs/getting_started/downloads.html) installed. Assuming you have the SDK installed, do the following to build a WebAssembly project:

```bash
# 🌐 For WebAssembly Projects
mkdir build
cd build
cmake .. -DXWIN_OS=WASM -DCMAKE_TOOLCHAIN_FILE="$EMSDK/emscripten/1.38.1/cmake/Modules/Platform/Emscripten.cmake" -DCMAKE_BUILD_TYPE=Release

# Run emconfigure with the normal configure command as an argument.
$EMSDK/emscripten/emconfigure ./configure

# Run emmake with the normal make to generate linked LLVM bitcode.
$EMSDK/emscripten/emmake make

# Compile the linked bitcode generated by make (project.bc) to JavaScript.
#  'project.bc' should be replaced with the make output for your project (e.g. 'yourproject.so')
$EMSDK/emscripten/emcc project.bc -o project.js
```

For more information visit the [Emscripten Docs on CMake](https://kripken.github.io/emscripten-site/docs/compiling/Building-Projects.html#using-libraries).

For **Android Studio** you'll need to make a project, then edit your `build.gradle` file.

```groovy
// 🤖 To build your Android Studio project
android {
    ...
    externalNativeBuild {
        cmake {
            ...
            // Use the following syntax when passing arguments to variables:
            // arguments "-DVAR_NAME=ARGUMENT".
            arguments "-DXWIN_PROTOCOL=ANDROID",
            // The following line passes 'rtti' and 'exceptions' to 'ANDROID_CPP_FEATURES'.
            "-DANDROID_CPP_FEATURES=rtti exceptions"
        }
    }
  buildTypes {...}

  // Use this block to link Gradle to your CMake build script.
  externalNativeBuild {
    cmake {...}
  }
}
```