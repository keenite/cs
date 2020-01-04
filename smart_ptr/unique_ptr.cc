#include <iostream>
#include <memory>

struct Task {
   int mId;
   Task(int id):mId(id)
   {
      std::cout << "Task  "<< mId << " Constructor" << std::endl;
   }
   ~Task()
   {
      std::cout << "Task "<< mId << " Destructor" << std::endl;
   }
};

int main()
{
   //Create an empty pointer
   std::unique_ptr<int> ptr1;

   if (!ptr1) {
      std::cout << "ptr1 is empty" << std::endl;
   }

   if (ptr1 == nullptr) {
      std::cout << "ptr1 is empty" << std::endl;
   }

   //FIXME: Compile Error
   //std::unique_ptr<Task> taskPtr2 = new Task();

   //Create a unique_ptr object through raw pointer
   //Once Task23 out of scope, destructor will be called
   //Not matter normal or exception exit
   std::unique_ptr<Task> taskPtr(new Task(23));

   if (taskPtr != nullptr) {
      std::cout << "taskPtr is not empty" << std::endl;
   }
   //A unique_ptr object always the unique owner of associated raw pointer
   //Cannot copy unique_ptr, its only movable
   std::cout << taskPtr->mId << std::endl;

   std::cout << "Reset taskPtr" << std::endl;
   //Reset will destructor the taskPtr
   taskPtr.reset();
   if (taskPtr == nullptr) {
      std::cout << "taskPtr is empty" << std::endl;
   }

   //Unique_ptr is not copyable
   std::unique_ptr<Task> taskPtr2(new Task(55));
   if (taskPtr2 != nullptr) {
      std::cout << "taskPtr2 is not empty" << std::endl;
   }

   //FIXME:unique_ptr not copyable
   //taskPtr = taskPtr2;

   {
      //Transfer ownership
      std::unique_ptr<Task> taskPtr4 = std::move(taskPtr2);
      if (taskPtr2 == nullptr) {
         std::cout << "taskPtr2 is empty" << std::endl;
      } else {
         std::cout << "taskPtr2 is not empty" << std::endl;
      }
      if (taskPtr4 == nullptr) {
         std::cout << "taskPtr4 is empty" << std::endl;
      } else {
         std::cout << "taskPtr4 is not empty" << std::endl;
      }

      std::cout << taskPtr4->mId << std::endl;

      //taskPtr4 goes out of scope and deletes the associated raw pointer
   }

   std::unique_ptr<Task> taskPtr5(new Task(66));

   //Release the ownership to ptr
   Task* ptr = taskPtr5.release();
   if (taskPtr5 == nullptr) {
      std::cout << "taskPtr5 is empty" << std::endl;
   }

   std::cout << ptr->mId << std::endl;

   delete ptr;

   return 0;
}

