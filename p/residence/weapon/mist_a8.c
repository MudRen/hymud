#include <ansi.h> 
#include <armor.h>

inherit HANDS;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;36mÁé·çÊÖÌ×[2;37;0m", ({ "bad hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸±");
		set("long", @LONG
ÌúÖ®ÊÖÌ×[2;37;0mÕâÊÇÒ»¸±ÓÉÏàµ±¼áÓ²µÄ[32mÇàÍ­[2;37;0m¼ÓÉÏ[1;37mÃŞ»¨[2;37;0mÖÆ³É£¬ÖØÒ»½ï¶şÁ½ÈıÇ®µÄ[1;36mÌúÖ®ÊÖÌ×[2;37;0m¡£
×ÛºÏÆÀ¼Û[32m¾«ÖÂÏ¸ÃÀ[2;37;0m ¿´ÆğÀ´Ïàµ±¼á¹Ì£¬¾ßÓĞ[36mÒ»°ã[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;37mÀ×[2;37;0m:[36m²»´í[2;37;0m [1;36mÈË[2;37;0m:[34mÏ¸Ëé[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[36m²»´í[2;37;0m ¸£Ô´:[33mÒ»°ã[2;37;0m 
ÇÉÖÆ:[33mÒ»°ã[2;37;0m 
ÖÜÌì:[32m¼«²î[2;37;0m ²»ÀÏ:[33mÒ»°ã[2;37;0m ÍşÁ¦:[32m¼«²î[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÔÆËªôá[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m°µÆ÷[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "mist");
		set("ownername", "ÔÆËªôá");
		set("value", 2000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",72);
		set("armor_prop/karey",7);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 622);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 72);
    set("armor_prop/qi", 72);
    set("armor_prop/jing", 72);
    set("armor_prop/jingli", 72);
    set("armor_prop/damage", 730);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",9);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",1);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",9);
    set("wtypeK",9);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "throwing",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		


		set("material", "default");
    set("sharpness", 1);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";