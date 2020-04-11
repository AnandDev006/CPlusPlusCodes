/*
    author : Anand

    This problem was asked by Jane Street.

    cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

    Given this implementation of cons:

    def cons(a, b):
      def pair(f):
          return f(a, b)
      return pair
    Implement car and cdr

*/

const cons = (a, b) => f => f(a, b);

const car = g => g((x, y) => x);
const cdr = g => g((x, y) => y);

console.assert(car(cons(3, 4)) == 3);
console.assert(cdr(cons(3, 4)) == 4);
