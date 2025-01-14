#include <gtest/gtest.h>

#include <RayCasting.h>
#include <Camera.h>
#include <Voxel.h>
/// @brief Basic test to check that data pipeline works
TEST(RayCastingTest, CheckCastingConstruction) {
    Camera camera;
    Voxel TSDF(3,4,5,0,0,0);
    RayCasting rayCastingRayCasting(TSDF, camera);
}


TEST(RayCastingTest, CheckFill_Pixel) {
	Camera camera;
    Voxel TSDF(100,100,200,50,50,0);
    for (int i =80;i<90;i++){
        float loc = 5.* i;
        float distance = TSDF.truncateDistance;
        TSDF.setDistance(0,0,loc, distance);
        TSDF.setDistance(-1,0,loc, distance);
        TSDF.setDistance(6,0,loc, distance);
        TSDF.setDistance(0,-1,loc, distance);
        TSDF.setDistance(0,6,loc, distance);
        TSDF.setDistance(-1,-1,loc, distance);
        TSDF.setDistance(6,6,loc, distance);
        TSDF.setDistance(-1,6,loc, distance);
        TSDF.setDistance(6,-1,loc, distance);

        

    }
    for (int i =90;i<=96;i++){
        float loc = 5.* i;
        float distance = TSDF.truncateDistance-(i-90)*5.;
        TSDF.setDistance(0,0,loc, distance);
        TSDF.setDistance(-1,0,loc, distance);
        TSDF.setDistance(6,0,loc, distance);
        TSDF.setDistance(0,-1,loc, distance);
        TSDF.setDistance(0,6,loc, distance);
        TSDF.setDistance(-1,-1,loc, distance);
        TSDF.setDistance(6,6,loc, distance);
        TSDF.setDistance(-1,6,loc, distance);
        TSDF.setDistance(6,-1,loc, distance);
        
    }
    for (int i =97;i<=103;i++){
        float loc = 5.* i;
        float distance = -(i-96)*5.;
        TSDF.setDistance(0,0,loc, distance);
        TSDF.setDistance(-1,0,loc, distance);
        TSDF.setDistance(6,0,loc, distance);
        TSDF.setDistance(0,-1,loc, distance);
        TSDF.setDistance(0,6,loc, distance);
        TSDF.setDistance(-1,-1,loc, distance);
        TSDF.setDistance(6,6,loc, distance);
        TSDF.setDistance(-1,6,loc, distance);
        TSDF.setDistance(6,-1,loc, distance);
        
    }
    
    RayCasting rayCastingRayCasting(TSDF, camera);
    rayCastingRayCasting.fill_pixel(0, 0);
    Surface surface = rayCastingRayCasting.getSurface();
    EXPECT_NEAR(surface.getVertex(0,0)(0), 0.,0.0001);
    EXPECT_NEAR(surface.getVertex(0,0)(1), 0.,0.0001);
    EXPECT_NEAR(surface.getVertex(0,0)(2), 480.,0.0001);
    EXPECT_NEAR(surface.getNormal(0,0)(0), 0.,0.0001);
    EXPECT_NEAR(surface.getNormal(0,0)(1), 0.,0.0001);
    EXPECT_NEAR(surface.getNormal(0,0)(2), -1.,0.0001);
    
}



