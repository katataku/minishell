FROM debian:stable-slim

WORKDIR /app

RUN apt-get update && apt-get install -y \
    cmake \
    make \
    gcc \
    googletest \
    g++ \
    libreadline-dev \
    python3-pip \
    valgrind

# GoogleTestsのインストール
# REF: https://stackoverflow.com/questions/24295876/cmake-cannot-find-googletest-required-library-in-ubuntu
RUN (cd /usr/src/googletest && cmake . && cmake --build . --target install)

RUN pip install norminette==3.3.2

CMD /bin/bash
