import numpy as np
from numpy import loadtxt
import torch
import torch.nn as nn
import torch.optim as optim

# 1.获取数据集
xy = loadtxt("diabetes.csv", delimiter=',', dtype=np.float32)
x_data = torch.tensor(xy[:, :-1].tolist())
y_data = torch.tensor(xy[:,[-1]].tolist())

# 2.搭建模型
class MyModel(nn.Module):
    def __init__(self, in_feature, out_feature):
        super().__init__()
        self.layer1 = nn.Linear(in_feature,12)
        self.layer2 = nn.Linear(12,6)
        self.layer3 = nn.Linear(6,out_feature)
        self.activate = nn.Sigmoid()

    def forward(self, x):
        x = self.layer1(x)
        x = self.activate(x)
        x=self.layer2(x)
        x=self.activate(x)
        x=self.layer3(x)
        x=self.activate(x)
        return x

# 实例化模型
model = MyModel(8,1)

# 3.创建损失函数和优化器
criterion = nn.BCELoss()
optimizer = optim.SGD(model.parameters(), lr=0.01)

# 4.训练循环
for epoch in range(500):
    # 前向传播
    y_hat = model(x_data)
    loss = criterion(y_hat, y_data)

    # 反向传播
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

    if(epoch % 10 == 0):
        print(f"epoch:{epoch}")
        print(f"loss:{loss.item():.4f}")

