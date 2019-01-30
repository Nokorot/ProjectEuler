
nextRow row = [x + y | (x,y) <- zip row (tail row)]
