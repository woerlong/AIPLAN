#   js学习
##  2022.1.18
    
    在爬取判决文书网时，发现有信息是加密的，需要逆向分析js
    通过断点调试查找到js解密代码如下：
    if (data.code == 1 || data.code == "success") {
        if(data.secretKey){
            **var obj = DES3.decrypt(data.result, data.secretKey);**
            try
            { 
                obj = $.parseJSON(obj) 
            }catch(e){}
            data.result = obj;
        }
    可以看出，这是一个用3DES进行加密的密文。
    但是问题在于，我通过常规的3DES解密，无法解出原文

    继续分析js文本，发现了用于解密的函数：

    var  = {
        iv: function() {
            return $.WebSite.formatDate(new Date(), "yyyyMMdd")
        },
        encrypt: function(b, c, a) {
            if (c) {
                return (CryptoJS.TripleDES.encrypt(b, CryptoJS.enc.Utf8.parse(c), {
                    iv: CryptoJS.enc.Utf8.parse(a || DES3.iv()),
                    mode: CryptoJS.mode.CBC,
                    padding: CryptoJS.pad.Pkcs7
                })).toString()
            }
            return ""
        },
        decrypt: function(b, c, a) {
            if (c) {
                return CryptoJS.enc.Utf8.stringify(CryptoJS.TripleDES.decrypt(b, CryptoJS.enc.Utf8.parse(c), {
                    iv: CryptoJS.enc.Utf8.parse(a || DES3.iv()),
                    mode: CryptoJS.mode.CBC,
                    padding: CryptoJS.pad.Pkcs7
                })).toString()
            }
            return ""
        }
    };

    在decrypt函数中，b为密文，c为密钥，a我没有找清楚是什么，但不影响程序的使用。
    得到该函数代码后，我们就可以对密文进行解密工作。

    分析可知，该加密使用的是3des加密，解密需要三个变量：密文，密钥，偏移量。
    其中密文和密钥会在包中获取。
    经过分析，偏移量为当日日期，即 (new Date(), "yyyyMMdd")
    解密模式为Pkcs7

    那么只剩下最后一个问题了，如何request正确的包。
    这个还得再分析分析。
    





