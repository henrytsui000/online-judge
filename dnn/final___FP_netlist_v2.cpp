#include <stdlib.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
//#include <bitset>
//#include <map>
#include <algorithm>

using namespace std;

class Gate {
   public:
    // for example //
    //Gate(const string _gate_type, const string _gate_num, const string _outnet, const string _innet1):gate_type(_gate_type), gate_num(_gate_num), out_net(_outnet), in_net_1(_innet1){}
    virtual int getout(){};
    virtual int getin1(){};
    virtual int getin2(){};
    virtual string getname(){};
    virtual void reset(){};
    /* define by yourself */
    //string gate_type, gate_num, out_net, in_net_1, in_net_2, in_net_3;
    //int in1_val, in2_val, in3_val, out_val;
};

class INV : public Gate {
   public:
    INV(string na, int* in1, int* out) : invin(in1), invname(na), invout(out) {
        if (*invin == 1)
            *invout = 0;
        else
            *invout = 1;
    }
    int getout() { return *invout; }
    int getin1() { return *invin; }
    string getname() { return invname; }
    void reset() {
        if (*invin == 1)
            *invout = 0;
        else
            *invout = 1;
    }

   private:
    string invname;
    int* invin;
    int* invout;
};
class NAND2 : public Gate {
   public:
    NAND2(string na, int* in1, int* in2, int* out) : nanin1(in1), nanin2(in2), nanname(na), nanout(out) {
        if (*nanin1 == *nanin2 && *nanin1 == 1)
            *nanout = 0;
        else
            *nanout = 1;
    }
    int getout() { return *nanout; }
    int getin1() { return *nanin1; }
    int getin2() { return *nanin2; }
    string getname() { return nanname; }
    void setout(int in) { *nanout = in; }
    void setin1(int in) { *nanin1 = in; }
    void setin2(int in) { *nanin2 = in; }
    void reset() {
        if (*nanin1 == *nanin2 && *nanin1 == 1)
            *nanout = 0;
        else
            *nanout = 1;
    }

   private:
    string nanname;
    int* nanin1;
    int* nanin2;
    int* nanout;
};
class NOR2 : public Gate {
   public:
    NOR2(string na, int* in1, int* in2, int* out) : norin1(in1), norin2(in2), norname(na), norout(out) {
        if (*norin1 == *norin2 && *norin1 == 0)
            *norout = 1;
        else
            *norout = 0;
    }
    int getout() { return *norout; }
    int getin1() { return *norin1; }
    int getin2() { return *norin2; }
    string getname() { return norname; }
    void setout(int in) { *norout = in; }
    void setin1(int in) { *norin1 = in; }
    void setin2(int in) { *norin2 = in; }
    void reset() {
        if (*norin1 == *norin2 && *norin1 == 0)
            *norout = 1;
        else
            *norout = 0;
    }

   private:
    string norname;
    int* norin1;
    int* norin2;
    int* norout;
};
class XOR2 : public Gate {
   public:
    XOR2(string na, int* in1, int* in2, int* out) : xorin1(in1), xorin2(in2), xorname(na), xorout(out) {
        if (*xorin1 != *xorin2)
            *xorout = 1;
        else
            *xorout = 0;
    }
    int getout() { return *xorout; }
    int getin1() { return *xorin1; }
    int getin2() { return *xorin2; }
    string getname() { return xorname; }
    void reset() {
        if (*xorin1 != *xorin2)
            *xorout = 1;
        else
            *xorout = 0;
    }

   private:
    string xorname;
    int* xorin1;
    int* xorin2;
    int* xorout;
};
class XNOR2 : public Gate {
   public:
    XNOR2(string na, int* in1, int* in2, int* out) : xnorin1(in1), xnorin2(in2), xnorname(na), xnorout(out) {
        if (*xnorin1 != *xnorin2)
            *xnorout = 0;
        else
            *xnorout = 1;
    }
    int getout() { return *xnorout; }
    int getin1() { return *xnorin1; }
    int getin2() { return *xnorin2; }
    string getname() { return xnorname; }
    void reset() {
        if (*xnorin1 != *xnorin2)
            *xnorout = 0;
        else
            *xnorout = 1;
    }

   private:
    string xnorname;
    int* xnorin1;
    int* xnorin2;
    int* xnorout;
};
class NAND3 : public NAND2 {
   public:
    NAND3(string na, int* in1, int* in2, int* in3, int* out) : NAND2(na, in1, in2, out), nanin3(in3) {
        if (getin1() == getin2() && getin2() == getin3() && getin1() == 1)
            setout(0);
        else
            setout(1);
    }
    int getin3() { return *nanin3; }
    void reset() {
        if (getin1() == getin2() && getin2() == getin3() && getin1() == 1)
            setout(0);
        else
            setout(1);
    }

