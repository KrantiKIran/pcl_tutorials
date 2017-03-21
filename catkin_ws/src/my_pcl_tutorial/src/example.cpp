#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
 #include <pcl/visualization/cloud_viewer.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <stdlib.h>

pcl::visualization::CloudViewer viewer ("Simple Cloud Viewer");
void 
cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input)
{
  // Create a container for the data.
  // sensor_msgs::PointCloud2 output;

  // // Do data processing here...
  // output = *input;
  pcl::PCLPointCloud2 pcl_pc2;
  pcl_conversions::toPCL(*input,pcl_pc2);
  pcl::PointCloud<pcl::PointXYZ>::Ptr temp_cloud(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::fromPCLPointCloud2(pcl_pc2,*temp_cloud);

   //... populate cloud
   viewer.showCloud(temp_cloud);
  if(viewer.wasStopped())
    exit (0);
  // Publish the data.
 //  pub.publish (output);
}

int
main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "my_pcl_tutorial");
  ros::NodeHandle nh;
 // pub = nh.advertise<sensor_msgs::PointCloud2> ("output", 1);
  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("velodyne_points", 1, cloud_cb);

  // Create a ROS publisher for the output point cloud
  

  // Spin
  ros::spin ();
}


// #include <ros/ros.h>
// // PCL specific includes
// #include <sensor_msgs/PointCloud2.h>
// #include <pcl_conversions/pcl_conversions.h>
//  #include <pcl/visualization/cloud_viewer.h>
// #include <pcl/point_cloud.h>
// #include <pcl/point_types.h>
// #include <boost/thread/thread.hpp>
// #include <pcl/common/common_headers.h>
// #include <pcl/features/normal_3d.h>
// #include <pcl/io/pcd_io.h>
// #include <pcl/visualization/pcl_visualizer.h>
// #include <pcl/console/parse.h>

    
// //int user_data;
// pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
//    //  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
//        //viewer->setBackgroundColor (0, 0, 0);
// void 
// viewerOneOff (pcl::visualization::PCLVisualizer& viewer)
// {
//     viewer.setBackgroundColor (1.0, 0.5, 1.0);
//     pcl::PointXYZ o;
//     o.x = 1.0;
//     o.y = 0;
//     o.z = 0;
//     viewer.addSphere (o, 0.25, "sphere", 0);
//     std::cout << "i only run once" << std::endl;
    
// }

// void
// cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input)
// {
//   // Create a container for the data.
  
//   pcl::PCLPointCloud2 pcl_pc2;
//     pcl_conversions::toPCL(*input,pcl_pc2);
//     pcl::PointCloud<pcl::PointXYZ>::Ptr temp_cloud(new pcl::PointCloud<pcl::PointXYZ>);
//     pcl::fromPCLPointCloud2(pcl_pc2,*temp_cloud);
//   cloud=temp_cloud;
//    //... populate cloud
//   //cloud=temp_cloud;
  
//   // Publish the data.
  
// }
    
// void 
// viewerPsycho (pcl::visualization::PCLVisualizer& viewer)
// {
//     static unsigned count = 0;
//     std::stringstream ss;
//     ss << "Once per viewer loop: " << count++;
//     viewer.removeShape ("text", 0);
//     viewer.addText (ss.str(), 200, 300, "text", 0);
    
//     //FIXME: possible race condition here:
//     user_data++;
// }
    
// int 
// main (int argc, char** argv)
// {
    
//     //pcl::io::loadPCDFile ("my_point_cloud.pcd", *cloud);
//     // Initialize ROS
//   	ros::init (argc, argv, "my_pcl_tutorial");
//   	ros::NodeHandle nh;

//   	// Create a ROS subscriber for the input point cloud
//     int i=-1;
//     if(i++)
// 	ros::Subscriber sub = nh.subscribe ("velodyne_points", 1, cloud_cb);


   
//     viewer->setBackgroundColor (0, 0, 0);
//     viewer->addPointCloud<pcl::PointXYZ> (cloud, "sample cloud");
//     if(i++)
//     ros::Subscriber sub = nh.subscribe ("velodyne_points", 1, cloud_cb);
//     //blocks until the cloud is actually rendered
//     //viewer.showCloud(cloud);
//     viewer->removePointCloud("sample cloud");
//     //use the following functions to get access to the underlying more advanced/powerful
//     //PCLVisualizer
    
//     //This will only get called once
//    // viewer.runOnVisualizationThreadOnce (viewerOneOff);
    
//     //This will get called once per visualization iteration
//   //  viewer.runOnVisualizationThread (viewerPsycho);
//     while (!viewer->wasStopped ())
//     {
//     //you can also do cool processing here
//     //FIXME: Note that this is running in a separate thread from viewerPsycho
//     //and you should guard against race conditions yourself...
//     // user_data++;
//     }
//     return 0;
// }

