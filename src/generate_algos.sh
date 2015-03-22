#! /bin/sh

## Blank out the generated_algos files
echo -n > generated_algos.cpp
echo -n > generated_algos.h

## Create the startings of the files
echo "#ifndef GENERATED_ALGOS_H" >> generated_algos.h
echo "#define GENERATED_ALGOS_H" >> generated_algos.h
echo "#include <string>" >> generated_algos.h
echo "namespace decrypter {" >> generated_algos.h
echo "#include \"generated_algos.h\"" >> generated_algos.cpp
echo "#include \"util.h\"" >> generated_algos.cpp
echo "namespace decrypter {" >> generated_algos.cpp
echo "using namespace std;" >> generated_algos.cpp

## Place the algos in the right places
for i in decrypt_algos/*; do
	ALGO_NAME=`basename $i`
	SPACED_ALGO_NAME=`echo $ALGO_NAME | sed 's/_/ /g'`
	echo "std::string $ALGO_NAME (std::string e);" >> generated_algos.h
	echo "string $ALGO_NAME (string e) {" >> generated_algos.cpp
	echo "if ( e.empty() ) return \"$SPACED_ALGO_NAME\";" >> generated_algos.cpp
	cat $i >> generated_algos.cpp
	echo "}" >> generated_algos.cpp
done

## Create the endings of the files
echo "}" >> generated_algos.h
echo "#endif" >> generated_algos.h
echo "}" >> generated_algos.cpp
