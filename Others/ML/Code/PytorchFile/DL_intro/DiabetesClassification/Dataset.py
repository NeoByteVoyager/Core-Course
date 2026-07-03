import torch
from torch.utils.data import Dataset
from  torch.utils.data import DataLoader
import torch.nn as nn
import torch.optim as optim
import numpy as np
from numpy import loadtxt



# 1.准备数据集,Dataset是一个抽象类，必须继承才能实例化
class MyDataset(Dataset):
    def __init__(self, path):
        xy = loadtxt(path, delimiter=',', dtype=np.float32)
        self.len = xy.shape[0]
        self.x_data = torch.tensor(xy[:,:-1])
        self.y_data = torch.tensor(xy[:,[-1]])

    def __getitem__(self, idx):
        return self.x_data[idx],self.y_data[idx]

    def __len__(self):
        return self.len

# 数据集
data_set = MyDataset("diabetes.csv")
data_loader = DataLoader(dataset=data_set,
                         shuffle=True,
                         batch_size=2,
                         num_workers=0)

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

if __name__ == "__main__":      # 在window上多进程加载数据训练循环必须写在这里面
    for epoch in range(100):
        loss_list = []
        for idx,data in enumerate(data_loader):
            # 取一个batch的数据
            x, label = data
            # 前向传播
            y_hat = model(x)
            loss = criterion(y_hat, label)
            loss_list.append(loss.item())
            # 反向传播
            optimizer.zero_grad()
            loss.backward()
            optimizer.step()
        if(epoch % 10 == 0):
            print(f"epoch:{epoch}|loss:{loss_list}")