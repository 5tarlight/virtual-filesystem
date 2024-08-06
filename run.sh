if [ ! -d "build" ]; then
  echo "Createing build directory"
  mkdir build
fi

cd build
cmake ..
make
cd ..

./build/vfs
