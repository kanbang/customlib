import QtQuick 1.1
Item {
    function aboutChildren()
    {
        /**
          每一个Item都由一个children列表，此表是用来保存当前Item的孩子的。
          例如：

          Item {
          children = 1;
          MouseArea {
          children = 0;
                }
          }
          */
    }

    //子类文件调用父类的id、属性值、
    function useParentId()
    {
        /**
          //A.qml
          Item {
          id: _a
          property int val : 100

          B {

           }
          }
          //main.qml

          item {
            id: rect
            property int val : 200

            A {
                id: _aa;
            }

            B {
            //在B.qml文件中可以引用父对象的id(rect, _aa),此时，_a这个id已经不存在了
                因为在main.qml中A {id: _aa }  已经把A 的id改了。如果时这样：
                A {
                }
                B.qml里面就可以使用_a;
            }
          }

          //B.qml
          Item {
            // 在B里面，可以调用任何引用了B的父亲的属性值，id等等
            function showA（）
            {
                _a.width = 300;
                val = 2000;
            }
          }
          */
    }

    //边框光滑
    smooth: true
    // 画矩形的时候四个角的光滑角度,此属性在Rectangle中使用
   // radius: 30
    // 可以存放所有的基本类型。例如：
    property variant tabs : [1, 2, 3, "four", "five"]
}


