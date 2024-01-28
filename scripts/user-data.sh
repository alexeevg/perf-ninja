#!/bin/bash
apt install linux-tools-common -y
apt install linux-tools-6.5.0-9-generic -y
apt install cmake -y
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
./llvm.sh 17 all
update-alternatives --install /usr/bin/cc cc /usr/bin/clang-17 30
update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++-17 30

# Check out the library.
git clone https://github.com/google/benchmark.git
# Go to the library root directory
cd benchmark
# Make a build directory to place the build output.
cmake -E make_directory "build"
cmake -E chdir "build" cmake -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on -DCMAKE_BUILD_TYPE=Release ../
# Build the library.
cmake --build "build" --config Release
#if you want to install the library globally, also run:
cmake --build "build" --config Release --target install

echo XXXX user-data successfully executed
