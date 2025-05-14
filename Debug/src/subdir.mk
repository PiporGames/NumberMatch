################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/NumberMatch.cpp \
../src/TADCelda.cpp \
../src/TADJuego.cpp \
../src/TADTablero.cpp \
../src/entorno.cpp \
../src/pr_celda.cpp \
../src/pr_tablero.cpp 

CPP_DEPS += \
./src/NumberMatch.d \
./src/TADCelda.d \
./src/TADJuego.d \
./src/TADTablero.d \
./src/entorno.d \
./src/pr_celda.d \
./src/pr_tablero.d 

OBJS += \
./src/NumberMatch.o \
./src/TADCelda.o \
./src/TADJuego.o \
./src/TADTablero.o \
./src/entorno.o \
./src/pr_celda.o \
./src/pr_tablero.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/NumberMatch.d ./src/NumberMatch.o ./src/TADCelda.d ./src/TADCelda.o ./src/TADJuego.d ./src/TADJuego.o ./src/TADTablero.d ./src/TADTablero.o ./src/entorno.d ./src/entorno.o ./src/pr_celda.d ./src/pr_celda.o ./src/pr_tablero.d ./src/pr_tablero.o

.PHONY: clean-src

