cmake_minimum_required(VERSION 3.24)
project(CodeWarsCpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(MyTests test.cpp test.cpp)
add_executable(digitize Fundamental/digitize.cpp)
add_executable(CountDig Fundamental/CountDig.cpp)
add_executable(ShortestWord Fundamental/ShortestWord.cpp)
add_executable(HowMuchILoveYou Fundamental/HowMuchILoveYou.cpp)

target_link_libraries(MyTests ${GTEST_BOTH_LIBRARIES})
target_link_libraries(MyTests ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(digitize ${GTEST_BOTH_LIBRARIES})
target_link_libraries(digitize ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(CountDig ${GTEST_BOTH_LIBRARIES})
target_link_libraries(CountDig ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(ShortestWord ${GTEST_BOTH_LIBRARIES})
target_link_libraries(ShortestWord ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(HowMuchILoveYou ${GTEST_BOTH_LIBRARIES})
target_link_libraries(HowMuchILoveYou ${CMAKE_THREAD_LIBS_INIT})

add_test(Test MyTests)
add_test(DigitizeTest digitize)
add_test(CountDigTest CountDig)
add_test(ShortestWordTest ShortestWord)
add_test(HowMuchILoveYouTest HowMuchILoveYou)


enable_testing()

