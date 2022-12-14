<!--
 Copyright 2022 gab
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
     http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
-->

# forensicpp (WIP)

forensicpp is an QT-based image analyser software including the following features:

* Image collection aggregation (local and remote filesystem (AWS S3 driver will be supported))
* OCR (Tesseract C++ API ?) on group of images
    * Result of image OCR can be indexed in an SQL/NoSQL database (coordinates of bounding boxes, text content, etc.)
    * We want GPU acceleration (CUDA kernels for OCR needed)
* Search engine on OCRed data
* Add many other features (for examples, https://github.com/zchee/cuda-sample)

* Possibility to associate multiple workers with one client (OpenMPI ?) 

# Dependencies

* `libmysqlclient-dev` : mysql C API is required
* `libmariadbc` and `libmariadbcpp` : the MariaDB C and C++ connectors (https://mariadb.com/docs/ent/connect/programming-languages/cpp/install/)