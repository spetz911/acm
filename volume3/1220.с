#include<stdio.h>
#include<string.h>

#define uint32_t unsigned int

#define VALSIZE 30
#define PSIZE 17
#define GET_BIT(P) ((stack[(P) >> 0x3] >> ((P) & 0x7)) & 0x1)
#define SET_BIT(P, BIT) ((BIT)?(stack[(P) >> 0x3] = stack[(P) >> 0x3] | (1 << ((P) & 0x7))):(stack[(P) >> 0x3] = stack[(P) >> 0x3] & (~(1 << ((P) & 0x7)))))

typedef struct {
	uint32_t val;
	uint32_t next;
} st_elem_t;

st_elem_t st_elem;
uint32_t sp[1000];
char stack[712500], buf[30];
uint32_t st_bit, c_bit, c_byte, i, j, n, stnum, stval;

void write_st_elem(uint32_t p) {
	st_bit = p * (VALSIZE + PSIZE);
	for(i=0;i<VALSIZE;i++) {
		SET_BIT(st_bit + i, (st_elem.val >> i) & 0x1);
	}
	st_bit = st_bit + VALSIZE;
	for(i=0;i<PSIZE;i++) {
		SET_BIT(st_bit + i, (st_elem.next >> i) & 0x1);
	}
}

void read_st_elem(uint32_t p) {
	st_bit = p * (VALSIZE + PSIZE);
	memset(&st_elem, 0, sizeof(st_elem_t));
	for(i=0;i<VALSIZE;i++) {
		st_elem.val = st_elem.val + (GET_BIT(st_bit + i) << i);
	}
	st_bit = st_bit + VALSIZE;
	for(i=0;i<PSIZE;i++) {
		st_elem.next = st_elem.next + (GET_BIT(st_bit + i) << i);
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	fgets(buf, 30, stdin);
	sscanf(buf, "%u", &n);
	for(j=0;j<n;j++) {
		fgets(buf, 30, stdin);
		if(buf[1] == 'U') {
			sscanf(buf + 5, "%u%u", &stnum, &stval);
			stnum--;
			st_elem.val = stval;
			st_elem.next = sp[stnum];
			write_st_elem(j);
			sp[stnum] = j;
			// printf("PUSHED AS %u\n", j);
		} else {
			sscanf(buf + 4, "%u", &stnum);
			stnum--;
			read_st_elem(sp[stnum]);
			printf("%u\n", st_elem.val);
			sp[stnum] = st_elem.next;
		}
	}
	return 0;
}
