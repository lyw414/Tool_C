#!/usr/bin/sh
Inc=`pwd`/include
Lib=`pwd`/lib
Src=`pwd`/src
Rul=`pwd`/rules
Bin=`pwd`/bin

export Inc
export Lib
export Src
export Rul
export Bin
#编译按优先级进行排序编译
if [ $1 == "clean" ];then
make -f build_all.mk clean
else
make -f build_all.mk basic
make -f build_all.mk all 
fi
