# README.md
CodeWars CPP 练习

测试采用google test

安装如下：

```shell
git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake ..
make
sudo make install
```

Windows下安装过程如下:

1. 安装MinGW，此处使用的是[mingw-builds](https://www.mingw-w64.org/downloads/#mingw-builds)

2. 安装cmake,下载链接[cmake](https://cmake.org/download/)

3. cmake-gui进行编译，注意选择“MinGW MakeFiles”以及native compliers，手动选择编译工具即可

4. 修改CmakeList.txt，Windows下设置`GTEST_ROOT`变量路径，编译时修改至c++14以上

配置CmakeLists.txt
```
cmake_minimum_required (VERSION 2.8)
project(code-for-blog)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++14 -Wall")

IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
    set(GTEST_ROOT "google_test_install_path")
ELSE ()
    MESSAGE(STATUS "current platform: ${CMAKE_SYSTEM_NAME}")
ENDIF ()

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(MyTests test.cpp)
target_link_libraries(MyTests ${GTEST_BOTH_LIBRARIES})
target_link_libraries(MyTests ${CMAKE_THREAD_LIBS_INIT})
add_test(Test MyTests)
enable_testing()
```

接着编写一个简单的单元测试文件 test.cpp：
```cpp
#include <gtest/gtest.h>
#include <numeric>
#include <vector>
// 测试集为 MyTest，测试案例为 Sum
TEST(MyTest, Sum)
{
std::vector<int> vec{1, 2, 3, 4, 5};
int sum = std::accumulate(vec.begin(), vec.end(), 0);
EXPECT_EQ(sum, 15);
}
int main(int argc, char *argv[])
{
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
```

编译好项目之后，使用命令make test就可以执行单元测试了：
```shell
make test
Running tests...
Test project /Users/senlin/my-test/build
Start 1: Test
1/1 Test #1: Test .............................   Passed    0.01 sec
100% tests passed, 0 tests failed out of 1
Total Test time (real) =   0.01 sec
```

简单的测试
- gtest 提供了TEST()宏，用来定义测试函数：

```cpp
TEST(test_suite_name, test_case_name)
{
// test body ...
}
```

在测试函数中，gtest 提供了EXPECT_*和ASSERT_*这两种风格的断言：

```cpp
TEST(MyTest, Add)
{
EXPECT_EQ(1 + 1, 2);
ASSERT_EQ(1 + 1, 2);
}
```
如果ASSERT_*执行失败了，会导致当前的测试函数立即返回。而EXPECT_*如果执行失败了，并不会导致测试函数返回。

gtest 提供了 8 个ASSERT_*断言，分别是ASSERT_TRUE()、ASSERT_FALSE()、ASSERT_EQ()、ASSERT_NE()、ASSERT_LT()、ASSERT_LE()、ASSERT_GT()和ASSERT_GE()。
EXPECT_*的断言同样也有 8 个，分别是ASSERT_TRUE()、ASSERT_FALSE()、EXPECT_EQ()、EXPECT_NE()、EXPECT_LT()、EXPECT_LE()、EXPECT_GT()和EXPECT_GE()。

- 在测试函数之间共享数据

有时候，我们不可避免地会在多个测试函数中操作相同的数据，例如：

```cpp
TEST(MyTest, Sum)
{
std::vector<int> vec;
vec.push_back(1);
vec.push_back(2);
EXPECT_EQ(3, std::accumulate(vec.begin(), vec.end(), 0));
}
TEST(MyTest, Size)
{
std::vector<int> vec;
vec.push_back(1);
vec.push_back(2);
EXPECT_EQ(2, vec.size());
}
```

一种更好的做法，是将初始化数据在多个测试函数之间共享，并且每个测试函数都拥有这些数据的一份副本，也就是说，在一个测试函数中修改数据，并不会影响到其它测试函数。例如，下面我们定义一个VectorTest类，它的数据成员vec可以在多个测试函数之间共享：

```cpp
#include <gtest/gtest.h>
#include <vector>
class VectorTest : public testing::Test
{
protected:
virtual void SetUp() override
{
vec.push_back(1);
vec.push_back(2);
vec.push_back(3);
}
std::vector<int> vec;
};
// 注意这里使用 TEST_F，而不是 TEST
TEST_F(VectorTest, PushBack)
{
// 虽然这里修改了 vec，但对其它测试函数来说是不可见的
vec.push_back(4);
EXPECT_EQ(vec.size(), 4);
EXPECT_EQ(vec.back(), 4);
}
TEST_F(VectorTest, Size)
{
EXPECT_EQ(vec.size(), 3);
}
int main(int argc, char *argv[])
{
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
```

可以看到，我们用SetUp()来初始化资源，如果有必要，还可以使用TearDown()来释放资源：

```cpp
class SomeTest : public ::testing::Test
{
protected:virtual void SetUp() override
{
// ...
}

virtual void TearDown() override 
{	
// ...	
}
};
```

以上参考自[使用 Google Test 测试框架](http://senlinzhan.github.io/2017/10/08/gtest/)、[Win10下VScode C++环境配置,Cmake与Gtest的简易使用](https://www.bilibili.com/read/cv17586887)
