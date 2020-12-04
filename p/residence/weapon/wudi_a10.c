#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

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
	      set_name("[35m¿ªÑôÖ®Åû·ç[2;37;0m", ({ "kaiyang armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
		set("long", @LONG
[35m¿ªÑôÖ®Åû·ç[2;37;0mÕâÊÇÒ»¼þÓÉ¼«Æä¼áÓ²µÄ[1;33m½ðÌú[2;37;0m¼ÓÉÏ[1;33mÄ¾ÃÞ»¨[2;37;0mÖÆ³É£¬ÖØËÄ½ïÁãÁ½¾ÅÇ®µÄ[35m¿ªÑôÖ®Åû·ç[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎÞË«[2;37;0m ¿´ÆðÀ´¼«Æä¼á¹Ì£¬¾ßÓÐ[36m²»Ð¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ð[2;37;0m:[35m±ê×¼[2;37;0m [36mÄ¾[2;37;0m:[1;35m¾øÊÀ[2;37;0m [32mË®[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;35m·ç[2;37;0m:[31m¾«ÖÂ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ð©·û×Ö£º
¼áÓ²:[1;31m¿ªÔª[2;37;0m ¸£Ô´:[36m²»´í[2;37;0m 
ÇÉÖÆ:[32m´Ö²Ú[2;37;0m 
°×Ê¯:[32m´Ö²Ú[2;37;0m ×ÏÊ¯:[33mºÜ¸ß[2;37;0m ÉÁµç:[33mºÜ¸ß[2;37;0m 

ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÎÞµÐ[2;37;0m ¡¿¡£ºÍÒ»Ð©¡¾ [1;32mÖ¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wudi");
		set("ownername", "ÎÞµÐ");
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",16);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 34);
    set("armor_prop/parry", 42);
    set("armor_prop/attack", 46);


    set("armor_prop/armor", 81);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",5);
    set("wtypeB",11);
    set("wtypeC",11);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",6);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 13);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";