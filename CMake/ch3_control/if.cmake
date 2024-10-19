cmake_minimum_required(VERSION 3.30.0)

set(varbool TRUE)

# 使用if
if(varbool)
    message(TRUE)
else()
    message(FALSE)
endif()

# NOT OR
if(NOT varbool OR varbool)
    message(TRUE)
else()
    message(FALSE)
endif()

# NOT AND
if(NOT varbool AND varbool)
    message(TRUE)
else()
    message(FALSE)
endif()
 
# LESS
if(1 LESS 2)
    message("1 Less 2")
endif()

# EQUAL
if("1" EQUAL 1)
    message("\"1\" EQUAL 1")
endif()
# 打印了这段语句，说明在cmake中，存储的数据都以字符 字符串的形式存储