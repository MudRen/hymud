#include <ansi.h> 
#include <armor.h>

inherit SURCOAT;

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
	      set_name("[33mÊŞÆ¤Ö®¶Ç´ø[2;37;0m", ({ "good surcoat", "surcoat" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
		set("long", @LONG
ÊŞÆ¤Ö®¶Ç´ø[2;37;0mÕâÊÇÒ»ÌõÓÉÎŞ±È¼áÓ²µÄ[1;37mÈíÒø[2;37;0m¼ÓÉÏ[1;37m²ÏË¿[2;37;0mÖÆ³É£¬ÖØÒ»½ï°ËÁ½ËÄÇ®µÄ[33mÊŞÆ¤Ö®¶Ç´ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;34m¾ÙÊÀº±¼û[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[36mÒ»°ã[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;36mÈË[2;37;0m:[1;33mÌìÊ¥[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÌìÊ¥[2;37;0m ÇÉÖÆ:[36m²»´í[2;37;0m 
ÉÁµç:[34mÏ¸Ëé[2;37;0m 

ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÊ·µÙ·ÒÖÜ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m×¦·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xianoda");
		set("ownername", "Ê·µÙ·ÒÖÜ");
		set("value", 9000);
		set("armor_prop/intelligence",40);
		set("armor_prop/strength",8);
		set("armor_prop/karey",40);
		set("armor_prop/percao",24);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 40);
    set("armor_prop/parry", 8);
    set("armor_prop/attack", 27);


    set("armor_prop/armor", 203);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 40);
    set("armor_prop/qi", 16);
    set("armor_prop/jing", 32);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 155);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",10);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "claw",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 10);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";