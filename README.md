## 项目简介

_**All-in-One**_ 数据包`序列`/`反序列`化 库，支持`C`/`C++`通过CMake调用该库。

## 开始使用

1. 将本仓库作为子模组克隆到项目仓库

    ```shell
    # 此处使用gitee镜像
    # 推荐新建一个3rdparty文件夹用于存储第三方库
    # mkdir 3rdparty
    git submodule add https://gitee.com/dlmu-cone/one-packet.git ./3rdparty/one-packet
    # 注册子模组
    git submodule update --init --recursive
    ```

2. 在CMake中导入本项目，并将Target与本项目的动态库进行链接

    ```cmake
    set(COMPILE_OP_EXAMPLE OFF) # 禁用生成示例程序
    set(COMPILE_OP_CTEST OFF) # 禁用生成CTest
    add_subdirectory(one-packet)
    target_link_libraries(target PRIVATE OnePacket)
    ```

3. 在C/C++中使用此库。

   ```c++
   #include "packets/CustomControllerPacket.h"
   #include "serialize.h"
   uint8_t buffer[50] = {};
   CustomControlPacket packet;
   
   int main() {
       init_custom_control_packet(&packet);
       serialize(&packet, buffer, 50);
       deserialize(buffer, &packet);
       return 0;
   }
   ```

## 添加数据包

### 标准数据包

- 在`./include/packets`文件夹下新建一个Packet的定义文件。数据包由`命令码`和`数据段`两部分组成。除了`cmd`字段为`命令码`
  外，其余部分统一算作`数据段`。此处参考XenoSlavePacket.h
   ```c++
   #ifndef XENOSLAVEPACKET_H
   #define XENOSLAVEPACKET_H
   
   #include <stdint.h>
   
   typedef struct __attribute__((packed)) {
   const uint16_t cmd;
   // unit: mm
   float lift; // z-axis
   float stretch; //y-axis
   float shift; // x-axis
   // unit: degree/s
   float suck_rotate; // rotate speed of end effector
   // unit: degree
   float r1;
   float r2;
   float r3;
   } XenoSlavePacket;
   
   static void init_xeno_slave_packet(XenoSlavePacket *packet) {
   *((uint16_t *) &packet->cmd) = 0x0201;
   }
   
   #endif //XENOSLAVEPACKET_H

   ```
- 在`src/DataLength.cpp`下填入命令码与结构体数据部分字节数的关系。比如：对于`XenoSlavePacket`而言，除了`cmd`字段外有7个
  `float`变量，每个`float`变量占用`4`字节，因此数据段长度为`28`。
   ```c++
   #include "DataLength.hpp"

   DataLengthMap data_length_map = {
       {0x0101, 1},
       {0x0201, 28} // 新增的部分
   };

   ```

- 重新运行CMake进行编译，即可正常使用serialize/deserialize函数操作新的数据包。

- 为了防止不可预料结果的发生，标准数据包的结构需满足以下要求：
    - 必须拥有`packed`特征；
    - `cmd`字段需要设置为`const`；
    - 数据包数据段长度不能超过`255`字节。

### 自定义数据包

TBD

## TODO

- 大疆通信协议支持
- Benchmark测试