### 静态库
- linux:libxxxx.a --->windows的.lib文件
### makefile
- 命名规则：
  - makefile
  - Makefile
- 三要素：
  - 目标
  - 依赖：通过什么文件去生成
  - 规则命令：如何去生成
- 函数：
  - wildcard：可以进行文件匹配
  - patsubst：内容的替换
- 变量：(只能在规则里出现)
  - $@代表目标
  - $^全部依赖
  - $<第一个依赖
  - $?第一个变化的依赖
### gdb调试
- 使用gdb:编译的时候加 -g参数


