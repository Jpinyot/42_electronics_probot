#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Test_Components.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Test_Components.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=conf_file.c main.c mode_selector.c bluetooth.c motor_driver.c pruebas.c start_button.c mux_final.c buzzer.c LDR.c proximity_sensor.c ledmatrix2.c rumba.c gyro.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/conf_file.o ${OBJECTDIR}/main.o ${OBJECTDIR}/mode_selector.o ${OBJECTDIR}/bluetooth.o ${OBJECTDIR}/motor_driver.o ${OBJECTDIR}/pruebas.o ${OBJECTDIR}/start_button.o ${OBJECTDIR}/mux_final.o ${OBJECTDIR}/buzzer.o ${OBJECTDIR}/LDR.o ${OBJECTDIR}/proximity_sensor.o ${OBJECTDIR}/ledmatrix2.o ${OBJECTDIR}/rumba.o ${OBJECTDIR}/gyro.o
POSSIBLE_DEPFILES=${OBJECTDIR}/conf_file.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/mode_selector.o.d ${OBJECTDIR}/bluetooth.o.d ${OBJECTDIR}/motor_driver.o.d ${OBJECTDIR}/pruebas.o.d ${OBJECTDIR}/start_button.o.d ${OBJECTDIR}/mux_final.o.d ${OBJECTDIR}/buzzer.o.d ${OBJECTDIR}/LDR.o.d ${OBJECTDIR}/proximity_sensor.o.d ${OBJECTDIR}/ledmatrix2.o.d ${OBJECTDIR}/rumba.o.d ${OBJECTDIR}/gyro.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/conf_file.o ${OBJECTDIR}/main.o ${OBJECTDIR}/mode_selector.o ${OBJECTDIR}/bluetooth.o ${OBJECTDIR}/motor_driver.o ${OBJECTDIR}/pruebas.o ${OBJECTDIR}/start_button.o ${OBJECTDIR}/mux_final.o ${OBJECTDIR}/buzzer.o ${OBJECTDIR}/LDR.o ${OBJECTDIR}/proximity_sensor.o ${OBJECTDIR}/ledmatrix2.o ${OBJECTDIR}/rumba.o ${OBJECTDIR}/gyro.o

# Source Files
SOURCEFILES=conf_file.c main.c mode_selector.c bluetooth.c motor_driver.c pruebas.c start_button.c mux_final.c buzzer.c LDR.c proximity_sensor.c ledmatrix2.c rumba.c gyro.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Test_Components.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX340F512H
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/conf_file.o: conf_file.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/conf_file.o.d 
	@${RM} ${OBJECTDIR}/conf_file.o 
	@${FIXDEPS} "${OBJECTDIR}/conf_file.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/conf_file.o.d" -o ${OBJECTDIR}/conf_file.o conf_file.c   
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c   
	
${OBJECTDIR}/mode_selector.o: mode_selector.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mode_selector.o.d 
	@${RM} ${OBJECTDIR}/mode_selector.o 
	@${FIXDEPS} "${OBJECTDIR}/mode_selector.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mode_selector.o.d" -o ${OBJECTDIR}/mode_selector.o mode_selector.c   
	
${OBJECTDIR}/bluetooth.o: bluetooth.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bluetooth.o.d 
	@${RM} ${OBJECTDIR}/bluetooth.o 
	@${FIXDEPS} "${OBJECTDIR}/bluetooth.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/bluetooth.o.d" -o ${OBJECTDIR}/bluetooth.o bluetooth.c   
	
${OBJECTDIR}/motor_driver.o: motor_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/motor_driver.o.d 
	@${RM} ${OBJECTDIR}/motor_driver.o 
	@${FIXDEPS} "${OBJECTDIR}/motor_driver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/motor_driver.o.d" -o ${OBJECTDIR}/motor_driver.o motor_driver.c   
	
${OBJECTDIR}/pruebas.o: pruebas.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pruebas.o.d 
	@${RM} ${OBJECTDIR}/pruebas.o 
	@${FIXDEPS} "${OBJECTDIR}/pruebas.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pruebas.o.d" -o ${OBJECTDIR}/pruebas.o pruebas.c   
	
${OBJECTDIR}/start_button.o: start_button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/start_button.o.d 
	@${RM} ${OBJECTDIR}/start_button.o 
	@${FIXDEPS} "${OBJECTDIR}/start_button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/start_button.o.d" -o ${OBJECTDIR}/start_button.o start_button.c   
	
${OBJECTDIR}/mux_final.o: mux_final.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mux_final.o.d 
	@${RM} ${OBJECTDIR}/mux_final.o 
	@${FIXDEPS} "${OBJECTDIR}/mux_final.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mux_final.o.d" -o ${OBJECTDIR}/mux_final.o mux_final.c   
	
${OBJECTDIR}/buzzer.o: buzzer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buzzer.o.d 
	@${RM} ${OBJECTDIR}/buzzer.o 
	@${FIXDEPS} "${OBJECTDIR}/buzzer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/buzzer.o.d" -o ${OBJECTDIR}/buzzer.o buzzer.c   
	
${OBJECTDIR}/LDR.o: LDR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LDR.o.d 
	@${RM} ${OBJECTDIR}/LDR.o 
	@${FIXDEPS} "${OBJECTDIR}/LDR.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LDR.o.d" -o ${OBJECTDIR}/LDR.o LDR.c   
	
