#include <iostream>
#include <pcl/common/io.h>
#include <pcl/io/pcd_io.h>
#include <gflags/gflags.h>
#include "utils/io/file_util.h"
#include "include/point_types.h"

//gflags argv
DEFINE_string(input_pcd_dir, "./fsd.pack", "input_pcd_dir");
DEFINE_string(output_pcd_dir, "./", "output_pcd_dir");

typedef pcl::PointCloud<PointXYZITRL> PPointCloud;


void pcdASCII_to_pcdBinary(std::string pcd_in, std::string pcd_out)
{

    PPointCloud::Ptr cloud_ptr(new PPointCloud());

    pcl::io::loadPCDFile(pcd_in, *cloud_ptr);

    std::string::size_type iPos = pcd_in.find_last_of('/') + 1;
    std::string pcd_file_name = pcd_in.substr(iPos, pcd_in.size() - iPos);
    std::string save_pcd_path = pcd_out + "/" + pcd_file_name;

    pcl::io::savePCDFileBinaryCompressed(save_pcd_path, *cloud_ptr);

    if (lib::FileUtil::Exists(save_pcd_path))
    {
        std::cout << "output pcd Exists! = " << save_pcd_path << std::endl;
    }

}


int main(int argc, char** argv) {

    gflags::ParseCommandLineFlags(&argc, &argv, true);
    std::cout << "input_pcd_dir = " << FLAGS_input_pcd_dir << std::endl;
    std::cout << "output_pcd_dir = " << FLAGS_output_pcd_dir << std::endl;
    std::vector<std::string> file_names;
    lib::FileUtil::GetFileList(FLAGS_input_pcd_dir, ".pcd", &file_names);

    for(auto file : file_names)
    {
        pcdASCII_to_pcdBinary(file, FLAGS_output_pcd_dir);

    }


    return 0;
}
