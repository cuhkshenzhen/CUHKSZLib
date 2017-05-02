#!/bin/bash

echo 'Setting up the script...'
# Exit with nonzero exit code if anything fails
set -e

DOXYGEN_VER=doxygen-1.8.13
DOXYGEN_TAR=${DOXYGEN_VER}.linux.bin.tar.gz
DOXYGEN_URL="http://ftp.stack.nl/pub/users/dimitri/${DOXYGEN_TAR}"
DOXYGEN_BIN="/usr/local/bin/doxygen"
wget -O - "${DOXYGEN_URL}" | \
		tar xz -C ${TMPDIR-/tmp} ${DOXYGEN_VER}/bin/doxygen
export PATH="${TMPDIR-/tmp}/${DOXYGEN_VER}/bin:$PATH"

################################################################################
##### Generate the Doxygen code documentation and log the output.          #####
echo 'Generating Doxygen code documentation...'
# Redirect both stderr and stdout to the log file AND the console.
doxygen Doxyfile 2>&1 | tee doxygen.log
