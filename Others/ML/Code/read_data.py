from torch.utils.data import Dataset
from PIL import  Image
import  os
class MyData(Dataset):
    def __init__(self,root_dir,label_dir):
        self.root_dir = root_dir
        self.label_dir = label_dir
        self.path = os.path.join(self.root_dir,self.label_dir)
        self.img_path = os.listdir(self.path)

    def __getitem__(self, idx):
        image_name = self.img_path[idx]
        image_item_path = os.path.join(self.root_dir,self.label_dir,image_name)
        image =  Image.open(image_item_path)
        label = self.label_dir
        return image,label
    def __len__(self):
        return len(self.img_path)
ant_data = MyData("hymenoptera_data/train","ants")
ant,label = ant_data.__getitem__(0)
bee_data = MyData("hymenoptera_data/train","bees")
data = ant_data + bee_data
