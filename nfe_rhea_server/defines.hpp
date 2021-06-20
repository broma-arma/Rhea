////////////////////////////////////////////////////////////////////////////////
//                                   Config                                   //
////////////////////////////////////////////////////////////////////////////////

// Version
	#define MAJOR 0
	#define MINOR 83
	#define PATCHLVL 3
	#define BUILD 0

	#define REQUIRED_VERSION 1.98

// Logging
	#define NAME RHEA.Server

	// Enable/Disable logging per error level. (Comment define to stop logging of that error level)
	//#define LOG_LEVEL_TRACE 1
	//#define LOG_LEVEL_DEBUG 1
	#define LOG_LEVEL_INFO 1
	#define LOG_LEVEL_WARNING 1
	#define LOG_LEVEL_ERROR 1

	// Cause log to also be sent to systemChat.
	//#define LOG_TO_SYSTEMCHAT 1

// Development
	// Enables function recompiling
	//#define RECOMPILE 1

////////////////////////////////////////////////////////////////////////////////

#ifdef LOG_TO_SYSTEMCHAT
	#define LOG(LEVEL, MESSAGE) call { private _msg = format ['[%1] %2: %3', 'NAME', LEVEL, MESSAGE]; systemChat _msg; diag_log text _msg; }
#else
	#define LOG(LEVEL, MESSAGE) diag_log text format ['[%1] %2: %3', 'NAME', LEVEL, MESSAGE]
#endif

// If only we had __VA_ARGS__...
#ifdef LOG_LEVEL_TRACE
	#define TRACE(MESSAGE) LOG('TRACE', FORMAT_3('%1 @%2:%3', MESSAGE, __LINE__ + 1, __FILE__))
	#define TRACE_1(MESSAGE,ARG1) TRACE(FORMAT_1(MESSAGE,ARG1))
	#define TRACE_2(MESSAGE,ARG1,ARG2) TRACE(FORMAT_2(MESSAGE,ARG1,ARG2))
	#define TRACE_3(MESSAGE,ARG1,ARG2,ARG3) TRACE(FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
	#define TRACE_4(MESSAGE,ARG1,ARG2,ARG3,ARG4) TRACE(FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
	#define TRACE_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) TRACE(FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
	#define TRACE_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) TRACE(FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
	#define TRACE_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) TRACE(FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
	#define TRACE_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) TRACE(FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))
#else
	#define TRACE(MESSAGE)
	#define TRACE_1(MESSAGE,ARG1)
	#define TRACE_2(MESSAGE,ARG1,ARG2)
	#define TRACE_3(MESSAGE,ARG1,ARG2,ARG3)
	#define TRACE_4(MESSAGE,ARG1,ARG2,ARG3,ARG4)
	#define TRACE_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5)
	#define TRACE_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)
	#define TRACE_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)
	#define TRACE_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8)
#endif
#ifdef LOG_LEVEL_DEBUG
	#define DEBUG(MESSAGE) LOG('DEBUG', MESSAGE)
	#define DEBUG_1(MESSAGE,ARG1) DEBUG(FORMAT_1(MESSAGE,ARG1))
	#define DEBUG_2(MESSAGE,ARG1,ARG2) DEBUG(FORMAT_2(MESSAGE,ARG1,ARG2))
	#define DEBUG_3(MESSAGE,ARG1,ARG2,ARG3) DEBUG(FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
	#define DEBUG_4(MESSAGE,ARG1,ARG2,ARG3,ARG4) DEBUG(FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
	#define DEBUG_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) DEBUG(FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
	#define DEBUG_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) DEBUG(FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
	#define DEBUG_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) DEBUG(FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
	#define DEBUG_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) DEBUG(FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))
#else
	#define DEBUG(MESSAGE)
	#define DEBUG_1(MESSAGE,ARG1)
	#define DEBUG_2(MESSAGE,ARG1,ARG2)
	#define DEBUG_3(MESSAGE,ARG1,ARG2,ARG3)
	#define DEBUG_4(MESSAGE,ARG1,ARG2,ARG3,ARG4)
	#define DEBUG_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5)
	#define DEBUG_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)
	#define DEBUG_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)
	#define DEBUG_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8)
#endif
#ifdef LOG_LEVEL_INFO
	#define INFO(MESSAGE) LOG('INFO ', MESSAGE)
	#define INFO_1(MESSAGE,ARG1) INFO(FORMAT_1(MESSAGE,ARG1))
	#define INFO_2(MESSAGE,ARG1,ARG2) INFO(FORMAT_2(MESSAGE,ARG1,ARG2))
	#define INFO_3(MESSAGE,ARG1,ARG2,ARG3) INFO(FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
	#define INFO_4(MESSAGE,ARG1,ARG2,ARG3,ARG4) INFO(FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
	#define INFO_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) INFO(FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
	#define INFO_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) INFO(FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
	#define INFO_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) INFO(FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
	#define INFO_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) INFO(FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))
