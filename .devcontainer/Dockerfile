ARG UBUNTU_VARIANT="noble"
FROM ubuntu:${UBUNTU_VARIANT}

ARG UBUNTU_VARIANT
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    apt-utils \
    ca-certificates \
    git \
    gpg-agent \
    gpg \
    libfmt-dev \
    libspdlog-dev \
    nano \
    ninja-build \
    software-properties-common \
    wget

# GCC
ARG GCC_VERSION="14"
RUN add-apt-repository -y ppa:ubuntu-toolchain-r/test && \
    apt-get update && apt-get install -y --no-install-recommends \
        gcc-${GCC_VERSION} \
        g++-${GCC_VERSION} \
        gdb

# Set the installed GCC as the default one
RUN update-alternatives --install /usr/bin/gcc gcc "$(which gcc-${GCC_VERSION})" 100 && \
    update-alternatives --install /usr/bin/g++ g++ "$(which g++-${GCC_VERSION})" 100

# LLVMs
ARG LLVM_VERSION="20"
ARG LLVM_URL="http://apt.llvm.org/${UBUNTU_VARIANT}/"
ARG LLVM_PKG="llvm-toolchain-${UBUNTU_VARIANT}-${LLVM_VERSION}"
ARG LLVM_REPO="deb ${LLVM_URL} ${LLVM_PKG} main"

RUN wget -qO- https://apt.llvm.org/llvm-snapshot.gpg.key | tee /etc/apt/trusted.gpg.d/apt.llvm.org.asc && \
    add-apt-repository -y ${LLVM_REPO} && \
    apt-get update && apt-get install -y --no-install-recommends \
        clang-${LLVM_VERSION} \
        lldb-${LLVM_VERSION} \
        lld-${LLVM_VERSION} \
        clangd-${LLVM_VERSION} \
        clang-tidy-${LLVM_VERSION} \
        clang-format-${LLVM_VERSION}

# Set the installed LLVM tools as the default ones
RUN update-alternatives --install /usr/bin/clang clang "$(which clang-${LLVM_VERSION})" 100 && \
    update-alternatives --install /usr/bin/clang++ clang++ "$(which clang++-${LLVM_VERSION})" 100 && \
    update-alternatives --install /usr/bin/clang-tidy clang-tidy "$(which clang-tidy-${LLVM_VERSION})" 1 && \
    update-alternatives --install /usr/bin/clang-format clang-format "$(which clang-format-${LLVM_VERSION})" 1

# CMake
# (don't use single quotes like in the official docs, otherwise the env won't expand)
ARG CMAKE_URL="https://apt.kitware.com/ubuntu/"
ARG CMAKE_REPO="deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] ${CMAKE_URL} ${UBUNTU_VARIANT} main"
RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | tee /usr/share/keyrings/kitware-archive-keyring.gpg >/dev/null && \
    echo ${CMAKE_REPO} | tee /etc/apt/sources.list.d/kitware.list >/dev/null && \
    apt-get update && \
    rm /usr/share/keyrings/kitware-archive-keyring.gpg && \
    apt-get install -y --no-install-recommends \
        kitware-archive-keyring \
        cmake \
        cmake-curses-gui

RUN apt-get autoremove -y && apt-get clean
