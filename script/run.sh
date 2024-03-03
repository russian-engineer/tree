. ./flags

cd ..

gcc $CFLAGS src/*.c -o bin/main && 
echo "[GCC] - finish" && ./bin/main && 
dot -Tsvg graphiz/bin_graph.dot > graphiz/output.svg && 
firefox graphiz/output.svg


