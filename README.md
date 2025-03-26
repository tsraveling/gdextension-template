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

## Integration with your Godot Project

## Building your binaries

### The Linux Builder
