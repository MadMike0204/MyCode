import os
from typing import List
print(os.getcwd())
``
mms : List[str] = ["2333333"] + ["jojo"]
for mm in mms:
    print(mm)

from typing import List, Union

def convert_single_element_lists_to_strings(input_list: List[Union[str, List[str]]]) -> List[str]:
    result = []
    for item in input_list:
        if isinstance(item, list) and len(item) == 1:
            # 如果元素是列表且只有一个元素，则提取该元素
            result.append(item[0])
        else:
            result.append(item)
    return result



['/tmp/gradio/05ff50a7b413b2d92c9d874ded787888ed4a2788/1758-907X-3-7.pdf', ['example.pdf'], 'example.pdf']