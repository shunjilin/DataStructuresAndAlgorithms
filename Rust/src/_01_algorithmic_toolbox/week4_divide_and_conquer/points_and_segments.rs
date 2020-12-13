///
/// Problem 5 - Organizing a Lottery
/// Given a set of segments, and a set of points on a line,
/// return the number of segments which contain each point (ends inclusive)
pub fn count_segments_covering_points(segments: &[Segment], points: &[i64]) -> Vec<i64> {
    // convert segments and points to Points
    let mut all_points = vec![];
    for segment in segments {
        all_points.push(Point {
            point: segment.start,
            point_type: PointType::Start,
            index: None,
        });
        all_points.push(Point {
            point: segment.end,
            point_type: PointType::End,
            index: None,
        });
    }
    for (index, point) in points.iter().enumerate() {
        all_points.push(Point {
            point: *point,
            point_type: PointType::Point,
            index: Some(index),
        })
    }
    // sort by position and type
    all_points.sort_by(|a, b| {
        if a.point == b.point {
            return a.point_type.partial_cmp(&b.point_type).unwrap();
        }
        a.point.cmp(&b.point)
    });
    let mut count = 0;
    let mut counts = vec![0; points.iter().count()];
    for point in all_points {
        match point.point_type {
            PointType::Start => count += 1,
            PointType::End => count -= 1,
            PointType::Point => counts[point.index.unwrap()] = count,
        }
    }
    counts
}

#[derive(PartialEq, PartialOrd)]
enum PointType {
    Start,
    End,
    Point,
}

struct Point {
    point: i64,
    point_type: PointType,
    index: Option<usize>,
}

pub struct Segment {
    start: i64,
    end: i64,
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn returns_correct_counts() {
        assert_eq!(
            count_segments_covering_points(
                &vec![Segment { start: 0, end: 5 }, Segment { start: 7, end: 10 }],
                &vec![1, 6, 11]
            ),
            vec![1, 0, 0]
        );
        assert_eq!(
            count_segments_covering_points(
                &vec![Segment {
                    start: -10,
                    end: 10
                },],
                &vec![-100, 100, 0]
            ),
            vec![0, 0, 1]
        );
        assert_eq!(
            count_segments_covering_points(
                &vec![
                    Segment { start: 0, end: 5 },
                    Segment { start: -3, end: 2 },
                    Segment { start: 7, end: 10 }
                ],
                &vec![1, 6]
            ),
            vec![2, 0]
        );
    }
}
