FROM mcr.microsoft.com/devcontainers/cpp:0-ubuntu-22.04

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="3.22.2"

# Optionally install the cmake for vcpkg
COPY ./reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
        chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh

# Add googletest and cmake 
RUN apt-get update && apt-get install -y build-essential libgtest-dev

# Add norminette
RUN apt-get install -y python3-pip python3-setuptools && python3 -m pip install --upgrade pip setuptools && pip3 install norminette

# Install ctest
RUN apt-get install -y cmake

# 42-formatter
RUN pip install c_formatter_42

# Install gcovr for code coverage
RUN pip install gcovr


# Prepare test environement
# RUN cmake --no-warn-unused-cli -Dgtest_build_samples:STRING=ON -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/g++ -S/workspaces/Piscine-42 -B/workspaces/Piscine-42/build -G Ninja

# [Optional] Uncomment this section to install additional vcpkg ports.
# RUN su vscode -c "${VCPKG_ROOT}/vcpkg install <your-port-name-here>"

# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>
