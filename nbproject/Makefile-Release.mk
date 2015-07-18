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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AbstractExpNode.o \
	${OBJECTDIR}/AbstractOperator.o \
	${OBJECTDIR}/ActiveNode.o \
	${OBJECTDIR}/Addition.o \
	${OBJECTDIR}/CppADSolver.o \
	${OBJECTDIR}/Division.o \
	${OBJECTDIR}/ExpNodeADNumber.o \
	${OBJECTDIR}/Exponential.o \
	${OBJECTDIR}/Logarithm.o \
	${OBJECTDIR}/Multiplication.o \
	${OBJECTDIR}/OptProblem.o \
	${OBJECTDIR}/OptStructure.o \
	${OBJECTDIR}/PassiveNode.o \
	${OBJECTDIR}/Power.o \
	${OBJECTDIR}/PyVariable.o \
	${OBJECTDIR}/Subtraction.o \
	${OBJECTDIR}/TempNode.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1

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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcppad_ipopt_solver.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcppad_ipopt_solver.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcppad_ipopt_solver.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/AbstractExpNode.o: AbstractExpNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractExpNode.o AbstractExpNode.cpp

${OBJECTDIR}/AbstractOperator.o: AbstractOperator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractOperator.o AbstractOperator.cpp

${OBJECTDIR}/ActiveNode.o: ActiveNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ActiveNode.o ActiveNode.cpp

${OBJECTDIR}/Addition.o: Addition.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Addition.o Addition.cpp

${OBJECTDIR}/CppADSolver.o: CppADSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CppADSolver.o CppADSolver.cpp

${OBJECTDIR}/Division.o: Division.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Division.o Division.cpp

${OBJECTDIR}/ExpNodeADNumber.o: ExpNodeADNumber.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExpNodeADNumber.o ExpNodeADNumber.cpp

${OBJECTDIR}/Exponential.o: Exponential.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Exponential.o Exponential.cpp

${OBJECTDIR}/Logarithm.o: Logarithm.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Logarithm.o Logarithm.cpp

${OBJECTDIR}/Multiplication.o: Multiplication.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Multiplication.o Multiplication.cpp

${OBJECTDIR}/OptProblem.o: OptProblem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OptProblem.o OptProblem.cpp

${OBJECTDIR}/OptStructure.o: OptStructure.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OptStructure.o OptStructure.cpp

${OBJECTDIR}/PassiveNode.o: PassiveNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PassiveNode.o PassiveNode.cpp

${OBJECTDIR}/Power.o: Power.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Power.o Power.cpp

${OBJECTDIR}/PyVariable.o: PyVariable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PyVariable.o PyVariable.cpp

${OBJECTDIR}/Subtraction.o: Subtraction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Subtraction.o Subtraction.cpp

${OBJECTDIR}/TempNode.o: TempNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TempNode.o TempNode.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/OperatorTests.o ${TESTDIR}/tests/OperatorTestsRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/OptimizationTests.o ${TESTDIR}/tests/OptimizationTestsRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/OptProbelmTests.o ${TESTDIR}/tests/OptProbelmTestsRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/ExpNodeTests.o ${TESTDIR}/tests/PackageTestsRunner.o ${TESTDIR}/tests/PyVariableTests.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/tests/OperatorTests.o: tests/OperatorTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/OperatorTests.o tests/OperatorTests.cpp


${TESTDIR}/tests/OperatorTestsRunner.o: tests/OperatorTestsRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/OperatorTestsRunner.o tests/OperatorTestsRunner.cpp


${TESTDIR}/tests/OptimizationTests.o: tests/OptimizationTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/OptimizationTests.o tests/OptimizationTests.cpp


${TESTDIR}/tests/OptimizationTestsRunner.o: tests/OptimizationTestsRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/OptimizationTestsRunner.o tests/OptimizationTestsRunner.cpp


${TESTDIR}/tests/OptProbelmTests.o: tests/OptProbelmTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/OptProbelmTests.o tests/OptProbelmTests.cpp


${TESTDIR}/tests/OptProbelmTestsRunner.o: tests/OptProbelmTestsRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/OptProbelmTestsRunner.o tests/OptProbelmTestsRunner.cpp


${TESTDIR}/tests/ExpNodeTests.o: tests/ExpNodeTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ExpNodeTests.o tests/ExpNodeTests.cpp


${TESTDIR}/tests/PackageTestsRunner.o: tests/PackageTestsRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/PackageTestsRunner.o tests/PackageTestsRunner.cpp


${TESTDIR}/tests/PyVariableTests.o: tests/PyVariableTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/PyVariableTests.o tests/PyVariableTests.cpp


