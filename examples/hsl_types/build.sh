#!/usr/bin/env bash

set -xe

if [ ! -d "build" ]; then
    mkdir build
fi

pushd build

##### C-project builds #####
# C89
cc -Wall -Wextra -pedantic -std=c89 -I../../../hslibc/ ../c_test.c -o c89-test.out

# C99
cc -Wall -Wextra -pedantic -std=c99 -I../../../hslibc/ ../c_test.c -o c99-test.out
cc -Wall -Wextra -pedantic -std=c11 -I../../../hslibc/ ../c_test.c -o c11-test.out


##### CPP Project Builds #####
# C++98
cc -Wall -Wextra -pedantic -std=c++98 -I../../../hslibc/ ../cpp_test.cpp -o cpp98-test.out

# C++11
cc -Wall -Wextra -pedantic -std=c++11 -I../../../hslibc/ ../cpp_test.cpp -o cpp11-test.out

popd

echo "Run Examples"

for FILE in build/*
do
    ./$FILE
    echo
done
