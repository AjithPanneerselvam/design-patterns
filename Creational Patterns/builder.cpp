#include<iostream> 
#include<vector>
#include<string> 

using namespace std; 

class File {
    string content; 

    public: 
        void write(string data) {
            content += data; 
        }

        string print() {
            return content; 
        }
};  

class Builder{
protected: 
        File* file; 

public: 
    virtual void addLine(string line) = 0; 
    virtual void createPara() = 0; 

    File* getFile() {
        return file; 
    } 

   }; 

class TexBuilder: public Builder {
public:
    TexBuilder() {
        file = new File; 
    }

    void addLine(string line) {
        string newline = "\n\\newline" + line;   
        file->write(newline); 
    }     

    void createPara() {
        file->write("\n\\newline\n\\newline");
    }
};

class TextBuilder: public Builder {
public:
    TextBuilder() {
        file = new File; 
    }

    void addLine(string line) {
        string newline = "\n" + line;   
        file->write(newline); 
    }     

    void createPara() {
        file->write("\n\n");
    }
};

class FileCreator {
    Builder* b; 

public: 
    void setBuilder(Builder* b) {
        this->b = b; 
    }

    void create(vector<string>& lines){
        for (int i = 0; i < lines.size(); i++) {
            b->addLine(lines[i]); 

            if (i != lines.size() - 1) { 
                b->createPara(); 
            }
        }
    }
};

int main() {
    vector<string> lines; 
    lines.push_back("I'm builder pattern"); 
    lines.push_back("I fall under creational pattern");

    TexBuilder texBuilder; 
    TextBuilder textBuilder; 

    FileCreator filecreator; 

    filecreator.setBuilder(&texBuilder);
    filecreator.create(lines);
    cout<<"\n"<<texBuilder.getFile()->print();

    filecreator.setBuilder(&textBuilder); 
    filecreator.create(lines);
    cout<<"\n"<<textBuilder.getFile()->print();

    return 0; 
}
