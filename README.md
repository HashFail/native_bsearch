Native Binary Search
--------------

A C implementation of the binary search algorithm for Ruby arrays. 

# Usage

The extension adds two methods to ruby arrays: native\_bsearch and native\_bindex. Both take either an object, 
which will be compared to the elements of the array using the <=> operator, or a block as a parameter. native\_bsearch
returns the element matching the parameter and native\_bindex returns it's index. 

Note: the array must be sorted according to the output of either the <=> operator or the block (duh), and if there is 
more than one element matching the target, the search is not guaranteed to return the first element. 

# Installation

If you want to download and compile the code, you will need the [rake compiler gem](https://github.com/luislavena/rake-compiler). Then, all you 
need to do is run `rake compile` in the project directory and include the file created in the lib folder. 

# Licence

[MIT](http://opensource.org/licenses/MIT)

# Acknowledgements

This is a modified version of [Tyler's](https://github.com/tyler) [binary\_search gem](https://github.com/tyler/binary_search). 
