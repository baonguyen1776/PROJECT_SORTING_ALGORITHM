#include <LibraryProject.h>
using namespace std;
using namespace std::chrono;

vector<string> Algorithm = {"selection-sort", "insertion-sort", "bubble-sort", "binaryinsertion-sort", "shaker-sort", "shell-sort", "quick-sort", "merge-sort", "heap-sort", "radix-sort", "counting-sort", "flash-sort"};

vector<string> outputParameters = {"-time", "-comp", "-both"};

vector<string> inputOrder = {"-rand", "-nsorted", "-sorted", "-rev"};

bool checkDataIsNumber(string s) {
    for (size_t i = 0; i < s.size(); i++) 
        if (!isdigit(s[i]))
            return false;
    return true;
}

// Đây là hàm dùng để sinh 1 file dữ liệu theo commandline và ghi nó vào file intput đầu vào
void generateAndWriteFile(string fileName, int n, int type) {
    ofstream fOut(fileName);
    int* newArr = new int[n];
    GenerateData(newArr, n, type);
    fOut << n << endl;
    for (int i = 0; i < n; i++)
        fOut << newArr[i] << " ";
    fOut.close();
}

//Giả sử ta đã tách được dữ liệu đầu vào thì đây là hàm để xủ lý nó
void processSort(vector<string> algos, string inputFile, string outputParams, int flag = 0) {
    //Đề phòng trường hợp quá nhiều thuật toán
    vector<Record> result;

    //Duyệt qua hết các thuật toán yêu cầu làm
    for (size_t i = 0; i < algos.size(); i++) {

        // bước 1: thực hiện yêu cầu tiên quyết là đọc ghi dữ liệu vào file
        ifstream fIn(inputFile);
        int n;
        fIn >> n;
        int* arr = new int[n];
        for (int j = 0; j < n; j++) 
            fIn >> arr[i];
        fIn.close();

        //bước 2: kiểm tra xem trong chuỗi vector algos gồm thuật toán gì và thực hiện nó
        string nameAlgo = algos[i];
        Record dataRecord;
        if (nameAlgo == "selection-sort") 
            dataRecord = getRecord(arr, n, selectionSortTime, selectionSortCmp);
        else if (nameAlgo == "insertion-sort") 
            dataRecord = getRecord(arr, n, insertionSortTime, insertionSortCmp);
        else if (nameAlgo == "bubble-sort") 
            dataRecord = getRecord(arr, n, bubbleSortTime, bubbleSortCmp);
        else if (nameAlgo == "shaker-sort") 
            dataRecord = getRecord(arr, n, shakerSortTime, shakerSortCmp);
        else if (nameAlgo == "shell-sort") 
            dataRecord = getRecord(arr, n, shellSortTime, shellSortCmp);
        else if (nameAlgo == "binaryinsertion-sort") 
            dataRecord = getRecord(arr, n, binaryInsertionSortTime, binaryInsertionSortCmp);
        else if (nameAlgo == "heap-sort") 
            dataRecord = getRecord(arr, n, heapSortTime, heapSortCmp);
        else if (nameAlgo == "quick-sort") 
            dataRecord = getRecord(arr, n, quickSortVer2Time, quickSortVer2Cmp);
        else if (nameAlgo == "merge-sort") 
            dataRecord = getRecord(arr, n, mergeSortTime, mergeSortCmp);
        else if (nameAlgo == "radix-sort") 
            dataRecord = getRecord(arr, n, radixSortTime, radixSortCmp);
        else if (nameAlgo == "counting-sort") 
            dataRecord = getRecord(arr, n, countingSortTime, countingSortCmp);
        else 
            dataRecord = getRecord(arr, n, flashSortTime, flashSortCmp);
        result.push_back(dataRecord);

        if (algos.size() == 1 && flag == 0) {
            ofstream fOut("output.txt");
            fOut << n << endl;
            for (int i = 0; i < n; i++)
                fOut << arr[i] << " ";
        }

        delete[] arr;
    }

    // Bước 3 là ta xử lý việc in ra của thuật toán
    // Sẽ có 3 loại:
    //     Loại 1: Chỉ in ra 1 trong 2 dạng là -time và -comp
    //     Loại 2: In ra cả 2 bằng lệnh -both
    //     Loại 3: Không có gì và ta tự in ra

    // Xử lý running time trước:
    if (outputParams == "-time" || outputParams == "-both" || outputParams == "") {
        cout << "Running time: ";
        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i].time;
            if (i < result.size() - 1)
                cout << " | ";
        }
        cout << endl;
    }

    if (outputParams == "-comp" || outputParams == "-both" || outputParams == "") {
        cout << "Running time: ";
        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i].comparision;
            if (i < result.size() - 1)
                cout << " | ";
        }
        cout << endl << endl;
    }

}

