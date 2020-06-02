#include <iostream>
#include <string>
#include <experimental/filesystem>
#include <chrono>
#include <vector>

namespace fs = std::experimental::filesystem ;

bool is_older_than( const fs::path& path, int hrs )
{
    auto now = fs::file_time_type::clock::now() ;
    using namespace std::chrono ;
    return duration_cast<hours>( now - fs::last_write_time(path) ).count() > hrs ;
}

std::vector<fs::path> files_older_than( fs::path dir, int hrs )
{
    std::vector<fs::path> result ;

    for( const auto& p : fs::recursive_directory_iterator(dir) )
        if( fs::is_regular_file(p) && is_older_than( p, hrs ) ) result.push_back(p) ;

    return result ;
}

std::pair<int,bool> remove_files_older_than( fs::path dir, unsigned int hour )
{
    int cnt = 0 ;
    try
    {
        for( const auto& p : files_older_than( dir, hour ) )
        {
            fs::remove(p) ;
            ++cnt ;
        }
        return { cnt, true };
    }
    catch( const std::exception& ) { return { cnt, false } ; }
}
int main(){
  std::string folder = "../file";// not quite sure relative path can work or not
  auto ans = remove_files_older_than(folder, 1);
  std::cout<<"fist is " << ans.first << ", second is " << ans.second << std::endl;
}
