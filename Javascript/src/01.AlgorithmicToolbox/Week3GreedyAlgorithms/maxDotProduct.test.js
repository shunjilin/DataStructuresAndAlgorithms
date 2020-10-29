import { maxDotProduct } from "./maxDotProduct";

describe("maxDotProduct", () => {
  it("returns maximum dot product of two sequences", () => {
    expect(maxDotProduct([23], [39])).toEqual(897);
    expect(maxDotProduct([1, 3, -5], [-2, 4, 1])).toEqual(23);
  });
});
