#! /bin/bash

cleanFiles() {
  echo "Cleaning"
  make clean 1>&2 > /dev/null
}

makeFiles() {
  echo "Compiling"
  make 1>&2 > /dev/null
  compiled=$?

  if [[ $compiled -ne 0 ]]; then
    echo "COMPILE FAILED"
    exit $compiled
  fi
}

runFiles() {
  makeFiles

  echo "Running"
  echo "------------------------------------"

  make run
}

while test $# -gt 0; do
  case "$1" in
    -h|--help)
      echo "-c to clean"
      echo "-m to make"
      echo "-r to run"
      echo "-a to clean, make, and run"
      exit 0;
      ;;
    -c)
      cleanFiles
      shift
      ;;
    -m)
      makeFiles
      shift
      ;;
    -r)
      runFiles
      shift
      ;;
    -a)
      cleanFiles
      runFiles
      exit
      ;;
    *)
      break
      ;;
  esac
done
