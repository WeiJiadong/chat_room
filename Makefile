#makefile

_BIN   = bin/
_HEAD  = head/
_SRC   = src/
_COM   = com/
CLIENT = client/client.cpp
SERVER = server/server.cpp
PROC   = *.cpp
RES_C  = client
RES_S  = server
SUCC   = 生成成功!
all : install

install :
	@g++ ${_SRC}${PROC} ${CLIENT} -o ${_BIN}${RES_C}  -I ${_HEAD}\
		&& echo -e "\e[31m" ${RES_C}${SUCC} "\e[0m"
	@g++ ${_SRC}${PROC} ${SERVER} -o ${_BIN}${RES_S}  -I ${_HEAD}\
		&& echo -e "\e[31m" ${RES_S}${SUCC} "\e[0m"

.PHONY : clean
clean  :
	rm ${_BIN}${RES}
