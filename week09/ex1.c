#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int FRAME_CNT = 100; //or 50 or 10
const int MAX_REF = 1e5; //maximum page reference number

int ref_cnt; //number of full page frames

int main(){
	freopen("input.txt", "r", stdin);

	int frames[FRAME_CNT];  //stores page references in its positions
	int in_frame[MAX_REF]; //1 if page reference in frame, 0 if not
	int novelty[MAX_REF]; //lowest novelty - most recently used


	int n;
	int hit = 0, miss = 0;

	//initially nothing is in page frames
	memset(frames, -1, sizeof(frames)); 
	memset(novelty, -1, sizeof(novelty));
	memset(in_frame, 0, sizeof(in_frame));

	while(scanf("%d", &n) == 1){
		if (in_frame[n]){// if already in frame, it's hit
			hit++;
			if (novelty[n]){ //if not already most recent
				for (int i = 0; i < FRAME_CNT; ++i){ //update(increase) novelties of newer page references 
					if (novelty[frames[i]] < novelty[n] && frames[i] != -1){
						novelty[frames[i]]++;
					}
				}
				novelty[n] = 0; //make current page reference the newest
			}
		}
		else { //if not in frame, it's miss
			miss++;
			if (ref_cnt < FRAME_CNT){ //if frames are not full
				frames[ref_cnt] = n; //just add new page reference to the end
				in_frame[n] = 1;
				novelty[n] = 0;
				for (int i = 0; i < ref_cnt; ++i){ //update(increase) novelties of previous page references
					novelty[frames[i]]++;
				}
				ref_cnt++;
			}
			else {  //if all frames are full
				int max_novelty = 0;
				int max_novelty_ind;
				for (int i = 0; i < FRAME_CNT; ++i){ //search for oldest(with biggest novelty) page reference
					if (novelty[frames[i]] > max_novelty){ 
						max_novelty = novelty[frames[i]];
						max_novelty_ind = i;
					}
					novelty[frames[i]]++; //update(increase) novelties of all page references inside our frames
				}
				//delete older page reference
				in_frame[frames[max_novelty_ind]] = 0;
				novelty[frames[max_novelty_ind]] = -1;

				//write new page reference to emptied page frame
				frames[max_novelty_ind] = n;
				novelty[n] = 0;
				in_frame[n] = 1;

			}
		}
	}
	printf("hit/miss ratio: %f", hit * 1.0 / miss); //result
	return 0;
}