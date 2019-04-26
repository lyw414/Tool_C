# Tool_C
基于C语言的小工具函数封装

ADT 原则：
调用流程：
如 List 结构：
1、申请资源 使用 宏 List 申请,malloc 使用 宏 NEW_List ; List NEW_List _List 申请资源形式
2、初始化资源 使用 结构体中 init 函数（使用资源必须 init）
3、使用ADT
4、使用完毕，clear清理资源，该资源可以复用无需再次init
5、使用完毕，释放资源 使用 free（仅释放动态申请资源）,若复用该资源 则需要再次init,若为NEW_List方式申请的资源 需要手动 free 结构资源


# Log
独立进程 使用SOCKET监听交互/多线程 线程安全(Init 开关控制即可)
使用 LYW_CODE_LOG_ON 宏定义 开启日志功能
# Agloritm
基础数据接口算法目录

# List
变长列表
使用单链表实现 应用查看 Test_List.c
# FixedLengthList
定长列表
使用定长数组实现 应用查看 Test_FixedLengthList.c
# Stack
使用 定长列表实现 应用查看 Test_Stack.c
# Queue
使用 定长列表实现 应用查看 Test_Queue.c
# KMP
KMP 字符串模式匹配 应用查看 Test_KMP.c
# BinaryTree
二叉树 通用存储结构
# BST
二叉搜索树 提供增删改查功能
#HEAP
最小值堆 提供堆创建 pushBack PopFront的功能
#Sort
排序结构 提供排序算法选择 支持插入（二分） 冒泡 分治等金典排序算法
