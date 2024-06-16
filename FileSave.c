#include "header.h"

Chain* CreatChain() {
	Chain* result = (Chain*)malloc(sizeof(Chain));
	result->next = NULL;
	FILE* fp = fopen(FILENAME, "rb");
	if (!fp) {
		return NULL;
	}

	Chain* chain = result;
	Books data;
	while (fread(&data, sizeof(Books), 1, fp) == 1) {
		// �����µ�Chain�ڵ�
		Chain* node = (Chain*)malloc(sizeof(Chain));
		node->data = data;

		// ��ȡBook����
		Book* book = NULL;
		Book** book_ptr = &(node->data.book);
		for (int i = 0; i < data.all_num; i++) {
			book = (Book*)malloc(sizeof(Book));
			fread(book, sizeof(Book), 1, fp);
			*book_ptr = book;
			book_ptr = &(book->next);
		}
		*book_ptr = NULL;

		// װ��
		chain->next = node;
		chain = chain->next;
	}

	chain->next = NULL;
	fclose(fp);
	return result;
}

int SaveToFile(char* filename, Chain* head) {
	FILE* fp = fopen(filename, "wb");
	if (!fp) {
		return -1;
	}

	Chain* chain = head->next;
	while (chain != NULL) {
		// д��Books����
		fwrite(&(chain->data), sizeof(Books), 1, fp);

		// д��Book����
		Book* book = chain->data.book;
		while (book != NULL) {
			fwrite(book, sizeof(Book), 1, fp);
			book = book->next;
		}

		chain = chain->next;
	}

	fclose(fp);
	return 0;
}
