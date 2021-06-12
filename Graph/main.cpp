/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Jackie
  * @version V1.0
  * @date    2021-06-05
  * @brief   ������
  ******************************************************************************
  * @attention
  * C++��׼��C++20
  * IDE��Clion 2021.1
  * .exe�ļ���cmake-build-debug�ļ���
  * ʹ���ⲿ�ļ�����ͼʱע��.exe�ļ���·��
  *
  * �������ϴ���Github�����ƣ���ע�պ����
  * Github��https://github.com/JackieCooo/DataStructureAndAlgorithm/Graph
  * ���ƣ�https://gitee.com/JackieCoo/DataStructureAndAlgorithm/Graph
  ******************************************************************************
  */

#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;

/**
  * @brief  ������
  * @param None
  * @retval None
  */
int main() {
    // �Լ�������Ҫѡ��ͬ�ı��뷽��
#if 0  // ����Ϊ�û�����
    Graph<int> g;
    string s = "../ExternImportExample.txt";
    g.createGraph(s);
    g.traversalWithDFS(0);
    g.traversalWithBFS(0);
    g.findShortestWayUsingDijkstra(0);
    g.findShortestWayUsingFloyd(0);
    g.createMinimumSpanningTreeUsingPrim(0);
    g.createMinimumSpanningTreeUsingKruskal();

#else  // ����Ϊ���Դ���
    Graph<int> graph;
    int choice;
    while (true) {
        cout << "��ѡ��(0�˳�, 1��ͼ, 2dfs����, 3bfs����, 4���·��, 5��С������):";
        cin >> choice;
        switch (choice) {
            case 0: {
                system("cls");  // ����
                cout << "�ټ���" << endl;
                system("pause");  // ��ͣ
                exit(0);  // �˳�����
            }
            case 1: {
                cout << "��ѡ�񴴽���ʽ: " << endl << "1. �ֶ�����" << endl << "2. �ⲿ�ļ�����" << endl;
                cin >> choice;
                if(choice == 1){
                    graph.createGraph();
                }
                else if(choice == 2){
                    cout << "�������ļ�·��: ";
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
                cout << "��ѡ��ʹ�õ��㷨: " << endl << "1. Floyd�㷨" << endl << "2. Dijkstra�㷨" << endl;
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
                cout << "��ѡ��ʹ�õ��㷨: " << endl << "1. Prim�㷨" << endl << "2. Kruskal�㷨" << endl;
                cin >> choice;
                if(choice == 1){
                    graph.createMinimumSpanningTreeUsingPrim(0);
                }
                else if(choice == 2){
                    graph.createMinimumSpanningTreeUsingKruskal();
                }
                break;
            }
            default: cout << "ѡ�����" << endl;
        }
    }
#endif
    return 0;
}