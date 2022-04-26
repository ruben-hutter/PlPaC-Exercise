class BufferedChange {
private:
    // operation to apply to value and element
    int op;
    // operand to apply operator to
    int* operand;
    // value in array to apply operator to
    int value;
    // gets the current value of the element in the array
    int getValueOf(int* operand);
    // applies the add operator
    int add();
    // applies the subtract aoperator
    int subtract();
    // aplies the multiplication operator
    int multiply();
    // applies the division multiplicator
    int divide();
    // enum storing all available operations
    enum Operator {ADD = 0, SUBTRACT = 1, MULT = 2, DIV = 3};

public:
    // constructor
    BufferedChange();
    // deconstructor
    ~BufferedChange();
    // executes the buffered change
    void execute();
};
