FROM debian:stable-slim

WORKDIR /app

RUN apt-get update && apt-get install -y \
    make \
    gcc \
    libreadline-dev \
    valgrind

CMD /bin/bash
