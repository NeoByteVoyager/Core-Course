import pandas as pd
# 1.读取文件
df = pd.read_csv("cleaned_data.csv")
print(df.info())
# 2.将性别转换为数字
if df['Sex'].dtype == 'str':
    df['Sex'] = df['Sex'].map({'female':0,'male':1})
df.to_csv("cleaned_data.csv",index=False)
print(df.info())