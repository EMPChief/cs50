from PIL import Image, ImageFilter

before = Image.open('Lena.png')
after = before.filter(ImageFilter.BoxBlur(5))
after.save('Lena-blur.png')