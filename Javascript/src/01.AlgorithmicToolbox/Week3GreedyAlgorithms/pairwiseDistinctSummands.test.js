import { pairwseDistinctSummands } from "./pairwiseDistinctSummands";

describe("pairwiseDistinctSummands", () => {
  it("returns different summands", () => {
    expect(pairwseDistinctSummands(2)).toEqual([2]);
    expect(pairwseDistinctSummands(6)).toEqual([1, 2, 3]);
    expect(pairwseDistinctSummands(8)).toEqual([1, 2, 5]);
  });
});
