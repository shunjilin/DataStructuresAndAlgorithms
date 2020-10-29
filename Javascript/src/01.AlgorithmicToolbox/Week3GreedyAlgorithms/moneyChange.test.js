import { minCoins } from "./moneyChange";

describe("moneyChange", () => {
  it("returns minimum amount of 1, 5 and 10 coins that make up total value", () => {
    expect(minCoins(2)).toEqual(2);
    expect(minCoins(28)).toEqual(6);
  });
});
