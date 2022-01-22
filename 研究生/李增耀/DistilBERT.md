## DistilBERT, a distilled version of BERT: smaller,faster, cheaper and lighter

## **摘要**

将BERT模型的规模减少40%，同时保留99%的语言理解能力，速度提高60%

为了利用更大模型在训练前学习到的归纳偏差，引入了结合语言建模、蒸馏和余弦距离损失的三重损失，这个更小、更快、更轻的模型在预训练中成本更低。

## **正文**

**提出的原因：**

①指数级放大这些模型的计算需求的环境成本

②模型不断增长的计算和内存需求可能会阻碍广泛采用



**Student architecture**

和原始bert一致

Token-type embedding和Pooler被删除

层数除以2



**Student initialization**

从教师中选取两层中的一层来初始化学生



**Distillation**

只使用动态掩码而不进行下一句预测

三重损失：有监督的MLM损失+蒸馏MLM损失+词向量余弦损失

有监督的MLM损失（hard label）：输入掩码句子，得到概率分布，利用交叉熵损失函数学习

蒸馏MLM损失（soft label）：教师模型输出的概率，利用交叉熵损失函数学习

词向量余弦损失：用于对其老师和学生模型