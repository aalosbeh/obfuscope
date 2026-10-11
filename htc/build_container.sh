#!/usr/bin/env bash
# Build the ObfuScope container and stage it on the OSDF for the OSPool.
#
# Prereqs: apptainer (or docker) on the access point, and write access to your
# OSDF namespace, typically /ospool/ap40/data/$USER on the OSPool.
set -euo pipefail

USER_NS="${OSDF_USER_NS:-/ospool/ap40/data/${USER}}"
IMG="obfuscope.sif"

echo ">> Building Apptainer image ${IMG} from Dockerfile"
# Apptainer can build directly from a Dockerfile-style def or from a docker daemon.
if command -v apptainer >/dev/null; then
    apptainer build "${IMG}" "docker-daemon://obfuscope:latest" \
        2>/dev/null || apptainer build "${IMG}" apptainer.def
else
    echo "apptainer not found; build the Docker image and push to a registry instead"
    exit 1
fi

echo ">> Staging ${IMG} to OSDF origin at ${USER_NS}/"
# On the OSPool access points the OSDF namespace is a normal path; a plain copy
# publishes the image to the distributed cache used by execution points.
mkdir -p "${USER_NS}"
cp -f "${IMG}" "${USER_NS}/${IMG}"

echo ">> Done. Reference it in submit files as:"
echo "   container_image = osdf://${USER_NS}/${IMG}"
