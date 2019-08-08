import { getMaxPair, maxPairwiseProduct } from "./MaxPairwiseProduct"

describe("max pairwise product", () => {
  const numbers = [21468, 16859, 82178, 70496, 82939, 44491]

  it("get max pair returns largest two numbers", () => {
    const maxPair = getMaxPair(numbers)
    expect(maxPair).toContain(82178)
    expect(maxPair).toContain(82939)
  })
  it("max pairwise product returns correct product", () => {
    expect(maxPairwiseProduct(numbers)).toBe(6815761142)
  })
})
