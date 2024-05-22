/* 2703. Return Length of Arguments Passed
*
* Java - Write a function argumentsLength that returns the count of arguments passed to it.
*
* I have very very little experience with java. so.  Let's see what happens.  The acceptance of this is like 100%
*/


/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    return args.length;                         // this is the bit I added
};

console.log(argumentsLength("test", "test", "test", 81));

/**
 * argumentsLength(1, 2, 3); // 3
 */