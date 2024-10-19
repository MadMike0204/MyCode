cmake_minimum_required(VERSION 3.30.0)

# for循环
foreach(VAR RANGE 3)
    message(${VAR})
endforeach()

message(---------)
# var in list
set(Mylist 1 2 3)

foreach(VAR IN LISTS Mylist)
    message(${VAR})
endforeach()
message(---------)

foreach(VAR IN LISTS Mylist ITEMS 4 jojo f)
    message(${VAR})
endforeach()

# zip
message(---------)
set(L1 one two three four)
set(L2 1 2 3 4 5 6)

foreach(num IN ZIP_LISTS L1 L2)
    message("word = ${num_0}, num = ${num_1}") # ${名称_列表序号}
endforeach()
