/**
 * Problem 1 - Money Change
 * @param {number} value total value of coins
 * @returns {number} minimum number of coins of value 1, 5 and 10 that exactly equal value
 */
export function minCoins(value) {
  const numberOf10 = Math.floor(value / 10);
  value %= 10;
  const numberOf5 = Math.floor(value / 5);
  value %= 5;
  const numberOf1 = value;
  return numberOf1 + numberOf5 + numberOf10;
}
