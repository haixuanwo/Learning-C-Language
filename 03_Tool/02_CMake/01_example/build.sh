
###
 # @Author: Clark
 # @Email: haixuanwoTxh@gmail.com
 # @Date: 2026-04-04 18:15:29
 # @LastEditors: Clark
 # @LastEditTime: 2026-04-05 10:29:56
 # @Description: file content
###
mkdir build
cd build
cmake ..
# cmake -DCMAKE_BUILD_TYPE=Debug ..
# cmake -DCMAKE_BUILD_TYPE=Release ..
make -j8

if [ $? -eq 0 ]; then
    echo "make success"
else
    echo "make failed"
    exit
fi

# ./main
gdb main
