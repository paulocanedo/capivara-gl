#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Action.o \
	${OBJECTDIR}/StringTokenizer.o \
	${OBJECTDIR}/Panel.o \
	${OBJECTDIR}/CheckBoxButton.o \
	${OBJECTDIR}/Label.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Component.o \
	${OBJECTDIR}/Button.o \
	${OBJECTDIR}/RadioButton.o \
	${OBJECTDIR}/GroupButtonControl.o \
	${OBJECTDIR}/RootContainer.o \
	${OBJECTDIR}/FontManager.o \
	${OBJECTDIR}/Graphics.o \
	${OBJECTDIR}/Image.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lGL -lglfw `pkg-config --libs freetype2` `pkg-config --libs ftgl` -lpng  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/capivara-gl

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/capivara-gl: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/capivara-gl ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Action.o: Action.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags freetype2` `pkg-config --cflags ftgl` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/Action.o Action.cpp

${OBJECTDIR}/StringTokenizer.o: StringTokenizer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags freetype2` `pkg-config --cflags ftgl` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/StringTokenizer.o StringTokenizer.cpp

${OBJECTDIR}/Panel.o: Panel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags freetype2` `pkg-config --cflags ftgl` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/Panel.o Panel.cpp

${OBJECTDIR}/CheckBoxButton.o: CheckBoxButton.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags freetype2` `pkg-config --cflags ftgl` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/CheckBoxButton.o CheckBoxButton.cpp

${OBJECTDIR}/Label.o: Label.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags freetype2` `pkg-config --cflags ftgl` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/Label.o Label.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags freetype2` `pkg-config --cflags ftgl` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Component.o: Component.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags freetype2` `pkg-config --cflags ftgl` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/Component.o Component.cpp

${OBJECTDIR}/Button.o: Button.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags freetype2` `pkg-config --cflags ftgl` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/Button.o Button.cpp

${OBJECTDIR}/RadioButton.o: RadioButton.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags freetype2` `pkg-config --cflags ftgl` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/RadioButton.o RadioButton.cpp

${OBJECTDIR}/GroupButtonControl.o: GroupButtonControl.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags freetype2` `pkg-config --cflags ftgl` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/GroupButtonControl.o GroupButtonControl.cpp

${OBJECTDIR}/RootContainer.o: RootContainer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags freetype2` `pkg-config --cflags ftgl` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/RootContainer.o RootContainer.cpp

${OBJECTDIR}/FontManager.o: FontManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags freetype2` `pkg-config --cflags ftgl` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/FontManager.o FontManager.cpp

${OBJECTDIR}/Graphics.o: Graphics.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags freetype2` `pkg-config --cflags ftgl` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/Graphics.o Graphics.cpp

${OBJECTDIR}/Image.o: Image.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags freetype2` `pkg-config --cflags ftgl` -std=c++11   -MMD -MP -MF $@.d -o ${OBJECTDIR}/Image.o Image.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/capivara-gl

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
