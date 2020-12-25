import { longestCommonSubsequenceTwo } from "./longestCommonSubsequenceTwo";

describe("longestCommonSubsequenceTwo", () => {
  it("returns longest common subsequence of two sequences", () => {
    expect(longestCommonSubsequenceTwo([2, 7, 5], [2, 5])).toEqual(2);
    expect(longestCommonSubsequenceTwo([7], [1, 2, 3, 4])).toEqual(0);
    expect(longestCommonSubsequenceTwo([2, 7, 8, 3], [5, 2, 8, 7])).toEqual(2);
  });
});
