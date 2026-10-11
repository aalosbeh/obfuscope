# VERSION 1 LEGACY: this recipe pins a version 1 software stack, not the environment of record in requirements.txt, and does not reproduce the article's tables.
# ObfuScope execution environment for the OSPool / CHTC.
#
# Build locally, push to a registry, then convert to a .sif that is staged on the
# OSDF (see build_container.sh). The image is intentionally small and pinned so
# that every one of the thousands of execution-point jobs runs an identical,
# reproducible software stack.
FROM python:3.11-slim

LABEL org.opencontainers.image.title="obfuscope" \
      org.opencontainers.image.description="Static obfuscation-provenance experiments" \
      org.opencontainers.image.licenses="MIT"

ENV PYTHONDONTWRITEBYTECODE=1 \
    PYTHONUNBUFFERED=1 \
    PIP_NO_CACHE_DIR=1

# Pinned scientific stack. Versions match environment.yml / requirements.txt so
# that laptop and cluster results are byte-for-byte comparable.
RUN pip install --no-cache-dir \
        "numpy==2.2.6" \
        "scipy==1.15.3" \
        "pandas==2.2.3" \
        "scikit-learn==1.7.2" \
        "pyarrow==17.0.0" \
        "matplotlib==3.9.2"

# The obfuscope package is shipped with each job via transfer_input_files, so it
# is not baked into the image; this keeps the image stable while code iterates.
WORKDIR /srv/obfuscope
CMD ["python3", "-c", "import sklearn, pandas, numpy; print('obfuscope env ready')"]
