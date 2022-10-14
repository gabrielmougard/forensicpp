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

#include "actions.h"

Actions *appActions = nullptr;

Actions::Actions() {
    init();
}

Actions *Actions::getInstance() {
    if(!appActions)
        appActions  = new Actions();
    return appActions;
}

const QMap<QString, QVersionNumber> &Actions::getMap() {
    return mActions;
}

QList<QString> Actions::getList() {
    return mActions.keys();
}

void Actions::init() {
    mActions.insert("nextImage", QVersionNumber(1,0,0));
    mActions.insert("prevImage", QVersionNumber(1,0,0));
    mActions.insert("toggleFullscreen", QVersionNumber(1,0,0));
    mActions.insert("fitWindow", QVersionNumber(1,0,0));
    mActions.insert("fitWidth", QVersionNumber(1,0,0));
    mActions.insert("fitNormal", QVersionNumber(1,0,0));
    mActions.insert("toggleFitMode", QVersionNumber(1,0,0));
    mActions.insert("resize", QVersionNumber(1,0,0));
    mActions.insert("rotateRight", QVersionNumber(1,0,0));
    mActions.insert("rotateLeft", QVersionNumber(1,0,0));
    mActions.insert("scrollUp", QVersionNumber(1,0,0));
    mActions.insert("scrollDown", QVersionNumber(1,0,0));
    mActions.insert("scrollLeft", QVersionNumber(1,0,0));
    mActions.insert("scrollRight", QVersionNumber(1,0,0));
    mActions.insert("zoomIn", QVersionNumber(1,0,0));
    mActions.insert("zoomOut", QVersionNumber(1,0,0));
    mActions.insert("zoomInCursor", QVersionNumber(1,0,0));
    mActions.insert("zoomOutCursor", QVersionNumber(1,0,0));
    mActions.insert("open", QVersionNumber(1,0,0));
    mActions.insert("save", QVersionNumber(1,0,0));
    mActions.insert("saveAs", QVersionNumber(1,0,0));
    mActions.insert("setWallpaper", QVersionNumber(0,9,3));
    mActions.insert("crop", QVersionNumber(1,0,0));
    mActions.insert("removeFile", QVersionNumber(1,0,0));
    mActions.insert("copyFile", QVersionNumber(1,0,0));
    mActions.insert("moveFile", QVersionNumber(1,0,0));
    mActions.insert("jumpToFirst", QVersionNumber(1,0,0));
    mActions.insert("jumpToLast", QVersionNumber(1,0,0));
    mActions.insert("openSettings", QVersionNumber(1,0,0));
    mActions.insert("closeFullScreenOrExit", QVersionNumber(1,0,0));
    mActions.insert("exit", QVersionNumber(1,0,0));
    mActions.insert("flipH", QVersionNumber(1,0,0));
    mActions.insert("flipV", QVersionNumber(1,0,0));
    mActions.insert("folderView", QVersionNumber(1,0,0));
    mActions.insert("pauseVideo", QVersionNumber(1,0,0));
    mActions.insert("frameStep", QVersionNumber(1,0,0));
    mActions.insert("frameStepBack", QVersionNumber(1,0,0));
    mActions.insert("folderView", QVersionNumber(1,0,0));
    mActions.insert("documentView", QVersionNumber(1,0,0));
    mActions.insert("toggleFolderView", QVersionNumber(1,0,0));
    mActions.insert("moveToTrash", QVersionNumber(1,0,0));
    mActions.insert("reloadImage", QVersionNumber(1,0,0));
    mActions.insert("copyFileClipboard", QVersionNumber(1,0,0));
    mActions.insert("copyPathClipboard", QVersionNumber(1,0,0));
    mActions.insert("renameFile", QVersionNumber(1,0,0));
    mActions.insert("contextMenu", QVersionNumber(1,0,0));
    mActions.insert("toggleTransparencyGrid", QVersionNumber(1,0,0));
    mActions.insert("sortByName", QVersionNumber(1,0,0));
    mActions.insert("sortByTime", QVersionNumber(1,0,0));
    mActions.insert("sortBySize", QVersionNumber(1,0,0));
    mActions.insert("toggleImageInfo", QVersionNumber(1,0,0));
    mActions.insert("toggleShuffle", QVersionNumber(1,0,0));
    mActions.insert("toggleScalingFilter", QVersionNumber(1,0,0));
    mActions.insert("toggleMute", QVersionNumber(1,0,0));
    mActions.insert("volumeUp", QVersionNumber(1,0,0));
    mActions.insert("volumeDown", QVersionNumber(1,0,0));
    mActions.insert("toggleSlideshow", QVersionNumber(1,0,0));
    mActions.insert("showInDirectory", QVersionNumber(1,0,0));
    mActions.insert("goUp", QVersionNumber(1,0,0));
    mActions.insert("discardEdits", QVersionNumber(1,0,0));
    mActions.insert("nextDirectory", QVersionNumber(1,0,0));
    mActions.insert("prevDirectory", QVersionNumber(1,0,0));
    mActions.insert("seekVideoForward", QVersionNumber(1,0,0));
    mActions.insert("seekVideoBackward", QVersionNumber(1,0,0));
    mActions.insert("lockZoom", QVersionNumber(1,0,0));
    mActions.insert("lockView", QVersionNumber(1,0,0));
    mActions.insert("print", QVersionNumber(1,0,0));
    mActions.insert("toggleFullscreenInfoBar", QVersionNumber(1,0,0));
    mActions.insert("pasteFile", QVersionNumber(1,0,0));
}