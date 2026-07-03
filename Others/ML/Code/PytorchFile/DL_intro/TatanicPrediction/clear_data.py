import pandas as pd
# 1.读取文件
df = pd.read_csv("train.csv")
# 2.删除不必要的列
df.drop(columns=['Name','Ticket','Cabin','Embarked'],inplace=True)
# 3.修改后的csv重新写入文件
df.to_csv("cleaned_data.csv",index=False) # 要写上index = False
