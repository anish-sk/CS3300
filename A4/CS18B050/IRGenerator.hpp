/*
    * Abstract Syntax Tree as input
    * Convert to 3 Address Code incrementally
    * File generated is a.ir
*/

#include <bits/stdc++.h>
#include "treeNode.hpp"
#include "symbolTable.hpp"
#include "codeGenerator.hpp"

using namespace std;

long long int label_count = 1ll;
long long int temp_count = 1ll;

extern treeNode* ast;

ofstream IR;        // file containing IR

symbolTableStack env;    // current symbol table environment
symbolTable final_table;    // used for code generation

int table_offset = 0;
int table_arg_offset = 0;
int depth_counter = 0;

void printAST(treeNode* root, string prefix = "", bool isLast = true) {
    if(root == NULL) {
        return;
    }
    cout << prefix;
    if(isLast) {
        cout << "└───────";
    }
    else {
        cout << "├───────";
    }
    if(root->nodeName == "identifier") {
        cout << root->lexValue << endl;
    }
    else {
        cout << root->nodeName << endl;
    }
    for(int i = 0; i < root->children.size(); i++) {
        if(i == root->children.size() - 1) {
            printAST(root->children[i], prefix + "|        ", true);
        }
        else {
            printAST(root->children[i], prefix + "|        ", false);
        }
    }
}

string newLabel() {   // returns new label
    string LABEL = ".L";
    string x = to_string(label_count);
    LABEL += x;
    label_count++;
    return LABEL;
}

string newTemp() {  // returns new temp variable for 3 address code
    string TEMP = "$t";
    string x = to_string(temp_count);
    TEMP += x;
    temp_count++;
    return TEMP; 
}

void setInherited(treeNode* root) {
    if(root->nodeName == "func_decl") {
        depth_counter = 0;
        root->depth = depth_counter;
        root->func_name = root->children[1]->lexValue;
    }
    if(root->nodeName == "compound_stmt") {
        depth_counter++;
        for(auto& child : root->children) {
            child->depth = depth_counter;
        }
    }
    else {
        for(auto& child : root->children) {
            child->depth = root->depth;
        }
    }
    for(auto& child : root->children) {
        child->func_name = root->func_name;
    }

}

