/**
 * Problem 3 - Edit Distance
 * Calculate the minimum number of operations (insertions, deletions and substitutions)
 * needed to transform one string to another.
 * https://en.wikipedia.org/wiki/Edit_distance
 * @param {string} first first string
 * @param {string} second second string
 * @returns {number} edit distance
 */
export function editDistance(first, second) {
  const editDistances = new Array(first.length + 1)
    .fill(Infinity)
    .map(() => new Array(second.length + 1).fill(Infinity));

  // intialize outer row / col
  // these are the number of operations to convert empty string to each input string
  for (let row = 0; row <= first.length; ++row) {
    editDistances[row][0] = row;
  }
  for (let col = 0; col <= second.length; ++col) {
    editDistances[0][col] = col;
  }
  // fill rest of elements
  for (let row = 1; row <= first.length; ++row) {
    for (let col = 1; col <= second.length; ++col) {
      if (first.charAt(row - 1) === second.charAt(col - 1)) {
        // same character, do nothing
        editDistances[row][col] = editDistances[row - 1][col - 1];
      } else {
        // with first input as reference; transform first to second
        const substitution = editDistances[row - 1][col - 1] + 1;
        const deletion = editDistances[row][col - 1] + 1;
        const addition = editDistances[row - 1][col] + 1;
        editDistances[row][col] = Math.min(substitution, deletion, addition);
      }
    }
  }
  return editDistances[first.length][second.length];
}
