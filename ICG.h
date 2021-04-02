#ifndef ICG_H
#define ICG_H
#include <map>

class BC{
    public:
        enum class InstrCode {
            aload,
            astore,
            iadd,
            isub,
            ifeq,
            _goto,
            ldc
        };
        static std::string instr_code_to_name( InstrCode instr_code ) {
        static const std::map<InstrCode,std::string> InstrCodeNames = {
            { InstrCode::aload, "aload" },
            { InstrCode::astore, "astore" },
            { InstrCode::ldc, "ldc" },
            { InstrCode::ifeq, "ifeq" },
            { InstrCode::_goto, "goto" },
            { InstrCode::iadd, "iadd" },
            { InstrCode::isub, "isub" }
        };
        auto it = InstrCodeNames.find( instr_code );
        if ( it != InstrCodeNames.end() )
            return it->second;
        return "unknown_instr_code";
        }
        class Label {
            public:
                Label ( ) : Label(-1) {}
                explicit Label( int num ) : num_(num) {}
                int get_num() const { return num_; }
                std::string to_string() const { return "L" + std::to_string(num_); }
            private:
                int num_;
        };
        

};



#endif