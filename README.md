Native Binary Search
--------------

A C implementation of the binary search algorithm for Ruby arrays. 

# Usage

The extension adds two methods to ruby arrays: native\_bsearch and native\_bindex. Both take either an object, 
which will be compared to the elements of the array using the <=> operator, or a block as a parameter. native\_bsearch
returns the element matching the parameter and native\_bindex returns it's index. Optionally, either method can take 
two additional number parameters representing the lower and upper bounds of the search. 

Note: the array must be sorted according to the output of either the <=> operator or the result of the block (duh), and if there is 
more than one element matching the target, the search is not guaranteed to return the first element. 

# Installation

To install the gem, simply run `gem install native_bsearch`. 

For use with bundler: `gem native_bsearch`. 

If you want to download and compile the code, you will need the [rake compiler gem](https://github.com/luislavena/rake-compiler). Then, all you 
need to do is run `rake compile` in the project directory. After that, `include` the file created in the lib folder, or run `rake native gem` and 
`gem install pkg/native_bsearch-(version)-(platform).gem` to compile and install the gem. 

# Versions

There are currently two versions of the gem available: 0.0.2 and 0.0.5. [Versions 0.0.1, 0.0.3, and 0.0.4 have been yanked](http://www.jakechristensen.net/posts/on-testing-your-code). The only difference is that 0.0.2 does not support the lower and upper bound parameters. 

# Licence

[MIT](http://opensource.org/licenses/MIT)

# Acknowledgements

This is a modified version of [Tyler's](https://github.com/tyler) [binary\_search gem](https://github.com/tyler/binary_search). 
