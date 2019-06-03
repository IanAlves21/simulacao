#include <bits/stdc++.h>

#define MWC_CYCLE 4096
#define MWC_C_MAX 809430660

struct mwc_state{
	uint32_t Q[MWC_CYCLE];
	uint32_t c;
	unsigned i;
};

uint32_t rand32(void){
	uint32_t result = rand();
	return result << 16 | rand();
}

void initMWC(struct mwc_state *state, unsigned int seed){
	srand(seed);
	for (int i = 0; i < MWC_CYCLE; i++)
		state->Q[i] = rand32();
	do
		state->c = rand32();
	while (state->c >= MWC_C_MAX);
	state->i = MWC_CYCLE - 1;
}

uint32_t randMWC(struct mwc_state *state){
	uint64_t const a = 18782;
	uint32_t const m = 0xfffffffe;
	uint64_t t;
	uint32_t x;

	state->i = (state->i + 1) & (MWC_CYCLE - 1);
	t = a * state->Q[state->i] + state->c;
	state->c = t >> 32;
	x = t + state->c;
	if (x < state->c) {
		x++;
		state->c++;
	}
	return state->Q[state->i] = m - x;
}

int main(){
	struct mwc_state mwc;
	unsigned int seed = time(NULL);

	initMWC(&mwc, seed);
	uint32_t num;
    // for(int h=0; h<1000000; h++){
		num = randMWC(&mwc);
	    printf("%u\n",num%10);
    // }
}
