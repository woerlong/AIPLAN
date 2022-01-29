# Selenium模块学习笔记

## 使用Selenium模块

- 要安装与浏览器同版本的驱动
- 基础代码
'''from selenium import webdriver
- browser = webdriver.Edge(executable_patp='msedgedriver.exe)
- browser.get('https://github.com')'''

|函数或属性|功能|
|--------|---|
|browser.get()|访问网页|
|browser.maximize_window()|最大化浏览器窗口|
|browser.current_url()|获取当前网页的url|
|browser.get_cookies()|获取当前网页用到的cookie|
|browser.name|获取当前浏览器驱动程序的名称|
|browser.title|获取当前网页的标题|
|browser.page_source|获取当前网页的源代码|
|browser.current_window_handle|获取当前网页的窗口|
|browser.window_handle|获取当前浏览器驱动程序打开的所有网页的窗口|
|browser.refresh()|刷新当前网页|
|browser.quit()|关闭当前浏览器驱动程序打开的所有网页并退出驱动程序|
|browser.close()|关闭当前网页|
|browser.back()|返回上一页|

## Selenium模块的标签定位

|定位方式|函数|
|:-----:|---|
|id属性|find_element_by_id(标签的id属性值)|
|name属性|find_element_by_name(标签的name属性值)|
|class属性|find_element_by_class_name(标签的class属性值)|
|标签名称|find_element_by_tag_name(标签名)|
|链接文本精确定位|find_element_by_link_text(用于精确定位链接文本的关键词)|
|链接文本模糊定位|find_element_by_partial_link_text(用于模糊定位链接文本的关键词)|
|CSS选择器|find_element_by_css_selector(css选择器)|
|XPath表达式|find_element_by_xpath(XPath表达式)|
- > 上表中的函数定位的是满足条件的第一个标签，如果要定位满足条件的多个标签，则要将函数名中的“element”改成“elements”

## Selenium模块的标签操作

|函数或属性|功能|
|:------:|---|
|get_attribute()|获取标签的属性值|
|is_selected()|判断标签是否被选中|
|is_displayed()|判断标签是否显示|
|is_enabled()|判断标签是否可用|
|text|获取标签的文本内容|
|send_keys()|对标签进行赋值|
|tag_name()|获取标签的名称|
|size|获取标签的大小|
|location|获取标签的位置坐标|
|click()|单击选中的标签|

## Selenium模块模拟鼠标操作

#### 模拟鼠标的单击、双击、右击

- ActionChains类中，click()函数用于模拟鼠标单击操作；double——click()函数是模拟鼠标双击；context()函数用于模拟鼠标右击
- 下面为代码演示
   - from selenium import webdriver
   - from selenium.webdriver import ActionChains
   - browser = webdriver.Edge(executable_path='msedgedriver.exe')
   - browser.get('https://www.taobao.com')
   - search_button = browser.find_element_by_xpath('//*[@id='J_TSearchForm']/div[1]/button')
        > 找标签
   - actions = ActionChains(browser)
        > 利用WebDriver对象browser实例化一个ActionChains对象，命名为actions
   - actions.click(search_button).perform()
        > 调用click()函数模拟针对‘搜索’按钮的单击操作，再调用perform()函数执行该操作

#### 模拟鼠标的长按和松开

- click_and_hold()函数用于模拟鼠标的长按操作（按下鼠标且不松开）
- release()函数用于模拟松开长按的鼠标操作

#### 模拟鼠标的拖动

- drag_and_drop()函数用于模拟拖动鼠标的操作
- drag_and_drop_by_offset()函数用于模拟鼠标将目标拖动一定距离的操作（需要给出水平方向和垂直方向上的位移值）

#### 模拟鼠标的移动

- move_by_offset()函数由于模拟将鼠标移动一定距离的操作（需要给出水平方向和垂直方向上的位移值）
- move_to_element()函数用于模拟将鼠标移动到指定元素所在位置的操作

## 《iframe》标签的处理（此处是'<>'括号，下同）