#else
	#define INFO(MESSAGE)
	#define INFO_1(MESSAGE,ARG1)
	#define INFO_2(MESSAGE,ARG1,ARG2)
	#define INFO_3(MESSAGE,ARG1,ARG2,ARG3)
	#define INFO_4(MESSAGE,ARG1,ARG2,ARG3,ARG4)
	#define INFO_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5)
	#define INFO_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)
	#define INFO_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)
	#define INFO_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8)
#endif
#ifdef LOG_LEVEL_WARNING
	#define WARNING(MESSAGE) LOG('WARN ', MESSAGE)
	#define WARNING_1(MESSAGE,ARG1) WARNING(FORMAT_1(MESSAGE,ARG1))
	#define WARNING_2(MESSAGE,ARG1,ARG2) WARNING(FORMAT_2(MESSAGE,ARG1,ARG2))
	#define WARNING_3(MESSAGE,ARG1,ARG2,ARG3) WARNING(FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
	#define WARNING_4(MESSAGE,ARG1,ARG2,ARG3,ARG4) WARNING(FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
	#define WARNING_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) WARNING(FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
	#define WARNING_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) WARNING(FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
	#define WARNING_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) WARNING(FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
	#define WARNING_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) WARNING(FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))
#else
	#define WARNING(MESSAGE)
	#define WARNING_1(MESSAGE,ARG1)
	#define WARNING_2(MESSAGE,ARG1,ARG2)
	#define WARNING_3(MESSAGE,ARG1,ARG2,ARG3)
	#define WARNING_4(MESSAGE,ARG1,ARG2,ARG3,ARG4)
	#define WARNING_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5)
	#define WARNING_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)
	#define WARNING_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)
	#define WARNING_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8)
#endif
#ifdef LOG_LEVEL_ERROR
	#define ERROR(MESSAGE) LOG('ERROR ', MESSAGE)
	#define ERROR_1(MESSAGE,ARG1) ERROR(FORMAT_1(MESSAGE,ARG1))
	#define ERROR_2(MESSAGE,ARG1,ARG2) ERROR(FORMAT_2(MESSAGE,ARG1,ARG2))
	#define ERROR_3(MESSAGE,ARG1,ARG2,ARG3) ERROR(FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
	#define ERROR_4(MESSAGE,ARG1,ARG2,ARG3,ARG4) ERROR(FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
	#define ERROR_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) ERROR(FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
	#define ERROR_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) ERROR(FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
	#define ERROR_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) ERROR(FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
	#define ERROR_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) ERROR(FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))
#else
	#define ERROR(MESSAGE)
	#define ERROR_1(MESSAGE,ARG1)
	#define ERROR_2(MESSAGE,ARG1,ARG2)
	#define ERROR_3(MESSAGE,ARG1,ARG2,ARG3)
	#define ERROR_4(MESSAGE,ARG1,ARG2,ARG3,ARG4)
	#define ERROR_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5)
	#define ERROR_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)
	#define ERROR_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)
	#define ERROR_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8)
#endif

#define ARR_1(ARG1) ARG1
#define ARR_2(ARG1,ARG2) ARG1, ARG2
#define ARR_3(ARG1,ARG2,ARG3) ARG1, ARG2, ARG3
#define ARR_4(ARG1,ARG2,ARG3,ARG4) ARG1, ARG2, ARG3, ARG4
#define ARR_5(ARG1,ARG2,ARG3,ARG4,ARG5) ARG1, ARG2, ARG3, ARG4, ARG5
#define ARR_6(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6
#define ARR_7(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7
#define ARR_8(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8

#define FORMAT_1(STR,ARG1) format[STR, ARG1]
#define FORMAT_2(STR,ARG1,ARG2) format[STR, ARG1, ARG2]
#define FORMAT_3(STR,ARG1,ARG2,ARG3) format[STR, ARG1, ARG2, ARG3]
#define FORMAT_4(STR,ARG1,ARG2,ARG3,ARG4) format[STR, ARG1, ARG2, ARG3, ARG4]
#define FORMAT_5(STR,ARG1,ARG2,ARG3,ARG4,ARG5) format[STR, ARG1, ARG2, ARG3, ARG4, ARG5]
#define FORMAT_6(STR,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) format[STR, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6]
#define FORMAT_7(STR,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) format[STR, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7]
#define FORMAT_8(STR,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) format[STR, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8]

#define QUOTE(ARG1) #ARG1

#define VERSION     MAJOR.MINOR
#define VERSION_STR MAJOR.MINOR.PATCHLVL.BUILD
#define VERSION_AR  MAJOR,MINOR,PATCHLVL,BUILD

#define VERSION_CONFIG version = VERSION; versionStr = QUOTE(VERSION_STR); versionAr[] = {VERSION_AR}

#ifdef RECOMPILE
	#undef RECOMPILE
	#define RECOMPILE recompile = 1
#else
	#define RECOMPILE recompile = 0
#endif
