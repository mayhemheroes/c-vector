FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y cmake clang
    
ADD . /c-vector
WORKDIR /c-vector

RUN mkdir -p build
WORKDIR build
RUN CC=clang CXX=clang++ cmake .. -DBUILD_FUZZER=1
RUN make


FROM --platform=linux/amd64 ubuntu:20.04
COPY --from=builder /c-vector/build/c-vector-fuzzer /

CMD /c-vector-fuzzer
