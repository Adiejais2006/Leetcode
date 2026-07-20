// Last updated: 7/20/2026, 10:12:52 PM
1/**
2 * @param {...(null|boolean|number|string|Array|Object)} args
3 * @return {number}
4 */
5var argumentsLength = function(...args) {
6return args.length;
7};
8
9/**
10 * argumentsLength(1, 2, 3); // 3
11 */