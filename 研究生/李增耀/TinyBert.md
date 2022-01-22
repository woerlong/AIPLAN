## TINYBERT: DISTILLING BERT FOR NATURAL LANGUAGE UNDERSTANDING

## **摘要**

1. 提出了一种新的Transformer蒸馏方法，该方法专门用于Transformer-based models
2. 引入了一个新的两阶段学习框架，该框架在培训前和任务特定学习阶段都执行变压器蒸馏
3. 效果：在GLUE基准上实现了教师模型BERT base 96%以上的表现，同时推理能力小7.5倍，快9.4倍。TinyBERT在BERT蒸馏方面也明显优于最先进的基线，参数仅为28%，推理时间为31%





## **正文**



**Transformer 蒸馏图（a：蒸馏框架	b：蒸馏细节）**

![image-20220117210837571]([AIPLAN/TinyBert_1.png at main · Zero-Lzy/AIPLAN (github.com)](https://github.com/Zero-Lzy/AIPLAN/blob/main/研究生/李增耀/img/TinyBert_1.png))



**TinyBert两段式学习图示**

![]([AIPLAN/TinyBert_2.png at main · Zero-Lzy/AIPLAN (github.com)](https://github.com/Zero-Lzy/AIPLAN/blob/main/研究生/李增耀/img/TinyBert_2.png))



**问题形式化**

学生M层，教师N层

n = g(m)作为学生层到教师层的映射函数，即第m层的学生模型从第n层的教师模型中学习信息

设0为嵌入层指标，M +1为预测层指标，定义对应的层映射分别为0 = g(0)和N +1 = g(M +1)

最小化以下目标从老师那里获得知识：

![image-20220117211708635]([AIPLAN/TinyBert_3.png at main · Zero-Lzy/AIPLAN (github.com)](https://github.com/Zero-Lzy/AIPLAN/blob/main/研究生/李增耀/img/TinyBert_3.png))





**Transformer-layer Distillation**

从attention提取知识：

![image-20220117211732051]([AIPLAN/TinyBert_4.png at main · Zero-Lzy/AIPLAN (github.com)](https://github.com/Zero-Lzy/AIPLAN/blob/main/研究生/李增耀/img/TinyBert_4.png))

h是attention heads数量，本文采用(未归一化)注意矩阵Ai作为拟合目标，而不是其softmax输出的softmax(Ai)

除了基于attention的提取外，我们还从Transformer层的输出中提取知识：

![image-20220117211748243]([AIPLAN/TinyBert_5.png at main · Zero-Lzy/AIPLAN (github.com)](https://github.com/Zero-Lzy/AIPLAN/blob/main/研究生/李增耀/img/TinyBert_5.png))





**Embedding-layer Distillation**

计算学生模型的词向量ES和教师模型的词向量ET之间的均方误差损失

![image-20220117211800743]([AIPLAN/TinyBert_6.png at main · Zero-Lzy/AIPLAN (github.com)](https://github.com/Zero-Lzy/AIPLAN/blob/main/研究生/李增耀/img/TinyBert_6.png))



**Prediction-Layer Distillation**

利用知识蒸馏来拟合教师模型的预测

![image-20220117211821285]([AIPLAN/TinyBert_7.png at main · Zero-Lzy/AIPLAN (github.com)](https://github.com/Zero-Lzy/AIPLAN/blob/main/研究生/李增耀/img/TinyBert_7.png))

zS和zT分别是学生和老师预测的logit向量



**教师与学生网络对应层的蒸馏损失总结：**

![image-20220117211834773]([AIPLAN/TinyBert_8.png at main · Zero-Lzy/AIPLAN (github.com)](https://github.com/Zero-Lzy/AIPLAN/blob/main/研究生/李增耀/img/TinyBert_8.png))

实验中，先进行中间层蒸馏(M≥M≥0)，然后进行预测层蒸馏(M = M + 1)。

**结论**

TinyBERT 在实现具有竞争力的性能的同时，显着减小了模型大小并缩短了原始 BERTBASE 的推理时间，这为在边缘设备上部署基于 BERT 的 NLP 应用程序提供了一种有效的方法
