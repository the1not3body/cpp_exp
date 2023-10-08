#define CALL_WITH_MAX(a, b) ((a) > (b) ? (a) : (b))

int main () {
    int a = 5, b = 0;
    CALL_WITH_MAX(++a, b);
    CALL_WITH_MAX(++a, b + 10);
    return 0;
}