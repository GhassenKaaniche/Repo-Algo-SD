#include <stdio.h>
#include "infinite_library.h"

int main() {
    int N, Q, x;
    scanf("%d", &N);

    Node *root = NULL;
    for (int i = 0; i < N; i++) {
        int id;
        scanf("%d", &id);
        root = insert(root, id);
    }

    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &x);
        if (search(root, x))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
