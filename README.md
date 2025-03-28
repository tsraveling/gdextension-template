# GDExtension Template

I love C++ -- I use it all the time, and for actual gameplay mechanics (especially CPU-intensive ones), I much prefer working in it.

That being said, I *don't* love it for GUI programming or any of the fiddly surface-layer stuff that goes into a game -- and that's the stuff Godot excels at! So the solution is to use a GDExtension, which is to say, a C++ module that you can use right from Godot.

This repo is meant to be a template. Clone or download this code, then copy or paste it into your project (I personally like to use `/ext` within my godot project root, which with the included scripts, will then build the extension binary into `/bin`, which is not gd-ignored). Just make sure you keep godot-cpp as a submodule, so that you can keep up to date with the latest library code in that repo.

## Initial Setup

1. Copy the contents of `/ext` in this repo into `{project root}/ext`, leaving out `/ext/godot-cpp` (you will add this to your own project in the correct way in step 2). You can put it somewhere else if you like, but make sure you modify `setup.sh` to account for that!
2. Run `setup.sh`. This will clone the [godot-cpp repo](https://github.com/godotengine/godot-cpp) into the correct position in your folder structure.
  - Note: if you then clone your repo on a fresh machine, you will need to make sure your submodules are initialized and downloaded with `git submodule update --init --recursive`.
3. Make sure you have [SConstruct](https://www.scons.org/) installed.
  - On Mac, you can just do `brew install scons`.
4. Copy `/bin` into `/bin` in your own project. This has the `gdextension` file which will serve as the interface between Godot and the binaries you build, and the SConstruct settings will deposit binaries into this folder (see "Building your binaries" below).
5. If you are using Vim (or another IDE that uses Clang), do `scons --compiledb` in your `/ext` folder. This will generate the necessary mappings you will need ([compile_commands.json](https://clang.llvm.org/docs/JSONCompilationDatabase.html)) so that your IDE doesn't throw a bunch of errors trying to work with Godot. Run this again if you ever update your `godot-cpp` library.

## Integration with your Godot Project

As long as your binary is built for your current OS, and the `ext.gdextension` file is in `/bin`, you should be good to go! Any entities you create and register (see below) will automatically be available from within Godot.

## Working with your extension

Now we get to the meat of the issue. Start by going into `/ext/src/register_types.cpp` and `.h`. These two files form your core interface between Godot and your C++ code. Any class you register here will be available within Godot. It's best to look over `/ext/src/ExampleEntity` and `.../register_types` for examples. You can use the Godot 4 documentation for details:

- [Compiling the plugin](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html#compiling-the-plugin)
- [Using the module](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html#using-the-gdextension-module)
- [Adding properties](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html#adding-properties)
- [Working with signals](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html#signals)

ExampleEntity has versions of all of the above, with fairly verbose code comments explaining how everything works.

## Building your binaries

On the operating system of your choice, simply run `scons` from the `/ext` folder, and the binary will be built. It will take a long time the first time in order to compile godot-cpp, but will be faster after that. Easy!

### The Linux Builder

When I first worked with GDExtensions, I did not have access to a Linux environment. However, I am a web developer, which means I have Docker. If you don't have a Linux OS of your own, but would like to compile a binary for linux, try the following:

1. [Install Docker Desktop](https://www.docker.com/) -- free version is fine.
2. With Docker Desktop running, simply go to `/ext` and then run `./build-linux.sh` from the command line. A lightweight Linux instance will be built and run via Docker, which will then compile the binary in Linux and copy it to your bin file. 

This is useful if, for instance, you would like to create a Steam Deck build, or just generally if you want your game to be available on Linux but don't have your own version of it.

Note: there are other options for cross-compiling from one OS to another -- [minGW](https://sourceforge.net/projects/mingw/) is used by some. I also suspect there's an option via WSL in Windows, but haven't got that set up yet (I tend to work on Mac). For now, if you have Docker, this works great.

## Conclusion

With the above tools, you should be ready to start coding powerful, performant C++ code for your Godot game. Good hunting!
