#! /bin/bash

echo "Cleaning"
make clean 1>&2 > /dev/null
echo "Compiling"
make 1>&2 > /dev/null
compiled=$?

if [[ $compiled -ne 0 ]]; then
    echo "COMPILE FAILED"
    exit $compiled
fi

echo ""
echo "Running"
echo "------------------------------------"

./main 2>&1