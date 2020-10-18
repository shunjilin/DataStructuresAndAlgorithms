export const getMaxPair = (numbers) => {
  if (numbers.length < 2) {
    throw new Error("must contain at least 2 numbers");
  }
  let largest = 0;
  let secondLargest = 0;
  numbers.map((num) => {
    if (num > largest) {
      secondLargest = largest;
      largest = num;
    }
  });
  return [largest, secondLargest];
};

export const maxPairwiseProduct = (numbers) => {
  return getMaxPair(numbers).reduce((a, b) => a * b);
};
