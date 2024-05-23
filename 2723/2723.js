/* 2723. Add Two Promises
    Given two promises promise1 and promise2, return a new promise. 
    promise1 and promise2 will both resolve with a number. The returned promise should resolve with the sum of the two numbers.

    Again, minimal javascript experience, but I looked up promises, and it looked like once they were fulfilled you could use their result.
        for async functions, you can 'await' a a function to tell it to wait for a promise, which would fulfill it, and then use the results.
        Otherwise, you're just adding two variables whose values are "undefined".
*/
/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    return await promise1 + await promise2;
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */