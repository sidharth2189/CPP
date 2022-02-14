#include <vector>
#include <mutex>
//namespace Qe
//{
    template <typename T>
    class queue
    {
    private:
        std::vector<T> queue_;
        std::mutex mtx; 
    public:
        void push(T element);
        void pop();
        T front();
    }; 
//}

#include "queue.cpp"