${OBJECTDIR}/proximity_sensor.o: proximity_sensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/proximity_sensor.o.d 
	@${RM} ${OBJECTDIR}/proximity_sensor.o 
	@${FIXDEPS} "${OBJECTDIR}/proximity_sensor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/proximity_sensor.o.d" -o ${OBJECTDIR}/proximity_sensor.o proximity_sensor.c   
	
${OBJECTDIR}/ledmatrix2.o: ledmatrix2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ledmatrix2.o.d 
	@${RM} ${OBJECTDIR}/ledmatrix2.o 
	@${FIXDEPS} "${OBJECTDIR}/ledmatrix2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ledmatrix2.o.d" -o ${OBJECTDIR}/ledmatrix2.o ledmatrix2.c   
	
${OBJECTDIR}/rumba.o: rumba.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rumba.o.d 
	@${RM} ${OBJECTDIR}/rumba.o 
	@${FIXDEPS} "${OBJECTDIR}/rumba.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/rumba.o.d" -o ${OBJECTDIR}/rumba.o rumba.c   
	
${OBJECTDIR}/gyro.o: gyro.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/gyro.o.d 
	@${RM} ${OBJECTDIR}/gyro.o 
	@${FIXDEPS} "${OBJECTDIR}/gyro.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/gyro.o.d" -o ${OBJECTDIR}/gyro.o gyro.c   
	
else
${OBJECTDIR}/conf_file.o: conf_file.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/conf_file.o.d 
	@${RM} ${OBJECTDIR}/conf_file.o 
	@${FIXDEPS} "${OBJECTDIR}/conf_file.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/conf_file.o.d" -o ${OBJECTDIR}/conf_file.o conf_file.c   
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c   
	
${OBJECTDIR}/mode_selector.o: mode_selector.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mode_selector.o.d 
	@${RM} ${OBJECTDIR}/mode_selector.o 
	@${FIXDEPS} "${OBJECTDIR}/mode_selector.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mode_selector.o.d" -o ${OBJECTDIR}/mode_selector.o mode_selector.c   
	
${OBJECTDIR}/bluetooth.o: bluetooth.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/bluetooth.o.d 
	@${RM} ${OBJECTDIR}/bluetooth.o 
	@${FIXDEPS} "${OBJECTDIR}/bluetooth.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/bluetooth.o.d" -o ${OBJECTDIR}/bluetooth.o bluetooth.c   
	
${OBJECTDIR}/motor_driver.o: motor_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/motor_driver.o.d 
	@${RM} ${OBJECTDIR}/motor_driver.o 
	@${FIXDEPS} "${OBJECTDIR}/motor_driver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/motor_driver.o.d" -o ${OBJECTDIR}/motor_driver.o motor_driver.c   
	
${OBJECTDIR}/pruebas.o: pruebas.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pruebas.o.d 
	@${RM} ${OBJECTDIR}/pruebas.o 
	@${FIXDEPS} "${OBJECTDIR}/pruebas.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pruebas.o.d" -o ${OBJECTDIR}/pruebas.o pruebas.c   
	
${OBJECTDIR}/start_button.o: start_button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/start_button.o.d 
	@${RM} ${OBJECTDIR}/start_button.o 
	@${FIXDEPS} "${OBJECTDIR}/start_button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/start_button.o.d" -o ${OBJECTDIR}/start_button.o start_button.c   
	
${OBJECTDIR}/mux_final.o: mux_final.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mux_final.o.d 
	@${RM} ${OBJECTDIR}/mux_final.o 
	@${FIXDEPS} "${OBJECTDIR}/mux_final.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mux_final.o.d" -o ${OBJECTDIR}/mux_final.o mux_final.c   
	
${OBJECTDIR}/buzzer.o: buzzer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buzzer.o.d 
	@${RM} ${OBJECTDIR}/buzzer.o 
	@${FIXDEPS} "${OBJECTDIR}/buzzer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/buzzer.o.d" -o ${OBJECTDIR}/buzzer.o buzzer.c   
	
${OBJECTDIR}/LDR.o: LDR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LDR.o.d 
	@${RM} ${OBJECTDIR}/LDR.o 
	@${FIXDEPS} "${OBJECTDIR}/LDR.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LDR.o.d" -o ${OBJECTDIR}/LDR.o LDR.c   
	
${OBJECTDIR}/proximity_sensor.o: proximity_sensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/proximity_sensor.o.d 
	@${RM} ${OBJECTDIR}/proximity_sensor.o 
	@${FIXDEPS} "${OBJECTDIR}/proximity_sensor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/proximity_sensor.o.d" -o ${OBJECTDIR}/proximity_sensor.o proximity_sensor.c   
	
${OBJECTDIR}/ledmatrix2.o: ledmatrix2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ledmatrix2.o.d 
	@${RM} ${OBJECTDIR}/ledmatrix2.o 
	@${FIXDEPS} "${OBJECTDIR}/ledmatrix2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ledmatrix2.o.d" -o ${OBJECTDIR}/ledmatrix2.o ledmatrix2.c   
	
${OBJECTDIR}/rumba.o: rumba.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rumba.o.d 
	@${RM} ${OBJECTDIR}/rumba.o 
	@${FIXDEPS} "${OBJECTDIR}/rumba.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/rumba.o.d" -o ${OBJECTDIR}/rumba.o rumba.c   
	
${OBJECTDIR}/gyro.o: gyro.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/gyro.o.d 
	@${RM} ${OBJECTDIR}/gyro.o 
	@${FIXDEPS} "${OBJECTDIR}/gyro.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/gyro.o.d" -o ${OBJECTDIR}/gyro.o gyro.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Test_Components.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Test_Components.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}           -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Test_Components.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Test_Components.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Test_Components.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
