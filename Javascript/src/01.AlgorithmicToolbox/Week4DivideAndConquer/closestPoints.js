/**
 * Problem 6 - Closest Points
 * Given n points on a plane, find the smallest distance between a pair
 * of two different points.
 * @param {Array.<{x: number, y: number}>} points set of points on a plane
 * @returns {number} smallest distance
 */
export function closestPointsDistance(points) {
  // sort according to x-coordinate
  points.sort((pointA, pointB) => pointA.x - pointB.x);
  return closestPointsDistanceHelper(points, 0, points.length);
}

function closestPointsDistanceHelper(points, startIndex, endIndex) {
  if (endIndex - startIndex === 1) {
    return Infinity;
  }
  // find closest distance of each half
  const middleIndex = startIndex + Math.floor((endIndex - startIndex) / 2);
  const leftClosestPointsDistance = closestPointsDistanceHelper(
    points,
    startIndex,
    middleIndex
  );
  const rightClosestPointsDistance = closestPointsDistanceHelper(
    points,
    middleIndex,
    endIndex
  );
  let closestPointsDistance = Math.min(
    leftClosestPointsDistance,
    rightClosestPointsDistance
  );
  // collect points in middle strip within closestPointsDistance to middle point
  const middlePoint = points[middleIndex];
  const pointsInMiddleStrip = [];
  for (let i = startIndex; i < endIndex; ++i) {
    if (Math.abs(points[i].x - middlePoint.x) < closestPointsDistance) {
      pointsInMiddleStrip.push(points[i]);
    }
  }
  // sort middle points by y coordinates
  pointsInMiddleStrip.sort((pointA, pointB) => pointA.y - pointB.y);
  // compare each point with 7 of its neighbors, updating closest points distance
  for (let i = 0; i < pointsInMiddleStrip.length; ++i) {
    for (let j = i + 1; j < i + 8 && j < pointsInMiddleStrip.length; ++j) {
      const distance = distanceBetweenPoints(
        pointsInMiddleStrip[i],
        pointsInMiddleStrip[j]
      );
      if (distance < closestPointsDistance) {
        closestPointsDistance = distance;
      }
    }
  }
  return closestPointsDistance;
}

function distanceBetweenPoints(pointA, pointB) {
  return Math.sqrt(
    Math.pow(pointA.x - pointB.x, 2) + Math.pow(pointA.y - pointB.y, 2)
  );
}
