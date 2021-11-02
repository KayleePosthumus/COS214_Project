#! /bin/bash

createFile() {
	local parent=": public ${2}"
	local include="
#include \"${2}.h\"
"
	if [ -z "$2" ]; then
		parent=""
		include=""
	fi

	echo "#ifndef ${1^^}_H
#define ${1^^}_H
${include}
class ${1} ${parent}
{
public:
	${1}();
	~${1}();
private:

};

#endif" >> ${1}.h

	echo "#include \"${1}.h\"

${1}::${1}() {}
${1}::~${1}() {}" >> ${1}.cpp
}

IFS=', ' read -p 'Files to create: ' -a files

for file in "${files[@]}"
do
	createFile $file
	read -p "Children of $file:" -a children
	for child in "${children[@]}"
	do
		createFile $child $file
	done
done