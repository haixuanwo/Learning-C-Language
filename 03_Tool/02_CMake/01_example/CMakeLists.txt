
cmake_minimum_required(VERSION 3.10)

project(Reactor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 目标系统名称
set(CMAKE_SYSTEM_NAME Linux)
# set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_SYSTEM_PROCESSOR x86)

# 交叉编译器路径
# set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)

add_compile_options(
    -g                      # 生成调试信息，供 gdb 等调试器使用
    -Wall                   # 启用大多数常见警告（所有警告的简称，实际并非全部）
    -Wextra                 # 启用额外警告（比 -Wall 更严格）
    -Werror                 # 报告所有警告为错误
    -Wshadow                # 警告变量名遮蔽（局部变量遮蔽全局变量/成员变量）
    -rdynamic               # 导出所有符号到动态符号表，使调试器能显示完整调用栈，dlopen 也能找到符号
    -std=c++17              # 使用 C++17 标准编译
    -Wconversion            # 警告隐式类型转换可能改变值（如 int → char，有符号/无符号转换）
    -march=native           # 针对当前机器的CPU架构优化
    -Wpointer-arith         # 警告依赖指针大小的算术运算（如 void* 指针加减）
    -Wwrite-strings         # 将字符串常量视为 const char* 而非 char*，防止意外修改
    -Wold-style-cast        # 警告使用C风格转换（如 (int)a），建议用 static_cast 等
    -Woverloaded-virtual    # 警告虚函数重载时隐藏了基类的虚函数
    -Wno-unused-parameter        # 关闭未使用参数的警告（函数参数声明了但未使用时不警告）
    -D_FILE_OFFSET_BITS=64       # 定义宏，使程序支持大于2GB的文件（启用64位文件偏移）
    -DCHECK_PTHREAD_RETURN_VALUE # 定义宏，用于检查 pthread 函数的返回值（增强错误处理）
)

# set(CMAKE_BUILD_TYPE Debug)

# 找到第三方cmake库
# set(OpenCV_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/OpenCV455/lib/cmake/opencv4")
# find_package(OpenCV REQUIRED)

# 指定头文件路径
include_directories(3rd_party/include)
include_directories(src)

file(GLOB_RECURSE SOURCES src/*.cpp)

# 链接库路径
link_directories(3rd_party/lib)

set(PROJECT_LIBS pthread)

add_executable(main main.cpp ${SOURCES})
target_link_libraries(main ${PROJECT_LIBS})
