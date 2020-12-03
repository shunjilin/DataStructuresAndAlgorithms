import { quickSort } from "./quickSort";

describe("quickSort", () => {
  it("sort array of random elements", () => {
    const randomElements = Array.from({ length: 100 }, () =>
      Math.floor(Math.random() * 100)
    );
    expect(quickSort(randomElements)).toEqual(randomElements.sort());
  });
});
