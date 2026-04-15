
###
 # @Author: Clark
 # @Email: haixuanwoTxh@gmail.com
 # @Date: 2026-04-15 11:32:20
 # @LastEditors: Clark
 # @LastEditTime: 2026-04-15 16:23:37
 # @Description: file content
###

mkdir -p build
cd build
# cmake .. && make -j16 && make test ARGS="--output-on-failure"
cmake .. && make -j16
