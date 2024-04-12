/* Binary Search for array of 100*/


#include <iostream>

using namespace std;

template <typename T, size_t N> /* <-- func template for generic code. 
typename T - creates a generic data type variable,
meaning that the data type would be passed as parameter but called T inside the function.
size_t - It’s a type which is used to represent the size of objects in bytes and is therefore used as the return type by the sizeof operator.
When we use a size_t object, we have to make sure that in all the contexts it is used, including arithmetic, we want only non-negative values. */
size_t arrlen(const T (&arr)[N]){
    return N; // <-- somehow returns the amount of elements and not size in bytes or anything
}

int binarySearch(const int arr[], const int target, const size_t length){
    // low is a "pointer" to the first element, high is "pointer" to the last
    int low = 0, high = length - 1; 

    cout << "Low" << '\t' << "High" << '\t' << "Value pos" << '\t' << "Value" << endl;

    while (low <= high) { // <-- as long as we have elements to check

        int middle = low + ((high - low) / 2); // <-- some shitty formula
        int val = arr[middle];

        cout << low << '\t' << high << '\t' << middle << "\t\t" << arr[middle] << endl;

        if (val < target) { low = middle + 1; }
        /* if the value in the middle of the section is less than our target,
        move the "first position pointer"(low) over the middle forward by one to cut off the first half of the section */
        else if (val > target) { high = middle - 1; }
        /* if the value is bigger, move the "last position pointer"(high) over the middle backwards by one
        to cut off the second half of the section*/
        else { return middle; }
        /* finally return the value */

    }
    
    return -1; /* returns -1 if target was not found */
}

int main(){
    //Create and fill an array

    int nums[100000];
    size_t numsLength = arrlen<int>(nums); /* <-- could be done with sizeof() method that returns size of parameter in bytes, therefore... 
    length of an array is a division of byte size of it by the bite size of its element, but was decided to flex */
    for (int i = 0; i < numsLength; i++){ nums[i] = i;} // <-- already sorted

    //Request a target
    int target;
    cout << "Enter your target form 0 to " << numsLength << ": ";
    cin >> target;

    /* int index = binarySearch(nums.data, target, numsLength); */
    int index = binarySearch(nums, target, numsLength);
    
    
    /* if (index != -1) { cout << target << " has been found at " << index; }
    else { cout << target << " has been not found.";} */
    if (index != -1 ) { cout << target << " has been found at " << index; }
    else { cout << target << " has been not found.";}

    return 0;
}

