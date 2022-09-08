#include<bits/stdc++.h>
using namespace std;

// points on a sphere
class point
{
private:
    double latitude;
    double longitude;
    double PI = acos(-1);
public:
    point(double x,double y)
    {
        this->latitude=x;
        this->longitude=y;
    }
    friend ostream& operator<<(ostream& os,point p)
    {
        os<<"("<<p.latitude<<","<<p.longitude<<")";
        return os;
    }
    double angle(point p)
    {
        // in radians
        return atan2(p.latitude-this->latitude,p.longitude-this->longitude);
    }
    double toRadians(double x)
    {
        return x*M_PI/180;
    }
    double toDegrees(double x)
    {
        return x*180/M_PI;
    }
    double distance(point p, double r=6371000)
    {
        // in meters
        double lat1=this->latitude*M_PI/180;
        double lat2=p.latitude*M_PI/180;
        double lon1=this->longitude*M_PI/180;
        double lon2=p.longitude*M_PI/180;
        double dlat=lat2-lat1;
        double dlon=lon2-lon1;
        double a=sin(dlat/2)*sin(dlat/2)+cos(lat1)*cos(lat2)*sin(dlon/2)*sin(dlon/2);
        double c=2*atan2(sqrt(a),sqrt(1-a));
        return r*c;
    }
    point rotate(double deg, double min=0, double sec=0)
    {
        // rotate by deg min sec
        double angle=deg+min/60+sec/3600;
        angle=angle*M_PI/180;
        double x=this->latitude*cos(angle)-this->longitude*sin(angle);
        double y=this->latitude*sin(angle)+this->longitude*cos(angle);
        return point(x,y);
    }
};

int main()
{
    vector<pair<string,point>> places;
    // places.push_back({"A",point(0,0)});
    places.push_back({"Home",point(12.886111018915114, 30.88839252864935)});
    places.push_back({"Office",point(12.300803, 30.871997)});
    places.push_back({"Playground",point(12.902151, 30.866697)});
    places.push_back({"Hospital",point(10.792796, 20.371025)});
    places.push_back({"Shop",point(10.764920, 20.417488)});
    places.push_back({"City",point(10.710659, 20.378514)});
    places.push_back({"Park",point(10.771622,20.419537)});
    sort(places.begin(),places.end(),[&](pair<string,point> a,pair<string,point> b)
    {
        return a.second.distance(places[0].second)<b.second.distance(places[0].second);
    });
    for(int i=0;i<places.size();i++)
    {
        cout<<places[i].first<<" "<<places[i].second.distance(places[0].second)/1000<<" km"<<endl;
    }
    return 0;
}