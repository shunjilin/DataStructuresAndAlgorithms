import { maxValueFractionalKnapsack } from "./fractionalKnapsack";

describe("fractionalKnapsack", () => {
  it("returns maximum fractional knapsack value", () => {
    expect(
      maxValueFractionalKnapsack(
        [
          { value: 60, weight: 20 },
          { value: 100, weight: 50 },
          { value: 120, weight: 30 },
        ],
        50
      )
    ).toBeCloseTo(180.0);
  });
});
