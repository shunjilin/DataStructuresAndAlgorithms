/**
 * Problem 2 - Majority Element
 * Given a sequence of elements (non-negative integers), check whether it contains an element that appears more than n/2 times.
 * If found, output that element, otherwise, output -1
 * @param {Array.<number>} elements sequence of non-negative integer elements
 * @returns {number} majority element, or -1 if no such element exists found
 */
export function majorityElement(elements) {
  return majorityElementHelper(elements, 0, elements.length);
}

function majorityElementHelper(elements, startIndex, endIndex) {
  if (endIndex - startIndex === 1) {
    return elements[startIndex];
  }
  const middleIndex = Math.floor((endIndex - startIndex) / 2) + startIndex;

  const leftMajority = majorityElementHelper(elements, startIndex, middleIndex);
  const rightMajority = majorityElementHelper(elements, middleIndex, endIndex);
  const majorityThreshold = (endIndex - startIndex) / 2;

  // if not same majority, count
  if (leftMajority !== rightMajority) {
    const leftMajorityCount = getElementCount(
      elements,
      startIndex,
      endIndex,
      leftMajority
    );
    const rightMajorityCount = getElementCount(
      elements,
      startIndex,
      endIndex,
      rightMajority
    );
    if (leftMajorityCount > majorityThreshold) {
      return leftMajority;
    }
    if (rightMajorityCount > majorityThreshold) {
      return rightMajority;
    }
    return -1; // no majority
  }
  // return majority
  return leftMajority;
}

function getElementCount(elements, startIndex, endIndex, elementToCount) {
  let count = 0;
  for (let i = startIndex; i < endIndex; ++i) {
    if (elements[i] === elementToCount) {
      count += 1;
    }
  }
  return count;
}
