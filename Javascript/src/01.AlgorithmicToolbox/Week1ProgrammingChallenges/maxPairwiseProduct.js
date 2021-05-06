/**
 * Maximum Pairwise Product Problem
 *
 * Given a list of integers, return the maximum pairwise product,
 * i.e. product between the two largest distinct (different index) numbers in the list
 * @param {Array.<number>} numbers list of integers
 * @returns maximum pairwise product
 */
export const maxPairwiseProduct = (numbers) => {
  const [largest, secondLargest] = getMaxPair(numbers);
  return largest * secondLargest;
};

export const getMaxPair = (numbers) => {
  return numbers.reduce(
    ([largest, secondLargest], num) => {
      if (num > largest) {
        return [num, largest];
      }
      if (num > secondLargest) {
        return [largest, num];
      }
      return [largest, secondLargest];
    },
    [0, 0]
  );
};
