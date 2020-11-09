# Course

[![hackmd-github-sync-badge](https://hackmd.io/tO_UqvW-TN26cBjs8TVfWA/badge)](https://hackmd.io/tO_UqvW-TN26cBjs8TVfWA)

[09C350] C++程式設計與資料結構實戰班 李宏儒

上課時間：109/11/1-12/13，週日，9：00-17：00，  
共六週42小時 11/22停課
## Notes
- 20201101  
    傳統C : struct  
    C++ : Class  
    結構, 類別, 物件定義  
    enum 列舉 與define意義相同  
    判斷運算子`&&` 條件先後影響效率 (越關鍵的條件放前面)  
    DLL動態連接檔(h檔, cpp檔)compiler完cpp會變亂碼  
    ==建構子==與類別同名, 無回傳值  
    ```cpp=
    class Set{
    private:
        //資料成員 屬性
        int iAry[10];
    public:
        Set(){}
        //函式原型
        void myFunction(int &);
    };


    int main(){

    }

    //函式主體
    void Set::myFunction(int &num ){
        //.................
    }
    ```
    函式特徵 : `參數的個數`, `型別`, `(成員函式)const`  
    利用上述特徵 可建構出 ==函式多載overloading==  
    動態配置, 動態宣告記憶體 : C `malloc` C++`new (程式碼執行完 記憶體還會佔著 最後要delete掉 否則要重開機才會release)`  
    ==指標== pointer : 減少透過作業系統幫忙的次數 能使程式直接去找到資料儲存的位置 (不再須要詢問OS作業系統)  
    同類別才有的(備用)複製建構子 `=`，若該類別內有 `new` 動態宣告記憶體 則須自行撰寫複製建構子，因備用建構子只能將指標內容複製，造成兩物件還是會只到同一塊記憶體，沒有實現複製的意義。應該要分別new出記憶體給他們。  
    複製運算子不會影響到原物件 (兩物件為獨立的)  
    建構子效率寫法(屬性為純數)  
    ```cpp=
    class CComplex{
    private:
        double _real;
        double _image;
    public:
        //建構子最佳最效率寫法 , :屬性(數值) 逗號分隔 生成物件的同時直接賦值
        Set(double real = 0.0, double image = 0.0):_real(real), _image(image){}
    };
    ```

- 20201108  
`this`為==物件指標==，指向當初呼叫函式的 ==該物件==，為使未來能順利符合其他compiler建議盡量都寫上this。  
`->`為多屬性(多樣複雜)的 ==存取運算子==，`*`則為純數的存取運算子。  
方案總管, 類別檢視  
將類別分割獨立成一cpp, h檔，其檔名須完全與類別名稱相同。且cpp務必include入h檔，h檔內全放 ==宣告==即可。所有與h檔有關的東西(有call到的)，一律移入h檔。  
rand() 現在為 <iostream> 函式庫，需與 <ctime> 當作random seed搭配使用，用法如下  

    ```cpp=
    //main.cpp
    #include <iostream>
    #include <ctime>
    using namespace std;
    int main(){
        srand( (unsigned)time(NULL)); //用到系統時間 設定亂數種子
    }
    //POKER.cpp
    void POKER::setShuffle(){
	    for(int i = 51; i>0; --i){
            int idx = rand()%i;
            int temp = iPoker[i];
            iPoker[i] = iPoker[idx];
            iPoker[idx] = temp;
	    }
    }
    ```
    
    ==auto==當區域變數執行結束，該記憶體會自動被release  
    區域變數(Local variable)3種宣告方式:  
    1.`(auto)` 區域結束時，記憶體release。(一般情況 現可省略)  
    2. `static` 區域結束時，記憶體不會被release。  
    3. `register` 將記憶體註冊在CPU暫存區，可助ALU科學運算加速  
    ==static於類別中== 的概念  
    查找資料資源網站: MSDN, STL標準樣板函式庫  
    資料結構四要素 : stack, queue, linked-list, tree  
    
- 20201115  

