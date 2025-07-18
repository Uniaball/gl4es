cmake_minimum_required(VERSION 3.10)

project(gl4es)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden -funwind-tables -g -D_THREAD_SAFE -fPIC -stdlib=libc++")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DANDROID -Wno-pointer-sign -Wno-macro-redefined -Wno-dangling-else -Wno-implicit-const-int-float-conversion -DNOX11 -fPIC -DNO_GBM -DDEFAULT_ES=3 -g -funwind-tables -O3 -fvisibility=hidden")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++")

set(CMAKE_ANDROID_STL_TYPE c++_static)

set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(C_SRC_FILES
        src/gl/string_utils.c
        src/gl/arbconverter.c
        src/gl/arbgenerator.c
        src/gl/arbhelper.c
        src/gl/arbparser.c
        src/gl/array.c
        src/gl/blend.c
        src/gl/blit.c
        src/gl/buffers.c
        src/gl/build_info.c
        src/gl/debug.c
        src/gl/decompress.c
        src/gl/depth.c
        src/gl/directstate.c
        src/gl/drawing.c
        src/gl/enable.c
        src/gl/envvars.c
        src/gl/eval.c
        src/gl/face.c
        src/gl/fog.c
        src/gl/fpe.c
        src/gl/fpe_cache.c
        src/gl/fpe_shader.c
        src/gl/framebuffers.c
        src/gl/getter.c
        src/gl/gl_lookup.c
        src/gl/gl4es.c
        src/gl/glstate.c
        src/gl/hint.c
        src/gl/init.c
        src/gl/light.c
        src/gl/line.c
        src/gl/list.c
        src/gl/listdraw.c
        src/gl/listrl.c
        src/gl/loader.c
        src/gl/logs.c
        src/gl/matrix.c
        src/gl/matvec.c
        src/gl/oldprogram.c
        src/gl/pixel.c
        src/gl/planes.c
        src/gl/pointsprite.c
        src/gl/preproc.c
        src/gl/program.c
        src/gl/queries.c
        src/gl/raster.c
        src/gl/render.c
        src/gl/shader.c
        src/gl/shaderconv.c
        src/gl/shader_hacks.c
        src/gl/stack.c
        src/gl/stencil.c
        src/gl/stubs.c
        src/gl/texenv.c
        src/gl/texgen.c
        src/gl/texture.c
        src/gl/texture_compressed.c
        src/gl/texture_params.c
        src/gl/texture_read.c
        src/gl/texture_3d.c
        src/gl/uniform.c
        src/gl/vertexattrib.c
        src/gl/wrap/gl4eswraps.c
        src/gl/wrap/gles.c
        src/gl/wrap/glstub.c
        src/gl/math/matheval.c
        src/glx/hardext.c
        src/glx/glx.c
        src/glx/lookup.c
        src/glx/gbm.c
        src/glx/streaming.c
        src/gl/vgpu/shaderconv.c
        src/gl/samplers.c
        )

set(CPP_SRC_FILES
        src/glsl/glsl_for_es.cpp
        )

set(SRC_FILES ${CPP_SRC_FILES} ${C_SRC_FILES})

find_library(GLSLANG_LIB glslang PATHS ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/)

add_library(gl4es SHARED ${SRC_FILES})

target_link_libraries(gl4es
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libglslang.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libspirv-cross-c-shared.so
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libSPIRV-Tools.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libSPIRV-Tools-diff.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libSPIRV-Tools-link.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libSPIRV-Tools-lint.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libSPIRV-Tools-opt.a
        ${CMAKE_SOURCE_DIR}/libraries/${ANDROID_ABI}/libSPIRV-Tools-reduce.a
        c
        c++_static
        c++abi
        dl
        )

target_include_directories(gl4es PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        )
