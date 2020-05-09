BN_SMC
======

Sequential monte carlo method apply on structure learning of a Bayesian Network.

# Dependency:
Boost(1.53), I have not tried higher versions, technically they should be backward competitable. 

Please put Boost into $WD/lib/

# Compile
If you are using GCC, the source code uses some features from C++11, so get a gcc version that has C++11 features enabled, I think maybe >5.4? The run the following to compile
```
make
```

On the other hand, we used to have intel compiler, icpc, installed on FSU clusters, so you can also run the following to use intel compiler:
```
make -f makefile-intel
```

Both methods will generate an executable a (forgive me.... when I was young I liked to use easy names).

# Run the program
```
./a NODES OBS iter chains cutoff cores temperature depth DATA_path PARAM_path output_path
```

NODES: number of nodes in the data set (a.k.a number of variables)

OBS: number of observations (data size)

iter: maximum iterations will be run for each SMC chain (depends on NODES, typically 1000)

chains: number of SMC chains to make, the more the better, but take more time to finish

cutoff: The cut off point where MIT test determine dependency, typically 0.05, you can set to 0.01 if needed

cores: Number of cores (threads, CPUs) to use, it gets replaced by number of cores available if the later one is smaller.

temperature: used to control the greedy level, 

depth: How many rounds of 3rd stage to perform, dont make it too big, typically 3-5

DATA_path: the path to the data file (please include the full file name)

PARAM_path: the path to the param file (please include the full file name)

output_path: the path to outputs, only need a directory


# Data
The data file is a cvs file, each row is one observation, while each column is a variable (node).
Something look like this:
2,2,2,2,2,2,2,2,3,3,2,3,2,2,1,2,2,4,2,3,3,2,2,1,1,4,1,2,3,1,2,4,1,2,3,3,1
2,1,1,2,1,2,2,2,3,2,1,2,2,2,2,2,2,4,2,3,3,3,2,1,1,4,1,2,3,1,2,4,1,2,3,3,3
2,2,2,2,2,2,2,2,3,3,2,3,2,2,3,2,2,1,2,1,1,2,2,1,1,4,2,2,3,2,1,1,3,2,3,3,3
2,2,2,2,2,2,2,2,3,3,2,3,2,2,1,2,2,1,2,1,1,2,2,1,1,2,2,2,3,2,1,1,3,2,3,1,1
2,2,2,2,2,2,2,2,1,1,2,1,2,2,3,2,2,4,2,3,3,2,2,1,1,2,2,3,4,4,2,4,1,1,2,1,2

# Param file
This file contains only a column, each row sepcifies how many categories are there in the corresponding variable (node).
Sample file:
2
3
3
2
3
2
3
2
3
3
2
3
2
2
3
4
2
4
2
3
3
3
2
2
3
4
2
3
4
4
4
4
3
2
3
3
3

