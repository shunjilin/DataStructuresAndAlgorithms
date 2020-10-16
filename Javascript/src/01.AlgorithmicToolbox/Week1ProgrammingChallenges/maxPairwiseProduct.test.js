import { maxPairwiseProduct } from "./maxPairwiseProduct";

describe("max pairwise product", () => {
  const numbers = [21468, 16859, 82178, 70496, 82939, 44491];

  it("max pairwise product returns correct product", () => {
    expect(maxPairwiseProduct(numbers)).toBe(6815761142);
  });
});
