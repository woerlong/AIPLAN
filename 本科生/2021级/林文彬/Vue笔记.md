#Vue

##一、引用Vue
<!-- 开发环境版本，包含了有帮助的命令行警告 -->
        <script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
        <!-- 生产环境版本，优化了尺寸和速度 -->
        <!--  <script src="https://cdn.jsdelivr.net/npm/vue"></script> -->

代码样例

        <div id="app">
        {{message}}
        </div>
        <script src="https://cdn.jsdelivr.net/npm/vue"></script>
        <script>
        var app=new Vue({
            el:"#app",
            data:{
                message:"Hello World"
            }
        })
        </script>

此段代码输出helloworld
在script的el中，el是选择器，选择Vue的作用域
 #app 通过id选择
 .app 通过class选择
 只有在作用域中的{{message}}才会被helloworld代替

##二、数据类型
普通字符串 message:"  "
数组 array:[1，2，3，4，5]
对象 obj:{
    name:" "
    class:" "
}

##三、各类关键字
###1、内容绑定，事件绑定
v-text,v-html,v-on
###2、显示切换，属性绑定
v-show,v-if,v-bind
###3、列表循环，表单元素绑定
v-for,v-on,v-model

###v-text


      <div id="app">
        <h2 v-text="message"></h2>
      </div>

      var app=new Vue({
          el:"#app",
          data:{
              message:"helloworld"
          }
      })

该段代码为输出helloworld，v-text实际上与{{message}}的效果一致

###v-html


     <div id="app">
     <p v-html="content">。。。</p>
     </div>

     var app=new Vue({
         el:"#app",
         data:{
             content:"<a href='#'>...</a>"
         }
     })

该段代码为输出一个链接，若content的数据不为网址，则v-html的作用与v-text的作用一样

###v-on
为元素绑定事件
v-on:click="方法"  单击触发   等价于@Click
v-on:monseenter="方法" 鼠标移动触发 等价于@monseenter
v-on:dbclick="方法" 双击触发 等价于@dbclick

var app=new Vue({
    el:"#app",
    methods:{
        方法一：方法名：function(){

        }
        方法二：方法名(){

        }
    }
})

###v-show
true使元素显示，false则隐藏元素

    <div id="app">
    <img src="" v-show="true">
    <img src="" v-show="isShow">
    </div>

    var app=new Vue({
        el:"#app",
        data:{
            isShow:false
        }
    })
第一个img可以显示，第二个显示不了

###v-if
v-if与v-show 类似
不同点在于，当v-if为false时，该部分直接不渲染所以不显示，而v-show是渲染了，但是不显示

###v-bind
设置元素的属性
v-bind:属性名=表达式

    <div id="app">
    <img v-bind:src="imgsrc"> <!--将src指向的地址变为imgsrc>
    </div>

    var app=new Vue({
        el:"#app",
        data:{
            imgsrc:"..."
        }
    })
该代码可用于快速改变引用图片的地址



###v-for
循环

    <div id="app">
        <ul>
            <li v-for="item in arr">{{item}}</li>
        </ul>
    </div>

    var app=new Vue({
        el:"#app",
        data:{
            arr:[1,2,3,4,5]
        }
    })

该代码用于循环输出数组中的元素
也可写成v-for=“（item，index）in arr" index为数组下标
{{index}}{{item}}为输出元素下标后再输出元素

若是对象

    var app=new Vue({
        el:"#app"
        data:{
            objarr:[{
                name:...
            }]
        }
    })

则用v-for="item in objarr" {{item.name}}输出

