import { binarySearch } from "./binarySearch";

describe("binarySearch", () => {
  it("returns correct key index", () => {
    expect(binarySearch([1, 5, 8, 12, 13], 8)).toEqual(2);
    expect(binarySearch([1, 5, 8, 12, 13], 1)).toEqual(0);
    expect(binarySearch([1, 5, 8, 12, 13], 23)).toEqual(-1);
  });
});
