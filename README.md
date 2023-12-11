# 抽卡估算器Gacha Estimator

一个使用蒙特卡洛方法（即多次抽卡）估算手游抽卡概率的估算器。A probility estimator for gacha games.

## 使用方法Usage

1. 通过git下载本仓库。Download this repository using git.
```
git clone https://github.com/zznewclear13/GachaEstimator.git
git submodule update --init --recursive
```

2. 双击`cmake.bat`配置VS工程。Double click `cmake.bat` to configure Visual Studio project.

3. 使用Visual Studio打开位于`build/`目录下的`Gacha Estimator.sln`。Under `build/` directory, open `Gacha Estimator.sln` using Visual Studio.

4. 点击`Build->Build Solution`开始构建。Click `Build->Build Solution` to start building.

5. 在`binary/Debug`或者`binary/Release`下即可找到构建好的`GachaEstimator.exe`。`GachaEstimator.exe` will be built to `binary/Debug` or `binary/Release`.

6. 双击`genshin.bat`即可估测原神抽卡概率。Double click `genshin.bat` to estimate gacha probability in Genshin Impact.

## 命令行说明Command Line Usage

通过自定义命令行也能运行此估算器。You can run this estimator through custom command line arguments.

1. -TotalSims: 模拟次数，默认1000
2. -MaxPulls: 最大抽卡次数，每一次模拟最大抽卡次数，默认100
3. -BaseProb: 基础概率
4. -SoftPity: 软保底，软保底触发后会逐渐增加概率
5. -SoftPityProb: 触发软保底后每次抽卡增加的概率
6. -HardPity: 硬保底，硬保底触发时当场判断是否抽中
7. -HardPityProb: 硬保底抽中概率（硬保底也能歪？）
8. -EarlyExit: 当抽中SSR后停止抽卡

## 特性Features

使用[nanothread](https://github.com/mitsuba-renderer/nanothread)进行多线程模拟抽卡。Multi-thread simulation based on [nanothread](https://github.com/mitsuba-renderer/nanothread). 

## 许可License

```
MIT License

Copyright (c) 2023 zznewclear@gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```