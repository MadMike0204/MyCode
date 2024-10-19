# 常用List 方法

# 添加元素
list(APPEND <list> [<element>....]) 
# 删除元素
list(REMOVE_ITEM <list> <value> [value...])
# 获取元素个数
list(LENGTH <list> <output variable>)
# 查找元素并返回索引
list(FIND <list> <value> <out-var>)
# 在index位置插入元素
list(INSERT <list> <index> [<element>...])
# 反转list
list(REVERSE <list>)
# 对list进行排序
list(SORT <list> [...])