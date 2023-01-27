class Solution {
    double r, x, y, pi = 3.14159265359 ;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius, x = x_center, y = y_center ;
    }
    
    vector<double> randPoint() {
        double length, theta ;
        double randnum1 = (double)rand()/RAND_MAX ;
        theta = randnum1*2*pi ;
        double randnum2 = (double)rand()/RAND_MAX ;
        length = sqrt(randnum2)*r ;
        double xx = x+ length*cos(theta) ;
        double yy = y+ length*sin(theta) ;
        return {xx,yy} ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
