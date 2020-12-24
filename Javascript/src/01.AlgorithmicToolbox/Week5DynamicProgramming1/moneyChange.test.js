import { minCoins } from "./moneyChange";

describe("moneyChange", () => {
  it("returns minimum amount of 1, 3 and 4 coins that make up total value", () => {
    expect(minCoins(2)).toEqual(2);
    expect(minCoins(34)).toEqual(9);
  });
});
