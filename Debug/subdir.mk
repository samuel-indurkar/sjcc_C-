################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PlayersOnTeam.cpp \
../compute_pi.cpp \
../electric_bill.cpp \
../falafel.cpp \
../longDistanceCall.cpp \
../mean_and_mode.cpp \
../metric_to_english.cpp \
../rockPaperScissors.cpp \
../sentence_format.cpp \
../stringReversal.cpp \
../sum_of_numbers.cpp \
../taxcalculator.cpp \
../tictactoe.cpp 

C_SRCS += \
../length_of_line.c 

OBJS += \
./PlayersOnTeam.o \
./compute_pi.o \
./electric_bill.o \
./falafel.o \
./length_of_line.o \
./longDistanceCall.o \
./mean_and_mode.o \
./metric_to_english.o \
./rockPaperScissors.o \
./sentence_format.o \
./stringReversal.o \
./sum_of_numbers.o \
./taxcalculator.o \
./tictactoe.o 

CPP_DEPS += \
./PlayersOnTeam.d \
./compute_pi.d \
./electric_bill.d \
./falafel.d \
./longDistanceCall.d \
./mean_and_mode.d \
./metric_to_english.d \
./rockPaperScissors.d \
./sentence_format.d \
./stringReversal.d \
./sum_of_numbers.d \
./taxcalculator.d \
./tictactoe.d 

C_DEPS += \
./length_of_line.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


