# First YOLO detection script
# Cars, people, animals, etc. 

# Import YOLO
from ultralytics import YOLO
import cv2

# Load the pre-trained YOLO model
model = YOLO("yolo11n.pt")

# Predict objects with image
results = model.predict(
    source="Image2.jpg",
    save=True,
    save_txt=True,
    conf=0.5,
)

# Show the results with bounding boxes
for r in results:
    print (f"\n found {len(r.boxes)} objects in the image!")

    for i, box in enumerate(r.boxes):

        class_id = int(box.cls)
        confidence = float(box.conf)
        class_name = model.names[class_id]

        print(f" {i+1}. {class_name} ({confidence:.1%} confidence)")

    r.show()

print ("\n Results saved in 'runs/detect/predict' folder!")
