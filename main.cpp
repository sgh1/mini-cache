#include <iostream>
#include <functional>
#include <tuple>
#include <map>

double f(int a, double b)
{
  return a+b;
}

namespace mini_cache
{

  template <typename R, typename... Args>
  class cache
  {
    public:
    
      cache(std::function<R(Args...)> f):
        f_(f)
      {}

      template <typename ...Params>
      R& operator()(Params&&... params)
      {
        // Create tuple of args/params.
        auto a = std::tuple<Params...>(std::forward<Params>(params)...);
        
        // See if the result we want is in the cache.
        auto it = cache_.find(a);
        if (it != cache_.end()){
          return it->second;
        }
        
        // Get iterator to new map entry.
        R* p_val = &cache_[a];
        
        // Assign value.
        *p_val = f_(std::forward<Params>(params)...);
        
        // Return value.
        return *p_val;
      }
      
      private:
      
      // The function for which the cache stores results.
      std::function<R(Args...)> f_;
      
      // The cache.
      std::map< std::tuple<Args...>, R > cache_;
    
  };
  
  template <int N, typename R, typename... Args>
  class lru_cache
  {
    
    struct lru_key
    {
      std::tuple<Args...> args_;
      //std::time_base last_used_;
    };
    
    
    
  };
           

}

int main()
{
  
  std::cout << "Hello World!\n";
  
  mini_cache::cache<double,int,double> c(f);
 
 std::cout << c(5,2) << "\n";
 
  
  return 0;
  
  
  
  
  
}
