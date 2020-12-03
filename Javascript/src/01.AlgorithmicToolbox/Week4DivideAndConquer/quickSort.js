/**
 * Problem 3 - Improving Quick Sort
 * Sorts a sequence of elements
 * Implements randomized quick sort with three way partition: less than, equal and more than
 * @param {Array.<number>} elements sequence of elements
 * @returns {Array.<number>} elements in non descending order
 */
export function quickSort(elements) {
  quickSortHelper(elements, 0, elements.length);
  return elements;
}

function quickSortHelper(elements, startIndex, endIndex) {
  if (endIndex - startIndex <= 1) {
    return;
  }
  const pivotIndex = getPivotIndex(startIndex, endIndex);
  let lessThanIndex = startIndex;
  let greaterThanIndex = endIndex - 1;
  let index = startIndex;
  while (index <= greaterThanIndex) {
    if (elements[index] < elements[pivotIndex]) {
      swap(elements, index, lessThanIndex);
      index += 1;
      lessThanIndex += 1;
    } else if (elements[index] > elements[pivotIndex]) {
      swap(elements, index, greaterThanIndex);
      greaterThanIndex -= 1;
    } else {
      // equal
      index += 1;
    }
  }
  quickSortHelper(elements, startIndex, pivotIndex);
  quickSortHelper(elements, pivotIndex, endIndex);
}

function getPivotIndex(startIndex, endIndex) {
  return startIndex + Math.floor(Math.random() * (endIndex - startIndex));
}

function swap(elements, index1, index2) {
  const temp = elements[index1];
  elements[index1] = elements[index2];
  elements[index2] = temp;
}
