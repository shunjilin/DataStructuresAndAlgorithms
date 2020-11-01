use std::collections::HashSet;
use std::iter::FromIterator;

/// Problem 4 - Collecting Singatures
///
/// Returns minimum set of points that cover all given segments on a plane
pub fn min_set_of_points_covering_segments(mut segments: Vec<Segment>) -> HashSet<u64> {
    // sort segments by end points
    segments.sort_by(|a, b| a.end.cmp(&(b.end)));
    let mut points: Vec<u64> = vec![];
    segments.iter().for_each(|segment| {
        // check if covered by previous points
        if !points.is_empty() {
            let point = points.last().unwrap();
            if point_covers_segment(*point, segment) {
                return;
            }
        }
        points.push(segment.end)
    });
    HashSet::from_iter(points)
}

fn point_covers_segment(point: u64, segment: &Segment) -> bool {
    segment.start <= point && segment.end >= point
}

#[derive(Clone, Copy)]
pub struct Segment {
    start: u64,
    end: u64,
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn covers_segments() {
        let segments = vec![
            Segment { start: 4, end: 7 },
            Segment { start: 1, end: 3 },
            Segment { start: 2, end: 5 },
            Segment { start: 5, end: 6 },
        ];
        let points = min_set_of_points_covering_segments(segments.clone());
        let covered_segments_removed: Vec<_> = segments
            .iter()
            .filter(|segment| {
                !points
                    .iter()
                    .any(|point| segment.start <= *point && segment.end >= *point)
            })
            .collect();
        assert_eq!(covered_segments_removed.is_empty(), true);
    }

    #[test]
    fn returns_minimum_set_of_points_covering_segments() {
        let segments = vec![
            Segment { start: 4, end: 7 },
            Segment { start: 1, end: 3 },
            Segment { start: 2, end: 5 },
            Segment { start: 5, end: 6 },
        ];
        let points = min_set_of_points_covering_segments(segments);
        assert_eq!(points.len(), 2);
    }
}
