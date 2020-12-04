#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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
	      set_name("[1;33mÑÅµäÄÈÖ®¶Ü[2;37;0m", ({ "fengwu shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ãæ");
		set("long", @LONG
[32m·ïÎèÖ®¶Ü[2;37;0mÕâÊÇÒ»ÃæÓÉÎŞ±È¼áÓ²µÄ[31mÍòÄêÉñÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØÊ®Ò»½ïÁùÁ½ÁùÇ®µÄ[32m·ïÎèÖ®¶Ü[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[33mºÜ¸ß[2;37;0m [36mÄ¾[2;37;0m:[1;32mÄ§Íõ[2;37;0m [32mË®[2;37;0m:[1;33mÌìÊ¥[2;37;0m [31m»ğ[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31mÎŞË«[2;37;0m ¾ø´ú:[34mÏ¸Ëé[2;37;0m ÇÉÖÆ:[34mÏ¸Ëé[2;37;0m 
×ÏÊ¯:[34mÏ¸Ëé[2;37;0m ³¤Éú:[36m²»´í[2;37;0m ²»ÀÏ:[33mºÜ¸ß[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m·ç·ç[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÖ¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lingdy");
		set("ownername", "·ç·ç");
		set("value", 16000);
		set("armor_prop/intelligence",40);
		set("armor_prop/strength",48);
		set("armor_prop/karey",48);
		set("armor_prop/percao",25);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 48);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 40);


    set("armor_prop/armor", 625);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 48);
    set("armor_prop/jing", 41);
    set("armor_prop/jingli", 41);
    set("armor_prop/damage", 414);

    set("wtypeA",6);
    set("wtypeB",9);
    set("wtypeC",10);
    set("wtypeD",12);
    set("wtypeE",6);
    set("wtypeF",6);
    set("wtypeG",6);
    set("wtypeH",6);
    set("wtypeI",6);
    set("wtypeJ",6);
    set("wtypeK",6);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";