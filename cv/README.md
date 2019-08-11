### 光流跟踪

```c++
/* 
    Calculates an optical flow for a sparse feature set 
    using the iterative Lucas-Kanade method with pyramids.
*/
void cv::calcOpticalFlowPyrLK(InputArray prevImg,
        InputArray nextImg,
        InputArray prevPts,
        InputOutputArray nextPts,
        OutputArray status,
        OutputArray err,
        Size winSize = Size(21, 21),
        int maxLevel = 3,
        TermCriteria criteria = TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 30, 0.01),
        int flags = 0,
        double minEigThreshold = 1e-4 
    )
/*
Parameters
prevImg: first 8-bit input image or pyramid constructed by buildOpticalFlowPyramid.
nextImg: second input image or pyramid of the same size and the same type as prevImg.
prevPts: vector of 2D points for which the flow needs to be found; point coordinates 
         must be single-precision floating-point numbers.
nextPts: output vector of 2D points (with single-precision floating-point coordinates) 
         containing the calculated new positions of input features in the second image; 
         when OPTFLOW_USE_INITIAL_FLOW flag is passed, the vector must have the same size as in the input.
status: output status vector (of unsigned chars); each element of the vector is set to 1 
        if the flow for the corresponding features has been found, otherwise, it is set to 0.
err: output vector of errors; each element of the vector is set to an error for the 
     corresponding feature, type of the error measure can be set in flags parameter; 
     if the flow wasn't found then the error is not defined (use the status parameter to find such cases).
winSize: size of the search window at each pyramid level.
maxLevel: 0-based maximal pyramid level number; if set to 0, pyramids are not used (single level), 
          if set to 1, two levels are used, and so on; if pyramids are passed to input 
          then algorithm will use as many levels as pyramids have but no more than maxLevel.
criteria: parameter, specifying the termination criteria of the iterative search algorithm 
         (after the specified maximum number of iterations criteria.maxCount or when the search window moves 
         by less than criteria.epsilon.
flags: operation flags:
    OPTFLOW_USE_INITIAL_FLOW uses initial estimations, stored in nextPts; if the flag is not set, 
        then prevPts is copied to nextPts and is considered the initial estimate.
    OPTFLOW_LK_GET_MIN_EIGENVALS use minimum eigen values as an error measure (see minEigThreshold description);
        if the flag is not set, then L1 distance between patches around the original and a moved point, 
        divided by number of pixels in a window, is used as a error measure.
minEigThreshold: the algorithm calculates the minimum eigen value of a 2x2 normal matrix of 
                 optical flow equations (this matrix is called a spatial gradient matrix in [23]),
                 divided by number of pixels in a window; if this value is less than minEigThreshold,
                 then a corresponding feature is filtered out and its flow is not processed, 
                 so it allows to remove bad points and get a performance boost.
*/
```

### 均匀提取特征

```c++
/* Determines strong corners on an image. */
void cv::goodFeaturesToTrack(InputArray image,
        OutputArray orners,
        int maxCorners,
        double qualityLevel,
        double minDistance,
        InputArray mask = noArray(),
        int blockSize = 3,
        bool useHarrisDetector = false,
        double k = 0.04 
    )
/*
Parameters
image:  Input 8-bit or floating-point 32-bit, single-channel image.
corners:  Output vector of detected corners.
maxCorners:  Maximum number of corners to return. If there are more corners than are found,
             the strongest of them is returned. maxCorners <= 0 implies that no limit 
             on the maximum is set and all detected corners are returned.
qualityLevel:  Parameter characterizing the minimal accepted quality of image corners.
               The parameter value is multiplied by the best corner quality measure, 
               which is the minimal eigenvalue (see cornerMinEigenVal ) or 
               the Harris function response (see cornerHarris ). 
               The corners with the quality measure less than the product are rejected. 
               For example, if the best corner has the quality measure = 1500, 
               and the qualityLevel=0.01 , then all the corners with the quality measure less than 15 are rejected.
minDistance:  Minimum possible Euclidean distance between the returned corners.
mask:  Optional region of interest. If the image is not empty 
       (it needs to have the type CV_8UC1 and the same size as image ), 
       it specifies the region in which the corners are detected.
blockSize:  Size of an average block for computing a derivative covariation matrix 
            over each pixel neighborhood. See cornerEigenValsAndVecs .
useHarrisDetector:  Parameter indicating whether to use a Harris detector 
                    (see cornerHarris) or cornerMinEigenVal.
k:  Free parameter of the Harris detector.
*/
```

### 直方图均衡化

```c++
// Base class for Contrast Limited Adaptive Histogram Equalization.
cv::CLAHE
/* 
    Equalizes the histogram of a grayscale image using Contrast Limited 
    Adaptive Histogram Equalization.
*/ 
virtual void cv::CLAHE::apply(InputArray src, OutputArray dst);
Parameters
    src     Source image of type CV_8UC1 or CV_16UC1.
    dst     Destination image. 
```

### 剔除异常点

```c++
/* Calculates a fundamental matrix from the corresponding points in two images. */
Mat cv::findFundamentalMat(InputArray points1,
        InputArray points2,
        int method = FM_RANSAC,
        double ransacReprojThreshold = 3.,
        double confidence = 0.99,
        OutputArray mask = noArray() 
    )
/*
Parameters
points1:  Array of N points from the first image. The point coordinates should be 
          floating-point (single or double precision).
points2:  Array of the second image points of the same size and format as points1 .
method:  Method for computing a fundamental matrix.
    CV_FM_7POINT for a 7-point algorithm. N=7
    CV_FM_8POINT for an 8-point algorithm. N≥8
    CV_FM_RANSAC for the RANSAC algorithm. N≥8
    CV_FM_LMEDS for the LMedS algorithm. N≥8
ransacReprojThreshold:  Parameter used only for RANSAC. It is the maximum distance 
                        from a point to an epipolar line in pixels, beyond which 
                        the point is considered an outlier and is not used for computing 
                        the final fundamental matrix. It can be set to something like 1-3, 
                        depending on the accuracy of the point localization, image resolution, 
                        and the image noise.
confidence:  Parameter used for the RANSAC and LMedS methods only. It specifies a 
            desirable level of confidence (probability) that the estimated matrix is correct.
mask:  标识哪些点是 inliers
*/
```

### 解算位姿

```c++
/*
Finds an object pose from 3D-2D point correspondences. 
https://docs.opencv.org/4.1.0/d9/d0c/group__calib3d.html#ga549c2075fac14829ff4a58bc931c033d
*/
bool cv::solvePnP(InputArray objectPoints,
        InputArray imagePoints,
        InputArray cameraMatrix,
        InputArray distCoeffs,
        OutputArray rvec,
        OutputArray tvec,
        bool useExtrinsicGuess = false,
        int flags = SOLVEPNP_ITERATIVE 
    )
/*
Parameters
objectPoints  Array of object points in the object coordinate space, Nx3 1-channel 
              or 1xN/Nx1 3-channel, where N is the number of points. vector<Point3f> 
              can be also passed here.
imagePoints	 Array of corresponding image points, Nx2 1-channel or 1xN/Nx1 2-channel,
             where N is the number of points. vector<Point2f> can be also passed here.
cameraMatrix  Input camera matrix
distCoeffs  Input vector of distortion coefficients
rvec  Output rotation vector (see Rodrigues ) that, together with tvec , 
      brings points from the model coordinate system to the camera coordinate system.
tvec  Output translation vector. 
flags  Method for solving a PnP problem
*/
```

### 