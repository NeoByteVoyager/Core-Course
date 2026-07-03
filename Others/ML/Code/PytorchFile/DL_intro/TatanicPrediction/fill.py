import pandas as pd
# 1.读取文件
df = pd.read_csv("cleaned_data.csv")
# 2.查看每一列的确实情况
print(df.isnull().sum())
# 3.计算Age列的中位数
age_median = df['Age'].median()
# 4.用中位数填补空缺值
df['Age'] = df['Age'].fillna(age_median)
# 5.写回文件
df.to_csv("cleaned_data.csv",index=False)