from PIL import Image, ImageDraw, ImageFont
import os
import hashlib
import random
from io import BytesIO

def set_color(img, color_rgb):
    img_list = []
    for pixel in img.getdata():
            img_list.append(color_rgb + (pixel[3],))
    new_img = Image.new("RGBA", img.size)
    new_img.putdata(img_list)
    return new_img

def write_text(img, text):
    draw = ImageDraw.Draw(img)
    font = ImageFont.load_default() 
    text_position = (10, 10)
    text_color = (0, 0, 0)  
    draw.text(text_position, text, fill=text_color, font=font)

def generate_random_karp(seed):
    random.seed(seed)
    karp_sources = {}
    poses = ('karp', 'karp-move')
    parts = ('line', 'body-color', 'parts-color', 'barbel_F', 'barbel_M')
    ext = "png"
    size = (200, 200)
    for pose in poses:
        pose_dict = {}
        for part in parts:
                asset_name = pose + "_" + part + "." + ext
                base_dir = os.path.dirname(os.path.abspath(__file__))
                pose_dict[part] = Image.open(os.path.join(base_dir, "assets", asset_name)).convert("RGBA")
        karp_sources[pose] = pose_dict

    karp_color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
    karp_gender = random.randint(0, 1)
    FLAG_A = ""
    if karp_color == (255, 215, 0): # golden one!
        FLAG_A = "JFS{karpe_diem"

    karp_bytes = {}
    for pose, karp in karp_sources.items():
        karp["body-color"] = set_color(karp["body-color"], karp_color)
        karp["barbel"] = [karp["barbel_F"], karp["barbel_M"]][karp_gender]
        del karp["barbel_F"], karp["barbel_M"]

        final_img = Image.new("RGBA", size)
        for part in karp.values():
            final_img = Image.alpha_composite(final_img, part)
        if FLAG_A:
             write_text(final_img, FLAG_A)
        img_byte_arr = BytesIO()
        final_img.save(img_byte_arr, format='PNG')
        
        img_byte_arr.seek(0)
        karp_bytes[pose] = img_byte_arr.getvalue()

    return karp_bytes



if __name__ == '__main__':
    os.environ['FLAG'] = "JFS{KARPE_DIEM_MAKE_A_SPLASH}"
    img_datas = generate_random_karp("RANDOMSEED")
    for name, data in img_datas.items():
        with open("generated_"+name+".png", "wb") as img_file:
            img_file.write(data)