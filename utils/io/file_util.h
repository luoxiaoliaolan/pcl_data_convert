// @file: file_util.h
// @brief:
#ifndef PERCEPTION_LIB_IO_FILE_UTIL_H_
#define PERCEPTION_LIB_IO_FILE_UTIL_H_

#include <string>
#include <vector>
#include "boost/algorithm/string/predicate.hpp"
#include "boost/filesystem.hpp"
#include "boost/algorithm/string.hpp"
#include "boost/lexical_cast.hpp"

namespace lib {

// custom file operate tools
enum FileType { TYPE_FILE, TYPE_DIR };

// file name compared type
enum FileCompareType {
  FCT_DIGITAL = 0,
  FCT_LEXICOGRAPHICAL = 1,
  FCT_UNKNOWN = 8
};

class FileUtil {
 public:
  FileUtil() {}

  ~FileUtil() {}

  // check whether file and directory exists
  static bool Exists(const std::string &filename);

  // check whether file exists with [suffix] extension in [path]
  static bool Exists(const std::string &path, const std::string &suffix);

  // check file type : directory or file
  static bool GetType(const std::string &filename, FileType *type);

  // remove file , include file and directory
  static bool DeleteFile(const std::string &filename);

  // rename file
  static bool RenameFile(const std::string &old_file,
                          const std::string &new_file);

  static bool GetFileContent(const std::string &path, std::string *content);
  static bool ReadLines(const std::string &path,
                         std::vector<std::string> *lines);

  static std::string RemoveFileSuffix(std::string filename);

  // TODO: this function stay just for compatibility,
  // should be removed later
  static bool GetFileList(const std::string &path, const std::string &suffix,
                            std::vector<std::string> *files);
  static void GetFilePaths(std::string &path, std::vector<std::string> *files);

  static bool GetFileList(const std::string &path,
                            std::vector<std::string> *files);

  static std::string GetAbsolutePath(const std::string &prefix,
                                       const std::string &relative_path);

  // get parent path as rank， "rank" must >= 0.
  // "/home/work/data/1.txt", rank = 0 -> "/home/work/data/"
  // "/home/work/data/1.txt", rank>=3 -> "/"
  // "/home/work/data/", rank = 0 -> "/home/work/data/"
  // "/home/work/data" and "data" is a real folder, rank = 0 -> "/home/work/data/"
  // "/home/work/data" and "data" is not a folder, rank = 0 -> "/home/work/"
  // "./space/work/data/1.txt", rank = 0 -> "./space/work/data/"
  // "./space/work/data/1.txt", rank>=3 -> "./"
  // "./space/work/data/", rank = 0 -> "./space/work/data/"
  // "./space/work/data" and "data" is a real folder, rank = 0 -> "./space/work/data/"
  // "./space/work/data" and "data" is not a folder, rank = 0 -> "./space/work/"
  // "space/work/data/1.txt", rank = 0 -> "./space/work/data/"
  // "space/work/data/1.txt", rank>=3 -> "./"
  // "space/work/data/", rank=0 -> "./space/work/data/"
  // "space/work/data" and "data" is a real folder, rank = 0 -> "./space/work/data/"
  // "space/work/data" and "data" is not a folder, rank = 0 -> "./space/work/"
  // "data" and "data" is a real folder, rank = 0 -> "./data/"
  // "a.txt", rank >= 0 -> "./"
  static std::string GetParentPath(const std::string &input_path, uint16_t rank);

  // get file name
  // "/home/work/data/1.txt" -> 1
  static void GetFileName(const std::string &file, std::string *name);

  // return -1 when error occurred
  static int NumLines(const std::string &filename);

  // compare two file's name by digital value
  // "/home/work/data/1.txt" < "/home/user/data/10.txt"
  // "1.txt" < "./data/2.txt"
  static bool CompareFileByDigital(const std::string &file_left,
                                      const std::string &file_right);

  // compare two file's name by lexicographical order
  static bool CompareFileByLexicographical(const std::string &file_left,
                                              const std::string &file_right);

  FileUtil(const FileUtil &) = delete;
  FileUtil &operator=(const FileUtil &) = delete;

 private:
  static bool CompareFile(const std::string &file_left,
                           const std::string &file_right, FileCompareType type);
};
}  // namespace lib

#endif  // PERCEPTION_LIB_IO_FILE_UTIL_H_

