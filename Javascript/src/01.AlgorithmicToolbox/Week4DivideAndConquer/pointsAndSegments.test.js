import { countSegmentsCoveringPoints } from "./pointsAndSegments";

describe("countSegmentsCoveringPoints", () => {
  it("returns correct counts", () => {
    expect(
      countSegmentsCoveringPoints(
        [
          {
            start: 0,
            end: 5,
          },
          { start: 7, end: 10 },
        ],
        [1, 6, 11]
      )
    ).toEqual([1, 0, 0]);
    expect(
      countSegmentsCoveringPoints(
        [
          {
            start: -10,
            end: 10,
          },
        ],
        [-100, 100, 0]
      )
    ).toEqual([0, 0, 1]);
    expect(
      countSegmentsCoveringPoints(
        [
          {
            start: 0,
            end: 5,
          },
          {
            start: -3,
            end: 2,
          },
          {
            start: 7,
            end: 10,
          },
        ],
        [1, 6]
      )
    ).toEqual([2, 0]);
  });
});
