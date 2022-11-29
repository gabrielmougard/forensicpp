include variables.mk

##################
# BUILD forensicpp
##################

${FORENSICPP_BUILD_CMAKE}:
	$(MKDIR) "${BUILD_RELEASE_DIR}" && \
	echo "Configure CMake with CMAKE_BUILD_TYPE='${BUILD_TYPE}'" && \
	cd "${BUILD_RELEASE_DIR}" && \
	../csm/csm.py ../ && \
	cmake -G Ninja \
		-DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
		-DUSE_LOGS=ON \
		-DEXTERNAL_PROJECT_NUM_JOBS=${NPROC} \
		.

build: ${FORENSICPP_BUILD_CMAKE}
	cd "${BUILD_RELEASE_DIR}" && ninja

build-debug: ${FORENSICPP_BUILD_CMAKE}
	cd "${BUILD_RELEASE_DIR}" && ninja -d explain

run: build
	./"${BUILD_RELEASE_DIR}"/install/forensicpp/bin/forensicpp