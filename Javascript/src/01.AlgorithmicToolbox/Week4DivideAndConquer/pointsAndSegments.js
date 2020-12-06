/**
 * Problem 5 - Organizing a Lottery
 * Given a set of segments, and a set of points on a line,
 * find the number of segments which contain each point (ends inclusive)
 * @param {Array.<{start: number, end: number}>} segments segments on a line
 * @param {Array.<number>} points set of points
 * @returns {Array.<number>} number of segments covering each point, in order
 */
export function countSegmentsCoveringPoints(segments, points) {
  // covert segments and  points to points
  const allPoints = [];
  segments.forEach((segment) => {
    allPoints.push({
      point: segment.start,
      type: "start",
    });
    allPoints.push({
      point: segment.end,
      type: "end",
    });
  });
  points.forEach((point, index) => {
    allPoints.push({
      point,
      type: "point",
      index: index,
    });
  });
  // sort by position and type
  allPoints.sort((pointA, pointB) => {
    if (pointA.point === pointB.point) {
      return getSortValue(pointA.type) - getSortValue(pointB.type);
    }
    return pointA.point - pointB.point;
  });
  let count = 0;
  const counts = new Array(points.length);
  // keep tally of counts by matching right and left segment points
  allPoints.forEach((point) => {
    switch (point.type) {
      case "start":
        count += 1;
        break;
      case "end":
        count -= 1;
        break;
      case "point":
        counts[point.index] = count;
        break;
    }
  });
  return counts;
}

function getSortValue(pointType) {
  switch (pointType) {
    case "start":
      return 0;
    case "point":
      return 1;
    case "end":
      return 2;
  }
}
