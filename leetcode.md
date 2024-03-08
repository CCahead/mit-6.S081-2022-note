可不可以新建一个数组储存这个链表啊？

如果我建一个ListNode类的数组的话，那从第二个元素开始就是：
dummy,Head,node1,node2...

然后他们有统一的数组下标，

那这个时候对他们的操作是怎么样的呢？

存储的数据是listnode*指针，那就相当于有一个顺序存储的地址数组

假设他们的地址顺序是这样的：

0x00,0x04,0x08,0x0C...那如果我想访问这个0x00所指向的那个node也可以直接使用解引用就可以操作了吧？这样既能够存储数据，又能够定位位置？



如果我要访问第一个元素，那就是v[1]，以此类推到v[n]；如果要删除倒数第n个元素的话，比如说删除v[3]的倒数第二个元素n=2：

那就是 1 2 3删除第二个，v[2]：

即v[size-n+1]是这个被删除元素；

v[size-n]是前一个元素，v[size-n+2]是后一个元素

那这个是要保证至少3个元素才能这么做吧？那就要考虑小于三个的情况

```
	=================================================================
==21==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x5020000000d8 at pc 0x55c41a21a794 bp 0x7fff0b667f90 sp 0x7fff0b667f88
READ of size 8 at 0x5020000000d8 thread T0
    #2 0x7f1f9a37ed8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f) (BuildId: c289da5071a3399de893d2af81d6a30c62646e1e)
    #3 0x7f1f9a37ee3f  (/lib/x86_64-linux-gnu/libc.so.6+0x29e3f) (BuildId: c289da5071a3399de893d2af81d6a30c62646e1e)
0x5020000000d8 is located 0 bytes after 8-byte region [0x5020000000d0,0x5020000000d8)
allocated by thread T0 here:
    #4 0x7f1f9a37ed8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f) (BuildId: c289da5071a3399de893d2af81d6a30c62646e1e)
Shadow bytes around the buggy address:
  0x501ffffffe00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x501ffffffe80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x501fffffff00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x501fffffff80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x502000000000: fa fa fd fa fa fa fd fa fa fa 00 00 fa fa 00 00
=>0x502000000080: fa fa 00 00 fa fa 00 00 fa fa 00[fa]fa fa fa fa
  0x502000000100: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x502000000180: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x502000000200: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x502000000280: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x502000000300: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==21==ABORTING
但为什么会报错堆溢出呢？
```

```c

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*>v;
        ListNode* tmp=head;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        v.push_back(dummy);
        while(!tmp){
            v.push_back(tmp);
            tmp=tmp->next;
        }
        if(n==0){
            v[v.size()-1]->next=nullptr;
        }else{
        v[v.size()-n]->next=v[v.size()-n+2];
        // free(v[v.size()-n]);
        }
        return dummy;
    
    }
     我现在的代码是这样的～
```



我稍微改了一下代码之后，我使用测试用例，会报这样的错：
Line 15: Char 16: runtime error: member access within misaligned address 0xbebebebebebebebe for type 'ListNode', which requires 8 byte alignment (__ListNodeUtils__.cpp) 0xbebebebebebebebe: note: pointer points here <memory cannot be printed> SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior __ListNodeUtils__.cpp:24:16

很奇怪？我为什么会出现错误呢？哦 好像是越界错误？？

因为如果我要加一个额外元素近来的话，那size也会变化哦！

假如链表共有n长时，那v在加入dummy之后就是n+1,size就是n+1!!!

方法是什么？先规定好： 链表长度为n







　对于滑动窗口而言，可能需要一个map来储存现在看见的字符，在每次进行插入操作的时候进行扫描，查看他的v是否大于1