cmake_minimum_required(VERSION 3.30.0)
# set
set(Var1 "JOJO")
message(${Var1})
message("-----------")

# 设置list
set(ListVars aa;bb;cc)
message(${ListVars})

# $PATH
# message($ENV{PATH})
set(ENV{CXX} "g++")
message($ENV{CXX})

# Unset 删除Var
unset(ENV{CXX})
message($ENV{CXX})