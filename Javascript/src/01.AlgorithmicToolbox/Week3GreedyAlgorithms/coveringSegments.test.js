import { getMinSetOfPointsCoveringSegments } from "./coveringSegments";

describe("coveringSegments", () => {
  it("points covers segments", () => {
    const segments = [
      { start: 4, end: 7 },
      { start: 1, end: 3 },
      { start: 2, end: 5 },
      { start: 5, end: 6 },
    ];
    const points = getMinSetOfPointsCoveringSegments(segments);
    const coveredSegmentsRemoved = segments.filter(
      (segment) =>
        // remove point if covered
        !points.some((point) => segment.start <= point && segment.end >= point)
    );
    expect(coveredSegmentsRemoved.length).toBe(0);
  });

  it("returns minimal set of points covering segments", () => {
    const segments = [
      { start: 4, end: 7 },
      { start: 1, end: 3 },
      { start: 2, end: 5 },
      { start: 5, end: 6 },
    ];
    const points = getMinSetOfPointsCoveringSegments(segments);
    expect(points.length).toBe(2);
  });
});
