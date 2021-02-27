cmake_minimum_required(VERSION 3.13)
project(matching_engine)

set(CMAKE_CXX_STANDARD 14)

add_executable(matching_engine main.cpp matching_engine.h order.h order_book.h trade_list.h)