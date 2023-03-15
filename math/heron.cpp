//Complexity: O(1)
//This formula is used to know the areo of a triangle
// a, b and c are the lenghts of the sides
// S = (a+b+c)/2
double heron(double s, double a, double b, double c){
  return sqrt(s*(s-a)*(s-b)*(s-c));
}
