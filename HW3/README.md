## Build

* Build with `Nova` Library.
* Copy folder `HW3` to `Nova/Project/` and ccmake the project in `Nova/build`
* Enable 'USE_DOUBLES` when building the project.


## Usage

* Run with `./bin/HW3`. If parameter `-size` is not defined, will be set as 16 by default.

```
./bin/HW3 -size 16 16
./bin/HW3 -size 32 32
./bin/HW3 -size 64 64
./bin/HW3 -size 128 128
./bin/HW3 -size 256 256
```
## Result

```
Cell	Iteration	1-Norm
16	25		0.329824
32	51		0.312677
64	102		0.303788
128	207		0.299263
256	420		0.296981
```

##
log2(0.329824/0.312677) = 0.07702328094
log2(0.312677/0.303788) = 0.04160821818
log2(0.303788/0.299263)= 0.02165096345
log2(0.299263/0.296981)= 0.01104328482
