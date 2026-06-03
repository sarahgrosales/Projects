# First YOLO detection script
# Cars, people, animals, etc. 

# Import YOLO
from ultralytics import YOLO

# Load the pre-trained YOLO model
model = YOLO("yolo11n.pt")

# Predict objects with image
results = model.predict(source="Image.jpg")

# Show the results with bounding boxes
for r in results:
    r.show()
