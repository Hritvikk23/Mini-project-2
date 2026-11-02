#pragma once
#include "airport.h"
#include <queue>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AirportBST{
public:
    AirportBST(){
        root = nullptr;
        count =0;
    }
    bool insert(const Airport &a){
        Node *parent = nullptr;
        Node *cur = root;

        while(cur!=nullptr){
            parent = cur;
            if(a.iata<cur->data.iata){
                cur = cur->left;
            }
            else if(a.iata>cur->data.iata){
                cur = cur->right;
            }
            else
                return false;
        }
        Node *n = new Node(a);
        if (parent==nullptr) root = n;
        else if (a.iata<parent->data.iata) parent->left = n;
        else parent->right = n;

        count ++;
        return true;
    }
    int size(){
        return count;
    }
    int height(){
        if (root == nullptr) return -1;
        queue<Node*>  q;
        q.push(root);
        int depth =0;

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            depth++;
        }
        return depth-1;
    }
    double avg_depth(){
        if (root == nullptr) return 0.0;
        double total = 0;
        queue<Node*>  q;
        q.push(root);
        int depth =0;

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* curr = q.front();
                q.pop();
                total = total+depth;
                if (curr->left !=nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
            depth++;
        }
        return total/count;
    }
    const Airport* search(const string &code, vector<string> &path, int &comp) const{
        comp =0;
        Node *cur = root;
        while(cur!=nullptr){
           path.push_back(cur->data.iata);
           comp++;
           
           if(code <cur->data.iata) cur = cur->left;
           else if (code >cur->data.iata) cur = cur->right;
           else return &cur->data;
        }
        return nullptr;
    }
    const Airport* min() const{
        if (root==nullptr) return nullptr;
        Node *cur = root;
        while(cur->left!= nullptr){
            cur = cur->left;
        }
        return &cur->data;
    }
    const Airport* max()const{
        if (root==nullptr) return nullptr;
        Node *cur = root;
        while(cur->right!= nullptr){
            cur = cur->right;
        }
        return &cur->data;
    }
private:
    struct Node{
        Airport data;
        Node *left;
        Node *right;
        Node(const Airport &a){
            data= a;
            left = nullptr;
            right = nullptr;
        }
    };
    Node *root;
    int count;
};