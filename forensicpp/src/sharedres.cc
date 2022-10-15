// Copyright 2022 gab
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "sharedres.h"


SharedResources *shrRes = nullptr;

SharedResources::SharedResources() {}

SharedResources::~SharedResources() {
    delete shrRes;
}

QPixmap *SharedResources::getPixmap(ShrIcon icon, qreal dpr) {
    QPixmap *pixmap;
    QString path;
    if(icon == ShrIcon::SHR_ICON_ERROR) {
        path = ":/res/icons/common/other/loading-error72.png";
        pixmap = mLoadingErrorIcon72;
    } else {
        path = ":/res/icons/common/other/loading72.png";
        pixmap = mLoadingIcon72;
    }
    if(pixmap)
        return pixmap;

    qreal pixmapDrawScale;
    if(dpr >= (1.0 + 0.001)) {
        path.replace(".", "@2x.");
        pixmap = new QPixmap(path);
        if(dpr >= (2.0 - 0.001))
            pixmapDrawScale = dpr;
        else
            pixmapDrawScale = 2.0;
        pixmap->setDevicePixelRatio(pixmapDrawScale);
    } else {
        pixmap = new QPixmap(path);
    }
    if(icon == ShrIcon::SHR_ICON_ERROR)
        mLoadingErrorIcon72 = pixmap;
    else
        mLoadingIcon72 = pixmap;
    return pixmap;
}

SharedResources *SharedResources::getInstance() {
    if(!shrRes) {
        shrRes = new SharedResources();
    }
    return shrRes;
}
