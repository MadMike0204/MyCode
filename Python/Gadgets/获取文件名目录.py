import os

def save_pdf_list(directory_path, output_file):
   """将PDF文件列表保存到txt文件"""
   pdf_files = [f for f in os.listdir(directory_path) if f.lower().endswith('.pdf')]
   
   with open(output_file, 'w', encoding='utf-8') as f:
       for pdf in pdf_files:
           f.write(f"{pdf}\n")

if __name__ == "__main__":
   try:
       save_pdf_list('.', 'pdf_files.txt')
       print("文件列表已保存至 pdf_files.txt")
   except Exception as e:
       print(f"错误：{str(e)}")