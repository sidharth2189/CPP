#include <vector>
#include <mutex>
//namespace Qe
//{
    template <typename T>
    class Qvs
    {
    private:
        std::vector<T> queue_;
        std::mutex mtx; 
    public:
        void push(T element);
        void pop();
        T front();
        void print_q();
    }; 
//}

#include "queue.cpp"