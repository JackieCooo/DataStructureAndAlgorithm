/**
 ******************************************************************************
 * @file    Graph.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-06-05
 * @brief   图模板头文件
 ******************************************************************************
 */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

#define Infinite -1

using namespace std;

template<class T>
class Graph{
private:
    vector< vector<T>* >* mat = nullptr;  // 邻接矩阵
    int g_size = 0;
public:
    Graph() = default;
    ~Graph();
    void createGraph();
    void createGraph(string& filepath);
    void traversalWithDFS(int start);
    void traversalWithBFS(int start);
    void findShortestWayUsingDijkstra(int start);
    void findShortestWayUsingFloyd(int start);
    void createMinimumSpanningTreeUsingPrim(int start);
    void createMinimumSpanningTreeUsingKruskal();
private:
    void dfs(int thisNode, vector<bool>& vis);
    int f_find(vector<int>& f_set, int n);
    static bool cmp(const pair< pair<int, int>, T >& a, const pair< pair<int, int>, T >& b);
};

/**
  * @brief  此函数为析构函数
  * @param None
  * @retval None
  */
template<class T>
Graph<T>::~Graph() {
    for(auto i : *mat){  // 逐个元素释放
        delete i;
    }
    delete mat;
}

/**
  * @brief  此函数通过手动输入创建图
  * @param None
  * @retval None
  */
template<class T>
void Graph<T>::createGraph() {
    int v;
    auto* res = new vector< vector<T>* >;
    cout << "输入节点数: ";
    cin >> v;
    g_size = v;
    cout << "输入整个图的邻接矩阵: " << endl;
    for(int i = 0; i < v; i++){  // 创造邻接矩阵
        auto* tmp = new vector<T>;
        for (int j = 0; j < v; ++j) {
            T val;
            cin >> val;
            tmp->push_back(val);
        }
        res->push_back(tmp);
    }
    mat = res;
    cout << "创建成功" << endl;
}

/**
  * @brief  此函数通过外部文件输入创建图
  * @param filepath 文件的路径
  * @retval None
  */
template<class T>
void Graph<T>::createGraph(string &filepath) {
    ifstream ifs;
    ifs.open(filepath, ios::in);
    if(ifs.is_open()){
        auto* res = new vector< vector<T>* >;
        while(!ifs.eof()){
            int v;
            ifs >> v;
            g_size = v;
            for(int i = 0; i < v; i++){  // 创造邻接矩阵
                auto* tmp = new vector<T>;
                for (int j = 0; j < v; ++j) {
                    T val;
                    ifs >> val;
                    tmp->push_back(val);
                }
                res->push_back(tmp);
            }
            mat = res;
        }
        cout << "创建成功" << endl;
    }
    else{
        cout << "文件打开失败" << endl;
    }
}

/**
  * @brief  此函数深度搜索图
  * @param start 开始搜索的节点序号
  * @retval None
  */
template<class T>
void Graph<T>::traversalWithDFS(int start) {
    vector<bool> vis(g_size, false);  // 记录节点是否遍历
    cout << "深度搜索为: ";
    dfs(start, vis);
    cout << endl;
}

/**
  * @brief  此函数为深度搜索的递归实现
  * @param thisNode 当前节点
  * @param vis 已访问节点数组
  * @retval None
  */
template<class T>
void Graph<T>::dfs(int thisNode, vector<bool>& vis) {
    if(vis[thisNode]){  // 此节点已访问过
        return;
    }
    cout << thisNode << " ";
    vis[thisNode] = true;  // 标记已访问节点
    for (int i = 0; i < g_size; ++i) {  // 遍历所有前驱
        if((*(*mat)[thisNode])[i] != Infinite && !vis[i]){  // 寻找有边连接且未被访问的节点
            dfs(i, vis);
        }
    }
}

/**
  * @brief  此函数广度搜索图
  * @param start 开始搜索的节点序号
  * @retval None
  */
template<class T>
void Graph<T>::traversalWithBFS(int start) {
    cout << "广度搜索为: ";
    queue<int> q;  // 存放待扩展节点
    vector<bool> vis(g_size, false);  // 记录节点是否遍历
    q.push(start);  // 压入起始节点
    while(!q.empty()){
        int tmp = q.front();
        if(vis[tmp]){  // 此节点已被访问
            q.pop();
            continue;
        }
        vis[tmp] = true;  // 标记已访问
        cout << tmp << " ";
        for (int i = 0; i < g_size; ++i) {
            if((*(*mat)[tmp])[i] != Infinite && !vis[i]){  // 寻找有边连接且未被访问的节点
                q.push(i);  // 压入待拓展节点
            }
        }
        q.pop();  // 已访问节点弹出
    }
    cout << endl;
}

/**
  * @brief  此函数使用Dijkstra算法寻找最短路径
  * @param start 起始点
  * @retval None
  */
template<class T>
void Graph<T>::findShortestWayUsingDijkstra(int start) {
    vector<T> dis(g_size, 0);  // 存放起始点至各点的最短距离
    vector<bool> vis(g_size, false);  // 记录节点是否已访问

    for (int i = 0; i < g_size; ++i) {  // 初始化dis
        dis[i] = (*(*mat)[start])[i];
    }

    int cnt = 0;  // 计算已知最短距离的顶点数量
    while(cnt != g_size){
        int index = 0;  // dis中最小数的下标
        int minDis = INT_MAX;  // 最小的数
        for(int i = 0; i < g_size; i++){  // 寻找dis中最小且未遍历的节点
            if(dis[i] != Infinite && dis[i] < minDis && !vis[i]){
                index = i;
                minDis = dis[i];
            }
        }
        vis[index] = true;  // 标记已访问
        ++cnt;
        for (int i = 0; i < g_size; ++i) {
            if(!vis[i] && (*(*mat)[index])[i] != Infinite && ((dis[index] + (*(*mat)[index])[i] < dis[i]) || (dis[i] == Infinite))){  // 如果起始节点到标记节点再到此节点的距离小于dis中起始节点到此节点的距离
                dis[i] = dis[index] + (*(*mat)[index])[i];
            }
        }
    }

    for (int i = 0; i < g_size; ++i) {
        cout << "从节点" << start << "到节点" << i << "的最短距离为" << dis[i] << endl;
    }
}

