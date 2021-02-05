#include "save_file.h"

// void cleaning_file(const std::string& folder_name, const std::string& file_name,
//                    std::string& full_ret_file) {
//   full_ret_file = THIS_COM + folder_name + file_name;
//   full_ret_file += ".txt";

//   std::list<std::string>::iterator iter = std::find(
//       gs_fileName_string.begin(), gs_fileName_string.end(), full_ret_file);
//   if (gs_fileName_string.end() == iter) {
//     gs_fileName_string.push_back(full_ret_file);
//     remove(full_ret_file.c_str());
//   }
// }

// void create_folder(const std::string& folder_name) {
//   std::string full_path = THIS_COM + folder_name;

//   if (mkdir(full_path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1) {
//     if (errno == EEXIST) {
//       // alredy exists
//       // printf("%s is already exist\n", full_path.c_str());
//     } else {
//       // something else
//       std::cout << "cannot create session name folder error:" << strerror(errno)
//                 << std::endl;
//       exit(0);
//     }
//   }
// }



template <typename T>
SaveFileManager<T>::SaveFileManager(const std::string file_name, const std::string folder_name)
  :file_name(file_name),
   folder_name(folder_name)
{
  cleaning_file();
  savefile.open(full_ret_file.c_str(), std::ios::app);
}

template <typename T>
void SaveFileManager<T>::cleaning_file()
{
  full_ret_file = THIS_COM + folder_name + file_name;
  full_ret_file += ".txt";

  std::list<std::string>::iterator iter = std::find(
      gs_fileName_string.begin(), gs_fileName_string.end(), full_ret_file);
  if (gs_fileName_string.end() == iter) {
    gs_fileName_string.push_back(full_ret_file);
    remove(full_ret_file.c_str());
  }
}

template <typename T>
void SaveFileManager<T>::create_folder()
{
  std::string full_path = THIS_COM + folder_name;

  if (mkdir(full_path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1) {
    if (errno == EEXIST) {
      // alredy exists
      // printf("%s is already exist\n", full_path.c_str());
    } else {
      // something else
      std::cout << "cannot create session name folder error:" << strerror(errno)
                << std::endl;
      exit(0);
    }
  }
}

template <typename T>
void SaveFileManager<T>::saveVector(const DVec<T>& _vec)
{
  for (int i(0); i < _vec.rows(); ++i) {
      savefile << _vec(i) << "\t";
    }
    savefile << "\n";
    savefile.flush();
}

template <typename T>
void SaveFileManager<T>::saveVector(const Vec3<T>& _vec)
{
  saveVector((DVec<T>)_vec);
}

template <typename T>
void SaveFileManager<T>::saveVector(const std::vector<T>& _vec)
{
  for (unsigned int i(0); i < _vec.size(); ++i) {
    savefile << _vec[i] << "\t";
  }
  savefile << "\n";
  savefile.flush();
}

template <typename T>
void SaveFileManager<T>::saveVector(T* _vec, int size)
{
  for (int i(0); i < size; ++i) {
    savefile << _vec[i] << "\t";
  }
  savefile << "\n";
  savefile.flush();
}

template <typename T>
void SaveFileManager<T>::saveValue(std::string _value)
{
  savefile << _value << "\n";
  savefile.flush();
}

// template class SaveFileManger<double>;
template class SaveFileManager<float>;