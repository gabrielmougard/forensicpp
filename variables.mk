# Copyright 2022 gab
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

########
# Utils
########

MKDIR=mkdir -p

########
# Paths
########

BUILD_RELEASE_DIR:=./build_release

BUILD_TYPE:=RELEASE
ARCH:=$(shell uname -m)

UNAME:=$(shell uname)
NPROC:=1
ifeq ($(UNAME),Darwin)
    NPROC:=$(shell sysctl -n hw.ncpu)
else
    NPROC:=$(shell nproc)
endif

############
# FORENSICPP
############
FORENSICPP_BUILD_CMAKE:=${BUILD_RELEASE_DIR}/CMakeLists.txt