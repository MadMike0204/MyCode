from PIL import Image

image = Image.open("5.jpg")

square_size = 2048

crops = [
    (1024, 0, 2048, 1024),       # 顶部中间
    (0, 1024, 1024, 2048),       # 中间左
    (1024, 1024, 2048, 2048),    # 中间中
    (2048, 1024, 3072, 2048),   # 中间右
    (3072, 1024, 4096, 2048),   # 中间最右
    (1024, 2048, 2048, 3072),   # 底部中间
]

# 切割并保存
for i, crop in enumerate(crops):
    square = image.crop(crop)
    square.save(f"square_{i + 1}.jpg")