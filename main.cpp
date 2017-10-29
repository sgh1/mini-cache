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
    
      
      R& operator()(Args&&... args)
      {
        // See if the result we want is in the cache.
        auto it = cache_.find(std::tuple<Args...>(args...));
        
        if (it != cache_.end())
          {
          return *it;
        }
        
        // It's not in the cache.  Compute, add, and return.
        R r = f_(args...);
        
        cache_[ std::tuple<Args...>(args...) ] = r;
        
        // TODO: one lookup.
        return cache_[ std::tuple<Args...>(args...) ];
      }
      
      
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
 
 std::cout << c.f_(5,2) << "\n";
 
  
  return 0;
  
  
  
  
  
}
