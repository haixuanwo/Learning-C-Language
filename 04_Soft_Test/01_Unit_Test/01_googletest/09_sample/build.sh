
mkdir -p build
cd build
cmake .. && make -j16 && make test ARGS="--output-on-failure"
