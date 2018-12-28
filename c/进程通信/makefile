
# get all .c file
SrcFiles=$(wildcard *.cpp) 
# all .c file --> .o file
ObjFiles=$(patsubst %.c,%.o,$(SrcFiles))

all:app1

# 定义变量，目标文件
# ObjFiles=01_.o
# 将编译的过程分离开
app1:$(ObjFiles)
	gcc -o $@ $(ObjFiles)

%.o:%.cpp
	gcc  -c $< 

# 01_.o:01_.cpp
# 	gcc -c 01_.cpp

test:
	echo $(SrcFiles)
	echo $(ObjFiles)

# 伪目标，防止有歧义
.PHONY:clean all
clean:
	@rm -f *.o 
	@rm -f app