bool check(vector<string> v, char* argv) {
    for (auto it : v) 
        if (it == argv)
            return true;
    return false;
}

int findDataType(string s) {
    for (size_t i = 0; i < inputOrder.size(); i++) 
        if (s == inputOrder[i])
            return i;
    return -1;
}

// Cuối cùng là hàm dùng để xử lý lệnh commandline rồi ném nó vào các hàm trên
void processArg(int argc, char *argv[]) {
    string model = "";
    vector<string> algos;
    int inputSize = 0;
    string _inputOrder = "", _outputPrams = "", checkTemp;
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-a")) 
            model = "-a";
        else if (strcmp(argv[i], "-c"))
            model = "-c";
        else if (check(algos, argv[i]))
            algos.push_back(argv[i]);
        else if (checkDataIsNumber(argv[i]))
            inputSize = stoi(argv[i]);
        else if  (check(inputOrder, argv[i]))
            _inputOrder = argv[i];
        else if (!i)
            checkTemp = argv[i];
    }
    if (model == "") {
        cout << "Error: No mode specified\n";
        return;
    }

    if (algos.empty()) {
        cout << "Error: No algorithm specified\n";
        return;
    }

    if (model == "-a") {
        cout << "ALGORITHM MODE\n";
    } else {
        cout << "COMPARISON MODE\n";
    }

    cout << "Algorithms: ";
    for (auto it = algos.begin(); it < algos.end(); it++) {
        cout << *it;
        if (it != algos.end() - 1) 
            cout << " | ";
    }
    cout << endl;

    if (inputSize) {
        //Trường hợp này là có input size
        cout << "Input size: " << inputSize << endl;
        if (_inputOrder != "") {
            //Đây là trường hợp chỉ có 1
            cout << "Input order: " << _inputOrder << endl;
            cout << "--------------------\n";
            int dataType = findDataType(_inputOrder);
            generateAndWriteFile("input.txt", inputSize, dataType);
            processSort(algos, "input.txt", _outputPrams);
        } else {
            //Xu lý trường hợp nhiều input_X.txt
            for (size_t i = 0; i < inputOrder.size(); i++) {
                cout << "Input order: " << _inputOrder << endl;
                cout << "--------------------\n";
                int j;
                if (i == 0) j = 1; //random
                if (i == 1) j = 3; //sorted
                if (i == 2) j = 4; //rev
                if (i == 3) j = 2; //nsorted
                generateAndWriteFile("input_" + to_string(j) + ".txt", inputSize, i);
                processSort(algos, "input_" + to_string(j) + ".txt", _outputPrams, 1);
            }
        }
    } else {
        //Trường hợp này là có k input size
        ifstream fIn(checkTemp);
        if (!fIn.is_open()) {
            cout << "Error: File not found\n";
            return;
        }
        int n; 
        fIn >> n;
        fIn.close();
        cout << "Input file: " << checkTemp << "\n";
        cout << "Input size: " << n << "\n";
        cout << "--------------------\n";
        processSort(algos, checkTemp, _outputPrams);
    }
}