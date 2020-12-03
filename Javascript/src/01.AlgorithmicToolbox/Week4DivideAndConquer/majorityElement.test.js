import { majorityElement } from "./majorityElement";

describe("majorityElement", () => {
  it("returns correct majority element", () => {
    expect(majorityElement([2, 3, 9, 2, 2])).toEqual(2);
    expect(majorityElement([2, 2, 3, 3, 4])).toEqual(-1);
    expect(majorityElement([2, 2, 3, 3])).toEqual(-1);
    expect(majorityElement([3, 3, 2, 3])).toEqual(3);
    expect(majorityElement([1, 2])).toEqual(-1);
    expect(majorityElement([1, 1])).toEqual(1);
    expect(majorityElement([1, 2, 3, 4, 5])).toEqual(-1);
  });
});
