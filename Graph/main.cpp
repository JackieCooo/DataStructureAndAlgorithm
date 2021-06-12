/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-06-05
  * @brief   主程序
  ******************************************************************************
  * @attention
  * C++标准：C++20
  * IDE：Clion 2021.1
  * .exe文件在cmake-build-debug文件内
  * 使用外部文件导入图时注意.exe文件的路径
  *
  * 代码已上传至Github和码云，关注日后更新
  * Github：https://github.com/JackieCooo/DataStructureAndAlgorithm/Graph
  * 码云：https://gitee.com/JackieCoo/DataStructureAndAlgorithm/Graph
  ******************************************************************************
  */

#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;

/**
  * @brief  主函数
  * @param None
  * @retval None
  */
int main() {
    // 自己根据需要选择不同的编译方案
#if 0  // 这里为用户代码
    Graph<int> g;
    string s = "../ExternImportExample.txt";
    g.createGraph(s);
    g.traversalWithDFS(0);
    g.traversalWithBFS(0);
    g.findShortestWayUsingDijkstra(0);
    g.findShortestWayUsingFloyd(0);
    g.createMinimumSpanningTreeUsingPrim(0);
    g.createMinimumSpanningTreeUsingKruskal();

#else  // 这里为测试代码
    Graph<int> graph;
    int choice;
    while (true) {
        cout << "请选择(0退出, 1建图, 2dfs遍历, 3bfs遍历, 4最短路径, 5最小生成树):";
        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // 清屏
                cout << "再见！" << endl;
                system("pause");  // 暂停
                exit(0);  // 退出程序
            }
            case 1: {
                cout << "请选择创建方式: " << endl << "1. 手动输入" << endl << "2. 外部文件输入" << endl;
                cin >> choice;
                if(choice == 1){
                    graph.createGraph();
                }
                else if(choice == 2){
                    cout << "请输入文件路径: ";
                    string s;
                    cin >> s;
                    graph.createGraph(s);
                }
                break;
            }
            case 2: {
                graph.traversalWithDFS(0);
                break;
            }
            case 3: {
                graph.traversalWithBFS(0);
                break;
            }
            case 4: {
                cout << "请选择使用的算法: " << endl << "1. Floyd算法" << endl << "2. Dijkstra算法" << endl;
                cin >> choice;
                if(choice == 1){
                    graph.findShortestWayUsingFloyd(0);
                }
                else if(choice == 2){
                    graph.findShortestWayUsingDijkstra(0);
                }
                break;
            }
            case 5: {
                cout << "请选择使用的算法: " << endl << "1. Prim算法" << endl << "2. Kruskal算法" << endl;
                cin >> choice;
                if(choice == 1){
                    graph.createMinimumSpanningTreeUsingPrim(0);
                }
                else if(choice == 2){
                    graph.createMinimumSpanningTreeUsingKruskal();
                }
                break;
            }
            default: cout << "选择错误！" << endl;
        }
    }
#endif
    return 0;
}