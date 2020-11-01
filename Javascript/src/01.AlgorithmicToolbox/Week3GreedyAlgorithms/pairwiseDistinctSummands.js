/**
 * Problem 5 - Maximum Number of Prizes
 * Goal is to find the maximal set of distinct positive integers that sum up to a given sum
 * @param {number} sum sum
 * @returns {Array.<number>} maximal set of distinct positive integers that sum to sum
 */
export function pairwseDistinctSummands(sum) {
  const summands = [];
  let summand = 1;
  let differenceFromSum = sum;
  while (differenceFromSum > 0) {
    const remainder = differenceFromSum - summand;
    if (remainder <= summand) {
      summands.push(differenceFromSum);
      return summands;
    }
    differenceFromSum -= summand;
    summands.push(summand);
    ++summand;
  }
  return summands;
}
