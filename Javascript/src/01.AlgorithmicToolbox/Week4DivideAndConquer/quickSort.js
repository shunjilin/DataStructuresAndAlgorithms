/**
 * Problem 3 - Improving Quick Sort
 * Sorts a sequence of elements
 * Implements randomized quick sort with three way partition: less than, equal and more than
 * @param {Array.<number>} elements sequence of elements
 * sorts elements in place
 */
export function quickSort(elements) {
  quickSortHelper(elements, 0, elements.length);
}

function quickSortHelper(elements, startIndex, endIndex) {
  if (endIndex - startIndex <= 1) {
    return;
  }
  const [equalStartIndex, equalEndIndex] = threeWayPartition(
    elements,
    startIndex,
    endIndex
  );
  quickSortHelper(elements, startIndex, equalStartIndex);
  quickSortHelper(elements, equalEndIndex + 1, endIndex);
}

// partition three ways: less than, equal, greater than random pivot element
// return the start and end index (inclusive) of the equal segment of the three way partition
function threeWayPartition(elements, startIndex, endIndex) {
  const pivotIndex = getPivotIndex(startIndex, endIndex);
  const pivotElement = elements[pivotIndex];
  // move pivot element to first element
  swap(elements, startIndex, pivotIndex);
  let equalStartIndex = startIndex + 1;
  let equalEndIndex = endIndex - 1;
  let index = startIndex + 1;
  while (index <= equalEndIndex) {
    if (elements[index] < pivotElement) {
      swap(elements, index, equalStartIndex);
      index += 1;
      equalStartIndex += 1;
    } else if (elements[index] > pivotElement) {
      swap(elements, index, equalEndIndex);
      equalEndIndex -= 1;
    } else {
      // equal
      index += 1;
    }
  }
  // move pivot element back to middle
  equalStartIndex -= 1;
  swap(elements, startIndex, equalStartIndex);
  // return middle (equal) range index
  return [equalStartIndex, equalEndIndex];
}

// get random pivot index
function getPivotIndex(startIndex, endIndex) {
  return startIndex + Math.floor(Math.random() * (endIndex - startIndex));
}

function swap(elements, index1, index2) {
  const temp = elements[index1];
  elements[index1] = elements[index2];
  elements[index2] = temp;
}
