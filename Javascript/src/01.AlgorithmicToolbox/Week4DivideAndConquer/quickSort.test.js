import { quickSort } from "./quickSort";

describe("quickSort", () => {
  it("sort array of random elements", () => {
    const randomElements = Array.from({ length: 100 }, () =>
      Math.floor(Math.random() * 100)
    );
    quickSort(randomElements);
    expect(
      // check if sorted
      randomElements.every(
        (value, index, array) => index === 0 || array[index - 1] <= value
      )
    ).toBeTruthy();
  });
});
