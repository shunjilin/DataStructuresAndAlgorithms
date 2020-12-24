/**
 * Problem 2 - Primitive Calculator
 * Calculator can only perform three operations: multiply by 2, multiply by 3 and add 1
 * @param {number} output output integer n, where 1 <= n <= 10^6
 * @returns {number} sequence of intemediate results (including final output) of applying operations to starting input of 1
 */
export function primitiveCalculator(output) {
  const minOperations = new Array(output + 1).fill(Infinity);
  minOperations[1] = 1;
  for (let i = 2; i < minOperations.length; ++i) {
    const add1 = minOperations[i - 1] + 1;
    const multiply2 = i % 2 === 0 ? minOperations[i / 2] + 1 : Infinity;
    const multiply3 = i % 3 === 0 ? minOperations[i / 3] + 1 : Infinity;
    minOperations[i] = Math.min(add1, multiply2, multiply3);
  }
  return getIntermediateValues(minOperations);
}

function getIntermediateValues(minOperations) {
  let value = minOperations.length - 1;
  const intermediateValues = [];
  while (value >= 1) {
    intermediateValues.push(value);
    if (minOperations[value] === minOperations[value - 1] + 1) {
      value = value - 1;
    } else if (
      value % 2 === 0 &&
      minOperations[value] === minOperations[value / 2] + 1
    ) {
      value = value / 2;
    } else if (
      value % 3 === 0 &&
      minOperations[value] === minOperations[value / 3] + 1
    ) {
      value = value / 3;
    } else {
      break;
    }
  }
  return intermediateValues.reverse();
}
