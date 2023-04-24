##说明
```
1. Mat

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
```