/*
    author : Anand
    Given a set of closed intervals, find the smallest set of numbers that covers all the intervals. If there are multiple smallest sets, return any of them.

    For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 9], one set of numbers that covers all these intervals is {3, 6}
*/

const findSmallestIntervalCoveringAllIntervals = intervals => {
	return intervals.reduce((smallestInterval, curInterval) => {
		curInterval.sort((a, b) => a - b);

		if (smallestInterval.length == 0) {
			return [curInterval[1], curInterval[1]];
		}
		if (smallestInterval[1] < curInterval[0]) {
			smallestInterval[1] = curInterval[0];
		}
		if (smallestInterval[0] > curInterval[1]) {
			smallestInterval[0] = curInterval[1];
		}
		return smallestInterval;
	}, []);
};

console.log(
	findSmallestIntervalCoveringAllIntervals([[0, 3], [2, 6], [3, 4], [6, 9]])
);
