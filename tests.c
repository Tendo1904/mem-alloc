//
// Created by tendo on 05.01.2022.
//
#include "util.h"
#include "mem.h"
#include "mem_internals.h"

#define KGRN  "\x1B[32m"
#define KRED  "\x1B[31m"
#define KNRM  "\x1B[0m"

static void denial(struct block_header* heap){
    fprintf(stdout,"\t%sDENIAL is on run\n\n",KRED);
    void* cell = _malloc(1000);
    struct block_header* header = (struct block_header*) (cell - offsetof(struct block_header, contents));
    if (cell == NULL){ err("We cannot afford loosing of our bravest");}
    if (header->next == NULL){ err("We must not loose our bonds");}
    if (header->is_free != false){ err("It just shouldn't be true");}
    if (header->capacity.bytes != 1000){ err("You're not whom I knew before");}
    debug_heap(stdout,heap);
    _free(cell);
    if (header->is_free != true){ err("So when you have a chance to be free, you decide not to be one");}
    fprintf(stdout,"\n%sWell this will definitely not pass other steps\n\n",KGRN);
}

static void anger(struct block_header* heap){
    fprintf(stdout,"\n\t%sHere is ANGER coming\n\n",KRED);
    void* cell_fst = _malloc(3000);
    void* cell_snd = _malloc(3100);
    if (cell_fst==NULL || cell_snd==NULL){ err("And you are calling this junk a code?!");}
    struct block_header* header_fst = (struct block_header*) (cell_fst - offsetof(struct block_header, contents));
    struct block_header* header_snd = (struct block_header*) (cell_snd - offsetof(struct block_header, contents));
    if (header_fst->capacity.bytes != 3000){ err("What a donkey!");}
    if (header_snd->capacity.bytes != 3100){ err("Are those your legs?");}
    debug_heap(stdout, heap);
    _free(cell_fst);
    if (header_fst->is_free!=true){ err("Pathetic weakling trembling before TRUE freedom");}
    if (header_snd->is_free!=false){ err("How dramatically fall your poorly written code");}
    debug_heap(stdout, heap);
    _free(cell_snd);
    fprintf(stdout,"\n%sLet you've passed my rage, but others will reach yah\n\n",KGRN);
}

static void bargaining(struct block_header* heap){
    fprintf(stdout,"\n\t%sWhy should we fighting if we can make a BARGAIN\n\n",KRED);
    void* cell_fst = _malloc(2500);
    void* cell_snd = _malloc(3100);
    void* cell_trd = _malloc(3400);
    if (cell_fst==NULL || cell_snd==NULL || cell_trd==NULL){ err("Of course it can be bypassed, doesn't it?");}
    struct block_header* header_fst = (struct block_header*) (cell_fst - offsetof(struct block_header, contents));
    struct block_header* header_snd = (struct block_header*) (cell_snd - offsetof(struct block_header, contents));
    struct block_header* header_trd = (struct block_header*) (cell_trd - offsetof(struct block_header, contents));
    if (header_snd->capacity.bytes != 3100){ err("What could I give for it to be otherwise?");}
    debug_heap(stdout,heap);
    _free(cell_snd);
    _free(cell_fst);
    debug_heap(stdout,heap);
    if (header_fst->next!=header_trd){ err("Would it be some business fst and snd have to merge?");}
    _free(cell_trd);
    fprintf(stdout,"\n%sAt least with me you had a chance, last two are not as forgivable as I am\n\n",KGRN);
}

static void depression(struct block_header* heap){
    fprintf(stdout,"\n\t%sSadly your code has got this far, so now it shall face a DEPRESSION\n\n",KRED);
    void* cell_fst = _malloc(8500);
    void* cell_snd = _malloc(3600);
    void* cell_trd = _malloc(4400);
    void* cell_frth = _malloc(3000);
    if (cell_fst==NULL || cell_snd==NULL || cell_trd==NULL){ err("Of course it can be bypassed, doesn't it?");}
    struct block_header* header_fst = (struct block_header*) (cell_fst - offsetof(struct block_header, contents));
    struct block_header* header_snd = (struct block_header*) (cell_snd - offsetof(struct block_header, contents));
    struct block_header* header_trd = (struct block_header*) (cell_trd - offsetof(struct block_header, contents));
    struct block_header* header_frth = (struct block_header*) (cell_frth- offsetof(struct block_header, contents));
    debug_heap(stdout,heap);
    if (header_fst->capacity.bytes!=8500 || header_snd->capacity.bytes!=3600 ||
        header_trd->capacity.bytes!=4400 || header_frth->capacity.bytes!=3000
        ){ err("There is nothing but eternal inappropriate bytes using");}
    if (header_fst->next!=header_snd || header_snd->next!=header_trd || header_trd->next!=header_frth ||
        (void*)(header_fst->contents+header_fst->capacity.bytes) != header_snd ||
        (void*)(header_snd->contents+header_snd->capacity.bytes) != header_trd ||
        (void*)(header_trd->contents+header_trd->capacity.bytes) != header_frth
        ){ err("This is desperate to watch you try not to loose your links");}
    _free(cell_fst);
    _free(cell_snd);
    _free(cell_trd);
    _free(cell_frth);
    fprintf(stdout,"\n%sHow highly you wouldn't climb, it is always a risk of fall\n\n",KGRN);
}

static void acceptance(struct block_header* heap){
    fprintf(stdout,"\n\t%sSo finally, time of ACCEPTANCE of your destiny has come\n\n",KRED);
    void* cell_fst = _malloc(10000);
    void* cell_snd = _malloc(5000);
    debug_heap(stdout,heap);
    struct block_header* header_fst = (struct block_header*) (cell_fst - offsetof(struct block_header, contents));
    struct block_header* header_snd = (struct block_header*) (cell_snd - offsetof(struct block_header, contents));
    if (header_fst->next == header_snd || (void*)(header_fst->contents+header_fst->capacity.bytes)==header_snd){
        err("And now these two must be divided by some plug");
    }
    fprintf(stdout,"\n%sWow, congratulations you've done it !!!\n\n",KGRN);
}

void try_pass_them_all(){
    size_t param = 10000;
    struct block_header* heap = heap_init(param);
    denial(heap);
    anger(heap);
    bargaining(heap);
    depression(heap);
    acceptance(heap);
}