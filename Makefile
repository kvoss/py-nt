CPP_FLAGS = -O2 -Wall -pedantic

factors.so: factors.cpp factorization.cpp factorization.hpp
	python setup.py build_ext --inplace

test: factors.so
	python -c 'import factors as f; print f.factor(33)'
	python -c 'import factors as f; print f.factor(3322)'
	python -c 'import factors as f; print f.factor(2345)'

timeit:
	python -m timeit -s "import factors as f" "f.factor(73726243)"

clean:
	rm -f factors.so

