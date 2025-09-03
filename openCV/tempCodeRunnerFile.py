import cv2
import numpy as np

def nothing(x):
    pass

# Load image
img = cv2.imread("rose1.png")
blurred = cv2.GaussianBlur(img, (5,5), 0)

# Convert to HLS (or HSV, try both)
hls = cv2.cvtColor(blurred, cv2.COLOR_BGR2HLS)

# Create window
cv2.namedWindow("Trackbars")

# Create trackbars for lower and upper H, L, S
cv2.createTrackbar("LH", "Trackbars", 0, 180, nothing)  # Hue lower
cv2.createTrackbar("LS", "Trackbars", 0, 255, nothing)  # Lightness lower
cv2.createTrackbar("LL", "Trackbars", 0, 255, nothing)  # Saturation lower

cv2.createTrackbar("UH", "Trackbars", 180, 180, nothing)  # Hue upper
cv2.createTrackbar("US", "Trackbars", 255, 255, nothing)  # Lightness upper
cv2.createTrackbar("UL", "Trackbars", 255, 255, nothing)  # Saturation upper

while True:
    # Get positions from trackbars
    lh = cv2.getTrackbarPos("LH", "Trackbars")
    ls = cv2.getTrackbarPos("LS", "Trackbars")
    ll = cv2.getTrackbarPos("LL", "Trackbars")
    uh = cv2.getTrackbarPos("UH", "Trackbars")
    us = cv2.getTrackbarPos("US", "Trackbars")
    ul = cv2.getTrackbarPos("UL", "Trackbars")

    # Define range
    lower = np.array([lh, ls, ll])
    upper = np.array([uh, us, ul])

    # Create mask
    mask = cv2.inRange(hls, lower, upper)

    # Apply mask
    result = cv2.bitwise_and(img, img, mask=mask)

    # Show
    cv2.imshow("Original", img)
    cv2.imshow("Mask", mask)
    cv2.imshow("Result", result)

    # Break with ESC
    if cv2.waitKey(1) & 0xFF == 27:
        break

cv2.destroyAllWindows()
