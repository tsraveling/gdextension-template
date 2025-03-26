# Choose a base image that is similar to the target environment
FROM ubuntu:latest

# Install Godot's dependencies
RUN apt-get update -qq && apt-get install -qq \
    build-essential scons pkg-config libx11-dev libxcursor-dev libxinerama-dev \
    libgl1-mesa-dev libglu-dev libasound2-dev libpulse-dev libfreetype6-dev libssl-dev \
    libudev-dev libxrandr-dev yasm

# Copy your project into the Docker image
COPY . /game-repo
WORKDIR /game-repo/ext

# Build your GDExtension
RUN scons platform=linux

# Start a bash session
CMD ["/bin/bash"]