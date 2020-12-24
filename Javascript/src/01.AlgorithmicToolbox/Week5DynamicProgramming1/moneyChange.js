/**
 * Problem 1 - Money Change Again
 * @param {number} value total value of coins
 * @returns {number} minimum number of coins of denominator 1, 3 and 4 that exactly changes value
 */
export function minCoins(value) {
  // intialize array with index corresponding to value
  const coinsToValue = new Array(value + 1).fill(Infinity);
  coinsToValue[0] = 0;
  for (let i = 1; i < coinsToValue.length; ++i) {
    // select minimum coins composition at each value
    const coinsAfterAdd1 = i >= 1 ? coinsToValue[i - 1] + 1 : Infinity;
    const coinsAfterAdd3 = i >= 3 ? coinsToValue[i - 3] + 1 : Infinity;
    const coinsAfterAdd4 = i >= 4 ? coinsToValue[i - 4] + 1 : Infinity;
    coinsToValue[i] = Math.min(coinsAfterAdd1, coinsAfterAdd3, coinsAfterAdd4);
  }
  return coinsToValue[value];
}
