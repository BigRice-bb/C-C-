//利用模版实现一个通用型的数组类
//堆区开辟数组空间-T *paddress
//需要完成赋值-故需要重载=  operator=(),不需要重载=
//需要完成索引,故需要重载[] operator[]
//m_capacity记录数组容量
//m_size记录数组大小
//有参构造  myarray(int capacity) 
//拷贝构造  myarray(const myarray &arr)
//需要提供接口让用户获取数组大小和数组容量
//需要提供方法让用户对数组进行尾插

template<class T>
class myarray
{
public:
//第一步,实现有参构造
    myarray(int capacity)
    {
        cout<<"有参构造函数调用"<<endl;
        this->m_capacity=capacity;
        this->m_size=0;
        this->m_paddress=new T[capacity];
    }
    //第二步,myarray[1]=6,重载[]
    //用引用来接收
    T& operator[](int index)
    {
        return this->m_paddress[index];
    }
    //第三步,实现拷贝构造
    myarray(const myarray &arr)
    {
        cout<<"拷贝构造函数调用"<<endl;
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->m_paddress = new T[this->m_capacity];
        for (int i = 0; i < this->m_capacity; i++)
        {
            this->m_paddress[i] = arr.m_paddress[i];
        }
    }
    //第四步,实现尾插函数
    void pushback(const T &val)
    {
        if (this->m_size == this->m_capacity)
        {
            return;
        }
        this->m_paddress[this->m_size] = val;
        this->m_size++;
    }
    //重载=号操作符 arr1=arr2
    myarray& operator=(const myarray &arr)
    {
        //先判断原来堆区是否有数据，如果有，先释放
        if (this->m_paddress != NULL)
        {
            delete[] this->m_paddress;
            this->m_paddress = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }
        //深拷贝
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->m_paddress = new T[this->m_capacity];
        for (int i = 0; i < this->m_size; i++)
        {
            this->m_paddress[i] = arr.m_paddress[i];
        }
        return *this;
    }

    //获取数组容量接口函数
    int getCapacity()
    {
        return this->m_capacity;
    }
    //获取数组大小接口函数
    int getSize()
    {
        return this->m_size;
    }
    //析构函数
    ~myarray()
    {
        cout << "析构函数调用" << endl;
        if (this->m_paddress != NULL)
        {
            delete[] this->m_paddress;
            this->m_paddress = NULL;
        }
    }

private:
    T *m_paddress;//指向堆区开辟的真实数组的指针
    int m_capacity;//数组容量
    int m_size;//数组大小
};

//封装一个打印数组的函数
template<class T>
void showarray(myarray<T> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}



