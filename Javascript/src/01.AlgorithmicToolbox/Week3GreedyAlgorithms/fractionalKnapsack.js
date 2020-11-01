/**
 * Problem 2 - Maximum Value of the Loot
 *
 * Fractional Knapsack Problem
 *
 * @param {Array.<{value: number, weight: number}>} items list of items each with value and weight
 * @param {number} capacity total capacity of knapsack
 * @returns {number} maximum value of items that can fit into the knapsack (fractional weight allowed)
 */
export function maxValueFractionalKnapsack(items, capacity) {
  // sort in ascending order of value over weight
  items.sort((a, b) => a.value / a.weight - b.value / b.weight);
  let maxValue = 0;
  while (items.length > 0 && capacity > 0) {
    const nextItem = items.pop();
    if (nextItem.weight < capacity) {
      // take unit value
      capacity -= nextItem.weight;
      maxValue += nextItem.value;
    } else {
      // take fractional value
      maxValue += (nextItem.value / nextItem.weight) * capacity;
      break;
    }
  }
  return maxValue;
}
