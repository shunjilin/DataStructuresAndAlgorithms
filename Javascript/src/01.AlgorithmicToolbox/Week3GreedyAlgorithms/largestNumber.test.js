import { largestNumber } from "./largestNumber";

describe("largestNumber", () => {
  it("returns maximum composable number from sequence", () => {
    expect(largestNumber([9, 4, 6, 1, 9])).toBe(99641);
    expect(largestNumber([23, 39, 92])).toBe(923923);
    expect(largestNumber([21, 2])).toBe(221);
  });
});
