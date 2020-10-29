/**
 * Problem 4 - Collecting Signatures
 * Return Minimum set of points that cover all segments
 * @param {Array.<{start: number, end: number}>} segments list of segments covering start to end
 * @returns {Array.<number>} minimum set of points that cover all given segments
 */
export function getMinSetOfPointsCoveringSegments(segments) {
  // sort segments by end points
  segments.sort((a, b) => a.end - b.end);
  const points = [];
  // cover by end points, skipping segments already covered
  segments.forEach((segment) => {
    // check if covered by previous point
    if (points.length > 0) {
      const point = points[points.length - 1];
      if (pointCoversSegment(point, segment)) {
        return;
      }
    }
    points.push(segment.end);
  });
  return points;
}

function pointCoversSegment(point, segment) {
  return segment.start <= point && segment.end >= point;
}