${OBJECTDIR}/AbstractExpNode_nomain.o: ${OBJECTDIR}/AbstractExpNode.o AbstractExpNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/AbstractExpNode.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractExpNode_nomain.o AbstractExpNode.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/AbstractExpNode.o ${OBJECTDIR}/AbstractExpNode_nomain.o;\
	fi

${OBJECTDIR}/AbstractOperator_nomain.o: ${OBJECTDIR}/AbstractOperator.o AbstractOperator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/AbstractOperator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractOperator_nomain.o AbstractOperator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/AbstractOperator.o ${OBJECTDIR}/AbstractOperator_nomain.o;\
	fi

${OBJECTDIR}/ActiveNode_nomain.o: ${OBJECTDIR}/ActiveNode.o ActiveNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ActiveNode.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ActiveNode_nomain.o ActiveNode.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ActiveNode.o ${OBJECTDIR}/ActiveNode_nomain.o;\
	fi

${OBJECTDIR}/Addition_nomain.o: ${OBJECTDIR}/Addition.o Addition.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Addition.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Addition_nomain.o Addition.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Addition.o ${OBJECTDIR}/Addition_nomain.o;\
	fi

${OBJECTDIR}/CppADSolver_nomain.o: ${OBJECTDIR}/CppADSolver.o CppADSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/CppADSolver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CppADSolver_nomain.o CppADSolver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/CppADSolver.o ${OBJECTDIR}/CppADSolver_nomain.o;\
	fi

${OBJECTDIR}/Division_nomain.o: ${OBJECTDIR}/Division.o Division.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Division.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Division_nomain.o Division.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Division.o ${OBJECTDIR}/Division_nomain.o;\
	fi

${OBJECTDIR}/ExpNodeADNumber_nomain.o: ${OBJECTDIR}/ExpNodeADNumber.o ExpNodeADNumber.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ExpNodeADNumber.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExpNodeADNumber_nomain.o ExpNodeADNumber.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ExpNodeADNumber.o ${OBJECTDIR}/ExpNodeADNumber_nomain.o;\
	fi

${OBJECTDIR}/Exponential_nomain.o: ${OBJECTDIR}/Exponential.o Exponential.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Exponential.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Exponential_nomain.o Exponential.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Exponential.o ${OBJECTDIR}/Exponential_nomain.o;\
	fi

${OBJECTDIR}/Logarithm_nomain.o: ${OBJECTDIR}/Logarithm.o Logarithm.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Logarithm.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Logarithm_nomain.o Logarithm.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Logarithm.o ${OBJECTDIR}/Logarithm_nomain.o;\
	fi

${OBJECTDIR}/Multiplication_nomain.o: ${OBJECTDIR}/Multiplication.o Multiplication.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Multiplication.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Multiplication_nomain.o Multiplication.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Multiplication.o ${OBJECTDIR}/Multiplication_nomain.o;\
	fi

${OBJECTDIR}/OptProblem_nomain.o: ${OBJECTDIR}/OptProblem.o OptProblem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/OptProblem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OptProblem_nomain.o OptProblem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/OptProblem.o ${OBJECTDIR}/OptProblem_nomain.o;\
	fi

${OBJECTDIR}/OptStructure_nomain.o: ${OBJECTDIR}/OptStructure.o OptStructure.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/OptStructure.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OptStructure_nomain.o OptStructure.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/OptStructure.o ${OBJECTDIR}/OptStructure_nomain.o;\
	fi

${OBJECTDIR}/PassiveNode_nomain.o: ${OBJECTDIR}/PassiveNode.o PassiveNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/PassiveNode.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PassiveNode_nomain.o PassiveNode.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/PassiveNode.o ${OBJECTDIR}/PassiveNode_nomain.o;\
	fi

${OBJECTDIR}/Power_nomain.o: ${OBJECTDIR}/Power.o Power.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Power.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Power_nomain.o Power.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Power.o ${OBJECTDIR}/Power_nomain.o;\
	fi

${OBJECTDIR}/PyVariable_nomain.o: ${OBJECTDIR}/PyVariable.o PyVariable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/PyVariable.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PyVariable_nomain.o PyVariable.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/PyVariable.o ${OBJECTDIR}/PyVariable_nomain.o;\
	fi

${OBJECTDIR}/Subtraction_nomain.o: ${OBJECTDIR}/Subtraction.o Subtraction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Subtraction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Subtraction_nomain.o Subtraction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Subtraction.o ${OBJECTDIR}/Subtraction_nomain.o;\
	fi

${OBJECTDIR}/TempNode_nomain.o: ${OBJECTDIR}/TempNode.o TempNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/TempNode.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TempNode_nomain.o TempNode.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/TempNode.o ${OBJECTDIR}/TempNode_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcppad_ipopt_solver.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
