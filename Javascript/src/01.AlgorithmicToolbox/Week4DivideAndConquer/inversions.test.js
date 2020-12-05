import { inversions } from "./inversions";

describe("inversions", () => {
  it("sort array of random elements", () => {
    const randomElements = Array.from({ length: 100 }, () =>
      Math.floor(Math.random() * 100)
    );
    inversions(randomElements);
    expect(randomElements).toEqual(randomElements.sort());
  });

  it("gets correct number of inversions", () => {
    expect(inversions([1, 2, 3])).toEqual(0);
    expect(inversions([3, 1, 2, 3, 1, 2])).toEqual(7);
    expect(inversions([0, -1, 1, -2, 2])).toEqual(4);
  });
});