- 网页里面的《iframe》是用于在一个网页中嵌套另一个网页，嵌套的网页可以作为一个独立的部分实现局部刷新，常用于表单的提交和第三方广告的异步加载等。
- 在《iframe》标签中，有其自己的《head》标签，《body》标签和其他标签，相当于一个嵌套在主页面中的子页面里
- 对于嵌套在《iframe》标签中的子页面，不能直接使用普通的标签定位方法来定位标签
- 要先用Selenium模块中的switch_to_frame()函数来跳转到这个新页面，再进行标签的定位。
- 下面是代码的演示
    - from selenium import webdriver
    - from selenium.webdriver import ActionChains
    - browser = webdriver.Edge(executable_path='msedgedriver.exe')
    - browser.implicitly_wait(10)
        > 设置隐式等待
    - browser.get('https://www.taobao.com')
    - shop_a = browser.find_element_by_xpath('/html/body/div[5]/div/div[1]/div/ul/a[1]/div[1]/img')
    - actions = ActionChains(browser)
    - actions.click(shop_a).perform()
    - browser.switch_to_window(browser.window_handles[-1])
        > 切换到打开的新页面
    - shop_one = browser.find_element_by_xpath('/html/body/div[2]/div[3]/ul/li[1]/a/img')
    - actions1 = ActionChains(browser)
        > browser对象中的页面跳转后，需要重新实例化ActionChains对象
    - action1.click(shop_one).perform()
    - browser.switch_to_window(browser.window_handles[-1])
        > 切换到打开的新页面
    - iframe_login = browser.find_element_by_id('sufei-dialog-content')
    - browser.switch_to_frame(iframe_login)
        > 切换到《iframe》标签中的子页面，即登录表单
    - user_input = browser.find_element_by_xpath('//*[@id="fm-login-id"]')
        > 定位登录表单中的用户名输入框
    - user_input.send_keys('12344')
        > 在输入框中输入“12344”
    - browser.quit()
        > 关闭所有页面，退出浏览器驱动程序

## 显式等待和隐式等待

在使用Selenium模块模拟用户操作浏览器时，浏览器会对要加载的网页用到的所有资源发送请求，然而网络阻塞或服务器繁忙等原因会导致各个资源的加载进度不一致，
如果在网页尚未完全加载时就进行定位标签等操作，就有可能因为标签不存在而出错。
对此我们要设置延时。python内置的time模块可以实现让程序等待指定的时间。但Selenium模块里面也有等待

1. 显式等待

显式等待是指当指定条件成立时再进行下一步操作，如果条件一直不成立就一直等待，直到等待时间达到了设定的超时时间才会报错
- 使用显式等待需要使用WebDriverWait类，传入WebDriver对象和超时时间作为参数，配合until()或until_not()函数进行条件设定
- 下面为代码演示
    - from selenium import webdriver
    - from selenium.webdriver.common.by import By
    - from selenium.webdriver.support import expected_conditions as EC
    - from selenium.webdriver.support.ui import WebDriverWait
    - browser = webdriver.Edge(executable_path='msedgedriver.exe')
    - browser.get('https://www.taobao.com')
    - element = WebDriverWait(driver=browser, timeout=10).until(EC.presence_of_element_located((By.ID, 'q')))
        > until()函数再等待期间会每隔一段时间就判断元素是否存在，直到返回值不是False，如果超时，则报错
    - element = WebDriverWait(driver=browser, timeout=10).until_not(EC.presence_of_element_located((By.ID, 'w')))
        > until_not()函数再等待期间会每隔一段时间就判断元素是否存在，直到返回值不是False，如果超时，则报错

2. 隐式等待

隐式等待是指再实例化浏览器的WebDriver对象时，为该对象设置一个超时时间，在操作该对象时，代码遇到元素为加载完毕或者不存在时，
会在规定的超时时间内不断的刷新页面来寻找该元素，直到找到该元素，如果超过超时时间还是找不到该元素，则会报错。
这种方法仅适用于元素缺少的情况。
- 下面为代码的演示
    - from selenium import webdriver
    - from selenium.webdriver.support.ui import WebDriverWait
    - browser = webdriver.Edge(executable_path='msedgedriver.exe')
    - browser.get('https://www.taobao.com')
    - browser.implicitly_wait(10)
        > 设置隐式等待，超时时间为10秒