set(POCO_EXENAME "PageCompiler")

# Sources
file(GLOB SRCS_G "src/*.cpp")
POCO_SOURCES_AUTO(SRCS ${SRCS_G})

add_executable(PageCompiler ${SRCS})
set_target_properties(PageCompiler
	PROPERTIES
	OUTPUT_NAME cpspc
)

target_link_libraries(PageCompiler PUBLIC Poco::Net Poco::Util)

install(
	TARGETS PageCompiler EXPORT PageCompilerTargets
	LIBRARY DESTINATION lib${LIB_SUFFIX}
	ARCHIVE DESTINATION lib${LIB_SUFFIX}
	RUNTIME DESTINATION bin
	INCLUDES DESTINATION include
)
