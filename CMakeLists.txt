cmake_minimum_required(VERSION 3.9)

project(array_r C)

# Exibindo dados de compilacao
message ( " => Processando ${CMAKE_CURRENT_BINARY_DIR}")
message ( " => Compilador: ${CMAKE_C_COMPILER}")
message ( " => Fonte:      ${PROJECT_SOURCE_DIR}" ) 
message ( " => Binary:     ${PROJECT_BINARY_DIR}/build" )
message ( " => Library:    ${CMAKE_SOURCE_DIR}/lib" )

# Definição dos arquivos
set(SOURCE_FILES
    src/array_reverse.c
)

# Define o modo debug
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE RelWithDebInfo)

# Executavel
add_executable(array_r ${SOURCE_FILES})
# Seta o diretorio de saida
set_target_properties(array_r PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/build")

# Target include always after add_executable
target_include_directories(array_r
    PUBLIC 
        inc/
)


# Add a custom target to make run
add_custom_target(run
    COMMAND array_r
    DEPENDS array_r
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build
)