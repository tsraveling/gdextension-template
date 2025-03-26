#!/bin/sh

# Run the Docker container to build your GDExtension
# This assumes that the Dockerfile takes care of running the build command
container_id=$(docker run -d st_linux_builder)

# Wait for the container to finish running
docker wait $container_id

# Copy logs
docker cp $container_id:/game-repo/ext/build.log build.log

# Copy the binary from the Docker container to your host system
docker cp $container_id:/game-repo/bin/your_binary_name ../../bin/

# Clean up the Docker container
docker rm $container_id
