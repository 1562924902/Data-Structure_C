typedef int KeyType; /* 定义关键字类型为整型 */
typedef int InfoType;


typedef struct
{  KeyType key; /* 关键字项 */
InfoType otherinfo; /* 其它数据项，具体类型在主程中定义 */
}ElemType; /* 记录类型 */

typedef struct
{
ElemType *elem; /* 数据元素存储基址，动态分配数组 */
int count; /* 当前数据元素个数 */
 /* 为当前容量 */
}HashTable;





  
