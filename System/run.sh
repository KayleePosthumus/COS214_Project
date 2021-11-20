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
  echo "Running"
  echo "------------------------------------"

  make run
}

while test $# -gt 0; do
  case "$1" in
    -h|--help)
      echo "-c or --clean to clean"
      echo "-m or --make to make"
      echo "-r or --run to run"
      echo "-a or --all to clean, make, and run (Exits script. Any flags after will be ignored)"
      exit 0;
      ;;
    -c|--clean)
      cleanFiles
      shift
      ;;
    -m|--make)
      makeFiles
      shift
      ;;
    -r|--run)
      runFiles
      shift
      ;;
    -a|--all)
      cleanFiles
      makeFiles
      runFiles
      exit
      ;;
    *)
      break
      ;;
  esac
done
