from PIL import Image, ImageDraw, ImageFont

# Define the size of the image
img_width, img_height = 1024, 768
image = Image.new("RGB", (img_width, img_height), "white")
draw = ImageDraw.Draw(image)

# Load a font
font = ImageFont.load_default()

# Draw the gates
draw.text((10, 10), "Logic Circuit for X and Y using 74LS153", font=font, fill="black")

# Draw circuit for X
draw.text((10, 50), "Circuit for X", font=font, fill="black")
draw.text((10, 80), "X = (NOT A AND NOT B AND C) OR (NOT A AND B AND NOT C)", font=font, fill="black")
draw.text((10, 110), "    OR (A AND NOT B AND NOT C) OR (A AND B AND C)", font=font, fill="black")

draw.rectangle([(10, 140), (300, 220)], outline="black", width=2)
draw.text((20, 150), "74LS153", font=font, fill="black")
draw.text((20, 180), "Inputs: A, B, C", font=font, fill="black")
draw.text((20, 200), "Output: X", font=font, fill="black")

# Draw circuit for Y
draw.text((10, 250), "Circuit for Y", font=font, fill="black")
draw.text((10, 280), "Y = (NOT A AND B AND C) OR (A AND NOT B AND C) OR (A AND B)", font=font, fill="black")

draw.rectangle([(10, 310), (300, 390)], outline="black", width=2)
draw.text((20, 320), "74LS153", font=font, fill="black")
draw.text((20, 350), "Inputs: A, B, C", font=font, fill="black")
draw.text((20, 370), "Output: Y", font=font, fill="black")

# Save the image
file_path = "logic_circuit_x_y.png"
image.save(file_path)

# Display the file path
file_path
