import { primitiveCalculator } from "./primitiveCalculator";

describe("primitiveCalculator", () => {
  it("returns correct intermediate values for computation", () => {
    expect(primitiveCalculator(1)).toEqual([1]);
    expect([
      [1, 2, 4, 5],
      [1, 3, 4, 5],
    ]).toContainEqual(primitiveCalculator(5));
    expect(primitiveCalculator(96234).length).toEqual(15);
  });
});
