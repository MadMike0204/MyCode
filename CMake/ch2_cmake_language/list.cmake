cmake_minimum_required(VERSION 3.30.0)

# 两种方式创建Var
set(LISTVALUE a1 a2 a3)
message(${LISTVALUE})

list(APPEND port p1 p2 p3)
message(${port})

# 获取长度
list(LENGTH LISTVALUE len)
message(${len})

# FIND
list(FIND LISTVALUE a2 index)
message(${index})

# REMOVE
list(REMOVE_ITEM port p1)
message(${port})

# 添加有两种方式
list(APPEND LISTVALUE jojo)
message(${LISTVALUE})

list(INSERT LISTVALUE 3 jostar)
message(${LISTVALUE})

# 反转
list(REVERSE LISTVALUE)
message(${LISTVALUE})

list(SORT LISTVALUE)
message(${LISTVALUE})