   private:
    int* nanin3;
};
class NOR3 : public NOR2 {
   public:
    NOR3(string na, int* in1, int* in2, int* in3, int* out) : NOR2(na, in1, in2, out), norin3(in3) {
        int time = 0;
        if (getin1() == 1) time += 1;
        if (getin2() == 1) time += 1;
        if (*norin3 == 1) time += 1;
        if (time = 0 || time == 2)
            setout(1);
        else
            setout(0);
    }
    int getin3() { return *norin3; }
    void reset() {
        int time = 0;
        if (getin1() == 1) time += 1;
        if (getin2() == 1) time += 1;
        if (*norin3 == 1) time += 1;
        if (time = 0 || time == 2)
            setout(1);
        else
            setout(0);
    }

   private:
    int* norin3;
};

string module_name;
vector<string> output;
vector<int> outval;
vector<string> input;
vector<int> inval;
vector<string> wire;
vector<int> wireval;
vector<Gate*> all_Gate;

int find(vector<string> a, string b) {
    int where = -1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b) where = i;
    }
    return where;
}

void parseNET(const char* fin) {
    ifstream filein;
    filein.open(fin, ios::in);
    string str, temp;

    //mudule name
    getline(filein, str);

    //output
    getline(filein, str);
    stringstream ss;
    ss << str;
    ss >> temp;
    string tt;
    int i = 0;
    while (getline(ss, tt, ' ')) {
        ss << tt;
        ss >> temp;
        if (i % 2 == 0) {
            output.push_back(temp);
        } else {
            int v = atoi(temp.c_str());
            outval.push_back(v);
        }
        i++;
    }

    //input
    getline(filein, str);
    ss << str;
    ss >> temp;
    i = 0;
    while (getline(ss, tt, ' ')) {
        ss << tt;
        ss >> temp;
        if (i % 2 == 0) {
            input.push_back(temp);
        } else {
            int v = atoi(temp.c_str());
            inval.push_back(v);
        }
        i++;
    }

    //wire
    getline(filein, str);
    ss << str;
    ss >> temp;
    i = 0;
    while (getline(ss, tt, ' ')) {
        ss << tt;
        ss >> temp;
        if (i % 2 == 0) {
            wire.push_back(temp);
        } else {
            int v = atoi(temp.c_str());
            wireval.push_back(v);
        }
        i++;
    }

    //Gate
    string type;
    while (filein >> type) {
        if (type == "INV") {
            string num, out, in1;
            int locat;
            int* value;
            int* outadd;
            filein >> num >> out >> in1;
            if (find(input, in1) != -1) {
                locat = find(input, in1);
                value = &(inval[locat]);
            } else {
                locat = find(wire, in1);
                value = &(wireval[locat]);
            }
            locat = find(wire, out);
            outadd = &(wireval[locat]);
            Gate* inv = new INV(num, value, outadd);

            all_Gate.push_back(inv);
        } else if (type == "NAND2") {
            string num, out, in1, in2;
            filein >> num >> out >> in1 >> in2;

            int locat;
            int* value1;
            int* value2;
            int* outadd;
            if (find(input, in1) != -1) {
                locat = find(input, in1);
                value1 = &(inval[locat]);
            } else {
                locat = find(wire, in1);
                value1 = &(wireval[locat]);
            }
            if (find(input, in2) != -1) {
                locat = find(input, in2);
                value2 = &(inval[locat]);
            } else {
                locat = find(wire, in2);
                value2 = &(wireval[locat]);
            }

            locat = find(wire, out);
            outadd = &(wireval[locat]);
            Gate* nand2 = new NAND2(num, value1, value2, outadd);

            all_Gate.push_back(nand2);
        } else if (type == "NOR2") {
            string num, out, in1, in2;
            filein >> num >> out >> in1 >> in2;

            int locat;
            int* value1;
            int* value2;
            int* outadd;
            if (find(input, in1) != -1) {
                locat = find(input, in1);
                value1 = &(inval[locat]);
            } else {
                locat = find(wire, in1);
                value1 = &(wireval[locat]);
            }
            if (find(input, in2) != -1) {
                locat = find(input, in2);
                value2 = &(inval[locat]);
            } else {
                locat = find(wire, in2);
                value2 = &(wireval[locat]);
            }

            locat = find(wire, out);
            outadd = &(wireval[locat]);
            Gate* nor2 = new NAND2(num, value1, value2, outadd);

            all_Gate.push_back(nor2);
        } else if (type == "XOR2") {
            string num, out, in1, in2;
            filein >> num >> out >> in1 >> in2;

            int locat;
            int* value1;
            int* value2;
            int* outadd;
            if (find(input, in1) != -1) {
                locat = find(input, in1);
                value1 = &(inval[locat]);
            } else {
                locat = find(wire, in1);
                value1 = &(wireval[locat]);
            }
            if (find(input, in2) != -1) {
                locat = find(input, in2);
                value2 = &(inval[locat]);
            } else {
                locat = find(wire, in2);
                value2 = &(wireval[locat]);
            }

            locat = find(wire, out);
            outadd = &(wireval[locat]);
            Gate* xor2 = new NAND2(num, value1, value2, outadd);

            all_Gate.push_back(xor2);
        } else if (type == "XNOR2") {
            string num, out, in1, in2;
            filein >> num >> out >> in1 >> in2;

            int locat;
            int* value1;
            int* value2;
            int* outadd;
            if (find(input, in1) != -1) {
                locat = find(input, in1);
                value1 = &(inval[locat]);
            } else {
                locat = find(wire, in1);
                value1 = &(wireval[locat]);
            }
            if (find(input, in2) != -1) {
                locat = find(input, in2);
                value2 = &(inval[locat]);
            } else {
                locat = find(wire, in2);
                value2 = &(wireval[locat]);
            }

            locat = find(wire, out);
            outadd = &(wireval[locat]);
            Gate* xnor2 = new NAND2(num, value1, value2, outadd);

            all_Gate.push_back(xnor2);
        } else if (type == "NAND3") {
            string num, out, in1, in2, in3;
            filein >> num >> out >> in1 >> in2 >> in3;

            int locat;
            int* value1;
            int* value2;
            int* value3;
            int* outadd;
            if (find(input, in1) != -1) {
                locat = find(input, in1);
                value1 = &(inval[locat]);
            } else {
                locat = find(wire, in1);
                value1 = &(wireval[locat]);
            }
            if (find(input, in2) != -1) {
                locat = find(input, in2);
                value2 = &(inval[locat]);
            } else {
                locat = find(wire, in2);
                value2 = &(wireval[locat]);
            }
            if (find(input, in3) != -1) {
                locat = find(input, in3);
                value3 = &(inval[locat]);
            } else {
                locat = find(wire, in3);
                value3 = &(wireval[locat]);
            }

            locat = find(wire, out);
            outadd = &(wireval[locat]);
            Gate* nand3 = new NAND2(num, value1, value2, outadd);

            all_Gate.push_back(nand3);
        } else if (type == "NOR3") {
            string num, out, in1, in2, in3;
            filein >> num >> out >> in1 >> in2 >> in3;

            int locat;
            int* value1;
            int* value2;
            int* value3;
            int* outadd;
            if (find(input, in1) != -1) {
                locat = find(input, in1);
                value1 = &(inval[locat]);
            } else {
                locat = find(wire, in1);
                value1 = &(wireval[locat]);
            }
            if (find(input, in2) != -1) {
                locat = find(input, in2);
                value2 = &(inval[locat]);
            } else {
                locat = find(wire, in2);
                value2 = &(wireval[locat]);
            }
            if (find(input, in3) != -1) {
                locat = find(input, in3);
                value3 = &(inval[locat]);
            } else {
                locat = find(wire, in3);
                value3 = &(wireval[locat]);
            }

            locat = find(wire, out);
            outadd = &(wireval[locat]);
            Gate* nor3 = new NAND2(num, value1, value2, outadd);

            all_Gate.push_back(nor3);
        } else if (temp == "endmodule") {
            break;
        }
    }

    filein.close();
}