void traverseAST(treeNode* root) {
    /**
     * Preprocess the current node
     * var_decl
     * local_decl
     * func_decl
     * assign_stmt
     * printf_stmt
     * if_stmt
     * while_stmt
     * return_stmt
     * expr
     * Pexpr
    **/
    setInherited(root);
    string name = root->nodeName;
    if(name == "if_gone"){
        return;
    }
    if(name == "var_decl") {
        // cout << "I am at " << name << endl;
    }
    if(name == "local_decl") {
        // cout << "I am at " << name << endl;
        if(root->children.size() == 3) {    // non-array declaration
            for(auto& child : root->children) {
                traverseAST(child);
            }
            auto child1 = root->children[1];
            child1->width = root->children[0]->width;
            child1->symbolTableName = child1->lexValue + "_" + child1->func_name + "_" + to_string(child1->depth);
            child1->offset = table_offset;
            table_offset += child1->width;
            env.set(child1->lexValue, child1);
            final_table.set(child1->symbolTableName, child1);
        }    
        else {  // array declaration
            for(auto& child : root->children) {
                traverseAST(child);
            }        
            auto child1 = root->children[1];
            string arr_length = root->children[3]->children[0]->children[0]->lexValue;   // assuming that the length of the array is an integer_lit
            child1->width = 4 * to_integer(arr_length);
            child1->symbolTableName = child1->lexValue + "_" + child1->func_name + "_" + to_string(child1->depth);
            child1->offset = table_offset;
            table_offset += child1->width;
            env.set(child1->lexValue, child1);
            final_table.set(child1->symbolTableName, child1);
        }
    }
    else if(name == "func_decl") {
            // cout << "I am at " << name << endl;
            table_offset = 4;
            table_arg_offset = 16;
            symbolTable top;
            env.addTable(top);
            IR << root->children[1]->lexValue <<  ":" << endl;
            for(auto& child : root->children) {
                traverseAST(child);
            }
            root->offset = table_offset;
            final_table.set("@" + root->children[1]->lexValue, root);
            env.removeTop();
            IR << "end" << endl;  // function code finishes
    }
    else if(name == "param") {
         if(root->children.size() == 2) {    // non-array paramter
            for(auto& child : root->children) {
                traverseAST(child);
            }
            auto child1 = root->children[1];
            child1->width = root->children[0]->width;
            child1->symbolTableName = child1->lexValue + "_" + child1->func_name + "_" + to_string(child1->depth);
            child1->offset = table_arg_offset;
            child1->isArg = true;
            table_arg_offset += 8;
            env.set(child1->lexValue, child1);
            final_table.set(child1->symbolTableName, child1);
        }       
    }
    else if(name == "assign_stmt") {
        //    cout << "I am at " << name << endl;
        for(auto& child : root->children) {
               traverseAST(child);
        }
        auto op_child = root->children[0];
        if(op_child->children.size() == 2) {
            string code = env.get(op_child->children[0]->lexValue) + " = " + op_child->children[1]->addr;
            IR << code << endl;
            // cout << root->code << endl;
         }
         else {          // array assignment to be handled
            string code = env.get(op_child->children[0]->lexValue) + "[" + op_child->children[2]->addr + "]" + " = " + op_child->children[4]->addr;
            IR << code << endl;
         }
    }
    else if(name == "compound_stmt") {
        symbolTable top;
        env.addTable(top);
        for(auto& child : root->children) {
            traverseAST(child);
        }
        env.removeTop();
    }
    else if(name == "print_stmt") {
        // cout << "I am at " << name << endl;
        for(auto& child : root->children) {
            traverseAST(child);
        }
        string arg = env.get(root->children[4]->lexValue);
        IR << "printf" << " " << arg << endl;
        //cout<<root->line_no<<"\n";
    }
    else if(name == "scanf_stmt") {
        // cout << "I am at " << name << endl;
        for(auto& child : root->children) {
            traverseAST(child);
        }
        string arg = env.get(root->children[5]->lexValue);
        IR << "scanf" << " " << arg << endl;
        //cout<<root->line_no<<"\n";
    }
    else if(name == "if_stmt") {
    //    cout << "I am at " << name << endl;
        if(root->children.size() == 5) {   // if but no else
            string l1 = newLabel();
            traverseAST(root->children[2]);  // expression
            string code3 = "ifFalse " + root->children[2]->addr + " goto " + l1; 
            IR << code3 << endl;
            traverseAST(root->children[4]);  // statement   
            string final_code = l1 + ":";
            IR << final_code << endl;
        }
        else {    // if followed by an else
            traverseAST(root->children[2]);  // expression
            string l1 = newLabel();
            string l2 = newLabel();
            string code4 = "ifFalse " + root->children[2]->addr + " goto " + l1;
            IR << code4 << endl;
            traverseAST(root->children[4]);  // if statement
            string code5 = "goto " + l2 + "\n" + l1 + ":";
            IR << code5 << endl;
            traverseAST(root->children[6]);  // else statement
            string code6 = l2 + ":";
            IR << code6 << endl;  
        }
   }
   else if(name == "while_stmt") {
    //    cout << "I am at " << name << endl;
        string l1 = newLabel(); // start of the loop
        string code5 = l1 + ":";
        IR << code5 << endl;
        traverseAST(root->children[2]); // condition expression
        string l2 = newLabel(); // outside the loop
        string code3 = "ifFalse " + root->children[2]->addr + " goto " + l2;
        IR << code3 << endl;
        traverseAST(root->children[4]); // statement
        string code6 = "goto " + l1 + "\n" + l2 + ":";
        IR << code6 << endl;
   }
   else if(name == "return_stmt") {
     //    cout << "I am at " << name << endl;
        for(auto& child : root->children) {
            traverseAST(child);
        } 
        if(root->children.size() == 2) {
            IR << "return " << "0" << endl;
        }
        else {
            IR << "return " << root->children[1]->addr << endl;
        }
        //cout<<root->line_no<<"\n";
   }
   else if(name == "incr_stmt") {
       for(auto& child : root->children) {
           traverseAST(child);
       }
       string var = env.get(root->children[0]->lexValue);
       IR << var << " = " << var << " PLUS " << 1 << endl; 
   }
   else if(name == "decr_stmt") {
       for(auto& child : root->children) {
           traverseAST(child);
       }
       string var = env.get(root->children[0]->lexValue);
       IR << var << " = " << var << " MINUS " << 1 << endl;
   }
   else if(name == "expr") {
        // cout << "I am at " << name << endl;
        if(root->children.size() == 1) {   // binary op or Pexpr
            string op = root->children[0]->nodeName;
            auto op_child = root->children[0];
            if(op_child->children.size() == 2) {     // binary op
                if(op == "AND") {
                    root->addr = newTemp();
                    op_child->symbolTableName = root->addr;
                    final_table.set(root->addr, op_child);
                    op_child->width = 4;
                    op_child->offset += table_offset;
                    table_offset += 4;
                    env.set(root->addr, op_child);
                    traverseAST(op_child->children[0]);
                    string L1 = newLabel();
                    string code1 = "ifFalse " + op_child->children[0]->addr + " goto " + L1;
                    IR << code1 << endl;
                    traverseAST(op_child->children[1]);
                    string L2 = newLabel();
                    string code2 = "if " + op_child->children[1]->addr + " goto " + L2;
                    IR << code2 << endl;
                    string L3 = newLabel();
                    IR << L1 << ":" << endl;
                    IR << root->addr << " = " << 0 << endl;
                    IR << "goto " << L3 << endl;
                    IR << L2 << ":" << endl;
                    IR << root->addr << " = " << 1 << endl;
                    IR << L3 << ":" << endl;
                }
                else if(op == "OR") {
                    root->addr = newTemp();
                    op_child->symbolTableName = root->addr;
                    final_table.set(root->addr, op_child);
                    op_child->width = 4;
                    op_child->offset += table_offset;
                    table_offset += 4;
                    env.set(root->addr, op_child);
                    traverseAST(op_child->children[0]);
                    string L1 = newLabel();
                    string code1 = "if " + op_child->children[0]->addr + " goto " + L1;
                    IR << code1 << endl;
                    traverseAST(op_child->children[1]);
                    string L2 = newLabel();
                    string code2 = "ifFalse " + op_child->children[1]->addr + " goto " + L2;
                    IR << code2 << endl;
                    string L3 = newLabel();
                    IR << L1 << ":" << endl;
                    IR << root->addr << " = " << 1 << endl;
                    IR << "goto " << L3 << endl;
                    IR << L2 << ":" << endl;
                    IR << root->addr << " = " << 0 << endl;
                    IR << L3 << ":" << endl;
                }
                else {
                    for(auto& child : root->children) {
                       traverseAST(child);
                    }
                    root->addr = newTemp();
                    op_child->symbolTableName = root->addr;
                    final_table.set(root->addr, op_child);
                    op_child->width = 4;
                    op_child->offset += table_offset;
                    table_offset += 4;
                    env.set(root->addr, op_child);
                    string code = root->addr +  " = " + op_child->children[0]->addr + " " + op + " " + op_child->children[1]->addr;
                    // string final_code = code1 + code2 + code3 + "\n";
                    IR << code << endl;
                }
            }
            else {          // Pexpr
                for(auto& child : root->children) {
                   traverseAST(child);
                }
                root->addr = root->children[0]->addr;
            }
        }
        else if(root->children.size() == 2) {   // unary op
            string op = root->children[0]->nodeName;
            root->addr = newTemp();
            root->children[0]->symbolTableName = root->addr;
            root->children[0]->width = 4;
            root->children[0]->offset += table_offset;
            table_offset += 4;
            env.set(root->addr, root->children[0]);
            final_table.set(root->addr, root->children[0]);
            for(auto& child : root->children) {
                traverseAST(child);
            }
            string code = root->addr + " = " + op + " " + root->children[1]->addr;
            IR << code << endl;
        }
        else {
            // HANDLE sizeof, array reference, function call
            root->addr = newTemp();
            root->children[1]->symbolTableName = root->addr;
            root->children[1]->width = 4;
            root->children[1]->offset += table_offset;
            table_offset += 4;
            env.set(root->addr, root->children[1]);
            final_table.set(root->addr, root->children[1]);
            if(root->children[0]->nodeName == "SIZEOF") {
                for(auto& child : root->children) {
                    traverseAST(child);
                }
                string size;
                if(final_table.isInTable(root->children[2]->addr)) {
                    auto node = final_table.getNode(root->children[2]->addr);
                    size = to_string(node->width);
                }
                else {
                    size = "4";
                } 
                string code = root->addr + " = " + size;
                IR << code << endl;
            }
            else if(root->children[1]->nodeName == "[") {    // array expression
                for(auto& child : root->children) {
                    traverseAST(child);
                }
                string code = root->addr + " = " + env.get(root->children[0]->lexValue) + "[" + root->children[2]->addr + "]";
                IR << code << endl;
            } 
            else {     // function call
                for(auto& child : root->children) {
                    traverseAST(child);
                }
                stack<string> s = root->children[2]->arg_stack;
                int n = s.size();
                while(!s.empty()) {
                    string arg = s.top();
                    s.pop();
                    IR << "param " << arg << endl;
                }
                string code = root->addr + " = " + "call function " + root->children[0]->lexValue + " " + to_string(n);
                IR << code << endl;
             }
        }
   }
   else if(name == "args") {
       for(auto& child : root->children) {
           traverseAST(child);
       }
       root->arg_stack = root->children[0]->arg_stack;
   }
   else if(name == "arg_list") {
       for(auto& child : root->children) {
            traverseAST(child);
       }
       if(root->children.size() == 1) {
            root->arg_stack.push(root->children[0]->addr);
       }
       else {
            stack<string> s = root->children[0]->arg_stack;
            s.push(root->children[2]->addr); 
            root->arg_stack = s;
       }
   }
   else if(name == "Pexpr") {
        // cout << "I am at " << name << endl;
        if(root->children.size() == 3) {   // (expr)
            for(auto& child : root->children) {
                traverseAST(child);
            }
            root->addr = root->children[1]->addr;
            root->code = root->children[1]->code;
        }
        else {
            if(root->children[0]->nodeName == "identifier") {
                root->addr = env.get(root->children[0]->lexValue);
            }
            else {
                root->addr = root->children[0]->lexValue;
            }
        }
   }
   if(name != "expr" and name != "Pexpr" and name != "assign_stmt" and name != "if_stmt" and name != "while_stmt" and name != "func_decl" and name != "compound_stmt" and 
   name != "print_stmt" and name != "param" and name != "args" and name != "arg_list" and name != "return_stmt" and name != "incr_stmt" and name != "decr_stmt") {
        string final_code = "";
        for(auto& child : root->children) {
            traverseAST(child);
            // final_code += child->code;
        }
        // root->code = final_code;
   }
}

int generateIR() {
    //printAST(ast, "", true);
    IR.open("b.ir");
    //cout<<"hianfaoisfn"<<flush;
    traverseAST(ast);
    //cout << "-----------3AC---------" << endl;
    IR.close();
    // final_table.debug();  // final symbol table
    codeGenerator();    // generate x86 code
    return 0;
}