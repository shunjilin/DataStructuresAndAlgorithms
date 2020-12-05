/**
 * Problem 4 - Inversions
 * Given a sequence of n integers a0, a1,..., a(n-1), find the number of inversions,
 * where an inversion is a pair of indices i, j where 0 <= i < j < n and ai > aj.
 * @param {Array.<number>} sequence sequence of integers
 * @returns {number} number of inversions
 */
export function inversions(sequence) {
  return inversionsHelper(sequence, 0, sequence.length);
}

function inversionsHelper(sequence, startIndex, endIndex) {
  if (endIndex - startIndex === 1) {
    return 0;
  }
  const middleIndex = startIndex + Math.floor((endIndex - startIndex) / 2);
  const leftInversions = inversionsHelper(sequence, startIndex, middleIndex);
  const rightInversions = inversionsHelper(sequence, middleIndex, endIndex);
  return (
    mergeWithInversions(sequence, startIndex, middleIndex, endIndex) +
    leftInversions +
    rightInversions
  );
}

function mergeWithInversions(sequence, startIndex, middleIndex, endIndex) {
  let inversions = 0;
  const merged = [];
  let leftIndex = startIndex;
  let rightIndex = middleIndex;
  // merge by comparing smallest of each of left, right
  while (leftIndex < middleIndex && rightIndex < endIndex) {
    if (sequence[leftIndex] <= sequence[rightIndex]) {
      merged.push(sequence[leftIndex]);
      ++leftIndex;
    } else {
      merged.push(sequence[rightIndex]);
      // inversions with all remaining left elements
      inversions += middleIndex - leftIndex;
      ++rightIndex;
    }
  }
  // leftover elements
  while (leftIndex < middleIndex) {
    merged.push(sequence[leftIndex]);
    ++leftIndex;
  }
  while (rightIndex < endIndex) {
    merged.push(sequence[rightIndex]);
    ++rightIndex;
  }
  // replace in existing sequence
  for (let i = 0; i < merged.length; ++i) {
    sequence[startIndex + i] = merged[i];
  }
  return inversions;
}
