/**
 * @file deque.cpp
 * Implementation of the Deque class.
 *
 */

/* No argument constructor */
template <class T>
Deque<T>::Deque():n1(-1),n2(-1){}



/**
 * Adds the parameter object to the right of the Deque.
 *
 * @param newItem object to be added to the Deque.
 */
//template <class T>
//void Deque<T>::pushR(T newItem)
//{
//    data.push_back(newItem);
//    n2 = n2 + 1;
//    n1 = 0;
//}
template <class T>
void Deque<T>::pushR(T newItem)
{
    if (data.empty()) {
        data.push_back(newItem);
        n1 = 0;
    }
//
    else {
      if(n2 < data.size()-1){
        data[n2+1] = newItem;
      }else{
        data.push_back(newItem);
      }
    }
    n2 = n2 + 1;
    
}

/**
 * Removes the object at the left of the Deque, and returns it to the
 * caller.
 *
 * See .h file for implementation notes.
 *
 * @return The item that used to be at the left of the Deque.
 */
//template <class T>
//T Deque<T>::popL()
//{
//    T revtal = data[n1];
//if(data.size() == 1){
//        data.pop_back();
//        n1 = -1;
//        n2 = -1;
//        return revtal;
//  }else{
//      int half = data.size() / 2;
//      n1 = n1 + 1;
//      if (n1 == half) {
//          data.erase(data.begin(),data.begin()+half);
//          n1 = 0;
//          n2 = n2 - half;
//      }
//
//
//      //n1 = 0;
////      data.pop_back();
//    }
//      return revtal;
//}

template <class T>
T Deque<T>::popL()
{
    T revtal = data[n1];
//if(data.size() == 1){
  if(n2 - n1 == 0) {
//        data.pop_back();
      vector<T> newVec;
      data = newVec;
        n1 = -1;
        n2 = -1;
        return revtal;
  }else{
      int half = data.size() / 2;
      n1 = n1 + 1;
      // even
      if (data.size()%2==0) {
          if (n1 == half) {
              vector<T> newVec;
              for (int i=n1; i < data.size(); i++) {
                  newVec.push_back(data[i]);
              }
              n1 = 0;
              n2 = n2 - half;
              data = newVec;
          }
          // odd
      }else{
          if (n1 == half + 1) {
              vector<T> newVec;
              for (int i=n1; i < data.size(); i++) {
                  newVec.push_back(data[i]);
              }
              n1 = 0;
              n2 = n2 - half - 1;
              data = newVec;
      }
      }
      
      int distance = n2 - (n1-1);
      if (distance == half) {
          vector<T> newVec;
          newVec.clear();
          for (int i=n1; i<=n2; i++) {
            newVec.push_back(data[i]);
          }
          data = newVec;
          n1 = 0;
          n2 = data.size() - 1;
      }
    }
      return revtal;
}



/**
 * Removes the object at the right of the Deque, and returns it to the
 * caller.
 *
 * @return The item that used to be at the right of the Deque.
 */
//template <class T>
//T Deque<T>::popR()
//{
//    T retval = data[n2];
//      if(n2 == 0){
//        n1 = -1;
//        n2 = -1;
//        data.pop_back();
//      }else{
//          int half = data.size() / 2;
//          n2 = n2 - 1;
//          if (n2 == half - 1) {
//              data.erase(data.begin()+ half,data.begin()+data.size());
//          }
//    }
//      return retval;
//
//}
template <class T>
T Deque<T>::popR()
{
    T retval = data[n2];
      if(n2 == 0){
          vector<T> newVec;
        n1 = -1;
        n2 = -1;
//        data.pop_back();
          data = newVec;
      }else{
          int half = data.size() / 2;
          n2 = n2 - 1;
          if (data.size()%2==0) {
              if (n2 == half - 1) {
                  vector<T> newVec;
                  for (int i=0; i<=n2; i++) {
                      newVec.push_back(data[i]);
                  }
                  data = newVec;
              }
          } else {
              if (n2 == half) {
                  vector<T> newVec;
                  for (int i=0; i<=n2; i++) {
                      newVec.push_back(data[i]);
                  }
                  data = newVec;
              }
          }
          
          int distance = n2 - (n1-1);
          if (distance == half) {
              vector<T> newVec;
              newVec.clear();
              for (int i=n1; i<=n2; i++) {
                newVec.push_back(data[i]);
              }
              data = newVec;
              n1 = 0;
              n2 = data.size() - 1;
          }
          
    }
      return retval;
    
}

/**
 * Finds the object at the left of the Deque, and returns it to the
 * caller. Unlike popL(), this operation does not alter the deque.
 *
 * @return The item at the front of the deque.
 */
template <class T>
T Deque<T>::peekL()
{
    return data[n1];
}



/**
 * Finds the object at the right of the Deque, and returns it to the
 * caller. Unlike popR(), this operation does not alter the deque.
 *
 * @return the value of The item at the right of the deque.
 */
template <class T>
T Deque<T>::peekR()
{
    return data[n2];
}



/**
 * Determines if the Deque is empty.
 *
 * @return bool which is true if the Deque is empty, false otherwise.
 */
template <class T>
bool Deque<T>::isEmpty() const
{
    return n1 == -1;
}
