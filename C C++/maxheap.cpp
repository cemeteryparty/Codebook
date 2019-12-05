#include <iostream>

class MaxHeap{
	private:
		int *heap;
		int size;
		int capacity;
	public:
		MaxHeap(int cap_arg = 10){
			if(cap_arg < 1){
				printf("Error : capacity should larger than 0.\n");
				printf("        resize capcity = 10.\n");
				cap_arg = 10;
			}
			capacity = cap_arg;
			size = 0;
			heap = new int [capacity + 1];
		}
		~MaxHeap(){
			delete [] heap;
		};
		void expand(){
			int *exp = new int [capacity * 2] + 1;
			for(int i = 1;i < size;i++)
				exp[i] = heap[i];
			delete [] heap;
			heap = exp;
		}
		void push(const int & value){
			if(size == capacity){
				expand();
				capacity *= 2;
			}
			int index = ++size;//index = 0:!beOccuipied,1:root
			while(index != 1 && heap[index / 2] < value){
				heap[index] = heap[index / 2];//parent down
				index >>= 1;
			}
			heap[index] = value;
		}
		void pop(){
			if(!size){
				printf("Error : Empty Heap can't implement pop().\n");
				return;
			}
			int last = heap[size--],index = 1,child = index * 2;//last element,ini to root,child
			//child & child + 1 are both child of same node
			while(child <= size){
				if(child < size && heap[child] < heap[child + 1])//detect the exist of child + 1
					child++;//max(heap[child],heap[child + 1])
				if(last > heap[child])
					break;//last element can put at index
				//can't
				heap[index] = heap[child];//rise child
				index = child;
				child = index * 2;
			}
			heap[index] = last;
		}
		int top(){
			if(!size){
				printf("Error : Empty Heap can't implement top().\n");
				return -1;
			}
			return heap[1];
		}
		int size_count(){
			return size;
		}
		int capacity_count(){
			return capacity;
		}
		bool empty(){
			if(!size)
				return true;
			return false;
		}
};
int main(int argc, char const *argv[]){
	MaxHeap h;
	int method,value;
	while(std::cin >> method){
		if(!method){//push
			std::cin >> value;
			h.push(value);
		}
		else if(method == 1)//top
			printf("%d\n",h.top());
		else if(method == 2)//size
			printf("%d\n",h.size_count());
		else if(method == 3)//capacity
			printf("%d\n",h.capacity_count());
		else{//pop
			printf("%d\n",h.top());
			h.pop();
			printf("%d\n",h.top());
		}
	}
	return 0;
}
