import { longestCommonSubsequenceThree } from "./longestCommonSubsequenceThree";

describe("longestCommonSubsequenceTwo", () => {
  it("returns longest common subsequence of two sequences", () => {
    expect(
      longestCommonSubsequenceThree([1, 2, 3], [2, 1, 3], [1, 3, 5])
    ).toEqual(2);
    expect(
      longestCommonSubsequenceThree(
        [8, 3, 2, 1, 7],
        [8, 2, 1, 3, 8, 10, 7],
        [6, 8, 3, 1, 4, 7]
      )
    ).toEqual(3);
  });
});
