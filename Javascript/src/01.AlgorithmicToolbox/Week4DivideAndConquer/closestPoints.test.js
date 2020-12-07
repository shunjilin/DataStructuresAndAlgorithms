import { closestPointsDistance } from "./closestPoints";

describe("closestPointsDistance", () => {
  it("returns correct closest points distance", () => {
    expect(
      closestPointsDistance([
        { x: 0, y: 0 },
        { x: 3, y: 4 },
      ])
    ).toBeCloseTo(5.0);
    expect(
      closestPointsDistance([
        { x: 7, y: 7 },
        { x: 1, y: 100 },
        { x: 4, y: 8 },
        { x: 7, y: 7 },
      ])
    ).toBeCloseTo(0.0);
    expect(
      expect(
        closestPointsDistance([
          { x: 4, y: 4 },
          { x: -2, y: -2 },
          { x: -3, y: -4 },
          { x: -1, y: 3 },
          { x: 2, y: 3 },
          { x: -4, y: 0 },
          { x: 1, y: 1 },
          { x: -1, y: -1 },
          { x: 3, y: -1 },
          { x: -4, y: 2 },
          { x: -2, y: 4 },
        ])
      ).toBeCloseTo(1.414213)
    );
  });
});
