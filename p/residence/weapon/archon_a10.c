#include <ansi.h> 
#include <armor.h>

inherit WAIST;

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
	      set_name("[37mÀ×µçÖ®Ñü´ø[2;37;0m", ({ "leidian waist", "waist" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
		set("long", @LONG
[37mÀ×µçÖ®Ñü´ø[2;37;0mÕâÊÇÒ»ÌõÓÉÎŞ±È¼áÓ²µÄ[31mÍòÄêÉñÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØ¶ş½ï°ËÁ½Ò»Ç®µÄ[37mÀ×µçÖ®Ñü´ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[36m²»Ğ¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[32mË®[2;37;0m:[1;31mÎŞË«[2;37;0m [33mÍÁ[2;37;0m:[31m¾«ÖÂ[2;37;0m [1;35m·ç[2;37;0m:[1;33mÌìÊ¥[2;37;0m 
[1;37mÀ×[2;37;0m:[33mºÜ¸ß[2;37;0m [1;34mµç[2;37;0m:[1;35m¾øÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m¿ªÔª[2;37;0m ÌìÓî:[36m²»´í[2;37;0m ÇÉÖÆ:[36m²»´í[2;37;0m 
×ÏÊ¯:[32m´Ö²Ú[2;37;0m ÉÁµç:[34mÏ¸Ëé[2;37;0m 
³¤Éú:[33mºÜ¸ß[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÌìÕı[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÈ­½Å[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "archon");
		set("ownername", "ÌìÕı");
		set("value", 16000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",48);
		set("armor_prop/karey",48);
		set("armor_prop/percao",40);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 40);
    set("armor_prop/parry", 48);
    set("armor_prop/attack", 40);


    set("armor_prop/armor", 630);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 40);
    set("armor_prop/qi", 44);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 93);

    set("wtypeA",5);
    set("wtypeB",4);
    set("wtypeC",12);
    set("wtypeD",6);
    set("wtypeE",6);
    set("wtypeF",10);
    set("wtypeG",6);
    set("wtypeH",11);
    set("wtypeI",6);
    set("wtypeJ",3);
    set("wtypeK",3);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "unarmed",
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