bool compare(Gate* a, Gate* b) {
    string as, bs;
    as = a->getname();
    bs = b->getname();
    string ass, bss;
    int ai, bi;
    ass = as.substr(1, as.size());
    bss = bs.substr(1, bs.size());
    ai = atoi(ass.c_str());
    bi = atoi(bss.c_str());
    return ai < bi;
}
//-------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    ifstream input1;
    ofstream outcome;
    input1.open(argv[2]);
    outcome.open("outcome.txt");
    parseNET(argv[1]);

    ////pattern input
    int use;
    use = input.size();
    string* instrarr = new string[use];
    int* innum = new int[use];
    string s1;
    input1 >> s1;
    for (int i = 0; i < input.size(); i++) input1 >> instrarr[i];
    input1 >> s1;
    while (s1 != "end") {
        for (int i = 0; i < input.size(); i++) input1 >> innum[i];
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input.size(); j++) {
                if (input[i] == instrarr[j]) inval[i] = innum[j];
            }
        }

        ////set value
        for (int i = 0; i < all_Gate.size(); i++) all_Gate[i]->reset();

        /// pattern output
        cout << s1;
        sort(all_Gate.begin(), all_Gate.end(), compare);
        for (int i = 0; i < all_Gate.size(); i++) outcome << all_Gate[i]->getname() << ' ' << all_Gate[i]->getout() << endl;
        input1 >> s1;
    }
    outcome.close();
    input1.close();
}
