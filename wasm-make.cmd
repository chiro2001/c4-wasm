call D:\\gits\\emsdk\\emsdk.bat construct_env 
@REM emcc -o www/gaokao-admission-emulator.js source/admission_operations.c source/main.c source/file_operations.c source/efiles/efiles.c source/merge_sort.c -Wall -O1 -s WASM=1 -s \"EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'UTF8ToString', 'cwrap', 'stringToUTF8Array', 'stringToUTF8', 'allocate', 'intArrayFromString', 'stringToAscii', 'ALLOC_NORMAL']\" -s EXPORT_ES6=1 -s MODULARIZE=1 -s USE_ES6_IMPORT_META=0 -s ASSERTIONS=1 -s ALLOW_MEMORY_GROWTH=1 -g4 --source-map-base http://localhost:8080/www/
@REM emcmake cmake .
@REM cmake . -DCMAKE_TOOLCHAIN_FILE=D:\gits\emsdk\upstream\emscripten\cmake\Modules\Platform\Emscripten.cmake -DCMAKE_CROSSCOMPILING_EMULATOR="D:/gits/emsdk/node/12.18.1_64bit/bin/node.exe" -G "MinGW Makefiles"

@REM cd build-wasm
@REM make
@REM cd ..

call emcc -o build-wasm\c4-wasm.js src/c4-wasm.c src/efiles/efiles.c src/filesystem.c -Wall -O1 -s WASM=1 -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'UTF8ToString', 'cwrap', 'stringToUTF8Array', 'stringToUTF8', 'allocate', 'intArrayFromString', 'stringToAscii', 'ALLOC_NORMAL']" -s EXPORT_ES6=1 -s MODULARIZE=1 -s USE_ES6_IMPORT_META=0 -s ASSERTIONS=1 -s ALLOW_MEMORY_GROWTH=1 -g4 --source-map-base .
@REM http://localhost:8080/www/

copy build-wasm\c4-wasm.js www\c4-wasm.js
copy build-wasm\c4-wasm.wasm www\c4-wasm.wasm
if exist build-wasm\c4-wasm.wasm.map (
  copy build-wasm\c4-wasm.wasm.map www\c4-wasm.wasm.map
)
@REM start server 8080
@REM start http://localhost:8080/www/index.html