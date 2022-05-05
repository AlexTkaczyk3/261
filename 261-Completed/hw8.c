typedef int data_t;
typedef struct {
    long len;
    data_t *data;
} vec_rec , *vec_ptr;

long vec_length(vec_ptr v) {
    return v->len;
}

int get_vec_element(vec_ptr v, long index, data_t * dest) {
    if (index < 0 || index >= v->len) {
        return 0;
    }
    *dest = v->data[index];
    return 1;
}

data_t *get_vec_start(vec_ptr v) {
    return v->data;
}

void hw8_func(vec_ptr u, vec_ptr v, vec_ptr p, data_t *dest) {
    long i;
    // replaced "vec_length(u)" with direct member call into new variable to reduce procedure calls
    int length = u->len; // fixed loop inefficiency for code motion
    // moved loop inefficiencies
    vec_ptr a = u;
    vec_ptr b = v;
    vec_ptr c = p;
    data_t udataAcc;
    data_t vdataAcc;
    data_t pdataAcc;
    long remainder = length % 6;
    for (i = 0; i < length, i = i + 6) {
        // replaced get_vec_element calls with direct member refrences to reduce procedure calls
        udataAcc = udataAcc + a->data[i] + a->data[i+1] + a->data[i+2] + a->data[i+3] + a->data[i+4] + a->data[i+5];
        vdataAcc = vdataAcc + b->data[i] + b->data[i+1] + b->data[i+2] + b->data[i+3] + b->data[i+4] + b->data[i+5];
        pdataAcc = pdataAcc + c->data[i] + c->data[i+1] + c->data[i+2] + c->data[i+3] + c->data[i+4] + c->data[i+5];
    }
    // extra loop for remainder
    for (int j = 0; j < remainder; j++) {
        udataAcc = udataAcc + a->data[length - j - 1];
        vdataAcc = vdataAcc + b->data[length - j - 1];
        pdataAcc = pdataAcc + c->data[length - j - 1];
        
    }
    *dest = *dest + udataAcc + vdataAcc + pdataAcc; // reduce unneccesary memory refrences
}
