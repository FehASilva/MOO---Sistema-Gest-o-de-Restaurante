# Gera automaticamente os arquivos fonte da pasta src
file(GLOB SRC_SOURCES "*.cpp" classes/*.cpp usecases/*.cpp)

# Adiciona os arquivos como biblioteca
add_library(src ${SRC_SOURCES})
