FROM debian:bookworm-slim AS builder

RUN apt update && \
    apt-get install -y build-essential && \
    apt-get install -y zlib1g-dev && \
    apt-get install -y openssl libssl-dev && \
    apt-get install -y cmake && \
    apt-get install -y git

WORKDIR /app

RUN mkdir -p /app/lib/DPP && \
    git clone https://github.com/brainboxdotcc/DPP.git /app/lib/DPP

ADD CMakeLists.txt /app/CMakeLists.txt
ADD src /app/src

RUN cmake -B /app/cmake-build -G "Unix Makefiles"
RUN cd /app/cmake-build && \
    make

ENTRYPOINT [ "/app/cmake-build/ConcordBot" ]
