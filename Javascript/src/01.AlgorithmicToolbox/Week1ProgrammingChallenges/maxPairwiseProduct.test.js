import { maxPairwiseProduct } from "./maxPairwiseProduct";

describe("max pairwise product", () => {
  it("max pairwise product returns correct product", () => {
    expect(maxPairwiseProduct([21468, 16859, 82178, 70496, 82939, 44491])).toBe(
      6815761142
    );
    expect(maxPairwiseProduct([10, 9, 8, 7, 6])).toBe(90);
  });
});
