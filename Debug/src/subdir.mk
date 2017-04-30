################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Array.cpp \
../src/BST.cpp \
../src/Collection.cpp \
../src/main.cpp 

OBJS += \
./src/Array.o \
./src/BST.o \
./src/Collection.o \
./src/main.o 

CPP_DEPS += \
./src/Array.d \
./src/BST.d \
./src/Collection.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


