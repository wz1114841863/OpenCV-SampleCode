##说明
```
1. Mat
由两个数据部分组成，矩阵头和一个指向存储所有像素值的矩阵
引用计数，拷贝构造和移动构造仅增加引用计数，每个对象仅由矩阵头信息不同，指向矩阵的指针相同
想要完全拷贝应该使用clone \ copyTo
同时支持使用不同类型的输出风格打印数组
2. InputArray

3. vecXX
Vec2b：表示每个Vec2b对象中,可以存储2个char(字符型)数据
Vec3b：表示每一个Vec3b对象中,可以存储3个char(字符型)数据,比如可以用这样的对象,去存储RGB图像
Vec4b：表示每一个Vec4b对象中,可以存储4个字符型数据,可以用这样的类对象去存储—4通道RGB+Alpha的图

4. bool imgWrite(const string &fileName, InputArray img, const vector<int> &param = vector<int>());
保存图像，其中最后一个参数是针对不同格式的图像设定具体的编码格式

5. saturate_cast<type>()
限制值的范围再type类型内

6. int createTrackbar(const string &trackbarame, const string &winname, int *value, int count, 
TrackbarCallback onChange=0, void *userdata=0);
value: 滑块的初始位置， count：滑块能到达的最大位置
TrackbarCallback: 回调函数， void XXX(int , void *); userdata: 用户传给回参函数的数据

7. operationsOnArrays:LUT()<lut>
用于批量进行图像元素查找、扫描与操作图像

```