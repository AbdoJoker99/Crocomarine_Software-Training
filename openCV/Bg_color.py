import cv2
import numpy as np

def nothing(x):
    pass


img = cv2.imread("rose1.png")
blurred = cv2.GaussianBlur(img, (5,5), 0)

hls = cv2.cvtColor(blurred, cv2.COLOR_BGR2HLS)


cv2.namedWindow("Trackbars")
cv2.resizeWindow("Trackbars", 400, 250)


cv2.createTrackbar("LH", "Trackbars", 0, 179, nothing)   # Lower Hue
cv2.createTrackbar("LL", "Trackbars", 0, 255, nothing)   # Lower Lightness
cv2.createTrackbar("LS", "Trackbars", 0, 255, nothing)   # Lower Saturation

cv2.createTrackbar("UH", "Trackbars", 179, 179, nothing) # Upper Hue
cv2.createTrackbar("UL", "Trackbars", 255, 255, nothing) # Upper Lightness
cv2.createTrackbar("US", "Trackbars", 255, 255, nothing) # Upper Saturation

while True:
  
    lh = cv2.getTrackbarPos("LH", "Trackbars")
    ll = cv2.getTrackbarPos("LL", "Trackbars")
    ls = cv2.getTrackbarPos("LS", "Trackbars")

    uh = cv2.getTrackbarPos("UH", "Trackbars")
    ul = cv2.getTrackbarPos("UL", "Trackbars")
    us = cv2.getTrackbarPos("US", "Trackbars")


    lower = np.array([lh, ll, ls])
    upper = np.array([uh, ul, us])

    mask = cv2.inRange(hls, lower, upper)

    
    result = cv2.bitwise_and(img, img, mask=mask)

    
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    gray_bgr = cv2.cvtColor(gray, cv2.COLOR_GRAY2BGR)

    
    final = np.where(mask[:, :, None] == 0, gray_bgr, result)

   
    cv2.imshow("Final", cv2.resize(final, (400, 300)))

  
    if cv2.waitKey(1) & 0xFF == 27:
        break

cv2.destroyAllWindows()
