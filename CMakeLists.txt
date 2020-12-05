cmake_minimum_required(VERSION 3.0.0)
project(c4-wasm VERSION 0.1.0)

include(CTest)
enable_testing()

# -Wall 
# -O1 
# -s WASM=1 
# -s \"EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'UTF8ToString', 'cwrap', 'stringToUTF8Array', 'stringToUTF8', 'allocate', 'intArrayFromString', 'stringToAscii', 'ALLOC_NORMAL']\" 
# -s EXPORT_ES6=1 
# -s MODULARIZE=1 
# -s USE_ES6_IMPORT_META=0 
# -s ASSERTIONS=1 
# -s ALLOW_MEMORY_GROWTH=1 
# -g4 
# --source-map-base http://localhost:8080/www/
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O1 -s WASM=1 -s \"EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'UTF8ToString', 'cwrap', 'stringToUTF8Array', 'stringToUTF8', 'allocate', 'intArrayFromString', 'stringToAscii', 'ALLOC_NORMAL']\" -s EXPORT_ES6=1 -s MODULARIZE=1 -s USE_ES6_IMPORT_META=0 -s ASSERTIONS=1 -s ALLOW_MEMORY_GROWTH=1 -g4 --source-map-base http://localhost:8080/www/")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O1 -s WASM=1 -s \"EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'UTF8ToString', 'cwrap', 'stringToUTF8Array', 'stringToUTF8', 'allocate', 'intArrayFromString', 'stringToAscii', 'ALLOC_NORMAL']\" -s EXPORT_ES6=1 -s MODULARIZE=1 -s USE_ES6_IMPORT_META=0 -s ASSERTIONS=1 -s ALLOW_MEMORY_GROWTH=1 -g4 --source-map-base http://localhost:8080/www/")
add_definitions(-Wall -O1 -s WASM=1 -s \"EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'UTF8ToString', 'cwrap', 'stringToUTF8Array', 'stringToUTF8', 'allocate', 'intArrayFromString', 'stringToAscii', 'ALLOC_NORMAL']\" -s EXPORT_ES6=1 -s MODULARIZE=1 -s USE_ES6_IMPORT_META=0 -s ASSERTIONS=1 -s ALLOW_MEMORY_GROWTH=1 -g4 --source-map-base http://localhost:8080/www/)
add_executable(c4-wasm src/c4-wasm.c src/efiles/efiles.c src/filesystem.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
