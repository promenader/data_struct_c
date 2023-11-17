CC=gcc

#定义宏
TARGET=main

#引用宏
all:$(TARGET)

# $@：代表产出文件名
# $*：代表产出文件名不包括扩展名
# $<：依赖项中第一个文件名
# $^：空格分隔的去重后的所有依赖项
# $+：同上，但没去重
# $?：同上，但只包含比产出更新的那些依赖
$(TARGET): main.c SqList.c
	$(CC) -o $@ $^


clean:
	rm $(TARGET)