import { editDistance } from "./editDistance";

describe("editDistance", () => {
  it("returns minimum edit distance", () => {
    expect(editDistance("ab", "ab")).toEqual(0);
    expect(editDistance("short", "ports")).toEqual(3);
    expect(editDistance("editing", "distance")).toEqual(5);
    expect(editDistance("abcdef", "azced")).toEqual(3);
  });
});
