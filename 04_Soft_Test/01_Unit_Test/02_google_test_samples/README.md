<!--
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2026-04-10 16:01:27
 * @LastEditors: Clark
 * @LastEditTime: 2026-04-10 19:03:36
 * @Description: file content
-->

# 安装googletest

## （1）命令安装
sudo apt update
sudo apt install -y libgtest-dev libgmock-dev googletest

## （2）源码安装
- 下载官方完整源码（包含 gtest + gmock）
git clone https://github.com/google/googletest.git
cd googletest

- 创建编译目录
mkdir build && cd build

- 编译，设置当前项目的C++版本
cmake .. -DBUILD_GMOCK=ON -DCMAKE_CXX_STANDARD=17
make -j4

- 安装到系统
sudo make install


使用find_package(GTest REQUIRED)命令来查找googletest，并链接到项目中。



# 本仓库的CMake中有一个在工程中下载googletest的示例，可以参考：
Learning-C-Language/03_Tool/02_CMake/cmake-examples/05-unit-testing/google-test-download



# googletest源码中的示例googletest/samples

## 01_sample
简单示例，使用TEST(测试套件组名, 测试用例名)

## 02_sample
示例如何写单元测试，使用TEST(测试套件组名, 测试用例名)，测试一个string类

## 03_sample
使用测试夹具，为所有TEST_F(测试套件组名, 测试用例名)添加初始化SetUp()和去初始化TearDown()函数
testing::Test
void SetUp()
void TearDown()

每个TEST_F都能使用已初始化的状态

## 04_sample
使用TEST(测试套件组名, 测试用例名)，测试一个Counter类

## 05_sample
可在void SetUp()，void TearDown()加入测试时间判断

## 06_sample
给多种不同数据类型，跑同一套测试逻辑
TYPED_TEST_CASE + TYPED_TEST

## 07_sample
防止一个测试影响它之后的测试，为每个测试创建和销毁被测试对象
TEST_P参数化测试，多组输入数据

## 08_sample
TEST_P
using ::testing::Combine;
如何测试依赖于一些全局标志变量的代码

## 09_sample
如何使用谷歌测试监听器API来实现一个可选的控制台输出，
以及如何使用UnitTest反射API来枚举测试用例和测试，并检查它们的结果

TestEventListeners
作用：在测试开始 / 结束、用例开始 / 结束时，自动执行你写的代码

## 10_sample
侦听器API来实现一个基本的泄漏检查器
TestEventListeners
EmptyTestEventListener
