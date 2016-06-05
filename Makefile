#makefile

_BIN  = bin/
_HEAD = head/
_SRC  = src/
_COM  = com/
PROC  = *.cpp
RES   = client
SUCC  = 生成成功!
all : install

install :
	@g++ ${_SRC}${PROC} -o ${_BIN}${RES}  -I ${_HEAD}\
		&& echo -e "\e[31m" ${RES}${SUCC} "\e[0m"

.PHONY : clean
clean  :
	rm ${_BIN}${RES}
