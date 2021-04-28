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

export const maxPairwiseProduct = (numbers) => {
  const [largest, secondLargest] = getMaxPair(numbers);
  return largest * secondLargest;
};