/**
  * @brief  此函数使用Floyd算法寻找最短路径
  * @param start 起始点
  * @retval None
  */
template<class T>
void Graph<T>::findShortestWayUsingFloyd(int start) {
    vector< vector<T> > tmp;
    for (int i = 0; i < g_size; ++i) {  // 复制邻接矩阵
        vector<T> tmpRow;
        for (int j = 0; j < g_size; ++j) {
            tmpRow.push_back((*(*mat)[i])[j]);
        }
        tmp.push_back(tmpRow);
    }

    for (int i = 0; i < g_size; ++i) {
        for (int j = 0; j < g_size; ++j) {
            for (int k = 0; k < g_size; ++k) {
                if(tmp[j][i] != Infinite && tmp[i][k] != Infinite && (tmp[j][k] > tmp[j][i] + tmp[i][k] || tmp[j][k] == Infinite)) {
                    tmp[j][k] = tmp[j][i] + tmp[i][k];
                }
            }
        }
    }

    for (int i = 0; i < g_size; ++i) {
        cout << "从节点" << start << "到节点" << i << "的最短距离为" << tmp[start][i] << endl;
    }
}

/**
  * @brief  此函数使用Prim算法创造最小生成树
  * @param start 起始点
  * @retval None
  */
template<class T>
void Graph<T>::createMinimumSpanningTreeUsingPrim(int start) {
    vector<bool> vis(g_size, false);  // 记录节点是否已加入最小生成树
    list< pair<int, int> > dis; // 记录树节点到未加入节点的距离
    T sum = 0;  // 记录最短距离
    cout << "节点加入的顺序为: " << start << " ";
    vis[start] = true;  // 标记起始节点已加入
    for (int i = 0; i < g_size; ++i) {
        if((*(*mat)[start])[i] != Infinite && start != i){
            dis.emplace_back(start, i);
        }
    }
    for (int i = 0; i < g_size-1; ++i) {  // 起始节点已加入，所以只用找n-1个节点
        int index = -1;  // 目标节点序号
        T minDis = INT_MAX;  // 距离
        for (auto &j : dis) {  // 从候选边中选择最短边
            if((*(*mat)[j.first])[j.second] < minDis){
                minDis = (*(*mat)[j.first])[j.second];
                index = j.second;
            }
        }
        vis[index] = true;  // 标记加入
        sum += minDis;
        cout << index << " ";
        vector< _List_iterator< pair<int, int> > > tmp;
        for (auto j = dis.begin(); j != dis.end(); j++) {  // 更新dis，去掉不符合的节点
            if(vis[j->second]){
                tmp.push_back(j);
            }
        }
        for (auto &j : tmp) {
            dis.erase(j);
        }
        for (int j = 0; j < g_size; ++j) {  // 更新dis，增加候选节点
            if((*(*mat)[index])[j] != Infinite && index != j && !vis[j]){
                dis.emplace_back(index, j);
            }
        }
    }
    cout << endl << "最短距离为: " << sum << endl;
}

/**
  * @brief  此函数使用Kruskal算法创造最小生成树
  * @param None
  * @retval None
  */
template<class T>
void Graph<T>::createMinimumSpanningTreeUsingKruskal() {
    vector<int> f(g_size, 0);  // 并查集，用于判断是否有环
    vector< pair< pair<int, int>, T > > dis;  // 记录所有边
    T sum = 0;  // 记录最短距离
    for (int i = 0; i < f.size(); ++i) {  // 初始化并查集
        f[i] = i;
    }
    for (int i = 0; i < g_size; ++i) {  // 加入所有边
        for (int j = i+1; j < g_size; ++j) {
            if((*(*mat)[i])[j] != Infinite) {
                dis.push_back(make_pair(make_pair(i, j), (*(*mat)[i])[j]));
            }
        }
    }
    sort(dis.begin(), dis.end(), cmp);  // 对所有边排序
    int cnt = 0;  // 记录已加入边数
    cout << "边加入的顺序为: ";
    for (int i = 0; cnt != g_size-1; ++i) {
        int f1 = f_find(f, dis[i].first.first);
        int f2 = f_find(f, dis[i].first.second);
        if(f1 != f2){  // 不在同一颗子树，合并
            f[f2] = f1;
            ++cnt;
            sum += dis[i].second;
            cout << dis[i].first.first << "-" << dis[i].first.second << " ";
        }
    }
    cout << endl << "最短距离为: " << sum << endl;
}

/**
  * @brief  此函数为并查集的查找函数
  * @param f_set 并查集的引用
  * @param n 要查找的元素
  * @retval 返回查找元素的根节点
  */
template<class T>
int Graph<T>::f_find(vector<int>& f_set, int n) {
    while(f_set[n] != n) n = f_set[n];
    return n;
}

/**
  * @brief  此函数为sort函数的回调函数
  * @param a 元素1
  * @param b 元素2
  * @retval true a小于b
  * @retval false a大于b
  */
template<class T>
bool Graph<T>::cmp(const pair<pair<int, int>, T> &a, const pair<pair<int, int>, T> &b) {
    return a.second < b.second;
}
