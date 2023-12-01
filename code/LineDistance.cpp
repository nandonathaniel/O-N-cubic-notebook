/*
Returns the signed distance between point p and the line con-
taining points a and b. Positive value on left side and negative
on right as seen from a towards b. a==b gives nan. P is sup-
posed to be Point<T> or Point3D<T> where T is e.g. double
or long long. It uses products in intermediate steps so watch
out for overflow if using int or long long. Using Point3D will
always give a non-negative distance.
*/
template<class P>
double lineDist(const P& a, const P& b, const P& p) {
	return (double)(b-a).cross(p-a)/(b-a).dist();
}
