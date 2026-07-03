import torch
import torch.nn as nn
import torch.optim as optim


# 1.构建训练集
x_data = torch.tensor([[1.0],[2.0],[3.0],[4.0]])
y_data = torch.tensor([[0.0],[0.0],[1.0],[1.0]])

# 2.搭建模型
class MyModel(nn.Module):
    def __init__(self, in_features, out_features):
        super().__init__()
        self.linear = nn.Linear(in_features, out_features)

    def forward(self, x):
        y_pred = torch.sigmoid(self.linear(x))
        return y_pred

# 实例化模型
model = MyModel(1,1)

# 3.构造损失函数和优化器
criterion = nn.BCELoss()
optimizer = optim.SGD(model.parameters(),lr=0.01)

# 4.训练循环
for epoch in range(100):
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
        print(f"weight:{model.linear.weight.item()}, bias:{model.linear.bias.item()}")
