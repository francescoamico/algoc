void mergeSort(void **array,size_t size,int (*sgn)());
void divide(void **array,size_t low,size_t high,int (*sgn)());
void merge(void **array,size_t left,size_t middle1,size_t middle2,size_t right,int (*sgn)());
int ascending();
int descending();