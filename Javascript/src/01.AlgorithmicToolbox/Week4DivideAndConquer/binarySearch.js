/**
 * Problem 1 - Binary Search
 * Given an input set of distinct positive integers in increasing order and a positive integer key,
 * output the index corresponding to the position of the key in the input set, and -1 if the key is not found.
 * @param {Array.<number>} input list of distinct positive integers in increasing order
 * @param {number} key
 * @returns {number} index of key in the input list, -1 if no such key found
 */
export function binarySearch(input, key) {
  return binarySearchHelper(input, key, 0, input.length);
}

function binarySearchHelper(input, key, startIndex, endIndex) {
  if (startIndex === endIndex) {
    return -1;
  }
  const middleIndex = Math.floor((endIndex - startIndex) / 2) + startIndex;
  const middleValue = input[middleIndex];
  if (key === middleValue) {
    return middleIndex;
  }
  if (key > middleValue) {
    return binarySearchHelper(input, key, middleIndex + 1, endIndex);
  }
  if (key < middleValue) {
    return binarySearchHelper(input, key, startIndex, middleIndex);
  }
}
