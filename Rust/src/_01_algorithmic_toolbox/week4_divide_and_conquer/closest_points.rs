///
/// Problem 6 - Closest Points
/// Given n points on a plane, find the smallest distance between a pair
/// of two different points.
pub fn closest_points(points: &mut [Point]) -> f64 {
    points.sort_by(|point_a, point_b| point_a.x.partial_cmp(&point_b.x).unwrap());
    closest_points_helper(points)
}
fn closest_points_helper(points: &[Point]) -> f64 {
    if points.len() == 1 {
        return f64::INFINITY;
    }
    // find closest distance of each half
    let middle_index = points.len() / 2;
    let left_closest_points_distance = closest_points_helper(&points[..middle_index]);
    let right_closest_points_distance = closest_points_helper(&points[middle_index..]);
    let mut closest_points_distance =
        left_closest_points_distance.min(right_closest_points_distance);
    // collect points in middle strip within closest points distance to middle point
    let middle_point = &points[middle_index];
    let mut points_in_middle_strip = vec![];
    for point in points {
        if (point.x - middle_point.x).abs() < closest_points_distance {
            points_in_middle_strip.push(point)
        }
    }
    // sort middle points by y coordinates
    points_in_middle_strip.sort_by(|point_a, point_b| point_a.y.partial_cmp(&point_b.y).unwrap());
    // compare each point with 7 of its neighbors, updating closest points distance
    for i in 0..points_in_middle_strip.len() {
        for j in i + 1..(i + 8).min(points_in_middle_strip.len()) {
            if j > points_in_middle_strip.len() {
                break;
            }
            let distance =
                distance_between_points(points_in_middle_strip[i], points_in_middle_strip[j]);
            closest_points_distance = closest_points_distance.min(distance);
        }
    }
    closest_points_distance
}

pub struct Point {
    x: f64,
    y: f64,
}

fn distance_between_points(point_a: &Point, point_b: &Point) -> f64 {
    ((point_a.x - point_b.x).powi(2) + (point_a.y - point_b.y).powi(2)).sqrt()
}

#[cfg(test)]
mod test {
    use super::*;

    fn approx_equal(a: f64, b: f64) -> bool {
        (a - b).abs() < 1e-6
    }
    #[test]
    fn returns_closest_points_distance() {
        assert_eq!(
            approx_equal(
                closest_points(&mut vec![
                    Point { x: 0.0, y: 0.0 },
                    Point { x: 3.0, y: 4.0 }
                ]),
                5.0
            ),
            true
        );
        assert_eq!(
            approx_equal(
                closest_points(&mut vec![
                    Point { x: 7.0, y: 7.0 },
                    Point { x: 1.0, y: 100.0 },
                    Point { x: 4.0, y: 8.0 },
                    Point { x: 7.0, y: 7.0 }
                ]),
                0.0
            ),
            true
        );
        assert_eq!(
            approx_equal(
                closest_points(&mut vec![
                    Point { x: 4.0, y: 4.0 },
                    Point { x: -2.0, y: -2.0 },
                    Point { x: -3.0, y: -4.0 },
                    Point { x: -1.0, y: 3.0 },
                    Point { x: 2.0, y: 3.0 },
                    Point { x: -4.0, y: 0.0 },
                    Point { x: 1.0, y: 1.0 },
                    Point { x: -1.0, y: -1.0 },
                    Point { x: 3.0, y: -1.0 },
                    Point { x: -4.0, y: 2.0 },
                    Point { x: -2.0, y: 4.0 },
                ]),
                1.414213
            ),
            true
        );
    }
}
