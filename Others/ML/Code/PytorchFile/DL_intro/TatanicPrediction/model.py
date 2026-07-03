import torch
import torch.nn as nn
import torch.optim as optim
import pandas as pd
from  torch.utils.data import Dataset,DataLoader


# 1.数据集准备
df = pd.read_csv("cleaned_data.csv")

# 前700行做训练集，后面的做测试集
train_df = df.iloc[:700]
test_df = df.iloc[700:]

# 提取特征和标签
x_train = train_df.drop(columns=['PassengerId','Survived'], errors = 'ignore').values
y_train = train_df['Survived'].values

x_test = test_df.drop(columns=['PassengerId','Survived'], errors = 'ignore').values
y_test = test_df['Survived'].values


class MyData(Dataset):
    def __init__(self, features, labels):
        self.x_data = torch.tensor(features, dtype=torch.float32)
        self.y_data = torch.tensor(labels, dtype=torch.float32).unsqueeze(-1)
        self.len = self.x_data.shape[0]

    def __getitem__(self, idx):
        return self.x_data[idx], self.y_data[idx]

    def __len__(self):
        return self.len

train_dataset = MyData(x_train, y_train)
test_dataset = MyData(x_test, y_test)

train_loader = DataLoader(dataset=train_dataset,
                          batch_size=32,
                          shuffle=True)
test_loader = DataLoader(dataset=test_dataset,
                         batch_size=32,
                         shuffle=False)


# 2. 搭建模型
class MyModel(nn.Module):
    def __init__(self, in_features, out_features):
        super().__init__()
        self.layer1 = nn.Linear(in_features,12)
        self.layer2 = nn.Linear(12,6)
        self.layer3 = nn.Linear(6,out_features)
        self.sigmoid = torch.nn.Sigmoid()

    def forward(self, x):
        x=self.sigmoid(self.layer1(x))
        x=self.sigmoid(self.layer2(x))
        x=self.sigmoid(self.layer3(x))
        return x

# 实例化模型
model = MyModel(train_dataset.x_data.shape[1], 1)

# 3.损失函数和优化器
criterion = nn.BCELoss()
optimizer = optim.SGD(model.parameters(), lr=0.1)

# 4.训练循环
for epoch in range(200):
    total_loss = 0
    for idx, data in enumerate(train_loader):
        x, label = data
        # 前向传播
        y_hat = model(x)
        loss = criterion(y_hat, label)

        # 反向传播
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        total_loss += loss.item()
    if epoch % 10 ==0:
        print(f"epoch:{epoch}|loss:{total_loss:.4f}")

# 5.测试集验证
correct = 0
total = 0

with torch.no_grad():
    for data in test_loader:
        x, label = data
        # 这里表示生还的概率
        predict = model(x)
        # 生还得概率大于0.5，则未生还的概率小于0.5根据这个打标签
        preds = (predict >= 0.5).float()

        total += x.size(0)
        correct += (preds == label).sum().item()

print(f"测试集上的准确率:{100 * correct / total:.2f}%")
