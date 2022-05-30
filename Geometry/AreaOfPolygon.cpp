struct Point 
{ 
    double x; 
    double y; 
    Point(double a=0, double b=0) { x=a; y=b;} //constructor 
}; 

ll area_of_polygon(int vcount,Point polygon[]) { 
    int i; 
    ll s; 
    if (vcount<3) 
        return 0; 
    s=polygon[0].y*(polygon[vcount-1].x-polygon[1].x); 
    for (i=1;i<vcount;i++) 
        s+=polygon[i].y*(polygon[(i-1)].x-polygon[(i+1)%vcount].x); 
    return s/2; 
} 
